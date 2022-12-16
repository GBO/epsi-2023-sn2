#include <iostream>
#include <vector>

using namespace std;

class Instrument {
private:
    string nom;

public:

    virtual string get_nom() = 0;

    virtual void sonner() = 0;
};

class Batterie : public Instrument {
public:
    virtual string get_nom() { return "Batterie"; }

    virtual void sonner() { cout << "Bang "; }
};

class Trompette : public Instrument {
public:
    virtual string get_nom() { return "Trompette"; }

    virtual void sonner() { cout << "Pouet "; }

};

class Guitare : public Instrument {
public:
    virtual string get_nom() { return "Guitare"; }

    virtual void sonner() { cout << "Ding "; }
};


class Orchestre {
private:
    vector<Instrument *> listeInstruments;
public:

void ajouter(Instrument* instrument){
    listeInstruments.push_back(instrument);
}

void sonner(){
    for(auto item: listeInstruments){
        item->sonner();
    }
}
};

class Groupe{
private:
    Guitare* guitare;
    Batterie* batterie;
    Trompette* trompette;
public:
    Groupe(Guitare* guitare1, Batterie* batterie1, Trompette* trompette1){
        this->trompette = trompette1;
        this->batterie = batterie1;
        this->guitare = guitare1;
    }

    void sonner(){
        this->guitare->sonner();
        this->batterie->sonner();
        this->trompette->sonner();
    }


};

int main() {
    Instrument *guitare = new Guitare();
    Instrument *trompette = new Trompette;
    Instrument *batterie = new Batterie;
    cout << "Exercice 2" << endl;
    guitare->sonner();
    trompette->sonner();
    batterie->sonner();
    cout << endl << "Exercice 3" << endl;
    Orchestre* o1 = new Orchestre;
    Instrument *basse = new Guitare();
    Instrument *electrique = new Guitare();
    o1->ajouter(guitare);
    o1->ajouter(trompette);
    o1->ajouter(batterie);
    o1->ajouter(basse);
    o1->ajouter(electrique);
    o1->sonner();
    o1->sonner();
    o1->sonner();
    cout << endl << "Exercice 4" << endl;
    Groupe* groupe = new Groupe(new Guitare, new Batterie, new Trompette);
    groupe->sonner();
    return 0;
}
