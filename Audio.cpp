#include <iostream>
#include "vector"

using namespace std;

class Instrument {
private :
    string nom;
public:
    Instrument(string nom) {
        this->nom = nom;
    }

    virtual string getnom() {
        return this->nom;
    }

    virtual string sonner() {
        cout << "iiii" << endl;
    }

    void afficher() {
        cout << this->nom << endl;
    }
};

class Batterie : public Instrument {
public:
    Batterie() : Instrument("Batterie") {}

    virtual string sonner() {
        cout << "bang" << endl;
    }
};

class Guitare : public Instrument {
public:
    Guitare() : Instrument("Guitare") {}

    virtual string sonner() {
        cout << "ding" << endl;
    }
};

class Trompette : public Instrument {
public:
    Trompette() : Instrument("Trompette") {}

    virtual string sonner() {
        cout << "pouet" << endl;
    }
};

class Orchestre {
private:
    vector<Instrument *> l1;
public:
    void ajouter(Instrument *l1) {
        this->l1.push_back(l1);
    }

    virtual string sonner() {
        for (int i = 0; i < l1.size(); ++i) {
            this->sonner();
        }
    }
};

class Groupe {
private:
    Guitare *guitare;
    Trompette *trompette;
    Batterie *batterie;

public:
    Groupe(Guitare *guitare1, Trompette *trompette1, Batterie *batterie1) {
        this->guitare = guitare1;
        this->batterie = batterie1;
        this->trompette = trompette1;
    }

    virtual string sonner() {
        for (int i = 0; i < 2; ++i) {
            this->sonner();
        }

    };

    int main() {
        cout << "exo 2" << endl;
        Instrument *batterie = new Batterie;
        batterie->afficher();
        batterie->sonner();
        Instrument *guitare = new Guitare;
        guitare->afficher();
        guitare->sonner();
        Instrument *trompette = new Trompette;
        trompette->afficher();
        trompette->sonner();
        cout << "exo 3" << endl;
        Orchestre *orchestre = new Orchestre;
        orchestre->ajouter(trompette);
        orchestre->ajouter(guitare);
        orchestre->ajouter(batterie);
        orchestre->sonner();
        orchestre->sonner();
        cout << "exo 4" << endl;
        // Groupe *groupe = new Groupe();
        // groupe->sonner();
    }
};