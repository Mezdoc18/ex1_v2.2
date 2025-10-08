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
    enum etStatClient enChoixFrequ;
    enum etChoixMenu enChoixMenu;

    initCollClient(&oSocietePOO);
    InitConsole(&oConsole);
  
    do
    {
        do 
        {
            AffichageConsole(&oConsole, "Que souhaitez-vous faire?\n");
            AffichageConsole(&oConsole, "- ajouter un nouveau client (1)\n");
            AffichageConsole(&oConsole, "- supprimer un client (2)\n");
            AffichageConsole(&oConsole, "- afficher la liste complete des clients (3)\n");
            AffichageConsole(&oConsole, "- afficher la liste des clients par frequentation (4)\n");
            AffichageConsole(&oConsole, "- quitter le menu (5)\n");
            dChoix = LireIntConsole(&oConsole);
        } while (dChoix < 1 || dChoix > 5);

        switch (enChoixMenu =(enum etChoixMenu)dChoix)
        {
            case AJOUT_CLIENT:           
                AjouterClientDansCollection(&oSocietePOO, &oConsole);
                break;

            case SUPP_CLIENT:
                SupprimerClientDeLaColl(&oSocietePOO, &oConsole);
                break;

            case AFFICH_LISTE:
            {
                int dPlaceLibreClient = 0;
                char sNbreClient[12] = { '\0' };

                AffichageConsole(&oConsole, "\n");
                AffichageConsole(&oConsole, "Nombre total de client dans la societe: ");
                dPlaceLibreClient = GetNbreClient(&oSocietePOO);
                _itoa_s(dPlaceLibreClient, sNbreClient, 10);
                AffichageConsole(&oConsole, sNbreClient);
                AffichageConsole(&oConsole, "\n");

                if (dPlaceLibreClient != 0)
                {
                    AfficherCollClient(&oSocietePOO, &oConsole);
                    AffichageConsole(&oConsole, "\n");
                }
                else
                    AffichageConsole(&oConsole, "Societe sans client actuellement\n\n");
                break;
            }
            case AFFICH_FREQU:
            {
                dChoix = 0;

                if (GetNbreClient(&oSocietePOO) == 0)
                    AffichageConsole(&oConsole, "\nSociete sans client actuellement\n\n");
                else
                {
                    do
                    {
                        AffichageConsole(&oConsole, "voulez-vous afficher la liste des:\n");
                        AffichageConsole(&oConsole, "- clients OCCASIONNELS? (1) \n");
                        AffichageConsole(&oConsole, "- clients REGULIERS? (2)\n");
                        AffichageConsole(&oConsole, "- clients TRES REGULIERS? (3)\n");

                        dChoix = LireIntConsole(&oConsole);
                    } while (dChoix < 1 || dChoix > 3);

                    AffichCollClientParFrequentation(&oSocietePOO, &oConsole, enChoixFrequ = (enum etStatClient)dChoix);
                }
                break;
            }
            case QUITTER:
                AffichageConsole(&oConsole,"Merci et a bientot\n");
                break;

            default:
                AffichageConsole(&oConsole,"Erreur choix dans le menu\n");
                break;
        }

    } while (dChoix != 5);

	return 0;
}
