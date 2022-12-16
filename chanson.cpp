// Inclusion des librairies
#include <iostream>
#include <vector>

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

//définition de la classe Instrument
class Instrument {
private:
    //attributs
    string nom;
public:
    //constructeur
    Instrument(string nom) {
        //initialisation de l'attribut nom
        this->nom = nom;
    }

    //méthode getNom qui retourne le nom de l'instrument (getter)
    string getNom() {
        return this->nom;
    }

    //méthode sonner qui affiche le son de l'instrument
    virtual void sonner() {
        //affichage du son de l'instrument
        cout << "bim bam" << endl;
    }
};

//définition de la classe Batterie qui hérite de la classe Instrument
class Batterie : public Instrument {
public:
    //Constructeur de la classe Batterie qui appelle le constructeur de la classe Instrument
    Batterie() : Instrument("Batterie") {
    }

    //méthode sonner qui affiche le son de la batterie
    void sonner() {
        cout << "bang" << endl;
    }
};

//définition de la classe Trompette qui hérite de la classe Instrument
class Trompette : public Instrument {
public:
    //Constructeur de la classe Trompette qui appelle le constructeur de la classe Instrument
    Trompette() : Instrument("Trompette") {
    }
    //méthode sonner qui affiche le son de la trompette
    void sonner() {
        cout << "pouet" << endl;
    }
};

//définition de la classe Guitare qui hérite de la classe Instrument
class Guitare : public Instrument {
public:
    //Constructeur de la classe Guitare qui appelle le constructeur de la classe Instrument
    Guitare() : Instrument("Guitare") {
    }
    //méthode sonner qui affiche le son de la guitare
    void sonner() {
        cout << "ding" << endl;
    }
};

void testExercice2(){
    cout << "Exercice 2" << endl;
    //instanciation d'un objet de type Batterie
    auto* batterie = new Batterie();
    //instanciation d'un objet de type Trompette
    auto* trompette = new Trompette();
    //instanciation d'un objet de type Guitare
    auto* guitare = new Guitare();

    //appel de la méthode pour faire sonner l'instrument
    batterie->sonner();
    trompette->sonner();
    guitare->sonner();
    cout << endl;
}

class Orchestre {
private:
    //attributs
    vector<Instrument*> instruments;
public:
    //constructeur
    Orchestre() {
    }

    //méthode ajouter qui ajoute un instrument à l'orchestre
    void ajouter(Instrument* instrument) {
        //ajout de l'instrument à la liste des instruments
        instruments.push_back(instrument);
    }

    //méthode sonner qui fait sonner tous les instruments de l'orchestre
    void sonner() {
        //parcours de la liste des instruments
        for (int i = 0; i < instruments.size(); i++) {
            //appel de la méthode sonner de l'instrument
            instruments[i]->sonner();
        }
    }
};

void testExercice3(){
    cout << "Exercice 3" << endl;
    //instanciation d'un objet de type Orchestre
    auto* orchestre = new Orchestre();
    //instanciation d'objets de type Batterie
    auto* batterie = new Batterie();
    auto* batterie2 = new Batterie();
    //instanciation d'objets de type Trompette
    auto* trompette = new Trompette();
    auto* trompette2 = new Trompette();
    //instanciation d'un objet de type Guitare
    auto* guitare = new Guitare();

    //ajout des instruments à l'orchestre
    orchestre->ajouter(batterie);
    orchestre->ajouter(batterie2);
    orchestre->ajouter(trompette);
    orchestre->ajouter(trompette2);
    orchestre->ajouter(guitare);

    //appel de la méthode pour faire sonner l'orchestre
    orchestre->sonner();
    cout << endl;
}

class Groupe{
private:
    //attributs
    Guitare* guitare;
    Trompette* trompette;
    Batterie* batterie;
public:
    //constructeur
    Groupe(Guitare* guitare, Trompette* trompette, Batterie* batterie) {
        //initialisation des attributs
        this->guitare = guitare;
        this->trompette = trompette;
        this->batterie = batterie;
    }

    //méthode sonner qui fait sonner tous les instruments du groupe
    void sonner() {
        //appel de la méthode sonner de l'instrument
        guitare->sonner();
        trompette->sonner();
        batterie->sonner();
    }
};

void testExercice4(){
    cout << "Exercice 4" << endl;
    //instanciation d'un objet de type Batterie
    auto* batterie = new Batterie();
    //instanciation d'un objet de type Trompette
    auto* trompette = new Trompette();
    //instanciation d'un objet de type Guitare
    auto* guitare = new Guitare();

    //instanciation d'un objet de type Groupe
    auto* groupe = new Groupe(guitare, trompette, batterie);

    //appel de la méthode pour faire sonner le groupe
    groupe->sonner();
    groupe->sonner();
    groupe->sonner();
    groupe->sonner();
    cout << endl;
}


int main() {
    testExercice2();
    testExercice3();
    testExercice4();
    return 0;
}
