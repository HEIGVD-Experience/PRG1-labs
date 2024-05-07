// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Serpent.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Définition des méthodes et constructeur pour la classe serpents.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include "Serpent.h"

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// CONSTRUCTEURS
// ---------------------------------------------------------------------------------------------------------------------
Serpent::Serpent(int _index, std::vector<Coordonnee>& _corps, Pomme& _pomme) {
    pomme             = _pomme;
    index             = _index;
    vecCorpsSerpent   = _corps;
}

// ---------------------------------------------------------------------------------------------------------------------
// METHODES
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// Gère le déplacement du serpent
void Serpent::deplacer() {

    // On récupère la position de la tête du serpent
    Coordonnee nouvelleCoordonne = vecCorpsSerpent[0];

    // On récupère la distance entre la tête et la pomme au travers d'une coordonnée
    Coordonnee distanceSerpentPomme = pomme.getCoordonnees() - vecCorpsSerpent[0];

    // Si la disance en valeur absolue de la hauteur est plus grande que la distance
    // en largeur alors on se déplace horizontalement
    if(abs(distanceSerpentPomme.getPosHauteur()) > abs(distanceSerpentPomme.getPosLargeur()))
    {
        // Si la pomme est en dessous du serpent alors on se déplace vers le bas
        if(distanceSerpentPomme.getPosHauteur() > 0)
            nouvelleCoordonne.deplace(Direction::BAS);
        // Sinon on se déplace vers le haut
        else
            nouvelleCoordonne.deplace(Direction::HAUT);
    }
    // Si la distance en largeur est plus grande ou égale à la distance en hauteur alors on se déplace horizontalement
    else
    {
        // Si la pomme est à droite du serpent alors on se déplace vers la droite
        if(distanceSerpentPomme.getPosLargeur() > 0)
            nouvelleCoordonne.deplace(Direction::DROITE);
        // Sinon on se déplace vers la gauche
        else
            nouvelleCoordonne.deplace(Direction::GAUCHE);
    }
    // On efface la dernière position du serpent
    vecCorpsSerpent.erase(vecCorpsSerpent.end()-1);

    // On ajoute la nouvelle position de la tête du serpent
    vecCorpsSerpent.insert(vecCorpsSerpent.begin(),nouvelleCoordonne);
}

// ---------------------------------------------------------------------------------------------------------------------
// Retourne vrai si le serpent qui se déplace est sur une pomme
bool Serpent::estSurPomme() {
    return vecCorpsSerpent.at(0) == pomme.getCoordonnees();
}

// ---------------------------------------------------------------------------------------------------------------------
// Mange la pomme et grandit de la valeur croissance de la pomme
void Serpent::mangePomme() {
    int augmentationTaille = pomme.getCroissance();
    grandit(augmentationTaille);
}

// ---------------------------------------------------------------------------------------------------------------------
// Retourne la position dans le vector du serpent qui est mangé et la position du corps ou il a été mangé
pair<int,int> Serpent::estSurSerpent(const vector<Serpent>& _vecSerpent) {

    // Définit une paire avec -1 comme valeur par défaut permettant de savoir si notre serpent
    // est sur un autre serpent ou non
    // indexSerpentManger.first  : correspond à la position dans le vector du serpent qui a été mangé
    // indexSerpentManger.second : correspond à la position sur laquelle il a été mangé
    pair<int, int> indexSerpentManger(-1,-1);

    // Pour chaque serpent du vector de serpent
    for (size_t i = 0; i < (size_t)_vecSerpent.size(); ++i) {

        // Si le serpent n'est pas le même que celui qui est en train de se déplacer
        if(_vecSerpent.at(i).getIndex() != index)
        {
            // Pour chaque coordonnée du serpent
            for (size_t j = 0; j < _vecSerpent[i].getCorpsSerpent().size(); ++j) {

                // Si la coordonnée du serpent est sur la tête du serpent qui se déplace
                if(this->vecCorpsSerpent[0] == _vecSerpent[i].getCorpsSerpent()[j]) {

                    // On retourne la position du serpent qui a été mangé et la position sur laquelle il a été mangé
                    indexSerpentManger.first = (int)i, indexSerpentManger.second = (int)j;
                    return indexSerpentManger;
                }
            }
        }
    }

    // Si le serpent n'a pas été mangé, on retourne -1
    return indexSerpentManger;
}

pair<int,int> Serpent::mangeSerpent(Serpent& _serpentMange, int _positionMange) {

    int augmentationTaille;

    // Définit une paire avec -1 comme valeur par défaut permettant de connaitre l'identifiant
    // du serpent qui a mangé et l'identifiant du serpent qui a été mangé
    // indexSerpentManger.first  : correspond à l'id du serpent qui a mangé
    // indexSerpentManger.second : correspond à l'id du serpent qui a été mangé
    pair<int,int> indexSerpentsMangeurs(-1,-1);

    // Si la position mangée est la tête du serpent
    if(_positionMange == 0)
    {
        // Si le serpent qui se déplace est plus grand que son adversaire
        if(vecCorpsSerpent.size() > _serpentMange.getCorpsSerpent().size()
        && vecCorpsSerpent.size() == _serpentMange.getCorpsSerpent().size())
        {
            // Augmente la taille du serpent de 60% la longueur du serpent mangé
            augmentationTaille = int(double(_serpentMange.getCorpsSerpent().size()) * 0.6);

            // On retourne l'id du serpent qui a mangé et l'id du serpent qui a été mangé
            indexSerpentsMangeurs.first = index, indexSerpentsMangeurs.second = _serpentMange.getIndex();

            // On fait grandir le serpent qui a mangé
            grandit(augmentationTaille);
        }
        // Si le serpent qui se déplace est plus petit que son adversaire
        else
        {
            // Augmente la taille du serpent de 60% la longueur du serpent mangé
            augmentationTaille = int(double(this->getCorpsSerpent().size()) * 0.6);

            // On retourne l'id du serpent qui a mangé et l'id du serpent qui a été mangé
            indexSerpentsMangeurs.first = _serpentMange.getIndex(), indexSerpentsMangeurs.second = index;

            // On fait grandir le serpent qui a mangé
            _serpentMange.grandit(augmentationTaille);
        }
    }
    // Si le serpent mange une partie du corps
    else{

        // Augemente la taille du serpent de 40% la longueur du serpent mangé
        augmentationTaille = int(((double)_serpentMange.getCorpsSerpent().size() - _positionMange + 1) * 0.4);

        // Efface la partie du corps du serpent qui a été mangé
        _serpentMange.vecCorpsSerpent.erase(_serpentMange.vecCorpsSerpent.begin()
                                            + _positionMange, _serpentMange.vecCorpsSerpent.end());

        // On fait grandir le serpent qui a mangé
        grandit(augmentationTaille);
    }

    return indexSerpentsMangeurs;
}

// ---------------------------------------------------------------------------------------------------------------------
// Fait grandir le serpent de la valeur passée en paramètre
void Serpent::grandit(int _augmentationTaille) {
    Coordonnee dernierPosition = vecCorpsSerpent.at(vecCorpsSerpent.size()-1);
    vecCorpsSerpent.insert(vecCorpsSerpent.end(), (size_t)_augmentationTaille, dernierPosition);
}

// ---------------------------------------------------------------------------------------------------------------------
// Retourne la position d'un serpent dans le vector de serpent en fonction de son identifiant
int Serpent::positionDansVector(const vector<Serpent> &_vecSerpent, int _index) {
    for(size_t i = 0; i < _vecSerpent.size(); i++)
    {
        if(_vecSerpent[i].getIndex() == _index) return (int)i;
    }
    return -1;
}