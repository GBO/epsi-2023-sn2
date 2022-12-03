#include <iostream>
#include <vector>
using namespace std;

// --- Exercice 1 ---
class Instrument {
protected:
    string nom;

public:
    Instrument(string nom) {
        this->nom = nom;
    }

    virtual string get_nom() { return this->nom; }

    virtual void sonner() {
        cout << "Instrument : " << this->nom << " sonne." << endl;
    }
};

// --- Exercice 2 ---
class Batterie : public Instrument {
public:
    Batterie () : Instrument("Batterie") {
    }

    virtual void sonner() {
        cout << "Bang" << endl;
    }
};

class Trompette : public Instrument {
public:
    Trompette() : Instrument("Trompette") {
    }

    virtual void sonner() {
        cout << "Pouet" << endl;
    }
};

class Guitare : public Instrument {
public:
    Guitare() : Instrument("Guitare") {
    }

    virtual void sonner() {
        cout << "Ding" << endl;
    }
};

// --- Exercice 3 ---
class Orchestre {
protected:
    vector<Instrument*> listeInstrument;

public:
    virtual void ajouter(Instrument* instrument) {
        listeInstrument.push_back(instrument);
    }

    virtual void sonner() {
        for (int i = 0; i < listeInstrument.size(); ++i) {
            if (listeInstrument[i]->get_nom() == "Batterie") {
                cout << "Bang" << endl;
            } else if (listeInstrument[i]->get_nom() == "Trompette") {
                cout << "Pouet" << endl;
            } else if (listeInstrument[i]->get_nom() == "Guitare") {
                cout << "Ding" << endl;
            } else {
                cout << "Un instrument sonne" << endl;
            }
        }
    }
};

// --- Exercice 4 ---
class Group {
protected:
    Guitare* guitare;
    Trompette* trompette;
    Batterie* batterie;

public:
    Group(Guitare* guitare, Trompette* trompette, Batterie* batterie) {
        this->guitare = guitare;
        this->trompette = trompette;
        this->batterie = batterie;
    }

    virtual void sonner() {
        this->guitare->sonner();
        this->trompette->sonner();
        this->batterie->sonner();
    }
};

int main() {
    cout << "TD Noté de Victor TERRIEN - EPSI - 01/12/2022" << endl;

    cout << " --- Exercices 1 et 2 --- " << endl;
    Instrument* b1 = new Batterie();
    Instrument* t1 = new Trompette();
    Instrument* g1 = new Guitare();
    b1->sonner();
    t1->sonner();
    g1->sonner();
    cout << endl;

    cout << " --- Exercice 3 --- " << endl;
    Orchestre* orch1 = new Orchestre();
    orch1->ajouter(b1);
    orch1->ajouter(t1);
    orch1->ajouter(g1);
    orch1->ajouter(b1);
    orch1->ajouter(t1);
    cout << "Orchestre sonne une fois : " << endl;
    orch1->sonner();
    cout << "Orchestre sonne une deuxième fois : " << endl;
    orch1->sonner();
    cout << "Orchestre sonne une troisième fois : " << endl;
    orch1->sonner();
    cout << endl;

    cout << " --- Exercice 4 --- " << endl;
    Group* grp1 = new Group(new Guitare, new Trompette, new Batterie);
    cout << "Groupe sonne une fois : " << endl;
    grp1->sonner();
    cout << "Groupe sonne une deuxième fois : " << endl;
    grp1->sonner();
    cout << "Groupe sonne une troisième fois : " << endl;
    grp1->sonner();

    delete b1;
    delete t1;
    delete g1;
    delete grp1;

    return 0;
}