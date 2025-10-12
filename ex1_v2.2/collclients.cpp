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

int AjouterClientDansCollection(struct etCollClient* pstCollClient, struct etConsole *pstConsole, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut)
{
	if (isTabFull(pstCollClient) == PLACE_DISPONIBLE)
	{
		AjoutClient(&pstCollClient->tClients[pstCollClient->dPlaceLibreClient], pstCollClient->dIDClient, pstConsole, sAjoutNom, sAjoutPrenom, sAjoutAdresse, enStatut);
				
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
		int dIx = -1;
		int dNumClientASupp = 0;

		do
		{			
			int dNumClient = 0;
			char sNumClient[12] = { '\0' };

			AffichageConsole(pstConsole, "\nQuel client voulez-vous supprimer?\n");
			AffichageConsole(pstConsole, "Merci d'entrer son numero dans le choix propose ci dessous?\n");
			AffichageConsole(pstConsole, "Si vous souhaitez annuler la suppression, tapez (-1)\n");

			for (int dJx = 0; dJx < TAILLETAB_CLIENT; dJx++)
			{
				dNumClient = getClientNum(&pstCollClient->tClients[dJx]);

				if (dNumClient != 0)
				{
					_itoa_s(dNumClient, sNumClient, 10);
					AffichageConsole(pstConsole, sNumClient);
					AffichageConsole(pstConsole, " ");
				}
			}
			AffichageConsole(pstConsole, "\n");

			dNumClientASupp = LireIntConsole(pstConsole);

			if (dNumClientASupp == -1)
			{
				AffichageConsole(pstConsole, "Annulation de la suppression d'un client\n\n");
				return ANNUL_SUPP;
			}
			// on recherche l'indice correspond au numéro de client à supprimer
			dIx = -1;

			for (int i = 0; i < pstCollClient->dPlaceLibreClient; i++)
			{
				if (getClientNum(&pstCollClient->tClients[i]) == dNumClientASupp)
				{
					dIx = i;
					break;
				}
			}

			if (dIx == -1)
			{
				AffichageConsole(pstConsole, "Le client avec ce numéro n'existe pas.\n\n");
			}
		} while (dIx == -1);
	


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

