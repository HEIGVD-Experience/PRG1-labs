//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : cribleEratosthene.h
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Calculer dans un vecteur un crible Eratosthene permettant de trouver
//                  les nombres premier dans une plage donnée par un utilisateur.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#ifndef LABO_CRIBLEERATOSTHENE_CRIBLEERATOSTHENE_H
    #define LABO_CRIBLEERATOSTHENE_CRIBLEERATOSTHENE_H

    // Includes pour les éléments nécessaires au .h
    #include <vector>          // nécessaire pour les paramètres


    /** Fonction permettant de calculer un vecteur booleen contenant un crible eratosthene
     * -----------------------------------------------------------------------------------------------------------------
     * @param tailleVector      : correspond à la plage de nombres à cribler pour trouver les nombres premiers
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : un vecteur de type booleen avec true si la position est un nombre premier
     * @exception               : -
     */
    std::vector<bool> cribleEratosthene(size_t tailleVecteur);


    /** Fonction permettant de calculer les nombres premiers en se basant sur un vecteur crible de type booleen
    * ------------------------------------------------------------------------------------------------------------------
    * @param vecCrible         : correspond au vecteur booleen
    * ------------------------------------------------------------------------------------------------------------------
    * @return                  : un vecteur de type entier avec les nombres premiers contenu dans le vecteur crible
    * @exception               : -
    */
    std::vector<int>  nbrsPremier(const std::vector<bool>& vecCrible);

#endif // LABO_CRIBLEERATOSTHENE_CRIBLEERATOSTHENE_H