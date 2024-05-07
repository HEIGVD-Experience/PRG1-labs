// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : annexe.h
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : S'occupe de générer des nombres aléatoires et la saisie de
//                  l'utilisateur.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include <string>
#include <vector>

#ifndef MODELCPP_ANNEXE_H
#define MODELCPP_ANNEXE_H

// Fonction permettant de faire saisir une valeur entière à un utilisateur et de gérer les potentielles erreurs.
// ---------------------------------------------------------------------------------------------------------------------
/// \param MSG         : correspond au message à avance avant la saisie
/// \param min         : correspond à la borne minimale acceptable pour la saisie
/// \param max         : correspond à la borne maximale acceptable pour la saisie
/// \param MSG_ERREUR  : correspond au message à avance si une erreur survient
/// \param pos         : correspond à l'espace entre le msg et le borne
// ---------------------------------------------------------------------------------------------------------------------
/// \return            : une valeur de type int comprenant la saisie de l'utilisateur
int  saisieEntier(const std::string& MSG, int min, int max, const std::string& MSG_ERREUR);

// ---------------------------------------------------------------------------------------------------------------------
// Fonction générant un nombre aléatoire dans une plage déterminée par des bornes
// https://github.com/gmbreguet/PRG1_DEMO/
/// \param min         : Borne minimal de génération
/// \param max         : Borne maximal de génération
// ---------------------------------------------------------------------------------------------------------------------
/// \return            : Chiffre [int] généré aléatoirement dans les bornes
int nbAleatoire (int min, int max);

#endif //MODELCPP_ANNEXE_H