#include <map>
#include <Servo.h> // Moteur
#include <OLED_I2C.h> // Ecran

using std::map;

System sys;

void setup() {
  // put your setup code here, to run once:
  sys = new System();
  sys.initialisation();
}

void loop() {
  // put your main code here, to run repeatedly:
  Jeu partie = Jeu(sys);
  partie.choisirNiveau();
  partie.jouer();
}

// Classes

class System {
  public:
    map<String, Capteur> capteurs;
    map<String, Moteur> moteurs;
    map<String, Ecran> ecrans;
    map<String, Led> leds;

    void initialisation() {
      
      capteurs["gauche"] = Capteur();
      capteurs["milieu"] = Capteur();
      capteurs["droit"] = Capteur();

      moteurs["gauche"] = Moteur();
      moteurs["milieu"] = Moteur();
      moteurs["droit"] = Moteur();

      ecrans["gauche"] = Ecran();
      ecrans["milieu"] = Ecran();
      ecrans["droit"] = Ecran();

      leds["addition"] = Led();
      leds["soustraction"] = Led();
      leds["multiplication"] = Led();
      leds["division"] = Led();
    } 

    void afficherSurTousLesEcrans(String str) {
      for (auto const& [key, val] : ecrans)
        {
            val.afficher(str);
        }
    }
};

class Jeu {
  public:
    int niveau = 1;
    int tentativeMaximum = 2;
    int tentativesRestante = tentativeMaximum;
    System sys;

    Jeu(System sys) {
      this->sys = sys;
    }

    void choisirNiveau() {
      // tant que le capteur du milieu ne detecte rien
      sys.ecrans["ecranGauche"].afficher("-");
      sys.ecrans["ecranDroit"].afficher("+");
      
      while () {
        sys.ecrans["ecranMilieu"].afficher(String(level));

        // Traiter les différents cas pour les capteurs
      }
    }
    
    void genererPropositions() {

    }

    void jouer() {
      sys.afficherSurTousLesEcrans("La partie va commencer !");
      delay(4000);

      while (niveau < 4) {
        // éteindre toutes les leds
        for (auto const& [key, val] : leds)
        {
            val.eteindre();
        }

        for (int i = 0; i < 2; i++) {

          // afficher les consignes sur quel écran ?

          String str = "";
          int v1 = random(0, 11);
          int v2 = random(0, 11);
          int operation = random(1, 5);
          int res = NULL;

          switch (operation) {
            case 1:
              sys.leds["addition"].allumer();
              str = String(v1) + "+" + String(v2) + "= ";
              res = v1+v2;
              break;

            case 2:
              sys.leds["soustraction"].allumer();
              str = String(v1) + "-" + String(v2) + "= ";
              res = v1-v2;
              break;

            case 3:
              sys.leds["multiplication"].allumer();
              str = String(v1) + "*" + String(v2) + "= ";
              res = v1*v2;
              break;

            case 4:
              sys.leds["division"].allumer();
              str = String(v1) + "/" + String(v2) + "= ";
              res = v1/v2;
              break;
          }

          if (res != proposition) {
            tentativesRestante -= 1;
          }
        }

        switch (tentativesRestante) {
          case 0:
            modifierNiveau(niveau - 1);
            break;
        }
        {
        case 1:

          break;
        
        case 2:
        modifierNiveau(niveau + 1);
          break;
        }

      }
      sys.afficherSurTousLesEcrans("Félicitations, vous avez achevé tous les niveaux !");
    }

    void modifierNiveau(int niveau) {
      if (1 <= niveau && niveau <= 4) {
        this->niveau = niveau;
      }
    }

    void modifierTentative(int tentative) {
      if (0 <= tentative && tentative <= tentativeMaximum) {
        this->tentativesRestante = tentative;
      }
    } 
};

class Capteur {
  public:
    int pin;
    Capteur() {

    }
};

class Moteur {
  public:
    int pin;
    Servo servoMoteur;
      Moteur(int pin) {
        this->pin = pin;
        configurer();
      }

      void configurer() {
        servoMoteur.attach(pin);
      }

      void tourner(int angle) {
        servoMoteur.write(angle);
      }
};

class Ecran {
  public:
    int pin;
    OLED myOLED(SDA, SCL, pin);

    Ecran(int pin) {
      this->pin = pin;

      configurer();
    }

    void configurer() {
      uint8_t BigNumbers[];
      myOLED.begin();
      myOLED.setFont(BigNumbers);
    }

    void afficher(float f) {
      myOLED.printNumF(f, RIGHT, 40);
      myOLED.update();
    }

    void afficher(int inte) {
      myOLED.printNumF(inte, RIGHT, 40);
      myOLED.update();
    }

    void afficher(String str) {
      myOLED.printNumF(str, RIGHT, 40);
      myOLED.update();
    }

    void cleanScreen() {
      myOLED.clrScr();
    }

};

class Led {
  public:
    int pin;

    Led(int pin) {
      this->pin = pin;
      configurer();
    }

    void allumer() {
      degitalWrite(pin, HIGHT); //le courant est envoyé sur la borne 1, la LED s'allume
    }

    void configurer() {
      pinMode(pin, OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie
    }

    void eteindre() {
      degitalWrite(pin, LOW);
    }
};
