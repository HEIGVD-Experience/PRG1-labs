// ---------------------------------------------------------------------------------------------------------------------
// Fichier        : Robots.h
// Auteur(s)      : Bee Gianni & Trüeb Guillaume
// Date           : 12 décembre 2022
// But            : Mise à disposition des méthodes et des constructeurs de robots
//                  qui doivent se battre. Ces derniers permettent de gérer
//                  les positions et le déplacement possibles.
// Modifications  : NIL
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_ROBOTS_ROBOTS_H
#define LABO_ROBOTS_ROBOTS_H

#include <array>
#include <vector>

// ---------------------------------------------------------------------------------------------------------------------
// Enum de direction du robot (Ordre du PDF)
enum class Direction{HAUT = 1, BAS, DROITE, GAUCHE};

class Robots {
public :
   // Constructeur de la classe Robots
   // ------------------------------------------------------------------------------------------------------------------
   /// \param id             : Numéro d'identification du robot
   /// \param _posLargeur    : Position sur l'axe des abscisses du robot
   /// \param _posHauteur    : Position sur l'axe des ordonnées du robot
   Robots(unsigned id, unsigned _posLargeur, unsigned _posHauteur);

   // Méthode permettant d'obtenir le numéro d'identifaction du robot
   // ------------------------------------------------------------------------------------------------------------------
   /// \return               : retourne l'id dans un entier non signé
   unsigned getID()          const { return id; };

   // Méthode permettant de définir la valeur de l'axe des abscisses
   // ------------------------------------------------------------------------------------------------------------------
   /// \param _posLargeur    : détermine la valeur de positionnement
   void setPosLargeur(unsigned _posLargeur);

   // Méthode permettant de définir la valeur de l'axe des ordonnées
   // ------------------------------------------------------------------------------------------------------------------
   /// \param _posHauteur    : déterminer la valeur de positionnement
   void setPosHauteur(unsigned _posHauteur);

   // Méthode permettant le déplacement aléatoire du robot dans des bornes du terrain
   // ------------------------------------------------------------------------------------------------------------------
   /// \param largeurTerrain : valeur de déplacement sur l'axe des abscisses
   /// \param hauteurTerrain : valeur de déplacement sur l'axe des ordonnées
   void deplacer(unsigned largeurTerrain, unsigned hauteurTerrain);

   // Méthode permettant de déterminer la position dans le vector d'un robot s'il
   // est sur la même position qu'un autre robot
   // ------------------------------------------------------------------------------------------------------------------
   /// \param vecRobots      : vecteur à contrôler
   /// \return               : retourne la position du robot dans le vector
   unsigned positionDUnRobot(const std::vector<Robots> &vecRobots) const;

   // Méthode permettant de déterminer si un robot existe aux positions posLargeur
   // et posHauteur
   // ------------------------------------------------------------------------------------------------------------------
   /// \param vecRobots      : vecteur à contrôler
   /// \param posLargeur     : Position sur la largeur à contrôler
   /// \param posHauteur     : Position sur la hauteur à contrôler
   /// \return               : retourne la position du robot dans le vector
   static unsigned positionDUnRobot(const std::vector<Robots>& vecRobots, unsigned posLargeur, unsigned posHauteur);

   // Destructeur
   ~Robots() = default;

// ---------------------------------------------------------------------------------------------------------------------
private :
   // Variable nécessaire au fonctionnement de la classe
   unsigned posLargeur = 0,     // Valeur de l'axe des abscisses
            posHauteur = 0;     // Valeur de l'axe des ordonnées
   unsigned id;                 // N° d'identification de l'objet/robot

};
#endif //LABO_ROBOTS_ROBOTS_H
