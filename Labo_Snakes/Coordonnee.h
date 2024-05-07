// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Coordonnee.h
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Permets de créer des coordonnées, les comparer, soustraire et de les déplacer. Peut s'utiliser
//                  pour des serpents ou des pommes. À pour objectif de simplifier la manipulation des coordonnées.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_SNAKES_COORDONNEE_H
#define LABO_SNAKES_COORDONNEE_H

// Gestion de la direction pour les déplacements
enum class Direction{HAUT = 1, BAS, DROITE, GAUCHE};

class Coordonnee {
public:

	// Constructeur par défaut de coordonnée
	// -----------------------------------------------------------------------------------------------------------------
	Coordonnee();

	// Constructeur de coordonnée
	// -----------------------------------------------------------------------------------------------------------------
	/// \param _posHauteur          : correspond à la position en hauteur de la coordonnée
	/// \param _posLargeur          : correspond à la position en largeur de la coordonnée
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                     : -
	Coordonnee(int _posHauteur, int _posLargeur);

	// Fonction qui déplace une coordonnée dans une direction donnée
	// -----------------------------------------------------------------------------------------------------------------
	/// \param direction            : correspond à la direction du déplacement
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                     : -
	void deplace(Direction direction);

	// Fonction qui récupère la position en hauteur de la coordonnée
	// -----------------------------------------------------------------------------------------------------------------
	/// \return			            : retourne la hauteur du point
	int getPosHauteur() const { return this->posHauteur; }

	// Fonction qui récupère la position en largeur de la coordonnée
	// -----------------------------------------------------------------------------------------------------------------
	/// \return			            : retourne la largeur du point
	int getPosLargeur() const { return this->posLargeur; }

	// Surcharge de l'opérateur == pour permettre de comparer des coordonnées
	// -----------------------------------------------------------------------------------------------------------------
	/// \param c1 			        : coordonnée avec laquelle on va comparer
    // -----------------------------------------------------------------------------------------------------------------
	/// \return			            : retourne true si les coordonnées sont égales, false sinon
	bool operator==(const Coordonnee& c1) const;

    // Surcharge de l'opérateur pour soustraire des coordonnées
    // -----------------------------------------------------------------------------------------------------------------
    /// \param c1 			        : coordonnée avec laquelle on va comparer
    // -----------------------------------------------------------------------------------------------------------------
    /// \return			            : retourne la coordonnée soustraite
    Coordonnee operator-(const Coordonnee& c1) const;

private:
	int posHauteur;
	int posLargeur;
};


#endif //LABO_SNAKES_COORDONNEE_H
