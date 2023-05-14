#include <map>
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
      
      capteurs["gauche"] = new Capteur();
      capteurs["milieu"] = new Capteur();
      capteurs["droit"] = new Capteur();

      moteurs["gauche"] = new Moteur();
      moteurs["milieu"] = new Moteur();
      moteurs["droit"] = new Moteur();

      ecrans["gauche"] = new Ecran();
      ecrans["milieu"] = new Ecran();
      ecrans["droit"] = new Ecran();

      leds["addition"] = new Led();
      leds["soustraction"] = new Led();
      leds["multiplication"] = new Led();
      leds["division"] = new Led();
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
      // tant que l'écran du milieu ne detecte rien
      while () {
        sys.ecrans["ecranGauche"].afficher("-");
        sys.ecrans["ecranMilieu"].afficher(String(level));
        sys.ecrans["ecranDroit"].afficher("+");

        // Traiter les différents cas pour les capteurs
      }
    }
    
    void genererPropositions() {

    }

    void jouer() {
      sys.afficherSurTousLesEcrans("La partie va commencer !");
      while (niveau < 4) {
        // afficher les consignes sur quel écran ?


        
        String str = "";
        int v1 = random(0, 11);
        int v2 = random(0, 11);
        int operation = random(1, 5);
        int res = NULL;

        switch (operation) {
          case 1:
            str = String(v1) + "+" + String(v2) + "= ";
            res = v1+v2;
            break;

          case 2:
            str = String(v1) + "-" + String(v2) + "= ";
            res = v1-v2;
            break;

          case 3:
            str = String(v1) + "*" + String(v2) + "= ";
            res = v1*v2;
            break;

          case 4:
            str = String(v1) + "/" + String(v2) + "= ";
            res = v1/v2;
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
}

class Capteur {
  public:
    Capteur() {

    }
}

class Moteur {
  public:

    Moteur() {

    }

    void demarrer() {

    }
}

class Ecran {
  public:

    Ecran() {

    }

    void afficher() {
      
    }
}

class Led() {
  public:
    Led() {

    }

    void allumer() {

    }

    void eteindre() {

    }
}
