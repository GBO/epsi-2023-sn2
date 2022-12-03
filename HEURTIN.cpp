#include <iostream>
#include "vector"

using namespace std;

//on créer la classe instrument qui comporte un nom

class Instrument {
private:
protected:

    string nom;

public:
    //constructeur
    Instrument(string nom) {

        //on met le nom de l'instrument dans la variable nom

        this->nom = nom;
    }

    //getter nom pour récupérer le nom de l'instrument
    string getNom() {
        return this->nom;
    }

    //méthode que les enfants instruments devront modifier (d'où le virtual)
    virtual void sonner() {

    }

};

//création de la classe Trompette qui est un instrument avec comme nom "Trompette"
class Trompette : public Instrument {
private:
protected:
public:
    Trompette() : Instrument("Trompette") {

    }

    //modification de la méthode sonner de la classe Instrument pour que la trompette sonne
    void sonner() {

        cout << "pouet" << endl;

    }
};

//création de la classe Guitare (idem à Trompette)
class Guitare : public Instrument {
private:
protected:
public:
    Guitare() : Instrument("Guitare") {

    }

    void sonner() {

        cout << "ding" << endl;

    }
};

//création de la classe Batterie (idem à Trompette)
class Batterie : public Instrument {
private:
protected:
public:
    Batterie() : Instrument("Batterie") {

    }

    void sonner() {

        cout << "Bang" << endl;

    }
};

//création de la classe Orchestre
class Orchestre {
private:

    //vector vide d'instruments qu'on remplira plus tard
    vector<Instrument *> instruments;

public:
    //constructeur vide car pas besoin d'instancier quoi que ce soit
    Orchestre() {

    }

    //méthode pour ajouter un instrument dans l'orchestre (ajout dans le vector d'Instruments créer plus tôt)
    void ajouter(Instrument *instrument) {

        this->instruments.push_back(instrument);

        cout << "l'instrument " << instrument->getNom() << " a été ajouté !" << endl;

    }

    //méthode pour faire sonner tous les instruments
    void sonner() {

        cout << "L'orchestre prépare son prochain morceau..." << endl;
        // pour chaque instruments dans la liste on appelle sa méthode sonner()
        for (int i = 0; i < this->instruments.size(); ++i) {
            this->instruments[i]->sonner();
        }
    }

};

//création de la classe Groupe
class Groupe {

private:

    Guitare *guitare;
    Trompette *trompette;
    Batterie *batterie;

    string nom;

    vector<Instrument *> listeInstruments;

protected:
public:
    //constructeur qui ajoutera directement les instruments du groupe et son nom dans les variables créées plus tôt
    //ajoute aussi les instruments dans une liste pour pouvoir s'en servir dans la méthode sonner()

    Groupe(string nom, Guitare *guitare, Trompette *trompette, Batterie *batterie) {

        this->batterie = batterie;
        this->trompette = trompette;
        this->guitare = guitare;

        this->nom = nom;

        listeInstruments.push_back(this->batterie);
        listeInstruments.push_back(this->guitare);
        listeInstruments.push_back(this->trompette);

    }

    //getter du nom de groupe
    string getNom() {
        return this->nom;
    }

    //méthode pour faire sonner les instruments du groupe
    void sonner() {

        cout << "Le groupe " << this->getNom() << " prépare un show d'enfer !!" << endl;

        // pour chaque instruments dans la liste on appelle sa méthode sonner()
        for (int i = 0; i < this->listeInstruments.size(); ++i) {
            this->listeInstruments[i]->sonner();
        }
    }

};


void exo1() {
    cout << "Exercice 1" << endl;

    Instrument *violon = new Instrument("Violon");

    cout << violon->getNom() << endl;
}

void exo2() {
    cout << "Exercice 2" << endl;

    Guitare *guitare = new Guitare;
    Batterie *batterie = new Batterie;
    Trompette *trompette = new Trompette;

    guitare->sonner();
    trompette->sonner();
    batterie->sonner();

}

void exo3() {
    cout << "Exercice 3" << endl;

    Guitare *guitare1 = new Guitare;
    Batterie *batterie1 = new Batterie;
    Batterie *batterie2 = new Batterie;
    Trompette *trompette1 = new Trompette;
    Trompette *trompette2 = new Trompette;
    Trompette *trompette3 = new Trompette;

    Orchestre *orchestre = new Orchestre;

    orchestre->ajouter(guitare1);
    orchestre->ajouter(batterie1);
    orchestre->ajouter(batterie2);
    orchestre->ajouter(trompette1);
    orchestre->ajouter(trompette2);
    orchestre->ajouter(trompette3);

    orchestre->sonner();
    orchestre->sonner();
    orchestre->sonner();

}

void exo4() {

    cout << "Exercice 4" << endl;

    Guitare *guitare = new Guitare;
    Batterie *batterie = new Batterie;
    Trompette *trompette = new Trompette;

    Groupe* groupe = new Groupe("CPPOnFire", guitare, trompette, batterie);

    groupe->sonner();
    groupe->sonner();
    groupe->sonner();

}


int main() {

    exo1();
    exo2();
    exo3();
    exo4();

    return 0;
}
