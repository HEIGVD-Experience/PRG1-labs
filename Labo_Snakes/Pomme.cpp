// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Pomme.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Créer une pomme et elle s'attribuera à un serpent. Elle lui donne
//                  aussi un taux de croissance
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include "Pomme.h"

// ---------------------------------------------------------------------------------------------------------------------
// CONSTRUCTEURS
// ---------------------------------------------------------------------------------------------------------------------

Pomme::Pomme() {}

Pomme::Pomme(int _index, Coordonnee _coordonnee)
{
    index       = _index;
    coordonnee  = _coordonnee;
    setCroissance();
}

// ---------------------------------------------------------------------------------------------------------------------
// METHODES
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// Définit la nouvelle croissance de la pomme avec un nombre aléatoire entre MIN_CROISSANCE et MAX_CROISSANCE
void Pomme::setCroissance(){
    croissance = nbAleatoire(MIN_CROISSANCE,MAX_CROISSANCE);
}

// ---------------------------------------------------------------------------------------------------------------------
// Définit la nouvelle position de la pomme
void Pomme::setCoordonnees(Coordonnee _coordonnee) {
    coordonnee = _coordonnee;
}