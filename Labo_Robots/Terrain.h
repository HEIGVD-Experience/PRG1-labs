// ---------------------------------------------------------------------------------------------------------------------
// Fichier        : Terrain.h
// Auteur(s)      : Bee Gianni & Trüeb Guillaume
// Date           : 12 décembre 2022
// But            : Mise à disposition des méthodes et des constructeurs de terrain
//                  qui permettent de générer le terrain pour le combat des robots
// Modifications  : NIL
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_ROBOTS_TERRAIN_H
#define LABO_ROBOTS_TERRAIN_H

#include <vector>
#include <string>
#include <limits>       // Numeric limits

#include "Robots.h"

class Terrain {
// ---------------------------------------------------------------------------------------------------------------------
public:

   // Constructeur de la classe terrain
   // ------------------------------------------------------------------------------------------------------------------
   /// \param _largeur       : Dimension de l'axe des abscisses
   /// \param _hauteur       : Dimension de l'axe des ordonnées
   // ------------------------------------------------------------------------------------------------------------------
   Terrain(unsigned _largeur, unsigned _hauteur) : largeur(_largeur), hauteur(_hauteur){};

   // Méthode permettant d'afficher le terrain et le vecteur de robots
   // ------------------------------------------------------------------------------------------------------------------
   /// \param vecRobots      : Vecteur à afficher dans le terrain
   // ------------------------------------------------------------------------------------------------------------------
   void afficher(const std::vector<Robots>& vecRobots) const;

// ---------------------------------------------------------------------------------------------------------------------
private:
    // Largeur et hauteur du terrain construit
    const unsigned largeur, hauteur;
};

#endif //LABO_ROBOTS_TERRAIN_H
