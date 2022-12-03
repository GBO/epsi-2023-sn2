#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Instrument {
protected:
    string nom;
    string bruit;
public:
    Instrument(string nom,string bruit) {
        this->nom = nom;
        this->bruit = bruit;
    }

    //accesseur de l'attribut nom
    string get_nom(){return this->nom;};

    //méthode vituelle sonner avec "bruit" le son de l'instrument
    virtual void sonner(){
        cout << this->bruit << endl;
    }
};

//la classe Batterie qui instancie Instrument avec des paramètres
class Batterie : public Instrument{
public:
    Batterie() : Instrument("batterie","bang") {}
};

//la classe Guitare qui instancie Instrument avec des paramètres
class Guitare : public Instrument{
public:
    Guitare() : Instrument("Guitare","ding") {}
};

//la classe Trompette qui instancie Instrument avec des paramètres
class Trompette : public Instrument{
public:
    Trompette() : Instrument("trompette","pouet") {}
};

class Orchestre{
private:
    //liste d'instruments instancier vide dans un premier temps
     vector<Instrument*> liste_instruments = {};
public:
    virtual void ajouter(Instrument* instrument){
        liste_instruments.push_back(instrument);
    }

    virtual void sonner(){
        for( Instrument *instrument : liste_instruments ){
            instrument->sonner();
        }
    }

};

class Groupe{
private:
    //instancie le fait d'avoir les 3 instruments
    Batterie* batterie;
    Guitare* guitare;
    Trompette* trompette;
public:
    Groupe(Batterie* batterie, Guitare* guitare, Trompette* trompette){
        this->batterie = batterie;
        this->guitare = guitare;
        this->trompette = trompette;
    }

    virtual void sonner(){
        //fait sonner les 3 instruments
        this->batterie->sonner();
        this->guitare->sonner();
        this->trompette->sonner();
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "évaluation pas Victor RAMBAUD" << endl << endl;

    //----------------les instruments tout seul----------------
    cout << endl << endl << "Solo time !!! " << endl;
    //instancier tout les instruments
    Instrument* i1 = new Batterie();
    Instrument* i2 = new Trompette();
    Instrument* i3 = new Guitare();

    //sonner
    i1->sonner();
    i2->sonner();
    i3->sonner();

    //supprimer
    delete i1;
    delete i2;
    delete i3;

    //----------------orchestre----------------
    cout << endl << endl << "Orchestre time !!! " << endl;
    Instrument* io1 = new Batterie();
    Instrument* io2 = new Batterie();
    Instrument* io3 = new Trompette();
    Instrument* io4 = new Trompette();
    Instrument* io5 = new Guitare();

    Orchestre* o1 = new Orchestre();

    o1->ajouter(io1);
    o1->ajouter(io2);
    o1->ajouter(io3);
    o1->ajouter(io4);
    o1->ajouter(io5);

    o1->sonner();

    delete io1;
    delete io2;
    delete io3;
    delete io4;
    delete io5;

    delete o1;

    //----------------Groupe----------------
    cout << endl << endl << "Group time !!! " << endl;
    Batterie* ig1 = new Batterie();
    Guitare* ig2 = new Guitare();
    Trompette* ig3 = new Trompette();

    Groupe* g1 = new Groupe(ig1,ig2,ig3);

    g1->sonner();

    delete ig1;
    delete ig2;
    delete ig3;

    delete g1;
    return 0;
}
