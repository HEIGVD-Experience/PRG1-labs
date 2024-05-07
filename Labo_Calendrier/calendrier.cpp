//---------------------------------------------------------
// Fichier        : calendrier.cpp
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Fichier permettant de calculer le calendrier d'une année
//                : donnée en paramètre provenant de la saisie d'un utilisateur.
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <iomanip>  //setprecision, setw
#include <iostream> //cout, cin
#include <string>   //string
#include <cmath>    //floor

#include "calendrier.h"

using namespace std;

const int LONGUEUR_AFFICHAGE = 4;   //Longueur d'affichage d'une case du calendrier

// Cette fonction permet de vérifier si l'année est bissextile
// Explication des paramètres :
// int annne                  : correspond à l'année saisie par l'utilisateur
bool estBissextille(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

// Cette fonction permet de récupérer le mois à afficher lors du résultat du calendrier
// Explication des paramètres :
// int     numMois            : correspond au numéro du mois à afficher
// bool    bissextile         : indique si l'année est bissextile ou non
// int&    nbJours            : correspond au nombre de jours du mois
// string& nomMois            : nom du mois à afficher
void detailsMois(int numMois, bool bissextile, int& nbJours, string& nomMois){

    switch (numMois) {
        case 1:
            nomMois = "Janvier";
            nbJours = 31;
            break;
        case 2:
            nomMois = "Fevrier";
            // Par rapport au résultat de si l'année est bissextile, le nombre de jours peut être égal à 28 ou 29
            nbJours = 28 + bissextile;
            break;
        case 3:
            nomMois = "Mars";
            nbJours = 31;
            break;
        case 4:
            nomMois = "Avril";
            nbJours = 30;
            break;
        case 5:
            nomMois = "Mai";
            nbJours = 31;
            break;
        case 6:
            nomMois = "Juin";
            nbJours = 30;
            break;
        case 7:
            nomMois = "Juillet";
            nbJours = 31;
            break;
        case 8:
            nomMois = "Aout";
            nbJours = 31;
            break;
        case 9:
            nomMois = "Septembre";
            nbJours = 30;
            break;
        case 10:
            nomMois = "Octobre";
            nbJours = 31;
            break;
        case 11:
            nomMois = "Novembre";
            nbJours = 30;
            break;
        case 12:
            nomMois = "Decembre";
            nbJours = 31;
            break;
        default:
            nomMois = "Inconnu";
            nbJours = 0;
            break;
    }
}

// Fonction permettant de trouver le premier jour de l'annee saisie par l'utilisateur
// en se basant sur l'algorithme de Zeller.
// https://en.wikipedia.org/wiki/Zeller%27s_congruence
// Explication des paramètres :
// int annee                  : contient l'année saisie par l'utilisateur
int calculerPremierJourAnnee(int annee)
{
    const int  JOUR = 1,                                        // Correspond au premier jour de janvier
               MOIS = 13;                                       // Mois 13 correspond à Janvier
    const int DERNIERS_CHIFFRES_ANNEE = (annee - 1) % 100;      // Correspond aux 2 derniers chiffres de l'annee - 1
    const int PREMIERS_CHIFFRES_ANNEE = (annee - 1) / 100;      // Correspond aux 2 premiers chiffres de l'annee - 1


    // Calcul du jour de la semaine du premier jour de l'année en se basant sur l'algorithme de Zeller
    int premierJour =   (int)(JOUR + floor(13 * (MOIS + 1) / 5) +
                        DERNIERS_CHIFFRES_ANNEE + floor(DERNIERS_CHIFFRES_ANNEE / 4) +
                        floor(PREMIERS_CHIFFRES_ANNEE / 4) - (2 * PREMIERS_CHIFFRES_ANNEE)) % 7;

    // Boucle permettant de connaitre le décalage d'affichage en fonction du jour de la semaine
    if(premierJour < 2)
    {
        premierJour += 6;
    }
    else
    {
        --premierJour;
    }

    return premierJour;

}

// Fonction permettant de construire l'affichage du calendrier
// Explication des paramètres :
// int& nbJours               : contient le nombre de jours pour le mois à afficher
// int& position              : contient la position du premier jour du mois (L/M/M/..)
void afficherCalendrier(int& nbJours, int& position) {

    // Décale la position du premier jour
    for (int i = 1; i < position; i++)
    {
        cout << setw(LONGUEUR_AFFICHAGE) << " ";
    }

    // Ecrit les jours par ligne de 7
    for(int jour = 1; jour <= nbJours; jour++)
    {
        cout << setw(LONGUEUR_AFFICHAGE) << jour;
        if(position % 7 == 0)
        {
            position = 1;
            cout << endl;
        }
        else
        {
            position++;
        }
    }

    cout << endl;
}

// Fonction permettant de calculer les informations principales du calendrier
// Explication des paramètres :
// int annee                  : contient l'année saisie par l'utilisateur
void calculerCalendrier(int annee) {

    int nbJours = 0;                                      // Contient le nombre de jours pour le mois à afficher
    int position = calculerPremierJourAnnee(annee);       // Contient la position du premier jour du mois (L/M/M/..)
    string nomMois;                                       // Contient le nom du mois à afficher
    string joursSemaine = "LMMJVSD";                      // Titre des jours de la semaine

    // Boucle permettant de calculer le calendrier pour chaque mois de l'année
    for(int numMois = 1; numMois <= 12; numMois++)
    {
        // Récupère les informations du mois à afficher
        detailsMois(numMois, estBissextille(annee), nbJours, nomMois);

        // Affiche le titre du mois et l'année
        cout << endl << nomMois << " " << annee << endl;

        // Affiche les jours de la semaine
        for(char c : joursSemaine)
        {
            cout << setw(LONGUEUR_AFFICHAGE) << c;
        }

        cout << endl;

        // Affiche le calendrier du mois
        afficherCalendrier(nbJours, position);

    }
}