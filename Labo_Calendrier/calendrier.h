//---------------------------------------------------------
// Fichier        : calendrier.h
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Fichier permettant de calculer le calendrier d'une année
//                : donnée en paramètre provenant de la saisie d'un utilisateur.
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#ifndef LABO_CALENDRIER_CALENDRIER_H
#define LABO_CALENDRIER_CALENDRIER_H

bool estBissextille(int);
void calculerCalendrier(int);
void detailsMois(int, bool, int&, std::string&);

#endif //LABO_CALENDRIER_CALENDRIER_H