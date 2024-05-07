//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : cribleEratosthene.cpp
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Calculer dans un vecteur un crible Eratosthene permettant de trouver
//                  les nombres premier dans une plage donnée par un utilisateur.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include "cribleEratosthene.h"

using namespace std;

// Fonction permettant de calculer un vecteur booleen de taille tailleVecteur
// avec true si la valeur est un nombre premier
// Source de l'algorithme : https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne
vector<bool> cribleEratosthene(size_t tailleVecteur){

    // Vecteur booleen initialisé a true pour toutes les valeurs
    vector<bool> vecteurCriblage(tailleVecteur, true);

    // Mets les valeurs 0 et 1 à false, car ils ne sont pas des nombres premiers.
    vecteurCriblage[0] = false;
    vecteurCriblage[1] = false;

    // On traverse le tableau vecteurCriblage depuis la valeur 2 et pour chaque position qui est
    // vrai, on met ces multiples à faux.
    for (size_t i = 2 ; i < tailleVecteur ; ++i)
        if(vecteurCriblage[i])
            for (size_t j = 2; j <= tailleVecteur / i; ++j)
                vecteurCriblage[i * j] = false;

    return vecteurCriblage;
}

vector<int> nbrsPremier(const vector<bool> &vecCrible){

    // Vecteur d'entier vide
    vector<int> vecNbrPremier;

    // Réservation de valeurs en se basant sur la taille du vecteur crible
    vecNbrPremier.reserve(vecCrible.size());

    // Pour tous les éléments du vecteur crible, si l'element i est vrai, alors on le rajoute au
    // vecteur de nombre premier.
    for(size_t i = 0; i < vecCrible.size(); ++i)
        if(vecCrible.at(i))
            vecNbrPremier.push_back((int) i);

    // Une fois le travail terminé on adapte la capacité du vecteur aux valeurs réeles
    vecNbrPremier.shrink_to_fit();

    return vecNbrPremier;
}
