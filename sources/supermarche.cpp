
#include <iostream>
#include <cmath>
#include <vector>

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
protected:
  vector<Article*> stock;
  virtual void approvisionner() = 0;
  virtual Article* prendre() = 0;

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
protected:
  int count;

  virtual void approvisionner() {
    cout << "Réappro Boulangerie !" << endl;
    for (int i = 0; i < 10; i++) {
      this->count += 1;
      this->stock.push_back(new Article("Baguette " + to_string(this->count), this->get_prix()));
    }
  }
  virtual Article* prendre() {
    Article* a = this->stock[0];
    this->stock.erase(this->stock.begin());
    if (this->stock.size() < 5) {
      this->approvisionner();
    }
    return a;
  }

public:
  Boulangerie() {
    this->count = 0;
    this->approvisionner();
  }
  virtual string get_nom() {
    return "Boulangerie";
  }
  virtual int get_prix() {
    return 1;
  }
  virtual Article* acheter(int argent) {
    if (argent >= this->get_prix()) {
      return this->prendre();
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
protected:
  int count;

  virtual void approvisionner() {
    cout << "Réappro Presse !" << endl;
    for (int i = 0; i < 10; i++) {
      this->count += 1;
      this->stock.push_back(new Article("Journal " + to_string(this->count), this->get_prix()));
    }
  }
  virtual Article* prendre() {
    Article* a = this->stock[this->stock.size() - 1];
    this->stock.pop_back();
    if (this->stock.size() < 5) {
      this->approvisionner();
    }
    return a;
  }

public:
  Presse() {
    this->count = 0;
    this->approvisionner();
  }
  virtual string get_nom() {
    return "Presse";
  }
  virtual int get_prix() {
    return 5;
  }
  virtual Article* acheter(int argent) {
    if (argent >= this->get_prix()) {
      return this->prendre();
    } else {
      return nullptr;
    }
  }
};

/**
 * Ex-2.4
 * La galerie
*/
class Galerie {
private:
  vector<Magasin*> magasins;

public:
  vector<Magasin*> get_magasins() { return this->magasins; }

  void ajouter(Magasin* magasin) {
    this->magasins.push_back(magasin);
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

  Galerie* galerie = new Galerie();
  galerie->ajouter(m1);
  galerie->ajouter(m2);

  for (int i = 0; i < 10; i++) {
    for (Magasin* magasin : galerie->get_magasins()) {
      // cout << magasin->get_nom() << endl;
      Article* a = magasin->acheter(magasin->get_prix());
      cout << "Le client " << (i + 1) << " achète " << a->get_nom() << " pour " << magasin->get_prix() << "€ dans " << magasin->get_nom() << endl;
      delete a;
    }
  }


  delete a1;
  delete a2;

  return 0;
}
