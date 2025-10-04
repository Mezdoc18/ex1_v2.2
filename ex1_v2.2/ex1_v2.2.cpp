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
  
    do
    {
        AffichageConsole(&oConsole,"voulez-vous ajouter un nouveau client (1), en supprimer un (2), afficher la liste complète (3) ou quitter ce menu (4)?\n");
        dChoix = LireIntConsole(&oConsole);

        switch (dChoix)
        {
        case 1:
           
            if (isTabFull(&oSocietePOO) == PLACE_DISPONIBLE)
            {
               
                // ajout client
                char tTempNom[TAILLE_NOM] = { '\0' };

                AffichageConsole(&oConsole, "Entrez le nom du client\n");
                LireTabCharConsole(&oConsole, tTempNom, TAILLE_NOM);
                printf("Le Nom encode est %s\n", tTempNom);
            }
            else
            {
                AffichageConsole(&oConsole,"Ajout impossible car tableau plein\n");
            }
            break;

        case 2:

            // suppression client
            break;

        case 3:
            //On affiche tous les clients

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


/*****************************************
 Test de la struct client et des fonctions
******************************************/
/*
char sNomTest[TAILLE_NOM] = "Radeon";
char sPrenomTest[TAILLE_PRENOM] = "Bob";
char sAdresse[TAILLE_ADRESSE] = "Rue des Liserons, 24 Seraing";
enum etStatClient enTestStatut = TRES_REGULIER;

char recupNom[TAILLE_NOM] = { '\0' };
char recupPrenom[TAILLE_PRENOM] = { '\0' };
char recupAdresse[TAILLE_ADRESSE] = { '\0' };

InitClient(&oSocietePOO.tClients[0], 0, sNomTest, sPrenomTest, sAdresse, enTestStatut);


printf("NUM CLIENT: %d\n\n", getClientNum(&oSocietePOO.tClients[0]));
getClientNom(&oSocietePOO.tClients[0], recupNom);
getClientPrenom(&oSocietePOO.tClients[0], recupPrenom);
getClientAdresse(&oSocietePOO.tClients[0], recupAdresse);
getClientFrequentation(&oSocietePOO.tClients[0]);

printf("NOM: %s\n", recupNom);
printf("PRENOM: %s\n", recupPrenom);
printf("ADRESSE: %s\n", recupAdresse);

if (oSocietePOO.tClients[0].enFrequentation == TRES_REGULIER)
{
	printf("STATUT: TRES REGULIER\n\n");
}
else
{
	printf("Pas statut attendu dans ce test\n");
}
*/


/***********************************************
*2ème série de test
************************************************/

/*char sNomTest1[TAILLE_NOM] = "Radeon";
	char sPrenomTest1[TAILLE_PRENOM] = "Bob";
	char sAdresse1[TAILLE_ADRESSE] = "Rue des Liserons, 24 Seraing";
	enum etStatClient enTestStatut1 = TRES_REGULIER;

	char sNomTest2[TAILLE_NOM] = "Radeon";
	char sPrenomTest2[TAILLE_PRENOM] = "Tiger";
	char sAdresse2[TAILLE_ADRESSE] = "Rue de la Vierge Mairie, 24 Outisplou";
	enum etStatClient enTestStatut2 = REGULIER;

	char sNomTest3[TAILLE_NOM] = "Baracouda";
	char sPrenomTest3[TAILLE_PRENOM] = "Ana";
	char sAdresse3[TAILLE_ADRESSE] = "Rue des Falaises, 32 Huy";
	enum etStatClient enTestStatut3 = OCCASIONNEL;

	InitClient(&oSocietePOO.tClients[0], 1, sNomTest1,sPrenomTest1,sAdresse1,enTestStatut1);
	InitClient(&oSocietePOO.tClients[1], 2, sNomTest2, sPrenomTest2, sAdresse2, enTestStatut2);
	InitClient(&oSocietePOO.tClients[2], 3, sNomTest3, sPrenomTest3, sAdresse3, enTestStatut3);

	AfficherClient(&oSocietePOO.tClients[0]);
	AfficherClient(&oSocietePOO.tClients[1]);
	AfficherClient(&oSocietePOO.tClients[2]);
	*/