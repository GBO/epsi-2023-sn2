#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>

using namespace std;

class Instrument {
private:
    string nom;
    string son;
public:
    Instrument(string nom, string son) {
        this->nom = nom;
        this->son = son;
    }

    string get_nom() { return this->nom; };

    void set_nom(string nom) { this->nom = nom; };

    void sonner() {
        cout << this->nom << " fait " << this->son << endl;
    };


};


class Batterie : public Instrument {
public:
    Batterie() : Instrument("Batterie", "poudoum tsshhhhh") {};
};

class Guitare : public Instrument {
public:
    Guitare() : Instrument("Guitare", "zwing zwing paf") {};
};

class Trompette : public Instrument {
public:
    Trompette() : Instrument("Trompette", "pouet pouet pouet") {};
};

Instrument *creer(string nom) {
    Instrument *instrument;

    if (nom == "batterie") {
        instrument = new Batterie();
    } else if (nom == "guitare") {
        instrument = new Guitare();
    } else if (nom == "trompette") {
        instrument = new Trompette;
    }
    return instrument;
};

class Orchestre {
private:
    vector<Instrument *> instrumentOrchestre;
public:

    void ajouterInstrument(Instrument *instrument) {
        this->instrumentOrchestre.push_back(instrument);
    }


    void creerOrchestre() {
        for (int i = 0; i <= 0; i++) {
            Instrument *instrumentG1 = creer("guitare");
            this->ajouterInstrument(instrumentG1);
            Instrument *instrumentG2 = creer("guitare");
            this->ajouterInstrument(instrumentG2);
            Instrument *instrumentT1 = creer("trompette");
            this->ajouterInstrument(instrumentT1);
            Instrument *instrumentT2 = creer("trompette");
            this->ajouterInstrument(instrumentT2);
            Instrument *instrumentB1 = creer("batterie");
            this->ajouterInstrument(instrumentB1);
            Instrument *instrumentB2 = creer("batterie");
            this->ajouterInstrument(instrumentB2);
        }
    };

    void sonnerORchestre() {
        for (int i = 0; i < instrumentOrchestre.size(); i++) {
            instrumentOrchestre[i]->sonner();
        }
    }

    //Fonction qui mélange mon orchestre
    void melangerOrcherstre() {
        for (int i = 0; i < 5; i++) {
            swap(instrumentOrchestre[i],instrumentOrchestre[rand() % 6]);
        }
    }
};

class Groupe {
private:
    vector<Instrument *> instrumentGroupe;
public:

    void ajouterInstrumentGroupe(Instrument *instrument) {
        this->instrumentGroupe.push_back(instrument);
    }

    void creerGroupe() {
        for (int i = 0; i == 0; i++) {
            Instrument *instrumentG = creer("guitare");
            this->ajouterInstrumentGroupe(instrumentG);
            Instrument *instrumentB = creer("batterie");
            this->ajouterInstrumentGroupe(instrumentB);
            Instrument *instrumentT = creer("trompette");
            this->ajouterInstrumentGroupe(instrumentT);
        }
    }

    void sonnerGroupe() {
        for (int i = 0; i < instrumentGroupe.size(); i++) {
            instrumentGroupe[i]->sonner();
        }
    }

};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "EXERCICE 1" << endl;

    Instrument *instrument = new Instrument("triange", "diiing");
    instrument->sonner();


    cout << "EXERCICE 2" << endl;

// Je les crée manuellement pour voir si ils marchent
//    Batterie *batterie = new Batterie();
//    Guitare *guiatre = new Guitare();
//    Trompette *trompette = new Trompette();
//
//    guiatre->sonner();
//    trompette->sonner();
//    batterie->sonner();


    Instrument *instrumentG = creer("guitare");
    Instrument *instrumentB = creer("batterie");
    Instrument *instrumentT = creer("trompette");

    instrumentB->sonner();
    instrumentG->sonner();
    instrumentT->sonner();

    cout << "EXERCICE 3" << endl;

    Orchestre *orchestre = new Orchestre;
    orchestre->creerOrchestre();
    orchestre->melangerOrcherstre();
    orchestre->sonnerORchestre();

    cout << "EXERCICE 4" << endl;

    Groupe *groupe = new Groupe;
    groupe->creerGroupe();
    groupe->sonnerGroupe();
    
    return 0;
}
