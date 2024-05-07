// ---------------------------------------------------------------------------------------------------------------------
// Fichier        : Labo_Robots_Groupe_07_H.cpp
// Auteur(s)      : Bee Gianni & Trüeb Guillaume
// Date           : 18 décembre 2022
// But            : Ce programme réalise un battle royal d'un nombre de robots
//                  défini par l'utilisateur dans un terrain. La saisie des
//                  dimensions du terrain est effectuée par l'utilisateur. Le
//                  programme s'arrête lorsqu'il n'y a plus qu'un robot.
// Modifications  : NIL
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
// ---------------------------------------------------------------------------------------------------------------------

#include <iostream>     // cout, cin
#include <cstdlib>      // EXIT_SUCCESS
#include <limits>       // numeric limits
#include <random>       // random
#include <string>       // Utilisation string
#include <thread>       // sleep for

#include "annexe.h"     // librairie personnelle (gestion saisie,...)
#include "Terrain.h"    // classe terrain

using namespace std;

int main() {

// ---------------------------------------------------------------------------------------------------------------------
// Definition des variables
// ---------------------------------------------------------------------------------------------------------------------
// Constante pour la génération du terrain
const int LARGEUR_MIN   = 10,  LARGEUR_MAX   = 1000;
const int HAUTEUR_MIN   = 10,  HAUTEUR_MAX   = 1000;

// Constante pour le nombre de robots présent lors du combat
const int NB_ROBOTS_MIN = 1 , NB_ROBOTS_MAX  = 10;

// Message d'erreur et de saisi d'utilisateur
const string MSG_ERREUR            = "/!\\ Saisie non conforme ...";
const string MSG_BIENVENUE         = "Ce programme realise un battle royal de robots dans une arene";
const string MSG_SORTIE            = "Pressez ENTER pour quitter";
const string MSG_SAISIE_LARGEUR    = "Largeur du terrain";
const string MSG_SAISIE_HAUTEUR    = "Hauteur du terrain";
const string MSG_SAISIE_ROBOTS     = "Nombre robots";

// Variable saisie par l'utilisateur pour la largeur et la hauteur du terrain
unsigned largeurTerrain, hauteurTerrain;

// Variable saisie par l'utilisateur pour le nombre de robot(s)
unsigned nbRobots;

// Vecteur pour l'historique des vainqueurs des combats
static vector<string> tableauDesScores;

// ---------------------------------------------------------------------------------------------------------------------
// Message de bienvenue
// ---------------------------------------------------------------------------------------------------------------------
cout << MSG_BIENVENUE << endl;

// Saisie des dimensions (largeur et hauteur) du terrain et du nombre de robots
largeurTerrain = saisieEntierPositif(MSG_SAISIE_LARGEUR, LARGEUR_MIN,LARGEUR_MAX, MSG_ERREUR);
hauteurTerrain = saisieEntierPositif(MSG_SAISIE_HAUTEUR, HAUTEUR_MIN,HAUTEUR_MAX, MSG_ERREUR);
nbRobots       = saisieEntierPositif(MSG_SAISIE_ROBOTS, NB_ROBOTS_MIN,NB_ROBOTS_MAX, MSG_ERREUR);

// ---------------------------------------------------------------------------------------------------------------------
// Initilisation et remplissage du vecteur de robots
// ---------------------------------------------------------------------------------------------------------------------
// Creation du vector de robots et reservation de l'espace nécessaire
vector<Robots> vecRobots;
vecRobots.reserve(nbRobots);

// Variable pour la génération des robots
unsigned posLargeur, posHauteur;

// Boucle de génération du nombre de robots
for(unsigned i = 0 ; i < nbRobots ; ++i){
    do{
       // Génération du robots dans des coordonnées aléatoires
        posLargeur = nbAleatoire(1,largeurTerrain);
        posHauteur = nbAleatoire(1,hauteurTerrain);

     // Contrôle qu'il n'y ait pas de recouvrement lors sa génération
    }while(Robots::positionDUnRobot(vecRobots, posLargeur, posHauteur) != numeric_limits<unsigned>::max());

    // Insertion des robots dans notre vector de robots
    vecRobots.insert(vecRobots.end(),Robots(i,posLargeur,posHauteur));
}

// Initialisation de notre terrain
Terrain monTerrain = Terrain(largeurTerrain, hauteurTerrain);

// ---------------------------------------------------------------------------------------------------------------------
// Boucle de jeu
// ---------------------------------------------------------------------------------------------------------------------
// Le programme se termine lorsqu'il n'y a plus que 1 robot en vie
while(vecRobots.size() > 1){

    // Affichage du terrain avec les robots
    monTerrain.afficher(vecRobots);

    // Mélange aléatoire du vecteur de robot pour obtenir une égalité des chances
    // lors des déplacements
    shuffle(vecRobots.begin(), vecRobots.end(), std::mt19937(std::random_device()()));

    // Pour chaque robot encore en vie, on les déplace
    for(size_t i = 0 ; i < nbRobots ; ++i){

        // Déplacement des robots en fonction de la taille du terrain
        vecRobots.at(i).deplacer(largeurTerrain, hauteurTerrain);

        // Récupération de la position dans les vector du robot à éliminer.
        // Si la valeur récupérée est -1 donc la plus grande valeur de unsigned
        // c'est qu'aucun robot n'a été éliminé
        unsigned robotATuer = vecRobots.at(i).positionDUnRobot(vecRobots);

        // Si un robot a été éliminé
        if(robotATuer != numeric_limits<unsigned>::max())
        {
            // Ajout d'une ligne au tableau des scores
            string str = "Robot " + to_string(vecRobots.at(i).getID())
                   + " a tue le " + to_string(vecRobots.at(robotATuer).getID());

            // Insertion de la ligne dans le vector du tableau des scores
            tableauDesScores.insert(tableauDesScores.end(),str);

           // Destruction de l'objet Robots éliminé
           vecRobots.at(robotATuer).~Robots();

           // Effacage du robots dans le vector
           vecRobots.erase(vecRobots.begin() + robotATuer);

           // Réduction du nombre de robots en jeu
           --nbRobots;
        }
    }

    // Affichage du tableau d'historique des gagnants
    cout << tableauDesScores;

    // Pause d'excution (PDF)
    this_thread::sleep_for(500ms);

    // Gestion du clear d'affichage (LABO_TONDEUSE)
    #ifdef _WIN32
    system("cls");      // WINDOWS
    #else
    system("clear");             // MAC
    #endif
}

// Affichage final du terrain et du vecteur de robots
monTerrain.afficher(vecRobots);

// Affichage final du tableau d'historique des vainqueurs
cout << tableauDesScores << endl;

// Affichage du nom du gagnant
cout << "Le robot " << vecRobots.at(0).getID() << " a gagne!" << endl;

// Gestion de la fin du programme
cout << MSG_SORTIE;
cin.ignore(numeric_limits<streamsize>::max(), '\n');     // Vider BUFFER
return EXIT_SUCCESS;
}