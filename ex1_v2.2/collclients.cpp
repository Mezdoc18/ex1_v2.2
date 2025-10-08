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

		AjoutClient(&pstCollClient->tClients[Ix], Ix, pstConsole);
				
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
		dConditionVerifie += AfficherClientParFrequentation(&pstCollClient->tClients[dI], pstConsole, enFrequ);
	}

	if (dConditionVerifie == 0)
		AffichageConsole(pstConsole, "Pas de client trouve.\n\n");
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
		pstCollClient->dNbreClient--; // on décrémente le compteur de CollClient

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
	return pstCollClient->dNbreClient;	
}

