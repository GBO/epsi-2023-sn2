#include <iostream>
#include <vector>

using namespace std;

// Définition de la class Instrument
class Instrument {
    // Possédant l'attribut nom
protected:
    string nom;
public:
    // Un accesseur (getter)
    Instrument(string nom) {
        this->nom = nom;
    }

    // la méthode sonner
    virtual void sonner() {
        cout << "Bruit d'un instrument" << endl;
    }
};

// Définition de la class Batterie spécialisant la classe Instrument
class Batterie : public Instrument{
public:
    // Qui possède forcéméent le nom Batterie
    Batterie() : Instrument("Batterie") {}
    // Et qui sonne de manière différente
    virtual void sonner(){
        cout << "bang" << endl;
    }
};

// Définition de la class Trompette spécialisant la classe Instrument
class Trompette : public Instrument{
public:
    // Qui possède forcéméent le nom Trompette
    Trompette() : Instrument("Trompette") {}
    // Et qui sonne de manière différente
    virtual void sonner(){
        cout << "pwet" << endl;
    }
};

// Définition de la class Guitar spécialisant la classe Instrument
class Guitar : public Instrument{
public:
    // Qui possède forcéméent le nom Guitar
    Guitar() : Instrument("Guitar") {}
    // Et qui sonne de manière différente
    virtual void sonner(){
        cout << "ding" << endl;
    }
};

// Définition de la classe Groupe
class Groupe{
protected:
    Guitar* guitare;
    Trompette* trompette;
    Batterie* batterie;
public:
    Groupe(Guitar* guitare, Trompette* trompette, Batterie* batterie) {
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

// Définition de la class Orchestre
class Orchestre {
protected:
    // Possédant une liste d'instrument
    vector<Instrument*> instruments;
public:
    // méthode permettant d'ajouter des instruments
    void  ajouter(Instrument* instrument){
        instruments.push_back(instrument);
    }
    // Méthode permettant de faire sonner tous l'orchester
    virtual void sonner(){
        for (int i = 0; i < instruments.size(); ++i) {
            instruments.at(i)->sonner();
        }
    }
};


int main(int argc, char **argv) {

    // Création des instrument et de l'orchester
    Instrument *piano = new Instrument("Piano");
    Instrument *batterie = new Batterie();
    Instrument *trompette = new Trompette();
    Instrument *trompette2= new Trompette();
    Instrument *guitar = new Guitar();
    Instrument *guitar2 = new Guitar();
    Orchestre *orchestre1 = new Orchestre();
    // Groupe *groupe = new Groupe(*batterie, *trompette, *guitar);

    // On fait sonner chaque élements individuellement
    piano->sonner();
    trompette->sonner();
    trompette2->sonner();
    batterie->sonner();
    guitar->sonner();
    guitar2->sonner();

    // On ajoute dans l'orchester les instruments
    orchestre1->ajouter(trompette);
    orchestre1->ajouter(trompette2);
    orchestre1->ajouter(batterie);
    orchestre1->ajouter(guitar);
    orchestre1->ajouter(guitar2);

    // On fait sonner l'orchestre
    orchestre1->sonner();

    // On fait sonner le groupe
    //groupe->sonner();

    // et on delete tout
    delete piano;
    delete trompette;
    delete trompette2;
    delete batterie;
    delete guitar;
    delete guitar2;
    delete orchestre1;
    //delete groupe;
}