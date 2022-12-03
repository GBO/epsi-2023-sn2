//
// Created by simon on 01/12/22.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Instrument {
private:
    string nom;

public:
    Instrument(string nom){
        this->nom = nom;
    }
    string get_nom() { return this->nom;}

    virtual void sonner() = 0;
};

class Batterie : public Instrument {
public:
    Batterie(): Instrument("Batterie"){
    }

    void sonner() override{
        cout << "bang" << endl;
    }
};

class Trompette : public Instrument {
public:
    Trompette(): Instrument("Trompette"){
    }

    void sonner() override{
        cout << "pouet" << endl;
    }
};

class Guitare : public Instrument {
public:
    Guitare(): Instrument("Guitare"){
    }

    void sonner() override{
        cout << "ding" << endl;
    }
};


class Orchestre {
private:
    vector<Instrument*> Instruments;
public:
    void ajouter(Instrument* instrument){
        this->Instruments.push_back(instrument);
    }

    void sonner(int nombre_fois) {
        for (int i = 0; i < nombre_fois; i++) {
            for (Instrument *instrument: this->Instruments) {
                instrument->sonner();
            }
        }
    }
};

class Groupe {
private:
    Guitare* guitare;
    Trompette* trompette;
    Batterie* batterie;
public:
    Groupe(Guitare* guitare, Trompette* trompette, Batterie* batterie){
        this->guitare = guitare;
        this->trompette = trompette;
        this->batterie = batterie;
    }

    void sonner(){
        guitare->sonner();
        trompette->sonner();
        batterie->sonner();
    }
};

int main(int argc, char **argv){
    cout << "Instanciation de guitare, trompette, batterie..." << endl;
    Guitare* guitare = new Guitare;
    Trompette* trompette = new Trompette;
    Batterie* batterie = new Batterie;

    cout << "guitare, trompette, batterie sonne..." << endl;
    guitare->sonner();
    trompette->sonner();
    batterie->sonner();

    cout << "\nInstanciation d'un orchestre..." << endl;
    Orchestre* orchestre = new Orchestre;
    cout << "Ajout de 3guitare, 1trompette et 1batterie, c'est plus joli..." << endl;
    orchestre->ajouter(guitare);
    orchestre->ajouter(trompette);
    orchestre->ajouter(guitare);
    orchestre->ajouter(batterie);
    orchestre->ajouter(guitare);
    cout<<"L'orchestre seras jouer 10fois" << endl;
    orchestre->sonner(10);

    cout<<"\nInstanciation du groupe avec une guitare, une trompette et une batterie..." << endl;
    Groupe* groupe = new Groupe(guitare, trompette, batterie);
    cout<<"Le groupe joue une fois"<<endl;
    groupe->sonner();

    cout<<"\nSupression de toutes les instances..." << endl;
    delete guitare;
    delete batterie;
    delete trompette;
    delete orchestre;
    delete groupe;

    return 0;
}