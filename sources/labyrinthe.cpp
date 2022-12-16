#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Salle {
private:
  Salle* nord;
  Salle* est;
  Salle* sud;
  Salle* ouest;

public:
  Salle() {
    this->nord = nullptr;
    this->est = nullptr;
    this->sud = nullptr;
    this->ouest = nullptr;
  }

  Salle* get_nord() { return this->nord; }
  void set_nord(Salle* salle) {
    this->nord = salle;
    salle->sud = this;
  }
  Salle* get_est() { return this->est; }
  void set_est(Salle* salle) {
    this->est = salle;
    salle->ouest = this;
  }
  Salle* get_sud() { return this->sud; }
  void set_sud(Salle* salle) {
    this->sud = salle;
    salle->nord = this;
  }
  Salle* get_ouest() { return this->ouest; }
  void set_ouest(Salle* salle) {
    this->ouest = salle;
    salle->est = this;
  }

  void afficher() {
    if (this->nord == nullptr) {
      cout << "######" << endl;
    } else {
      cout << "##  ##" << endl;
    }

    if (this->ouest == nullptr) {
      cout << "##";
    } else {
      cout << "  ";
    }

    cout << "  ";

    if (this->est == nullptr) {
      cout << "##" << endl;
    } else {
      cout << "  " << endl;
    }

    if (this->sud == nullptr) {
      cout << "######" << endl;
    } else {
      cout << "##  ##" << endl;
    }
  }

};

class Voyageur {
private:
  string nom;
  Salle* salle;

public:
  Voyageur(string nom) {
    this->nom = nom;
    this->salle = nullptr;
  }

  string get_nom() { return this->nom; }
  Salle* get_salle() { return this->salle; }

  void voyager(Salle* destination) {
    this->salle = destination;
    cout << this->nom << " change de salle :" << endl;
    destination->afficher();
  }
};

class Commande {
private:
  string nom;
public:
  Commande(string nom) {
    this->nom = nom;
  }
  string get_nom() { return this->nom; }
  virtual void executer(Voyageur* voyageur) = 0;
};

class CommandeVoyageSud: public Commande {
public:
  CommandeVoyageSud() : Commande("Voyager au Sud") {}
  virtual void executer(Voyageur* voyageur) {
    if (voyageur->get_salle() != nullptr && voyageur->get_salle()->get_sud() != nullptr) {
      cout << voyageur->get_nom() << " voyage au sud :" << endl;
      voyageur->voyager(voyageur->get_salle()->get_sud());
    }
  }
};
class CommandeVoyageNord: public Commande {
public:
  CommandeVoyageNord() : Commande("Voyager au Nord") {}
  virtual void executer(Voyageur* voyageur) {
    if (voyageur->get_salle() != nullptr && voyageur->get_salle()->get_nord() != nullptr) {
      cout << voyageur->get_nom() << " voyage au nord :" << endl;
      voyageur->voyager(voyageur->get_salle()->get_nord());
    }
  }
};
class CommandeVoyageEst: public Commande {
public:
  CommandeVoyageEst() : Commande("Voyager à l'Est") {}
  virtual void executer(Voyageur* voyageur) {
    if (voyageur->get_salle() != nullptr && voyageur->get_salle()->get_est() != nullptr) {
      cout << voyageur->get_nom() << " voyage à l'est :" << endl;
      voyageur->voyager(voyageur->get_salle()->get_est());
    }
  }
};
class CommandeVoyageOuest: public Commande {
public:
  CommandeVoyageOuest() : Commande("Voyager à l'Ouest") {}
  virtual void executer(Voyageur* voyageur) {
    if (voyageur->get_salle() != nullptr && voyageur->get_salle()->get_ouest() != nullptr) {
      cout << voyageur->get_nom() << " voyage à l'ouest :" << endl;
      voyageur->voyager(voyageur->get_salle()->get_ouest());
    }
  }
};

class Menu {
private:
  vector<Commande*> commandes;
public:
  void ajouter(Commande* commande) {
    this->commandes.push_back(commande);
  }
  Commande* choisir() {
    Commande* resultat = nullptr;
    int i = 0;
    for (Commande* commande: this->commandes) {
      cout << i << " : " << commande->get_nom() << endl;
      i++;
    }
    int choix;
    cin >> choix;
    // TODO : Contrôler l'entrée utilisateur
    return this->commandes[choix];
  }
};

int main(int argc, char **argv)
{
  cout << "Exercice 4 - Labyrinthe" << endl;

  Salle* entree = new Salle();
  entree->set_est(new Salle());
  entree->set_sud(new Salle());
  entree->get_sud()->set_est(new Salle());

  cout << "Entrée :" << endl;
  entree->afficher();
  cout << "Au sud :" << endl;
  entree->get_sud()->afficher();
  cout << "A l'est :" << endl;
  entree->get_sud()->get_est()->afficher();

  Voyageur* indy = new Voyageur("Indy");
  indy->voyager(entree);

  Menu* menu = new Menu();
  menu->ajouter(new CommandeVoyageNord());
  menu->ajouter(new CommandeVoyageEst());
  menu->ajouter(new CommandeVoyageSud());
  menu->ajouter(new CommandeVoyageOuest());


  for (int i = 0; i < 5; i++) {
    Commande* cmd = menu->choisir();
    cmd->executer(indy);
  }

  return 0;
}
