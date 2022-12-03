#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>


using namespace std;

class Instrument {
private:
    string name;
    string song;
public:

    Instrument(string name, string song) {
        this->name = name;
        this->song = song;
    }

    virtual ~Instrument() {}

    string getName() {
        return this->name;
    }

    string getSong() {
        return this->song;
    }

    virtual void sonner() {
        cout << "L'instrument " + this->name + " fait le song " + this->song << endl;
    }

};

class Batterie : public Instrument {
public:
    Batterie() : Instrument("Batterie", "Boum Boum") {}
};

class Trompette : public Instrument {
public:
    Trompette() : Instrument("Trompette", "Tutututu") {}
};

class Guitare : public Instrument {
public:
    Guitare() : Instrument("Guitare", "Ding ding dong") {}
};

class Orchestre {
private:
    vector<Instrument *> instruments;
public:

    void ajouter(Instrument *name) {
        instruments.push_back(name);
    }

    void sonner() {
        for (int i = 0; i < instruments.size(); i++) {
            instruments[i]->sonner();
        }
    }
};

class Groupe {
private:
    Batterie *batterie;
    Trompette *trompette;
    Guitare *guitare;
public:
    Groupe(Batterie *batterie, Trompette *trompette, Guitare *guitare) {
        this->batterie = batterie;
        this->trompette = trompette;
        this->guitare = guitare;
    }
    ~Groupe() {
        delete batterie;
        delete trompette;
        delete guitare;
    }
    void sonner() {
        batterie->sonner();
        trompette->sonner();
        guitare->sonner();
    }

};


int main() {
    SetConsoleOutputCP(CP_UTF8);

    //Exercice 1
    cout << "\n-- Exercice 1 --" << endl;
    auto *pInstrument = new Instrument("Test", "Youpi ça marche");
    pInstrument->sonner();

    //Exercice 2
    cout << "\n-- Exercice 2 --" << endl;
    auto *pBatterie = new Batterie();
    pBatterie->sonner();
    auto *pTrompette = new Trompette();
    pTrompette->sonner();
    auto *pGuitare = new Guitare();
    pGuitare->sonner();

    //Exercice 3
    cout << "\n-- Exercice 3 --" << endl;
    auto *pBatterie2 = new Batterie();
    auto *pTrompette2 = new Trompette();
    auto *pOrchestre = new Orchestre();
    pOrchestre->ajouter(pTrompette);
    pOrchestre->ajouter(pTrompette2);
    pOrchestre->ajouter(pBatterie);
    pOrchestre->ajouter(pBatterie2);
    pOrchestre->ajouter(pGuitare);
    pOrchestre->sonner();
    cout << endl;

    //Exercice 4
    pOrchestre->sonner();


    //Exercice 4
    cout << "\n-- Exercice 4 --" << endl;
    auto *pGroupe = new Groupe(pBatterie, pTrompette, pGuitare);
    pGroupe->sonner();
    cout << endl;
    pGroupe->sonner();



    return 0;
}
