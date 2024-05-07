// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Terrain.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Créer un terrain de jeu pour les serpents.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include "Terrain.h"

// ---------------------------------------------------------------------------------------------------------------------
// CONSTRUCTEURS
// ---------------------------------------------------------------------------------------------------------------------
Terrain::Terrain() {
    hauteur = 500;
    largeur = 500;
}

Terrain::Terrain(int _hauteur, int _largeur) {
    hauteur = _hauteur;
    largeur = _largeur;
}