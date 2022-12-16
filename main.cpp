#include <iostream>
using namespace std;

class Batterie {
private:
    string nom;
public:
    Batterie(string nom) {
        this->nom = nom;
    }
    string getNom() {
        return this->nom;
    }
    string getSound() {
        cout << "bang" << endl;
    }
};

class Trompette {
private:
    string nom;
public:
    Trompette(string nom) {
        this->nom = nom;
    }
    string getNom() {
        return this->nom;
    }
    string getSound(){
        cout << "pouet" << endl;
    }
};

class Guitare {
private:
    string nom;
public:
    Guitare(string nom) {
        this->nom = nom;
    }
    string getNom() {
        return this->nom;
    }
    string getSound(){
        cout << "ding" << endl;
    }
};

class Instrument {
    private:
        string nom;
        Guitare *guitare;
        Trompette *trompette;
        Batterie *batterie;

public:
    Instrument(string nom, string nomGuitare, string nomTrompette, string nomBatterie) {
        this->nom = nom;
        this->guitare = new Guitare(nomGuitare);
        this->trompette = new Trompette(nomTrompette);
        this->batterie = new Batterie(nomBatterie);
    }
    string getNom() {
        return this->nom;
    }

    void jouerGuitare() {
        this->guitare->getSound();
    }
    void jouerTrompette() {
        this->trompette->getSound();
    }
    void jouerBatterie() {
        this->batterie->getSound();
    }
};

int main() {
    Instrument *instrument = new Instrument("instrument", "guitare", "trompette", "batterie");
    instrument->jouerGuitare();
    instrument->jouerTrompette();
    instrument->jouerBatterie();
    return 0;
}
