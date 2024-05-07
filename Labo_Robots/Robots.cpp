// ---------------------------------------------------------------------------------------------------------------------
// Fichier        : Robots.cpp
// Auteur(s)      : Bee Gianni & Trüeb Guillaume
// Date           : 12 décembre 2022
// But            : Ce programme représente la définition du constructeur de robot et
//                  des différentes méthodes pour la classe robots (get, set,
//                  déplacement,...)
// Modifications  : NIL
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include "Robots.h"
#include "annexe.h"

using namespace std;

// Constructeur de la classe Robots
Robots::Robots(unsigned _id, unsigned _posLargeur, unsigned _posHauteur)
               : posLargeur(_posLargeur), posHauteur(_posHauteur), id(_id){}

// Méthode permettant de définir la valeur de l'axe des abscisses
void Robots::setPosLargeur(unsigned _posLargeur) {this -> posLargeur = _posLargeur;}

// Méthode permettant de définir la valeur de l'axe des ordonnées
void Robots::setPosHauteur(unsigned _posHauteur) {this -> posHauteur = _posHauteur;}

// Méthode permettant le déplacement aléatoires du robots dans des bornes
void Robots::deplacer(unsigned largeurTerrain, unsigned hauteurTerrain) {

   // Déclaration des variables
   unsigned positionHauteur, positionLargeur;

   do {
      // Génération d'un déplacement dans une direction aléatoire
      auto direction = (Direction) nbAleatoire(1, 4);

      // Copie des valeurs de positions actuelle
      positionLargeur = this->posLargeur;
      positionHauteur = this->posHauteur;

      // Incrémentation/Décrémentation des valeurs en fonction de l'aléatoire
      switch (direction) {
         case Direction::HAUT   :
            positionHauteur -= 1; break;
         case Direction::BAS    :
            positionHauteur += 1; break;
         case Direction::DROITE :
            positionLargeur += 1; break;
         case Direction::GAUCHE :
            positionLargeur -= 1; break;
      }
   }
   // Contrôle que les nouvelles positions sans encore dans la zone
   while (!((positionLargeur <= largeurTerrain && positionLargeur > 0) &&
            (positionHauteur <= hauteurTerrain && positionHauteur > 0)));

   // Affectation des nouvelles positions
   setPosLargeur(positionLargeur);
   setPosHauteur(positionHauteur);
}

// Méthode permettant de déterminer la position du robot s'il est sur la même position qu'un autre robot
unsigned Robots::positionDUnRobot(const std::vector<Robots> &vecRobots) const {
    for(unsigned i = 0; i < vecRobots.size() ; ++i){
        // Détermine s'il est sur les mêmes coordonnées mais que c'est pas lui-même
        if(vecRobots[i].posLargeur == this->posLargeur &&
           vecRobots[i].posHauteur == this->posHauteur &&
           vecRobots[i].id         != this->id)
           // Retourne la valeur de la position
           return i;
    }
    return (unsigned)-1;
}

// Méthode permettant de déterminer si la position donnée en paramètre correpond à une des robots dans le vector
unsigned Robots::positionDUnRobot(const vector<Robots>& vecRobots, unsigned posLargeur, unsigned posHauteur){
    for(unsigned i = 0; i < vecRobots.size() ; ++i){
        // Détermine s'il est sur les mêmes coordonnées mais que c'est pas lui-même
        if(vecRobots[i].posLargeur == posLargeur &&
           vecRobots[i].posHauteur == posHauteur)
            // Retourne la valeur de la position
            return i;
    }
    return (unsigned)-1;
}