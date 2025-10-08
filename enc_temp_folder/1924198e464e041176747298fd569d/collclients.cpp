#include <iostream>
#include "collclients.h"
#include "console.h"


void initCollClient(struct etCollClient* pstCollClient)
{
	char sNull = { '\0' };

	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		setClient(&pstCollClient->tClients[dI], 0, &sNull, &sNull, &sNull, INCONNUE);
	}
	pstCollClient->dPlaceLibreClient = 0;
	pstCollClient->dIDClient = 0;
}

int isTabFull(struct etCollClient* pstCollClient)
{
	if (pstCollClient->dPlaceLibreClient < TAILLETAB_CLIENT)
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
		AjoutClient(&pstCollClient->tClients[pstCollClient->dPlaceLibreClient], pstCollClient->dIDClient, pstConsole);
				
		pstCollClient->dPlaceLibreClient++;	
		pstCollClient->dIDClient++;

		AffichageConsole(pstConsole, "\n");
		return SUCCES;
	}
	else
	{
		AffichageConsole(pstConsole, "\nAjout impossible car tableau plein\n\n");
		return TABLEAU_PLEIN;
	}	
}

void AfficherCollClient(struct etCollClient* pstCollClient, struct etConsole *pstConsole)
{
	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		AfficherClient(&pstCollClient->tClients[dI], pstConsole);
	}	
}

void AffichCollClientParFrequentation(struct etCollClient* pstCollClient, struct etConsole* pstConsole, enum etStatClient enChoixFrequ)
{
	// variable qui vaudra 0 à la fin de la fonction si aucun client trouve avec cette frequentation
	int dConditionVerifie = 0; 


	switch (enChoixFrequ)
	{
		case OCCASIONNEL:
			AffichageConsole(pstConsole, "\nLISTE CLIENTS OCCASSIONNELS\n");
			break;
		case REGULIER:
			AffichageConsole(pstConsole, "\nLISTE CLIENTS REGULIERS\n");
			break;
		case TRES_REGULIER:
			AffichageConsole(pstConsole, "\nLISTE CLIENTS TRES REGULIERS\n");
			break;
		default:
			AffichageConsole(pstConsole, "Erreur statut\n");
			break;
	}

	for (int dI = 0; dI < TAILLETAB_CLIENT; dI++)
	{
		dConditionVerifie += AfficherClientParFrequentation(&pstCollClient->tClients[dI], pstConsole, enChoixFrequ);
	}

	if (dConditionVerifie == 0)
		AffichageConsole(pstConsole, "Pas de client trouve.\n\n");
}

int SupprimerClientDeLaColl(struct etCollClient* pstCollClient, struct etConsole* pstConsole)
{
	 // on vérifie que la collection n'est pas vide
	if (pstCollClient->dPlaceLibreClient > 0)
	{
		int dNumClientASupp = 0;
		do
		{
			AffichageConsole(pstConsole, "\nQuel client voulez-vous supprimer?\n");
			AffichageConsole(pstConsole, "Merci d'entrer son numero?\n");
			dNumClientASupp = LireIntConsole(pstConsole);
		} while (dNumClientASupp < 1 || dNumClientASupp > TAILLETAB_CLIENT);

		int dIx = dNumClientASupp - 1; // indice du client dans le tableau

		SupprimerClient(&pstCollClient->tClients[dIx]);

		// on décalle tous les clients à D du client supprimé vers la G dans le tabclient
		for (dIx; dIx < (pstCollClient->dPlaceLibreClient - 1); dIx++)
		{
			pstCollClient->tClients[dIx] = pstCollClient->tClients[dIx + 1];
		}
		// on décrémente le compteur de CollClient
		pstCollClient->dPlaceLibreClient--; 

		// on vide la dernière case client copiée dans la case à sa G sur laquelle pointe maintenant dPlaceLibreClient
		SupprimerClient(&pstCollClient->tClients[pstCollClient->dPlaceLibreClient]);

		AffichageConsole(pstConsole, "Client supprime avec succes!\n\n");
		return SUCCES;
	}
	else
	{
		AffichageConsole(pstConsole, "Aucun client a supprimer actuellement.\n\n");
		return LISTE_VIDE;
	}
}

int GetNbreClient(struct etCollClient* pstCollClient)
{
	return pstCollClient->dPlaceLibreClient;	
}

