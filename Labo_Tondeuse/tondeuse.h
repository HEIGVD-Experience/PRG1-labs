//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Tondeuse_Groupe_06_G
// Fichier        : tondeuse.h
// Auteur(s)      : Mariaux Ewan & Trüeb Guillaume
// But            : Fichier permettant de mettre à disposition des fonctions pouvant tondre un terrain
//                : définit dans le fichier main.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

    #include <vector>       // nécessaire pour les paramètres
    #include <array>        // nécessaire pour les paramètres

    // Enumeration des différents types de sol possible pour notre terrain
    // - L : limite
    // - X : obstacle
    // - H : herbe haute
    // - h : herbe coupée
    enum Topologie{X, L, H, h};

    // Définition d'un vecteur d'enum de topologie
    using LigneTerrain = std::vector<Topologie>;

    // Définition d'un vecteur comprenant un vecteur de topologie
    using Terrain = std::vector<LigneTerrain>;

    // Définition d'un array comportant les postions (x,y) de la tondeuse
    using Tondeuse = std::array<int, 2>;

    /** Fonction permettant de tondre un terrain en donnant en paramètre le terrain ainsi qu'une tondeuse.
     *  Il faudra aussi spécifier combien de déplacement celle-ci peux faire et dire si l'on souhaite que
     *  l'affichage se synchronise après chaque déplacement de la tondeuse.
     * -----------------------------------------------------------------------------------------------------------------
     * @param terrain           : vecteur composé de vecteur d'enum Topologie
     * @param tondeuse          :
     * @param nbreDeplacements  :
     * @param afficher          :
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : -
     * @exception               : -
     */
    void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbreDeplacements, bool afficher);

#endif //LABO_TONDEUSE_TONDEUSE_H
