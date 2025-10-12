// ex1_v2.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string.h>
#include "client.h"
#include "collclients.h"
#include "console.h"

/// <summary>
/// Correction du prof: dans CollClients la fonction AjouterClients doit recevoir soit directement une copie de struct client à copier soit les 
/// différentes valeurs 
/// C'est en effet différent de fournir les valeurs que de les modifier dans le main
/// Ce sont les fonctions propres à clients qui vont traiter les données donc pas de problème d'encapsulation!
/// <returns></returns>

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
            {
                // Gestion NOM
                char sNomTemp[TAILLE_NOM] = { '\0' };
                AffichageConsole(&oConsole, "Quel est le nom du client? ");
                LireTabCharConsole(&oConsole, sNomTemp, TAILLE_NOM);

                // Gestion PRENOM
                char sPrenomTemp[TAILLE_PRENOM] = { '\0' };
                AffichageConsole(&oConsole, "Quel est le prenom du client? ");
                LireTabCharConsole(&oConsole, sPrenomTemp, TAILLE_PRENOM);

                // Gestion ADRESSE
                char sAdresseTemp[TAILLE_ADRESSE] = { '\0' };
                AffichageConsole(&oConsole, "Quelle est l'adresse du client? ");
                LireTabCharConsole(&oConsole, sAdresseTemp, TAILLE_ADRESSE);

                // Gestion FREQUENTATION
                int dFrequentation = 0;
                enum etStatClient enTemp = INCONNUE;

                AffichageConsole(&oConsole, "Quelle est la frequentation du client?\n");
                AffichageConsole(&oConsole, "OCCASIONNEL(1)\n");
                AffichageConsole(&oConsole, "REGULIER(2)\n");
                AffichageConsole(&oConsole, "TRES REGULIER(3)\n");

                do
                {
                    switch (dFrequentation = LireIntConsole(&oConsole))
                    {
                    case 1:
                        enTemp = OCCASIONNEL;
                        break;

                    case 2:
                        enTemp = REGULIER;
                        break;
                    case 3:
                        enTemp = TRES_REGULIER;
                        break;
                    default:
                        AffichageConsole(&oConsole, "Erreur dans le choix:\n");
                        AffichageConsole(&oConsole, "OCCASIONNEL(1)\n");
                        AffichageConsole(&oConsole, "REGULIER(2)\n");
                        AffichageConsole(&oConsole, "TRES REGULIER(3)\n\n");
                        break;
                    }
                } while (dFrequentation < 1 || dFrequentation >3);

                AjouterClientDansCollection(&oSocietePOO, &oConsole, sNomTemp, sPrenomTemp, sAdresseTemp, enTemp);
                break;
            }
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
