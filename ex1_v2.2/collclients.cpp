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
		setClientAdresse(&pstCollClient->tClients[dI], &sNull);
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

		LireDataNouvClientViaConsole(&pstCollClient->tClients[Ix], Ix, pstConsole);
				
		pstCollClient->dNbreClient++;	
		return SUCCES;
	}
	else
	{
		AffichageConsole(pstConsole, "Ajout impossible car tableau plein\n");
		return TABLEAU_PLEIN;
	}	
}

void AfficherCollClient(struct etCollClient* pstCollClient, struct etConsole *pstConsole)
{
	// compteur qui va s'incrémenter à chaque fois que AfficherClient est appelé et que le client sera vide
	// si le compteur = au nbre de place du tableau, alors on affiche qu'il est vide
	int dCompteur = 0;

	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		dCompteur += AfficherClient(&pstCollClient->tClients[dI], pstConsole);
	}

	if (dCompteur == TAILLETAB_CLIENT)
		AffichageConsole(pstConsole, "Tableau VIDE\n");
}

int SupprimerClientDeLaColl(struct etCollClient* pstCollClient, struct etConsole* pstConsole)
{
	 // on vérifie que la collection n'est pas vide
	if (pstCollClient->dNbreClient > 0)
	{
		int dNumClientASupp = 0;
		do
		{
			AffichageConsole(pstConsole, "Quel client voulez-vous supprimer?\n");
			AffichageConsole(pstConsole, "Merci d'entrer son numero?\n");
			dNumClientASupp = LireIntConsole(pstConsole);
		} while (dNumClientASupp < 1 || dNumClientASupp > TAILLETAB_CLIENT);

		SupprimerClient(&pstCollClient->tClients[dNumClientASupp - 1]);

		AffichageConsole(pstConsole, "Client supprime avec succes!\n\n");
		return SUCCES;
	}
	else
	{
		return LISTE_VIDE;
	}
}

int GetNbreClient(struct etCollClient* pstCollClient)
{
	return pstCollClient->dNbreClient;	
}

