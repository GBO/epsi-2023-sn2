#include <iostream>
#include <cmath>

using namespace std;
/**
 * Exercice 1
 *Classe de base représentant la voiture
*/
class Instrument {
protected:
    string nom;
public:
    Instrument(string nom) {
        this->nom = nom;
    }

    virtual string get_nom() { return this->nom; }

    virtual void sonner() {
        cout << this->nom << "sonne" << endl;
    }
};

/**
 * Exercice2
 *Classe spécialisant un Instrument en Batterie
*/
class Batterie : public Instrument {
public:
    Batterie() : Instrument("Batterie"){
    }
    virtual string get_nom() {return this->nom;}
    virtual void sonner() {
        cout << this->get_nom() << " fait bang" << endl;
    }
};

//Classe spécialisant un Instrument en Trompette
class Trompette : public Instrument {
public:
    Trompette() : Instrument("Trompette"){
    }
    virtual string get_nom() {return this->nom;}
    virtual void sonner() {
        cout << this->get_nom() << " fait pouet" << endl;
    }
};

//Classe spécialisant un Instrument en Guitare
class Guitare : public Instrument {
public:
    Guitare() : Instrument("Guitare"){

    }
    virtual string get_nom() {return this->nom;}
    virtual void sonner() {
        cout << this->get_nom() << " fait ding" << endl;
    }
};


Instrument* creer(string nom) {
    Instrument* instrument;
    // En fonction du paramètre fourni, on instancie des objets de la bonne classe
    if (nom == "Batterie") {
        instrument= new Batterie();
    } else if (nom == "Trompette") {
        instrument = new Trompette();
    } else if (nom == "Guitare") {
        instrument = new Guitare();
    }

    return instrument;
}



int main(int argc, char **argv)
{
    cout << "\nVoici la liste des instruments et leur bruit !\n" << endl;

    Instrument* v1 = creer("Batterie");
    Instrument* v2 = creer("Trompette");
    Instrument* v3 = creer("Guitare");


    v1->sonner();
    v2->sonner();
    v3->sonner();

    delete v1;
    delete v2;
    delete v3;

    return 0;
}