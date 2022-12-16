// appel des librairies utiliser
#include <iostream>
#include <vector>
#include <windows.h>
#include <cmath>
// changer le set d'affichage pour l'UTF-8
#pragma execution_character_set( "utf-8" )
// appel de la fonction pour ne plus devoir utiliser std
using namespace std;


// Classe instrument
class Instrument {
// Argument nom en proteger pour l'heriter
protected :
    string nom;
public :
    // Constructeur avec nom comme parametre
    Instrument(string nom) {
        this->nom = nom;
    }
    // Getter de nom
    virtual string get_nom() { return this->nom; }
    // Fonction sonner pour l'instrument de basse
    virtual void sonner() {
        cout << this->nom << " sonne!" << endl;
    }
};

// Batterie qui est un enfant d'Instrument
class Batterie: public Instrument {
public :
    //Constructeur de Baterie, qui utilise celui de Instrument et qui défini son nom comme Batterie
    Batterie() : Instrument("Batterie") {}
    // Getter du nom de la Batterie
    virtual string get_nom() { return this->nom; }
    // Fait sonner l'instrument avec son bruit
    virtual void sonner() {
        cout << this->get_nom() << " bang" << endl;
    }
};

class Trompette: public Instrument {
private :
    string nom;
public :
    Trompette() : Instrument("Trompette") {}
    virtual string get_nom() { return this->nom; }
    virtual void sonner() {
        cout << this->get_nom() << " pouet" << endl;
    }
};

class Guitare: public Instrument {
private :
    string nom;
public :
    Guitare() : Instrument("Guitare") {}
    virtual string get_nom() { return this->nom; }
    virtual void sonner() {
        cout << this->get_nom() << " ding" << endl;
    }
};

// Classe Orchestre
class Orchestre {
// Argument de la liste d'Instruments
private:
    vector<Instrument*> instruments;
public:
    // Méthode ajouter pour ajouté un instrument a la fin de la liste instruments
    void ajouter(Instrument* i){
        instruments.push_back(i);
    }
    // Méthode pour faire sonner tous les instruments de la liste
    void sonner(){
        for (int i = 0; i < instruments.size(); ++i) {
            instruments[i]->sonner();
        }
    }
};

// Classe Groupe
class Groupe{
// Arguments des membres du groupe : une Batterie, une Trompette, une Guitare
private:
    Batterie* batterie;
    Trompette* trompette;
    Guitare* guitare;
public:
    // Constructeur de Groupe avec tous les membres obligatoire
    Groupe(Batterie* b, Trompette* t, Guitare* g){
        if(b != nullptr || t != nullptr || g != nullptr){
            this->batterie = b;
            this->trompette = t;
            this->guitare = g;
        } else {
            cout << "il manque un membres du groupe" << endl;
        }
    }
    // Méthode pour faire sonner tous les membres
    void sonner(){
        batterie->sonner();
        trompette->sonner();
        guitare->sonner();
    }
};

int main(int argc, char **argv) {
    // Changer le part d'Output pour utiliser l'UTF-8
    SetConsoleOutputCP(65001);

    cout << "TD Quentin VERDIER" << endl;

    cout << "Test exo 1 :" << endl;
    Instrument* i = new Instrument("test");
    i->sonner();

    cout << "\nTest exo 2 :" << endl;
    Batterie* b = new Batterie();
    Trompette* t = new Trompette();
    Guitare* g = new Guitare();
    b->sonner();
    t->sonner();
    g->sonner();

    cout << "\nTest exo 3 :" << endl;
    Orchestre* o = new Orchestre();
    Trompette* t2 = new Trompette();
    Guitare* g2 = new Guitare();
    o->ajouter(b);
    o->ajouter(t);
    o->ajouter(g);
    o->ajouter(t2);
    o->ajouter(g2);
    o->sonner();
    o->sonner();
    o->sonner();

    cout << "\nTest exo 3 :" << endl;
    Groupe* gr = new Groupe(b, t, g);
    gr->sonner();
    gr->sonner();
    gr->sonner();

    delete i;
    delete b;
    delete t;
    delete g;
    delete o;
    delete t2;
    delete g2;
    delete gr;

    return 0;
}