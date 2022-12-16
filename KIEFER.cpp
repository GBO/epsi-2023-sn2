#include <iostream>
#include <vector>

using namespace std;

class Instrument{
private:
    string nom;
public:
    Instrument(string nom){
        this->nom = nom;
    }

    string get_nom() {return this->nom;}

    virtual void sonner(){ };
};

class Batterie : public Instrument{
public:
    Batterie() : Instrument("Batterie") { }

    virtual void sonner() {
        cout << "Bang" << endl;
    }
};

class Trompette : public Instrument{
public:
    Trompette() : Instrument("Trompette") { }

    virtual void sonner() {
        cout << "Pouet" << endl;
    }
};

class Guitare : public Instrument{
public:
    Guitare() : Instrument("Guitare") { }

    virtual void sonner() {
        cout << "Ding" << endl;
    }
};

class Orchestre{
private:
    vector<Instrument*> v;
public:
    Orchestre(){ // J'ai fait ça par soucis d'habitude avec le this->v
        this->v = v;
    }

    void ajouter(Instrument* instrument){
        this->v.push_back(instrument);
    }

    void sonner(){
        for (int i = 0; i < this->v.size(); ++i) {
            this->v[i]->sonner(); // fait sonner l'élément i
        }
    }
};

class Groupe{
private:
    Guitare* lg = new Guitare; // lg diminutif de LaGuitare
    Batterie* lb = new Batterie;
    Trompette* lt = new Trompette;
public:
    Groupe(Guitare* lg, Batterie* lb, Trompette* lt){
        this->lg = lg;
        this->lb = lb;
        this->lt = lt;
    }

    void sonner(){
        lg->sonner();
        lb->sonner();
        lt->sonner();
    }
};


int main() {
    //Créations des Instruments
    Batterie* b = new Batterie;
    Trompette* t = new Trompette;
    Guitare* g = new Guitare;
    Guitare* g2 = new Guitare;
    Trompette* t2 = new Trompette;

    //Test Exercice 2 :
    cout << "exercice 2 : " << endl;
    b->sonner();
    t->sonner();
    g->sonner();
    cout << endl;

    //Test Exercice 3 :
    cout << "exercice 3 : " << endl;
    Orchestre* o = new Orchestre;

    o->ajouter(b);
    o->ajouter(t);
    o->ajouter(t2);
    o->ajouter(g);
    o->ajouter(g2);

    o->sonner();
    o->sonner();
    cout << endl;

    //Test Exercice 3 :
    cout << "exercice 4 : " << endl;
    Groupe* leGroupe = new Groupe(g,b,t);

    leGroupe->sonner();
    leGroupe->sonner();



    return 0;
}
