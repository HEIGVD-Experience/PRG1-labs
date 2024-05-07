// ---------------------------------------------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Bee Gianni & Trüeb Guillaume
// Date           : 12 décembre 2022
// But            : Ce programme représente la méthode afficher pour l'affichage
//                  de la zone de combat et des robots
// Modifications  : NIL
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include <iostream>

#include "Terrain.h"

using namespace std;

// Constante pour l'affichage
const string LIMITEHAUTEUR = "-";
const string LIMITELARGEUR = "|";
const string VIDE          = " ";

// Méthode permettant d'afficher le terrain et le vecteur de robots
void Terrain::afficher(const vector<Robots>& vecRobots) const {

    unsigned robotAAfficher;

   // Affichage des limites supérieur
    for(unsigned k = 0 ; k <= this->largeur+1 ; ++k)
        cout << LIMITEHAUTEUR;
    cout << endl;

    // Affichage du corps du terrain
    for(unsigned i = 1 ; i <= this->hauteur ; ++i){

        // Affichage du bords de la ligne
        cout << LIMITELARGEUR;

        // Pour chaque position du terrain
        for(unsigned j = 1 ; j <= this->largeur ; ++j){
            // On regarde s'il existe un robot à afficher
            robotAAfficher = Robots::positionDUnRobot(vecRobots, j, i);

            // S'il existe un robot à afficher
            if (robotAAfficher != numeric_limits<unsigned>::max()){
                // On affiche l'ID du robot
                cout << vecRobots.at(robotAAfficher).getID();
            }
            else{
                // On affiche un espace
                cout << VIDE;
            }
        }
        cout << LIMITELARGEUR << endl;
    }

    // Affichage de la limite de la largeur
    for(unsigned i = 0 ; i <= this->largeur + 1; ++i)
        cout << LIMITEHAUTEUR;

    cout << endl;
}