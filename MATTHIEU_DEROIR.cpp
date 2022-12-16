#include <iostream>
#include <vector>

using namespace std;

void print(string str) {
    cout << str << endl;
}

class Instrument {
protected:
    string name;
public:
    Instrument(string name) {
        this->name = name;
    }

    string getName() { return this->name; }

    void setName(string name) { this->name = name; }

    virtual void makeSound() {}
};

class Guitar : public Instrument {
public:
    Guitar(string name) : Instrument(name) {}

    string getName() { return this->name; }

    void setName(string name) { this->name = name; }

    void makeSound() {
        print("Ding");
    }
};

class Drums : public Instrument {
public:
    Drums(string name) : Instrument(name) {}

    string getName() { return this->name; }

    void setName(string name) { this->name = name; }

    void makeSound() {
        print("Bang");
    }
};

class Orchestra {
private:
    vector<Instrument *> instruments;
public:
    void addInstrument(Instrument *instrument) {

        this->instruments.push_back(instrument);

    }

    void makeSounds() {
        for (int i = 0; i < this->instruments.size(); i++) {
            this->instruments[i]->makeSound();
        }
    }
};

class Trumpet : public Instrument {
public:
    Trumpet(string name) : Instrument(name) {}

    string getName() { return this->name; }

    void setName(string name) { this->name = name; }

    void makeSound() {
        print("Pouet");
    }
};

class Group {
private:
    Guitar * guitar;
    Trumpet * trumpet;
    Drums * drums;
public:
    Group(Guitar* guitar, Trumpet* trumpet, Drums* drums){
        this->guitar = guitar;
        this->trumpet = trumpet;
        this->drums = drums;
    }

    void makeSound(){
        this->guitar->makeSound();
        this->trumpet->makeSound();
        this->drums->makeSound();
    }
};

int main() {
    print("TD Noté de Ghislain BOUCHET - EPSI - 01/12/2021");

    // Instanciation de deux trompettes
    Trumpet *trumpet1 = new Trumpet("Trumpet");
    Trumpet *trumpet2 = new Trumpet("Trumpet");

    // Instanciation de deux guitares
    Guitar *guitar1 = new Guitar("Guitar");
    Guitar *guitar2 = new Guitar("Guitar");

    // Instanciation d'une batterie
    Drums *drums1 = new Drums("Drums");

    // Utilisation de la methode makeSound de chaque instrument dérivée de la méthode virtuelle de la classe instrument
    trumpet1->makeSound();
    guitar1->makeSound();
    drums1->makeSound();

    // Instanciation d'un orchestre
    Orchestra *orchestra1 = new Orchestra();

    // Ajout des 5 instruments à l'orchestre
    orchestra1->addInstrument(trumpet1);
    orchestra1->addInstrument(trumpet2);
    orchestra1->addInstrument(guitar1);
    orchestra1->addInstrument(guitar2);
    orchestra1->addInstrument(drums1);

    // Utilisation de la méthode make sound qui fait jouer à la suite tout les instruments de l'orchestre
    orchestra1->makeSounds();
    orchestra1->makeSounds();
    orchestra1->makeSounds();

    // Instanciation d'un groupe avec en paramétre 1 une guitare, 1 trompette et une batterie
    Group *group1 = new Group(guitar1, trumpet1, drums1);

    // Utilisation de la méthode make sound qui fait jouer à la suite tout les instruments du groupe
    group1->makeSound();
    group1->makeSound();
    group1->makeSound();

    // on supprime les objets pour libérer la mémoire
    delete(group1);
    delete(orchestra1);
    delete(guitar1);
    delete(guitar2);
    delete(trumpet1);
    delete(trumpet2);
    delete(drums1);

    return 0;
}
