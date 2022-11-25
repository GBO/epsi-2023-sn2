
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Ex-2.1
 * Classe Article de base
*/
class Article {
private:
  string nom;
  int prix;

public:
  Article(string nom, int prix) {
    this->nom = nom;
    this->prix = prix;
  }
  string get_nom() { return this->nom; }
  int get_prix() { return this->prix; }

  void afficher() {
    cout << "Article '" << this->nom << "' (" << this->prix << "€)" << endl;
  }
};

/**
 * Ex-2.2
 * Classe abstraite Magasin : contrat de service pour tous les autres magasins
*/
class Magasin {
public:
  // Les méthodes ne sont pas implémentées avec la syntaxe `= 0` pour
  // le rendre abraites
  virtual string get_nom() = 0;
  virtual int get_prix() = 0;
  virtual Article* acheter(int argent) = 0;
};

/**
 * Ex-2.3
 * Spécialisation Boulangerie implémentant toutes les méthodes abstraites
*/
class Boulangerie: public Magasin {
public:
  virtual string get_nom() {
    return "Boulangerie";
  }
  virtual int get_prix() {
    return 1;
  }
  virtual Article* acheter(int argent) {
    if (argent >= this->get_prix()) {
      return new Article("Baguette", this->get_prix());
    } else {
      return nullptr;
    }
  }
};

/**
 * Ex-2.3
 * Spécialisation Presse implémentant toutes les méthodes abstraites
*/
class Presse: public Magasin {
public:
  virtual string get_nom() {
    return "Presse";
  }
  virtual int get_prix() {
    return 5;
  }
  virtual Article* acheter(int argent) {
    if (argent >= this->get_prix()) {
      return new Article("Journal", this->get_prix());
    } else {
      return nullptr;
    }
  }
};


int main(int argc, char **argv)
{
  cout << "Exercice 2 - Supermarché" << endl;

  // Ne compile pas : la classe Magasin est abstraite (et donc non instanciable)
  // Magasin* magasin = new Magasin();

  Magasin* m1 = new Boulangerie();
  Magasin* m2 = new Presse();

  Article* a1 = m1->acheter(1);
  Article* a2 = m2->acheter(50);

  a1->afficher();
  a2->afficher();

  delete a1;
  delete a2;

  return 0;
}
