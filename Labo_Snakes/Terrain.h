// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Terrain.h
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Header pour la classe Terrain.cpp
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_SNAKES_TERRAIN_H
#define LABO_SNAKES_TERRAIN_H


class Terrain {
public:

	// Constructeur par défaut de terrain
	// -----------------------------------------------------------------------------------------------------------------
	Terrain();

	// Constructeur de terrain
	// -----------------------------------------------------------------------------------------------------------------
	/// \param _hauteur     : correspond à la hauteur du terrain
	/// \param _largeur     : correspond à la largeur du terrain
	Terrain(int _hauteur, int _largeur);

	// Fonction qui récupère sa hauteur
	// -----------------------------------------------------------------------------------------------------------------
	/// \return             : la hauteur du terrain
	int getHauteur() const { return this->hauteur;}

	// Fonction qui récupère sa largeur
	// -----------------------------------------------------------------------------------------------------------------
	/// \return             : la largeur du terrain
	int getLargeur() const { return this->largeur;}

private:

    //Attributs
	int hauteur;
	int largeur;
};


#endif //LABO_SNAKES_TERRAIN_H
