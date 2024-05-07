//---------------------------------------------------------
// Fichier        : Labo_Calendrier_Groupe_04_B.cpp
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Application permettant de calculer et afficher
//                : le calendrier d'une année donnée en paramètre.
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <string>   //string
#include <cstdlib>  //EXIT_SUCCESS

#include "saisie_utilisateur.h"
#include "calendrier.h"

int main() {

   // Déclaration des valeurs minimum et maximum
   const int   ANNEE_MIN = 1800,
               ANNEE_MAX = 2100;

   // Déclaration des messages à afficher
   const std::string MSG_ERREUR  = "/!\\ veuillez saisir une année entre 1800 et 2100 ...";
   const std::string MSG         = "Entrer une annee [1800 et 2100] : ";

   // Fait tourner le programme tant que l'utilisateur ne quitte pas
   do {

        // Récupération de l'année saisie par l'utilisateur
        int annee = saisieUtilisateur(MSG, ANNEE_MIN, ANNEE_MAX, MSG_ERREUR);

        // Affichage du calendrier
        calculerCalendrier(annee);

   } while (recommencerProgramme());

   return EXIT_SUCCESS;
}