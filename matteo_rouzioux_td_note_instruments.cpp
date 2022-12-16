#include <iostream>

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

/**
 * TD noté sur les classes d'instruments
 * 01/12/2022
 * Mattéo ROUZIOUX
*/

/**
 * exercice 1 - Instrument (6 points)
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
        cout << "L'instrument " << this->nom << " sonne mais il ne fait pas parti de l'orchestre..." << endl;
    }
};



/**
 * exercice 2 - Batterie, Trompette et Guitare (6 points)
*/
//Initialisation d'une classe Batterie
class Batterie : public Instrument {
public:
    Batterie(): Instrument("Batterie") {
        //On donne sa valeur au nom
        this->nom = "Batterie";
    }

    virtual void sonner() {
        //message personnalisé pour le son de la batterie
        cout << "La " << this->nom << " fait bang !" << endl;
    }
};
class Trompette : public Instrument {
public:
    Trompette(): Instrument("Trompette") {
        //On donne sa valeur au nom
        this->nom = "Trompette";
    }

    virtual void sonner() {
        //message personnalisé pour le son de la trompette
        cout << "La " << this->nom << " fait pouet !" << endl;
    }
};
class Guitare : public Instrument {
public:
    Guitare(): Instrument("Guitare") {
        //On donne sa valeur au nom
        this->nom = "Guitare";
    }

    virtual void sonner() {
        //message personnalisé pour le son de la guitare
        cout << "La " << this->nom << " fait ding !" << endl;
    }
};

//Fonction de création d'instrument
Instrument* ajouter(string nom) {
    Instrument* instrument;
    // En fonction du paramètre fourni, on instancie des objets de la bonne classe
    if (nom == "Batterie") {
        instrument = new Batterie();
    } else if (nom == "Trompette") {
        instrument = new Trompette();
    } else if (nom == "Guitare"){
        instrument = new Guitare();
    } else {
        //si l'instrument n'est pas reconnu on lui met le message par défaut
        instrument = new Instrument(nom);
    }

    return instrument;
}

int main(int argc, char **argv)
{
    cout << "TD Noté de Mattéo ROUZIOUX - EPSI - 01/12/2022" << endl;
    //création de nos instruments
    Instrument* i1 = ajouter("Batterie");
    Instrument* i2 = ajouter("Trompette");
    Instrument* i3 = ajouter("Guitare");

    //application des fonctions à nos nouveaux instruments
    i1->sonner();
    i2->sonner();
    i3->sonner();

    //Suppression des variables
    delete i1;
    delete i2;
    delete i3;

    return 0;
}
