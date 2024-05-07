// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Serpent.h
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Créer des serpents avec une pomme et les faire déplacer, manger
//                  leur pomme ou un autre serpent.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#ifndef LABO_SNAKES_SERPENT_H
#define LABO_SNAKES_SERPENT_H

#include <vector>
#include "Coordonnee.h"
#include "Pomme.h"

class Serpent {
public:

    // Constructeur de Serpent
    // -----------------------------------------------------------------------------------------------------------------
    /// \param _index         : correspond à son index
    /// \param _corps         : correspond à un vecteur de coordonnée qui va servir pour sa taille
    /// \param _pomme         : correspond à la pomme qui va chercher à manger
    explicit Serpent(int _index, std::vector<Coordonnee>& _corps, Pomme& _pomme);

    // Fonction permettant de récupérer l'index d'un serpent
    // -----------------------------------------------------------------------------------------------------------------
    /// \return               : retourne l'index du serpent
    int getIndex() const { return index; }

    // Fonction permettant de récupérer la pomme d'un serpent
    // -----------------------------------------------------------------------------------------------------------------
    /// \return               :  retourne la pomme du serpent
    Pomme& getPomme() { return pomme; }

    // Fonction permettant de récupérer le corps d'un serpent
    // -----------------------------------------------------------------------------------------------------------------
    /// \return               :  retourne le vecteur de coordonnées du serpent
    std::vector<Coordonnee> getCorpsSerpent() const { return vecCorpsSerpent ;}

    // Fonction permettant de savoir si le serpent est sa pomme ou non
    // -----------------------------------------------------------------------------------------------------------------
    /// \return               :  retourne un booléen en fonction de si le serpent est sur sa pomme
    bool estSurPomme();

    // Méthode permettant de manger la pomme
    // -----------------------------------------------------------------------------------------------------------------
    void mangePomme();

    // Fonction permettant de savoir si le serpent qui se déplace est sur un autre. Si oui il retournera l'identifiant
    // du serpent sur lequel il se trouve et la position sur le corps du serpent
    // -----------------------------------------------------------------------------------------------------------------
    /// \param _vecSerpent    : correspond au vecteur de serpents
    // -----------------------------------------------------------------------------------------------------------------
    /// \return               :  retourne une pair de coordonnée
    std::pair<int,int> estSurSerpent(const std::vector<Serpent>& _vecSerpent);

    // Fonction permettant de manger un autre serpent
    // -----------------------------------------------------------------------------------------------------------------
    /// \param _serpentMange  : correspond au serpent qui est mange
    /// \param _positionMange : correspond à l'endroit où le serpent est mangé
    // -----------------------------------------------------------------------------------------------------------------
    /// \return               :  retourne une pair de coordonnée.
    std::pair<int,int> mangeSerpent(Serpent& _serpentMange, int _positionMange);

    // Fonction permettant de déplacer le serpent
    // -----------------------------------------------------------------------------------------------------------------
    void deplacer();

    // Fonction permettant de grandir le serpent.
    // -----------------------------------------------------------------------------------------------------------------
    /// \param _augmentation  : correspond au serpent qui mange
    void grandit(int _augmentation);

	// Fonction savoir où l'index dans le corps du serpent touché
	// -----------------------------------------------------------------------------------------------------------------
	/// \param _vecSerpent  	: correspond au vecteur de serpents
	/// \param _index  			: correspond au serpent qui est touché
	// -----------------------------------------------------------------------------------------------------------------
	/// \return						: l'index dans le corps du serpent
	static int positionDansVector(const std::vector<Serpent>& _vecSerpent, int _index);

private:

    // Attributs
	int   index;
	Pomme pomme;
	std::vector<Coordonnee> vecCorpsSerpent;
};


#endif //LABO_SNAKES_SERPENT_H
