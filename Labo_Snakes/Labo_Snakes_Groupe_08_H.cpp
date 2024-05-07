//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_Snakes
// Fichier        : Labo_Snakes_Groupe_08_H.cpp
// Auteur(s)      : Sebastian Diaz & Trüeb Guillaume
// But            : Créer une arène ou des serpents mange leur pomme et s'attaque
//                  entre eux. Le dernier sur l'arène gagne.
// Modifications  : -
// Remarque(s)    : Reprise de la demo :
//                : https://github.com/gmbreguet/PRG1_DEMO/tree/main/03_Structures/03_Moving_Point_SDL
//                : pour gérer l'affichage avec SDL2.
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

#include <SDL.h>
#include "Jeu.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
int main(int argv, char** args) {

    // Nécessaire pour la compilation sur Windows
    (void)argv;
    (void)args;

    // Récupération des paramètres pour connaitre la taille du terrain et le nombre de serpents ------------------------
    int hauteurEcran, largeurEcran, nbSerpents;

    string message = "Largeur du terrain : ";
    string messageErreur = "Erreur : La largeur doit être comprise entre 50 et 1200";
    largeurEcran = saisieEntier(message, 50, 1200, messageErreur);

    message = "Largeur du terrain : ";
    messageErreur = "Erreur : La largeur doit être comprise entre 50 et 1200";
    hauteurEcran = saisieEntier(message, 50, 800, messageErreur);

    message = "Largeur du terrain : ";
    messageErreur = "Erreur : La largeur doit être comprise entre 50 et 1200";
    nbSerpents   = saisieEntier(message, 2, 1000,  messageErreur);

    // Paramètrages de SDL ---------------------------------------------------------------------------------------------
    SDL_Window*    window         = nullptr;
    SDL_Renderer*  renderer       = nullptr;
    bool           appIsRunning   = true;
    const int      SCALE          = 1;

    // Initialisation de SDL -------------------------------------------------------------------------------------------
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(largeurEcran  * SCALE, hauteurEcran * SCALE, SDL_WINDOW_SHOWN, &window, &renderer);

    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "Battle royale de serpents!");
    SDL_RenderSetScale(renderer, SCALE, SCALE);

    // Création du jeu
    Jeu jeu(largeurEcran,hauteurEcran,nbSerpents);

    // Boucle de jeu ---------------------------------------------------------------------------------------------------
    while (appIsRunning) {

        // Affichange en blanc de l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

        // Nettoyage de l'affichage
        SDL_RenderClear(renderer);

        // Avance dans la partie
        jeu.avance();

        // Récupération du vector de serpents encore vivant
        vector<Serpent> mesSerpents = jeu.getSerpents();

        // S'il reste un serpent le jeu s'arrête
        if (mesSerpents.size() == 1)
        {
            appIsRunning = false;
        }

        // Dessine chaques serpents et chaque pomme.
        for(Serpent serpent : mesSerpents)
        {
            // Récupération des positions du corps du serpent
            vector<Coordonnee> vecCorpsSerpent = serpent.getCorpsSerpent();

            // Pour chaque coordonnée du serpent on dessine un pixel
            for(Coordonnee coordonnee : vecCorpsSerpent)
            {
                // Couleur en vert pour les serpents
                SDL_SetRenderDrawColor(renderer, 0, 128, 0, 100);

                // Ajoute le point dans le renderer
                SDL_RenderDrawPoint(renderer, coordonnee.getPosHauteur(), coordonnee.getPosLargeur());
            }

            // Couleur en rouge pour les pommes
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 100);

            // On récupère la pomme du serpent.
            Coordonnee pomme = serpent.getPomme().getCoordonnees();

            // Ajoute le point de pomme dans le renderer
            SDL_RenderDrawPoint(renderer, pomme.getPosHauteur(), pomme.getPosLargeur());
        }

        // Gestion des évènements --------------------------------------------------------------------------------------
        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            switch (event.type) {
                case SDL_QUIT     :  appIsRunning = false;
                    break;

            } // Changement de l'évènement appIsRunning

        }

        // Affichage de l'écran
        SDL_RenderPresent(renderer);

    } // Fin de la boucle de jeu

    // Détruit l'affichage.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}