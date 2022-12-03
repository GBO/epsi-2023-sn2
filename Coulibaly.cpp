#include <iostream>
#include <iostream>
#include <list>

using namespace std;


class Instrument{
private:
    string nom;
    string son;

public:
    Instrument(string nom, string son){
        this->nom = nom;
        this->son = son;
    }
    string get_nom(){ return this->nom; }
    string get_son(){ return this->son; }

    virtual void sonner() {
        cout <<this->get_son() <<endl ;
    }
};

class Batterie: public Instrument{
public:
    Batterie(): Instrument("Batterie", "bang") {
        this->sonner();
    }
};

class Trompette: public Instrument {
public:
    Trompette(): Instrument("Trompette", "pouet") {
        this->sonner();
    }
};

class Guitare: public Instrument {
public:
    Guitare(): Instrument("Guitare", "ding") {
        this->sonner();
    }
};

/*
class Orchestre{
private:
    list<Instrument> vector;


public:
    Orchestre(list<Instrument> vector){
        this->vector = vector;
    }
    Instrument get_list() {return this->vector;}

    virtual void sonner(){
        return ;
    }
};
 */

class Groupe : public Guitare, public Trompette, public Batterie{
protected:
    Guitare* guitare;
    Trompette* trompette;
    Batterie* batterie;

public:
    Groupe(): Guitare(), Trompette(), Batterie() {

    }

    virtual void sonner(){
        cout << guitare->get_son() <<endl;
        cout << trompette->get_son() <<endl;
        cout << batterie->get_son() <<endl;
    }
};

int main() {
    Instrument* B = new Batterie();
    Instrument* T = new Trompette();
    Instrument* G = new Guitare();

    // Groupe
    Groupe* groupe = new Groupe();
    groupe->sonner();


    return 0;
}
