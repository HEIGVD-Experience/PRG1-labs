// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Coordonnee.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Définition des méthodes et constructeurs pour la classe Coordonnee.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------
#include "Coordonnee.h"

// ---------------------------------------------------------------------------------------------------------------------
// CONSTRUCTEURS
// ---------------------------------------------------------------------------------------------------------------------
Coordonnee::Coordonnee() {
    this->posLargeur = 0;
    this->posHauteur = 0;
}

Coordonnee::Coordonnee(int _posHauteur, int _posLargeur) {
    this->posHauteur = _posHauteur;
    this->posLargeur = _posLargeur;
}
// ---------------------------------------------------------------------------------------------------------------------
// METHODES
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// Fonction qui déplace une coordonnée dans une direction donnée
void Coordonnee::deplace(Direction direction) {
    switch (direction) {
        case Direction::HAUT   :
            this->posHauteur -= 1; break;
        case Direction::BAS    :
            this->posHauteur += 1; break;
        case Direction::DROITE :
            this->posLargeur += 1; break;
        case Direction::GAUCHE :
            this->posLargeur -= 1; break;
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// OPERATEURS
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// Operateur de comparaison permettant de comparer deux coordonnées simplement
bool Coordonnee::operator==(const Coordonnee &c1) const {
    return this->getPosHauteur() == c1.getPosHauteur() &&
           this->getPosLargeur() == c1.getPosLargeur();
}

// ---------------------------------------------------------------------------------------------------------------------
// Operateur de soustraction permettant de soustraire deux coordonnées simplement
Coordonnee Coordonnee::operator-(const Coordonnee &c1) const {

    Coordonnee nouvelleCoordonnee;
    nouvelleCoordonnee.posLargeur = this->getPosLargeur() - c1.getPosLargeur();
    nouvelleCoordonnee.posHauteur = this->getPosHauteur() - c1.getPosHauteur();

    return nouvelleCoordonnee;
}
