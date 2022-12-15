
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Ex-1.3
 * Classe représentant un moteur sa cylindrée et son régime.
*/
class Moteur {
private:
  int cylindree;
  int regime;
public:
  Moteur(int cylindree, int regime) {
    this->cylindree = cylindree;
    this->regime = regime;
  }
  int get_cylindree() { return this->cylindree; }
  int get_regime() { return this->regime; }
};

/**
 * Ex-1.3
 * Classe représentant une boîte de vitesse et son rapport de boîte
*/
class Boite {
private:
  int rapport;
public:
  Boite(int rapport) {
    this->rapport = rapport;
  }
  int get_rapport() { return this->rapport; }
};

/**
 * Ex-1.3
 * Classe représentant les roues et leur circonférence
*/
class Roues {
private:
  int circonference;
public:
  Roues(int circonference) {
    this->circonference = circonference;
  }
  int get_circonference() { return this->circonference; }
};

/**
 * Ex-1.1
 * Classe de base représentant la voiture
*/
class Voiture {
protected:
  string marque;
  string modele;

  Moteur* moteur;
  Boite* boite;
  Roues* roues;

public:
  Voiture(string marque, string modele) {
    this->marque = marque;
    this->modele = modele;
  }

  virtual string get_marque() { return this->marque; }
  virtual string get_modele() { return this->modele; }

  virtual void afficher() {
    cout << "Voiture " << this->marque << " " << this->modele << endl;
  }

  virtual int get_vitesse_max() {
    return round((moteur->get_regime() / boite->get_rapport()) * roues->get_circonference() * 0.06);
  }
};

/**
 * Ex-1.2
 * Classe spécialisant une voiture en Lamborghini
*/
class LamborghiniGallardo : public Voiture {
public:
  LamborghiniGallardo(): Voiture("Lamborghini", "Gallardo") {}

  virtual void afficher() {
    cout << "La Lambo : " << this->marque << " " << this->modele << endl;
  }
};

/**
 * Ex-1.2
 * Classe spécialisant une voiture en Focus
*/
class FordFocusRS : public Voiture {
public:
  FordFocusRS(): Voiture("Ford", "Focus RS") {
    // Ex-1.3 : Initialisation des composants de notre Voiture
    this->moteur = new Moteur(2261, 6000);
    this->boite = new Boite(5);
    this->roues = new Roues(4388);
  }

  virtual void afficher() {
    cout << "La Ford Focus R.S." << endl;
  }
};



class VoitureFactory {
private:
  static VoitureFactory* instance;

  VoitureFactory() {}
public:
  static VoitureFactory* get_instance();

  Voiture* creer(string modele);
};

VoitureFactory* VoitureFactory::instance = nullptr;

VoitureFactory* VoitureFactory::get_instance() {
  if (VoitureFactory::instance == nullptr) {
    VoitureFactory::instance = new VoitureFactory();
  }
  return VoitureFactory::instance;
}  


/**
 * Ex-1.4
 * Première version de Factory sous forme de fonction simple
*/
Voiture* VoitureFactory::creer(string modele) {
  Voiture* voiture;
  // En fonction du paramètre fourni, on instancie des objets de la bonne classe
  if (modele == "Gallardo") {
    voiture = new LamborghiniGallardo();
  } else if (modele == "FocusRS") {
    voiture = new FordFocusRS();
  // Avec un recours par défaut à une simple Voiture
  } else {
    voiture = new Voiture("Générique", modele);
  }

  return voiture;
}


int main(int argc, char **argv)
{
  cout << "Exercice 1.1 - Voiture" << endl;

  Voiture* v1 = VoitureFactory::get_instance()->creer("Gallardo");
  Voiture* v2 = VoitureFactory::get_instance()->creer("FocusRS");
  Voiture* v3 = VoitureFactory::get_instance()->creer("Mégane");

  v1->afficher();
  cout << "Vitesse max : " << v1->get_vitesse_max() << endl;
  v2->afficher();
  cout << "Vitesse max : " << v2->get_vitesse_max() << endl;
  v3->afficher();

  delete v1;
  delete v2;
  delete v3;

  return 0;
}
