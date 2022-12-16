#include <iostream>
#include <vecteur>

using namespace std;

class Instrument {
private:
  string nom;
  int prix;

public:
  Instrument(string nom, int prix) {
    this->nom = nom;
    this->prix = prix;
  }
  string get_nom() { return this->nom; }
  int get_prix() { return this->prix; }

  void afficher() {
    cout << "Instrument '" << this->nom << "' (" << this->prix << "€)" << endl;
  }
};



class Batterie {
public:
  virtual string get_nom() = 0;
  virtual int get_prix() = 0;
  virtual Instrument* jouer(int nom) = 0;
};

class Trompette: public Batterie {
public:
    virtual string get_nom() {
        return "Trompette";
    }
    virtual int get_prix() {
        return 1;
    }
    virtual Instrument* jouer(int nom) {
        if (nom >= this->get_prix()) {
            return new Instrument("Clavier", this->get_prix());
        } else {
            return nullptr;
        }
    }
};


class Guitare: public Batterie {
public:
    virtual string get_nom() {
        return "Guitare";
    }
    virtual int get_prix() {
        return 5;
    }
    virtual Instrument* jouer(int nom) {
        if (nom >= this->get_prix()) {
            return new Instrument("Spectacle", this->get_prix());
        } else {
            return nullptr;
        }
    }
}
;int main(int argc, char **argv)



Batterie* m1 = new Batterie();
Batterie* m2 = new Clavier();

Instrument* a1 = m1->jouer(1);
Instrument* a2 = m2->jouer(50);

1->afficher();
2->afficher();

delete a1;
delete a2;

return 0;
}