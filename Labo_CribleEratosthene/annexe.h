//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : annexe.h
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Fournir différentes fonctions permettant de rendre plus efficace
//                : certaines actions répétitives, tel que la saisie utilisateur.
// Modifications  : Ajout de l'affichage de vecteurs criblés ainsi que de vecteur d'entiers.
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#ifndef ANNEXE_H
    #define ANNEXE_H

    #include <vector>          // nécessaire pour les paramètres
    #include <string>          // nécessaire pour les paramètres

    /** Fonction permettant de faire saisir une valeur entière à un utilisateur
     *  et de prendre en charge les potentielles erreurs.
     * -----------------------------------------------------------------------------------------------------------------
     * @param MSG               : correspond au message à afficher avant la saisie
     * @param min               : correspond à la borne minimale acceptable pour la saisie
     * @param max               : correspond à la borne maximale acceptable pour la saisie
     * @param MSG_ERREUR        : correspond au message à afficher si une erreur survient
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : une valeur de type int comprenant la saisie de l'utilisateur
     * @exception               : -
     */
    int  saisieEntier(const std::string& MSG, int min, int max, const std::string& MSG_ERREUR);


    /** Fonction permettant d'afficher les valeurs d'un vecteur de type booleen sous format true = 0 et false = X
    * -----------------------------------------------------------------------------------------------------------------
    * @param vecteur            : correspond au vecteur de booleen
    * @param titre              : correspond au titre à afficher avant d'afficher le vecteur
    * @param largeurColonne     : correspond à la largeur d'affichage d'une valeur du vecteur
    * @param nbreColonne        : correspond au nombres de colonnes autorisée dans l'affichage
    * -----------------------------------------------------------------------------------------------------------------
    * @return                   : -
    * @exception                : -
    */
    void afficheVecteur(const std::vector<bool>& vecteur, const std::string& titre = "",
                        int largeurColonne = 0, int nbreColonne = 0);


    /** Fonction permettant d'afficher les valeurs d'un vecteurs de type int
    * -----------------------------------------------------------------------------------------------------------------
    * @param vecteur            : correspond au vecteur de int
    * @param titre              : correspond au titre à afficher avant d'afficher le vecteur
    * @param largeurColonne     : correspond à la largeur d'affichage d'une valeur du vecteur
    * @param nbreColonne        : correspond au nombres de colonnes autorisée dans l'affichage
    * -----------------------------------------------------------------------------------------------------------------
    * @return                   : -
    * @exception                : -
    */
    void afficheVecteur(const std::vector<int>&  vecteur, const std::string& titre = "",
                        int largeurColonne = 0, int nbreColonne = 0);


#endif //ANNEXE_H