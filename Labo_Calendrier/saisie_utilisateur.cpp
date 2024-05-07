//---------------------------------------------------------
// Fichier        : saisie_utilisateur.cpp
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Fichier permettant de récupérer la saisie de l'utilisateur puis de la contrôler et de demander
//                  à l'utilisateur s'il souhaite recommencer le programme.
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <iostream> //cout, cin

#include "saisie_utilisateur.h"

#define VIDER_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

// Cette fonction permet à l'utilisateur d'entrer une valeur de type int
// Explication des paramètres :
// string& MSG                : correspond au message de demande de saisie
// int     min                : correspond à la valeur de saisie minimum
// int     max                : correspond à la valeur de saisie maximum
// string& MSG_ERREUR         : correspond au message d'erreur à afficher si l'entrée est fausse
int saisieUtilisateur(const std::string& MSG, int min, int max, const std::string& MSG_ERREUR) {

    int  saisie;                 // Variable de stockage de la saisie
    bool erreur;                 // Variable de stockage de l'état de la saisie

    do {
        // Affichage message de demande de saisie
        std::cout << MSG;

        // Vérifie si le flux est cassé ou si la valeur est en dehors des valeurs minimum et maximum
        erreur = not(std::cin >> saisie) or saisie < min or saisie > max;

        // Si la saisie est incorrecte affiche message erreur et répare le flux
        if (erreur) {
            std::cout << MSG_ERREUR << std::endl;
            std::cin.clear();
        }

        VIDER_BUFFER;

    }while(erreur);

    return saisie;
}

// Cette fonction permet à l'utilisateur de recommencer le programme
bool recommencerProgramme() {
    char saisie;                // Variable de stockage de la saisie
    bool erreur;                // Variable de stockage de l'état de la saisie
    bool recommencer;           // Variable de stockage de la réponse de retour

    do {
        // Affichage message de demande de saisie
        std::cout << std::endl << "Voulez-vous recommencer le programme ? (o/n) : ";

        // Vérifie si le flux est cassé ou si la valeur est en dehors des valeurs minimum et maximum
        erreur = not(std::cin >> saisie) or (saisie != 'o' and saisie != 'n');

        // Si la saisie est incorrecte affiche message erreur et répare le flux
        if (erreur) {
            std::cout << "/!\\ Veuillez saisir 'o' ou 'n' ..." << std::endl;
            std::cin.clear();
        }

        VIDER_BUFFER;

    }while(erreur);

    // Si l'utilisateur a saisi 'o' on retourne true
    if (saisie == 'o') {
        recommencer = true;
    }
    else {
        recommencer = false;
    }

    return recommencer;
}