// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : annexe.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Implémentation des fonctions dans annexe.h.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include "annexe.h"

#include <iostream>
#include <random>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Fonction permettant de faire saisir une valeur entière à un utilisateur et de
// prendre en charge les potentielles erreurs.
int saisieEntier(const string& MSG, int min, int max, const string& MSG_ERREUR) {

    int  saisie;            // Variable de stockage de la saisie
    bool erreur;            // Variable de stockage de l'état de la saisie

    do {
        // Affichage message de demande de saisie
        cout << MSG <<  "[" << min << ".." << max << "] : ";

        // Vérifie si le flux est cassé ou si la valeur est en dehors des valeurs minimum et maximum
        erreur = not(cin >> saisie) or saisie < min or saisie > max;

        // Si la saisie est incorrecte affiche message erreur et répare le flux
        if (erreur) {
            cout << MSG_ERREUR << endl;
            cin.clear();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while(erreur);

    return saisie;
}

// ---------------------------------------------------------------------------------------------------------------------
// Fonction générant un nombre aléatoire dans une plage déterminée par les bornes
// D'après le git https://github.com/gmbreguet/PRG1_DEMO/
int nbAleatoire (int min, int max) {

    // Utilisation de static pour le générateur permettant d'éviter
    // de le définir à chaque appel de nbrAleatoire
    static random_device rand_dev;
    static default_random_engine generator(rand_dev());

    // Distribution d'un random de manière uniforme
    uniform_int_distribution<int> distr(min, max);
    return distr(generator);

}