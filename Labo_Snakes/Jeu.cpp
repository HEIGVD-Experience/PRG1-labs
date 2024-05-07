// ---------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Jeu.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Définition des méthodes et constructeur pour la classe Jeu.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

#include "Jeu.h"

using namespace std;
// ---------------------------------------------------------------------------------------------------------------------
// CONSTRUCTEURS
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// Constructeur par défaut de jeu
Jeu::Jeu(int _hauteurTerrain, int _largeurTerrain, int _nbSerpents) {

    // Crée l'objet du terrain
    terrain = Terrain(_hauteurTerrain, _largeurTerrain);

    int posHauteur, posLargeur;

    // Crée un vector de coordonnées pour les serpents et les pommes
    vector<Coordonnee> vecCoordonneeDepart;

    // Rempli le vector de coordonnées avec des coordonnées de départ aléatoires et uniques
    while(vecCoordonneeDepart.size() < (size_t)_nbSerpents*2) {

        posHauteur = nbAleatoire(0, _hauteurTerrain);
        posLargeur = nbAleatoire(0, _largeurTerrain);

        Coordonnee coordonneeDepart(posHauteur, posLargeur);

        // Si la coordonnée n'est pas déjà dans le vector, on l'ajoute
        if(find(vecCoordonneeDepart.begin(), vecCoordonneeDepart.end(), coordonneeDepart) == vecCoordonneeDepart.end()){
            vecCoordonneeDepart.push_back(coordonneeDepart);
        }
    }

    // On crée le nombre de serpents demandé
    for (size_t i = 0; i < (size_t)_nbSerpents; i+=2) {

        // Création du vecCorpsSerpent du serpent
        vector<Coordonnee> corpsSerpent = vector<Coordonnee>(10,vecCoordonneeDepart[i]);

        // Création de la pomme pour le serpent
        Pomme pomme = Pomme((int)i, vecCoordonneeDepart[i+1]);

        // Crée le serpent avec une coordonnée unique et une pomme
        Serpent serpent = Serpent((int)i, corpsSerpent, pomme);

        // Controler pas la même position
        vecSerpent.push_back(serpent);
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// METHODES
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// Fonction principale qui gère l'avancement du jeu en mélangeant le vecteur de serpents, puis en déplacent chaques
// serpents et en vérifiant les collisions avec les pommes et les autres serpents.
void Jeu::avance(){

    int posHauteur, posLargeur;

    // Permet de mélanger le vecteur de serpents de manière aléatoire à chaque tour du jeu pour que le premier serpent
    // à se déplacer ne soit pas toujours le même
    // -----------------------------------------------------------------------------------------------------------------
    // C++ reference : https://cplusplus.com/reference/random/mt19937/
    shuffle(vecSerpent.begin(), vecSerpent.end(), mt19937(random_device()()));

    // Boucle de déplacement de tous les serpents
    for (size_t i = 0; i < vecSerpent.size(); i++) {

        // Déplacement du serpent
        vecSerpent.at(i).deplacer();

        // Si sur la même case que la pomme
        if(vecSerpent.at(i).estSurPomme())
        {
            // Le serpent mange sa pomme
            vecSerpent.at(i).mangePomme();

            // Définir une nouvelle position pour la pomme
            posHauteur = nbAleatoire(0, terrain.getHauteur());
            posLargeur = nbAleatoire(0, terrain.getLargeur());

            // Création de la pomme pour le serpent
            vecSerpent.at(i).getPomme().setCoordonnees(Coordonnee(posHauteur,posLargeur));

            // Augmenter la taille de la pomme
            vecSerpent.at(i).getPomme().setCroissance();
        }

        // Regarde si le serpent qui se déplace arrive sur un autre serpent
        pair<int,int> positionSurSerpent = vecSerpent.at(i).estSurSerpent(vecSerpent);

        // Si le serpent est sur un autre serpent
        if(positionSurSerpent.first >= 0)
        {
            pair<int,int> indexSerpentsMangeurs;

            // Définit une paire avec -1 comme valeur par défaut permettant de connaitre l'identifiant
            // du serpent qui a mangé et l'identifiant du serpent qui a été mangé
            indexSerpentsMangeurs = vecSerpent.at(i).mangeSerpent(vecSerpent.at((size_t)positionSurSerpent.first),
                                                                  positionSurSerpent.second);

            // Si un serpent est mort on retourne son identifiant et celui du serpent qui l'a mangé
            if(indexSerpentsMangeurs.first >= 0 && indexSerpentsMangeurs.second >= 0)
            {

                // On écrit dans le terminal les scores
                ecrireScore(indexSerpentsMangeurs.first, indexSerpentsMangeurs.second);

                // On récupère la position dans le vecteurdu serpent qui a été mangé
                int posSerpentMange = Serpent::positionDansVector(vecSerpent, indexSerpentsMangeurs.second);

                // Supprimer le serpent
                vecSerpent.erase(vecSerpent.begin() + posSerpentMange);
            }
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// Fonction qui écrit dans le terminal quel serpent a mangé quel serpent
void Jeu::ecrireScore(int idSerpentMangeur, int idSerpentMange) {
    cout    << "Le serpent " << setw(3) << idSerpentMangeur
            << " a mangé le serpent " << setw(3) << idSerpentMange << endl;
}