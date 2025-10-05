#include <iostream>
#include <string.h>
#include "client.h"
#include "console.h"

/********************************************************
 Printf devra être remplacé par l'objet console dans la
 fct void AfficherClient
*********************************************************/



int getClientNum(struct etClient* pstclient)
{
	return pstclient->dNumClient;
}

void getClientNom(struct etClient* pstClient, char *NomClient)
{
	strcpy_s(NomClient, TAILLE_NOM, pstClient->sNom);
}

void getClientPrenom(struct etClient* pstClient, char* PrenomClient)
{
	strcpy_s(PrenomClient, TAILLE_PRENOM, pstClient->sPrenom);
}

void getClientAdresse(struct etClient* pstClient, char* AdresseClient)
{
	strcpy_s(AdresseClient, TAILLE_ADRESSE, pstClient->sAdresse);
}

enum etStatClient getClientFrequentation(struct etClient* pstClient)
{
	return pstClient->enFrequentation;
}

void InitAJoutClient(struct etClient* pstClient, int dNumero, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut)
{
	pstClient->dNumClient = dNumero;
	strcpy_s(pstClient->sNom, TAILLE_NOM, sAjoutNom);
	strcpy_s(pstClient->sPrenom, TAILLE_PRENOM, sAjoutPrenom);
	strcpy_s(pstClient->sAdresse, TAILLE_ADRESSE, sAjoutAdresse);
	pstClient->enFrequentation = enStatut;
}

void Supprimer(struct etClient* pstClient)
{
	int dNull = 0;
	char cNull = '\0';

	pstClient->dNumClient = 0;
	strcpy_s(pstClient->sNom, &cNull);
	strcpy_s(pstClient->sPrenom, &cNull); 
	strcpy_s(pstClient->sAdresse, &cNull);
	pstClient->enFrequentation= INCONNUE;
}

int AfficherClient(struct etClient* pstClient, struct etConsole* pstConsole)
{
	int dClientVide = 1;

	if (pstClient->dNumClient != 0)
	{
		char recupNum[12] = { '\0' };
		char recupNom[TAILLE_NOM] = { '\0' };
		char recupPrenom[TAILLE_PRENOM] = { '\0' };
		char recupAdresse[TAILLE_ADRESSE] = { '\0' };

		AffichageConsole(pstConsole,"\n");
		AffichageConsole(pstConsole,"NUM CLIENT: ");
		int dNumClient = getClientNum(pstClient);
		_itoa_s(dNumClient, recupNum, 10);
		AffichageConsole(pstConsole, recupNum);

		AffichageConsole(pstConsole, "\nNOM: ");
		getClientNom(pstClient, recupNom);
		AffichageConsole(pstConsole,recupNom);

		AffichageConsole(pstConsole, "\nADRESSE: ");
		getClientAdresse(pstClient, recupAdresse);
		AffichageConsole(pstConsole, recupAdresse);
		
		if (pstClient->enFrequentation == TRES_REGULIER)
		{
			printf("\nSTATUT: TRES REGULIER\n\n");
		}
		else if (pstClient->enFrequentation == REGULIER)
		{
			printf("\nSTATUT: REGULIER\n\n");
		}
		else if (pstClient->enFrequentation == OCCASIONNEL)
		{
			printf("\nSTATUT: OCCASIONNEL\n\n");
		}
		else
		{
			printf("Erreur dans le status de frequentation\n");
		}
		return dClientVide = 0;
	}
	else
	{
		return dClientVide = 1;
	}
		
}