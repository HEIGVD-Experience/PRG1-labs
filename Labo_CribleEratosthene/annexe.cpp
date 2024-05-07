//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : annexe.cpp
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Fournir différentes fonctions permettant de rendre plus efficace
//                : certaines actions répétitives, tel que la saisie utilisateur.
// Modifications  : Ajout de l'affichage de vecteurs criblés ainsi que de vecteur d'entiers.
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include "annexe.h"

#include <iostream>     // Utilisation de cout, cin
#include <iomanip>      // Utilisation de setw
#include <limits>       // Utilisation de numeric limits

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

// Fonction permettant à l'utilisateur de saisir un entier et permet de le controler
// en fonction de bornes données en paramètres
int saisieEntier(const string& MSG, int min, int max, const string& MSG_ERREUR) {

    int  saisie;                 // Variable de stockage de la saisie
    bool erreur;                 // Variable de stockage de l'état de la saisie

    // Tant que la saisie est mauvaise on redemande jusqu'à que la valeur soit exploitable
    do {
        // Affichage message de demande de saisie
        cout << MSG << " [" << min << " - " << max << "] : ";

        // Vérifie si le flux est cassé ou si la valeur est en dehors des valeurs minimum et maximum
        erreur = not(cin >> saisie) or saisie < min or saisie > max;

        // Si la saisie est incorrecte affiche message erreur et répare le flux
        if (erreur) {
            cout << MSG_ERREUR << endl;
            cin.clear();
        }

        VIDER_BUFFER;

    }while(erreur);

    return saisie;
}

// Fonction permettant d'afficher les valeurs d'un vecteur de type booleen sous format true = 0 et false = X
void afficheVecteur(const vector<bool>& vecteur, const string &titre, const int largeurColonne,
                    const int nbreColonne){

    // Affichage du titre
     cout << endl << titre << endl;

    // On parcourt le vecteur pour écrire tous ses éléments
    for (size_t i = 0 ; i < vecteur.size() ; ++i) {

        // Si la valeur est true alors on écrit O sinon  X
        if(vecteur[i])
            cout << setw(largeurColonne) << "O";
        else
            cout << setw(largeurColonne) << "X";

        // Lors ce que nous avons atteint le nombre de colonne alors on passe à la ligne
        if(nbreColonne > 0 && i % (size_t)nbreColonne == (size_t)nbreColonne - 1)
            cout << endl;
    }

    cout << endl << endl;
}

// Fonction permettant d'afficher les valeurs d'un vecteur d'entier
void afficheVecteur(const vector<int>& vecteur, const string& titre, const int largeurColonne,
                    const int nbreColonne){

    // Affichage du titre
    cout << endl << titre << endl;

    // On parcourt le vecteur pour écrire tous ses éléments
    for (size_t i = 0 ; i < vecteur.size() ; ++i) {

        // On écrit la valeur du vecteur dans une zone de taille largeurColonne
        cout << setw(largeurColonne) << vecteur[i];

        // Lors ce que nous avons atteint le nombre de colonnes alors on passe à la ligne
        if(nbreColonne > 0 && i % (unsigned long)nbreColonne == (unsigned long)nbreColonne - 1)
            cout << endl;

    }

    cout << endl << endl;
}

