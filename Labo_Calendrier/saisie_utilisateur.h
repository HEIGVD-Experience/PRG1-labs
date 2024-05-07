//---------------------------------------------------------
// Fichier        : saisie_utilisateur.h
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Fichier permettant de récupérer la saisie de l'utilisateur puis de la contrôler et de demander
//                  à l'utilisateur s'il souhaite recommencer le programme.
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#ifndef LABO_CALENDRIER_SAISIE_UTILISATEUR_H
#define LABO_CALENDRIER_SAISIE_UTILISATEUR_H

int  saisieUtilisateur(const std::string&, int, int, const std::string&);
bool recommencerProgramme();

#endif //LABO_CALENDRIER_SAISIE_UTILISATEUR_H