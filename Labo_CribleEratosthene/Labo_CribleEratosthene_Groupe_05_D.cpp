//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : Labo_CribleEratosthene_Groupe_05_D.cpp
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Créer un programme permettant de calculer les nombres premiers en se basant sur un
//                : crible eratosthene.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>             // Utilisation de cout, cin
#include <cstdlib>              // Utilisation de EXIT_SUCCESS
#include <limits>               // Utilisation de numeric limits
#include <vector>               // Utilisation des vecteurs

#include "annexe.h"             // Librairie personnelle
#include "cribleEratosthene.h"  // Librairie pour calculer le crible d'eratosthene

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {

    const int MIN_VALEUR        = 2;        // Valeur minimale autorisee pour l'utilisateur
    const int MAX_VALEUR        = 100;      // Valeur maximale autorisee pour l'utilisateur
    const int NBRE_COLONNE      = 10;       // Nombre de colonnes d'affichage
    const int LARGEUR_COLONNE   = 4;        // Largeur d'une colonne d'affichage

    // Saisie pour récupérer le nombre de valeurs à parcourir pour calculer
    // les nombres premiers.
    size_t nbreValeurs = (size_t)saisieEntier("Nombre de valeurs", MIN_VALEUR, MAX_VALEUR, "La valeur est hors-plage!");

    // En fonction de nbreValeurs calculer un vecteur crible avec tous les
    // nombres premiers et l'affecter dans un vecteur de booleen et puis l'affiche.
    vector<bool> vecteurCriblage   = cribleEratosthene(nbreValeurs);
    afficheVecteur(vecteurCriblage, "Criblage du tableau", LARGEUR_COLONNE, NBRE_COLONNE);

    // En fonction du vecteur crible, on le parcourt et recupere tous les nombres premiers, on
    // affiche le nombre de chiffres premier identifies et puis on les affiche.
    vector<int>  vecteurNbrPremier = nbrsPremier(vecteurCriblage);
    cout << vecteurNbrPremier.size() << " nombres premiers ont ete identifies.";
    afficheVecteur(vecteurNbrPremier, "Nombres premiers:", LARGEUR_COLONNE, NBRE_COLONNE);

    // Demande à l'utilisateur d'appuyer sur entrer pour quitter le programme
    cout << endl << "Appuyez sur ENTER pour quitter le programme.";
    VIDER_BUFFER;
    return EXIT_SUCCESS;

}