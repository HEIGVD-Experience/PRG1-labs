// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Jeu.h
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Classe gérant le jeu d'un point de vue global. Donne l'ordre du jeu en appelant les
//                  différentes fonctions des autres classes. Gère aussi le vecteur de serpents.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_SNAKES_JEU_H
#define LABO_SNAKES_JEU_H

#include <vector>
#include <string>

#include "Pomme.h"
#include "Serpent.h"
#include "Coordonnee.h"
#include "Terrain.h"
#include "annexe.h"


class Jeu {
public:

	// Constructeur du jeu
	// -----------------------------------------------------------------------------------------------------------------
	/// \param _hauteurTerrain     : correspond à l'hauteur du terrain
	/// \param _largeurTerrain     : correspond à la largeur du terrain
	/// \param _nbSerpents         : correspond au nombre de serpents sur le terrain
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                    : -
    Jeu(int _hauteurTerrain, int _largeurTerrain, int _nbSerpents);

    // Fonction permettant de récupérer le vector de serpents
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                    : retourne en référence le vector de serpents
    const std::vector<Serpent>& getSerpents() const { return vecSerpent; }

	// Fonction principale qui gère l'avancement du jeu et qui fait passer les tours
	// -----------------------------------------------------------------------------------------------------------------
	/// \return    					: -
	void avance();

	// Fonction permettant d'écrire le tableau des scores
	// -----------------------------------------------------------------------------------------------------------------
	/// \param idSerpentMangeur     : correspond à l'identifiant du serpent qui mange.
	/// \param idSerpentMange       : correspond à l'identifiant du serpent mangé.
    // -----------------------------------------------------------------------------------------------------------------
	/// \return                     : -
    static void ecrireScore(int idSerpentMangeur, int idSerpentMange) ;

private:
	Terrain terrain;                    // Terrain du jeu
	std::vector<Serpent> vecSerpent;    // Vector de serpents
};


#endif //LABO_SNAKES_JEU_H
