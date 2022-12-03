#include <iostream>

using namespace std;

class Instrument {
private:
    string nom;
    string bruit;
protected:
public:
    Instrument(string nom, string bruit) {
        this->nom = nom;
        this->bruit = bruit;
    }

    string getNom() {
        return this->nom;
    }

    string getBruit() {
        return this->bruit;
    }

    void sonner() {
        cout << "L'instrument " << this->getNom() << " fait le bruit " << this->getBruit() << endl;
    }
};
//EXERCICE 1

/*int main() {
Instrument* trompette = new Instrument("Trompette");
trompette->sonner();
}*/

class Batterie : public Instrument {

private:
protected:
public:

    virtual string getNom() {
        return "Batterie";
    }

    virtual string getBruit() {
        return "bang";
    }
};

class Trompette : public Instrument {

private:
protected:
public:

    virtual string getNom() {
        return "Trompette";
    }

    virtual string getBruit() {
        return "pouet";
    }
};

class Guitare : public Instrument {

private:
protected:
public:
    virtual string getNom() {
        return "Guitare";
    }

    virtual string getBruit() {
        return "ding";
    }
};

//EXERCICE 2
/*int main() {
    Instrument *trompette = new Instrument("trompette","pouet");
    Instrument *batterie = new Instrument("batterie","bang");
    Instrument *guitare = new Instrument("guitare","ding");
    trompette->sonner();
    batterie->sonner();
    guitare->sonner();
};
 */
/*class Orchestre{
    vector<Instrument*> = listeInstrument
};*/
class Groupe{
private:
    Guitare* guitare;
    Batterie* batterie;
    Trompette* trompette;
protected:
public:
    Groupe(Guitare* guitare1, Batterie* batterie1,Trompette* trompette1){
        this->trompette = trompette1;
        this->guitare = guitare1;
        this->batterie = batterie1;
    }
};
int main(){
Groupe* groupe = new Groupe(guitare: new Guitare, trompette: new Trompette, batterie: new Batterie);
groupe->sonner();
};