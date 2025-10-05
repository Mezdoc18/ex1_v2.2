// ex1_v2.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string.h>
#include "client.h"
#include "collclients.h"
#include "console.h"

// ATTENTION IL FAUT D2CALER TOUT LE TABLEAU DANS LA FCONTION SUPPR CLIENT QD client -- !!!!!
int main()
{
	struct etCollClient oSocietePOO = { 0 };
    struct etConsole oConsole;

    int dChoix = 0;
    enum etChoixMenu enChoix = INIT_CHOIX_MENU;

    char sNomTemp[TAILLE_NOM] = { '\0' };
    char sPrenomTemp[TAILLE_PRENOM] = { '\0' };
    char sAdresseTemp[TAILLE_ADRESSE] = { '\0' };
    int dStatut = 0;

    initCollClient(&oSocietePOO);
    InitConsole(&oConsole);
  
    do
    {
        int dValReturn = 0;
        

        do 
        {
            AffichageConsole(&oConsole, "voulez-vous ajouter un nouveau client (1), en supprimer un (2), afficher la liste complete (3) ou quitter ce menu (4)?\n");
            dChoix = LireIntConsole(&oConsole);
        
            // cast int vers enum pour switch case plus lisible
            enChoix = (enum etChoixMenu)dChoix; 
        } while (enChoix != AJOUT_CLIENT && enChoix != SUPPRESSION_CLIENT && enChoix != AFFICHAGE_CLIENT && enChoix != EXIT_MENU);
        
        switch (enChoix)
        {
            case AJOUT_CLIENT:
           
                dValReturn = (isTabFull(&oSocietePOO));

                // gestion des returns
                if (dValReturn == TABLEAU_PLEIN)
                {
                    AffichageConsole(&oConsole, "Ajout impossible car tableau plein.\n");
                }
                else if (dValReturn == PLACE_DISPONIBLE_AJOUT_EN_COURS)
                {
                    AffichageConsole(&oConsole, "Quel est le nom du client? ");
                    LireTabCharConsole(&oConsole, sNomTemp, TAILLE_NOM);

                    AffichageConsole(&oConsole, "Quel est le prenom du client? ");
                    LireTabCharConsole(&oConsole, sPrenomTemp, TAILLE_PRENOM);

                    AffichageConsole(&oConsole, "Quelle est l'adresse du client? ");
                    LireTabCharConsole(&oConsole, sAdresseTemp, TAILLE_ADRESSE);

                    do
                    {
                        AffichageConsole(&oConsole, "Quelle est la frequentation du client?\n");
                        AffichageConsole(&oConsole, "OCCASIONNEL(1)\n");
                        AffichageConsole(&oConsole, "REGULIER(2)\n");
                        AffichageConsole(&oConsole, "TRES REGULIER(3)\n");
                        dStatut = LireIntConsole(&oConsole);
                    } while (dStatut < 1 || dStatut > 3);

                    if(AjouterClient(&oSocietePOO, sNomTemp,sPrenomTemp, sAdresseTemp, (enum etStatClient) dStatut) == SUCCES)
                        AffichageConsole(&oConsole, "Client ajoute avec succes.\n");
                    else
                        AffichageConsole(&oConsole, "Erreur lors de l'ajout du client.\n");
                }
                break;

            case SUPPRESSION_CLIENT:

                dValReturn = isTabEmpty(&oSocietePOO);

                if (dValReturn == LISTE_VIDE)
                    AffichageConsole(&oConsole, "Aucun client à supprimer\n");

                else if (dValReturn == SUCCES)
                {
                    int dNumClientASupp = 0;
                    do
                    {
                        AffichageConsole(&oConsole, "Quel client voulez-vous supprimer?\n");
                        AffichageConsole(&oConsole, "Merci d'entrer son numero?\n");
                        dNumClientASupp = LireIntConsole(&oConsole);

                    } while (dNumClientASupp < 1 || dNumClientASupp > TAILLETAB_CLIENT);

                    dNumClientASupp--;

                    if (SupprimerClient(&oSocietePOO, dNumClientASupp) == SUCCES)
                        AffichageConsole(&oConsole, "Client supprime avec succes.\n");
                    else
                        AffichageConsole(&oConsole, "Erreur lors de la suppression du client.\n");                                       
                }
                break;

            case AFFICHAGE_CLIENT:
            {
                int dNbreClient = 0;
                char sNbreClient[12] = { '\0' };

                AffichageConsole(&oConsole, "\n");
                AffichageConsole(&oConsole, "Nombre total de client dans la societe: ");
                dNbreClient = GetNbreClient(&oSocietePOO);
                _itoa_s(dNbreClient, sNbreClient, 10);
                AffichageConsole(&oConsole, sNbreClient);
                AffichageConsole(&oConsole, "\n");
                AfficherCollClient(&oSocietePOO, &oConsole);
                AffichageConsole(&oConsole, "\n");

                break;
            }
            case EXIT_MENU:
                AffichageConsole(&oConsole,"Merci et a bientot\n");
                break;

            default:
                AffichageConsole(&oConsole,"Erreur choix dans le menu\n");
                break;
        }

    } while (enChoix != EXIT_MENU);

	return 0;
}
