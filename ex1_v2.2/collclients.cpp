#include <iostream>
#include "collclients.h"
#include "console.h"

void initCollClient(struct etCollClient* pstCollClient)
{
	char sNull = { '\0' };

	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		InitAJoutClient(&pstCollClient->tClients[dI], 0, &sNull, &sNull, &sNull, INCONNUE);
	}
	pstCollClient->dNbreClient = 0;
}

int isTabFull(struct etCollClient* pstCollClient)
{
	if (pstCollClient->dNbreClient < TAILLETAB_CLIENT)
		{
		return PLACE_DISPONIBLE_AJOUT_EN_COURS;
		}
	else 
		return TABLEAU_PLEIN;
}

int isTabEmpty(struct etCollClient* pstCollClient)
{
	if (pstCollClient->dNbreClient == 0)
	{
		return LISTE_VIDE;
	}
	else
		return SUCCES;
}

int AjouterClient(struct etCollClient* pstCollClient, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut)
{

		int Ix = pstCollClient->dNbreClient;

		InitAJoutClient(&pstCollClient->tClients[Ix], Ix, sAjoutNom, sAjoutPrenom, sAjoutAdresse, enStatut);
				
		pstCollClient->dNbreClient++;	
		
		return SUCCES;
	
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

int SupprimerClient(struct etCollClient* pstCollClient, int ClientASupp)
{
	Supprimer(&pstCollClient->tClients[ClientASupp]);

	pstCollClient->dNbreClient--;
				
	return SUCCES;	
}

int GetNbreClient(struct etCollClient* pstCollClient)
{
	return pstCollClient->dNbreClient;	
}

