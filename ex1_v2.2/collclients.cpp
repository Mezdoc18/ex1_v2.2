#include <iostream>
#include "collclients.h"
#include "console.h"

void initCollClient(struct etCollClient* pstCollClient)
{
	char sNull = { '\0' };

	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		setclientNum(&pstCollClient->tClients[dI], 0);
		setClientNom(&pstCollClient->tClients[dI], &sNull);
		setClientPrenom(&pstCollClient->tClients[dI], &sNull);
		setclientAdresse(&pstCollClient->tClients[dI], &sNull);
		setClientFrequentation(&pstCollClient->tClients[dI], INCONNUE);
	}
	pstCollClient->dNbreClient = 0;
}

int isTabFull(struct etCollClient* pstCollClient)
{
	if (pstCollClient->dNbreClient < TAILLETAB_CLIENT)
		{
		return PLACE_DISPONIBLE;
		}
	else 
		return TABLEAU_PLEIN;
}

int AjouterClientDansCollection(struct etCollClient* pstCollClient, struct etConsole *pstConsole)
{
	if (isTabFull(pstCollClient) == PLACE_DISPONIBLE)
	{
		//NbreClient représente le total de client contenu dans le tableau
		//mais aussi l'index de la prochaine struct client dispo
		int Ix = pstCollClient->dNbreClient;

		AffichageConsole(pstConsole, "Client numéro %d\n", );
		int dNumclient = ;


		
		setclientNum(&pstCollClient->tClients[Ix], 0);
		setClientNom(&pstCollClient->tClients[Ix], &sNull);
		setClientPrenom(&pstCollClient->tClients[Ix], &sNull);
		setclientAdresse(&pstCollClient->tClients[Ix], &sNull);
		setClientFrequentation(&pstCollClient->tClients[Ix], INCONNUE);
		

		pstCollClient->dNbreClient++;
		

		AffichageConsole(pstConsole, "Entrez le nom du client\n");
		LireTabCharConsole(pstConsole, tTempNom, TAILLE_NOM);
		printf("Le Nom encode est %s\n", tTempNom);
	}
	else
	{
		AffichageConsole(pstConsole, "Ajout impossible car tableau plein\n");
		return TABLEAU_PLEIN;
	}
	
	
	
	int PlaceNouvClient = PlaceTabDispo(pstCollClient);

	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		setclientNum(&pstCollClient->tClients[dI], 0);
		setClientNom(&pstCollClient->tClients[dI], &sNull);
		setClientPrenom(&pstCollClient->tClients[dI], &sNull);
		setclientAdresse(&pstCollClient->tClients[dI], &sNull);
		setClientFrequentation(&pstCollClient->tClients[dI], INCONNUE);
	}
	
	pstCollClient->dNbreClient++;
}

