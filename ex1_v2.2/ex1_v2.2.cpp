// ex1_v2.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string.h>
#include "client.h"
#include "collclients.h"
int main()
{
	struct etCollClients oSocietePOO = { 0 };

	char sNomTest1[TAILLE_NOM] = "Radeon";
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