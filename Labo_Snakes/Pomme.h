// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Pomme.h
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Header pour la classe Pomme.cpp
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_SNAKES_POMME_H
#define LABO_SNAKES_POMME_H

#include "annexe.h"
#include "Coordonnee.h"

class Pomme {
public:

	// Constructeur par défaut de pomme
	// -----------------------------------------------------------------------------------------------------------------
	Pomme();

	// Constructeur de pomme
	// -----------------------------------------------------------------------------------------------------------------
	/// \param _index     	        :  correspond à son index
	/// \param _coordonnee          :  correspond à sa position dans le terrain
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                     :  -
	Pomme(int _index, Coordonnee _coordonnee);

	// Fonction qui récupère la position de la pomme sur le terrain
	// -----------------------------------------------------------------------------------------------------------------
	/// \return                     :  sa position dans le terrain
	Coordonnee getCoordonnees() { return coordonnee; }

	// Fonction qui récupère le taux de croissance une fois la pomme mangé
	// -----------------------------------------------------------------------------------------------------------------
	/// \return                     :  la valeur de croissance
	int  getCroissance() const { return croissance; }

    // Fonction qui retourne l'index de la pomme
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                     :  l'index de la pomme
    int getIndex() const { return index; }

	// Fonction attribue un nouveau taux de croissance
	// -----------------------------------------------------------------------------------------------------------------
    /// \return                     :  -
    void setCroissance();

	// Fonction attribue une nouvelle position à la pomme
	// -----------------------------------------------------------------------------------------------------------------
	/// \param _coordonnee          :  les nouvelles coordonnées de la pomme
    // -----------------------------------------------------------------------------------------------------------------
    /// \return                     :  -
	void setCoordonnees(Coordonnee _coordonnee);

private:

    // Attributs
	Coordonnee coordonnee;
    int index, croissance;

    // Croissance minimale et maximale de la pomme
    static int const MIN_CROISSANCE =  1;
    static int const MAX_CROISSANCE = 10;

};


#endif //LABO_SNAKES_POMME_H
