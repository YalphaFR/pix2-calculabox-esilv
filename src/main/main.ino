#include <map>
using std::map;

System sys = null;

void setup() {
  // put your setup code here, to run once:
  sys = new System().initialization();
}

void loop() {
  // put your main code here, to run repeatedly:
  const Game partie = new Game();
  partie.menu();
  partie.play();
}

// Classes

class System {
  public:
    const map<string, Capteur> capteurs;
    const map<string, Moteur> moteurs;
    const map<string, Ecran> ecrans;
    const map<string, Led> leds;

    void initialization() {
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
}

class Game {
  public:
    const int levels[4] = {1, 2, 3, 4};
    int level = null;
    int tentativeMaximum = 2;
    int tentativesRestante = tentativeMaximum;
    

    Game(int level) {
      this->level = level;
    }

    void menu() {
      while () {
        System.ecrans["ecranGauche"].afficher("-");
        System.ecrans["ecranMilieu"].afficher(String(level));
        System.ecrans["ecranDroit"].afficher("+");

        // Traiter les différents cas pour les capteurs
      }
    }

    void play() {
      System.ecrans["ecranMilieu"].afficher("La partie va commencer !");
      while () {

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
    void demarrer() {

    }
}

class Ecran {
  public:
    void afficher() {
      
    }
}

class Led() {
  public:

}
