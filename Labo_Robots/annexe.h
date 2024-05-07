// ---------------------------------------------------------------------------------------------------------------------
// Fichier        : annexe.h
// Auteur(s)      : Bee Gianni & Trüeb Guillaume
// Date           : 18 novembre 2022
// But            : Fournir différentes fonctions permettant de rendre plus efficace
//                  certaines actions répétitives, tel que la saisie utilisateur.
// Modifications  : NIL
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include <string>
#include <vector>

#ifndef MODELCPP_ANNEXE_H
#define MODELCPP_ANNEXE_H

// Fonction permettant de faire saisir une valeur entière à un utilisateur et de gérer les potentielles erreurs.
// ---------------------------------------------------------------------------------------------------------------------
/// \param MSG         : correspond au message à afficher avant la saisie
/// \param min         : correspond à la borne minimale acceptable pour la saisie
/// \param max         : correspond à la borne maximale acceptable pour la saisie
/// \param MSG_ERREUR  : correspond au message à afficher si une erreur survient
/// \param pos         : correspond à l'espace entre le msg et le borne
// ---------------------------------------------------------------------------------------------------------------------
/// \return            : une valeur de type int comprenant la saisie de l'utilisateur
/// \exception         : - (Aucune exception)
unsigned  saisieEntierPositif(const std::string& MSG, unsigned min, unsigned max,
                              const std::string& MSG_ERREUR, int pos = 7);

// ---------------------------------------------------------------------------------------------------------------------
// Fonction générant un nombre aléatoire dans une plage déterminée par des bornes
// https://github.com/gmbreguet/PRG1_DEMO/
/// \param min         : Borne minimal de génération
/// \param max         : Borne maximal de génération
// ---------------------------------------------------------------------------------------------------------------------
/// \return            : Chiffre [int] généré aléatoirement dans les bornes
/// \exception         : - (Aucune exception)
unsigned nbAleatoire (unsigned min, unsigned max);

// ---------------------------------------------------------------------------------------------------------------------
// Opérateur de flux permettant l'affichage d'un string
/// \param os          : Valeur de sortie
/// \param vs          : Valeur d'entrée
// ---------------------------------------------------------------------------------------------------------------------
/// \exception         : - (Aucune exception)
std::ostream& operator<<(std::ostream& os,const std::vector<std::string>& vs);

#endif //MODELCPP_ANNEXE_H
