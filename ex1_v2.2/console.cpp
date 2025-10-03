#include <iostream>
#include <string.h>
#include "console.h"
#include "collclients.h"

void LancementMenu(struct etConsole *pConsole, struct etCollClient *pCollClient)
{
    int dChoix = 0;
    int dPlaceLibreTab = 0;
    do
    {
        printf("voulez-vous ajouter un nouveau client (1), en supprimer un (2), afficher la liste complète (3) ou quitter ce menu (4)?\n");
        scanf_s("%d", &dChoix);

        switch (dChoix)
        {
        case 1:
            // ajout client
            if (dPlaceLibreTab = isTabPleinAndNumber(pCollClient) != TABLEAU_PLEIN)
            {
                
            }
            else
            {
                printf("Ajout impossible car tableau plein\n");
            }
            break;

        case 2:

           // suppression client
            break;

        case 3:
            //On affiche tous les clients
           
            break;

        case 4:
            printf("Merci et a bientot\n");
            break;

        default:
            printf("Erreur choix dans le menu\n");

            break;
        }

    } while (dChoix != 4);
}