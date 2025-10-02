// ex1_v2.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string.h>
#include "client.h"
#include "collclients.h"
int main()
{
	struct etCollClients oSocietePOO = { 0 };
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

	return 0;
}

