//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : annexe.cpp
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Fichier mettant à disposition des fonctions globales utilisables dans plusieurs projets.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include <random>

#include "annexe.h"

using namespace std;

// Set d'un generateur de nombre aléatoire
// Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/main/04_Fonctions/04_random.cpp
int nbrAleatoire(int min, int max) {

    // Utilisation de static pour le générateur permettant d'éviter
    // de le définir à chaque appel de nbrAleatoire
    static random_device rand_dev;
    static default_random_engine generator(rand_dev());

    // Distribution d'un random de manière uniforme
    uniform_int_distribution<int> distr(min, max);
    return distr(generator);
}