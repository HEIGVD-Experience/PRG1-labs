//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : annexe.h
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Fichier mettant à disposition des fonctions globales utilisables dans plusieurs projets.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#ifndef MODELCPP_ANNEXE_H
#define MODELCPP_ANNEXE_H

    /** Fonction permettant de choisir un nombre aléatoire se trouvant dans une plage d'entier donnée en paramètre.
     * -----------------------------------------------------------------------------------------------------------------
     * @param min               : correspond à la borne minimale pour le nombre aléatoire
     * @param max               : correspond à la borne maximale pour le nombre aléatoire
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : une valeur de type int comprenant un entier aléatoire
     * @exception               : -
     */
    int nbrAleatoire(int min, int max);

#endif //MODELCPP_ANNEXE_H
