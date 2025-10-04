// ex1_v2.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string.h>
#include "client.h"
#include "collclients.h"
#include "console.h"

int main()
{
	struct etCollClient oSocietePOO = { 0 };
    struct etConsole oConsole;

    int dChoix = 0;

    initCollClient(&oSocietePOO);
  
    do
    {
        AffichageConsole(&oConsole,"voulez-vous ajouter un nouveau client (1), en supprimer un (2), afficher la liste complete (3) ou quitter ce menu (4)?\n");
        dChoix = LireIntConsole(&oConsole);

        switch (dChoix)
        {
        case 1:
           
            AjouterClientDansCollection(&oSocietePOO, &oConsole);
            
            break;

        case 2:

            SupprimerClientDeLaColl(&oSocietePOO, &oConsole);
            break;

        case 3:
            AfficherCollClient(&oSocietePOO, &oConsole);

            break;

        case 4:
            AffichageConsole(&oConsole,"Merci et a bientot\n");
            break;

        default:
            AffichageConsole(&oConsole,"Erreur choix dans le menu\n");
            break;
        }

    } while (dChoix != 4);

	return 0;
}
