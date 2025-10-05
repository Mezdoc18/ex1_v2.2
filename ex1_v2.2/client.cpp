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

void InitClient(struct etClient* pstClient, int dNumero, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut)
{
	pstClient->dNumClient = dNumero;
	strcpy_s(pstClient->sNom, TAILLE_NOM, sAjoutNom);
	strcpy_s(pstClient->sPrenom, TAILLE_PRENOM, sAjoutPrenom);
	strcpy_s(pstClient->sAdresse, TAILLE_ADRESSE, sAjoutAdresse);
	pstClient->enFrequentation = enStatut;
}

void LireDataNouvClientViaConsole(struct etClient* pstClient, int Index, struct etConsole* pstConsole)
{
	// Gestion NUMERO CLIENT

	int dNumClient = Index + 1;
	char sNumClient[12] = {'\0'};

	_itoa_s(dNumClient, sNumClient, 10);
	AffichageConsole(pstConsole, "Le numero attribue au client est ");
	AffichageConsole(pstConsole, sNumClient);
	AffichageConsole(pstConsole, "\n");

	// Gestion NOM
	char sNomTemp[TAILLE_NOM] = { '\0' };
	AffichageConsole(pstConsole, "Quel est le nom du client? ");
	LireTabCharConsole(pstConsole, sNomTemp, TAILLE_NOM);

	// Gestion PRENOM
	char sPrenomTemp[TAILLE_PRENOM] = { '\0' };
	AffichageConsole(pstConsole, "Quel est le prenom du client? ");
	LireTabCharConsole(pstConsole, sPrenomTemp, TAILLE_PRENOM);

	// Gestion ADRESSE
	char sAdresseTemp[TAILLE_ADRESSE] = { '\0' };
	AffichageConsole(pstConsole, "Quelle est l'adresse du client? ");
	LireTabCharConsole(pstConsole, sAdresseTemp, TAILLE_ADRESSE);

	// Gestion FREQUENTATION
	int dFrequentation = 0;
	enum etStatClient enTemp = INCONNUE;

	AffichageConsole(pstConsole, "Quelle est la frequentation du client?\n");
	AffichageConsole(pstConsole, "OCCASIONNEL(1)\n");
	AffichageConsole(pstConsole, "REGULIER(2)\n");
	AffichageConsole(pstConsole, "TRES REGULIER(3)\n");

	do
	{
		switch (dFrequentation = LireIntConsole(pstConsole))
		{
		case 1:
			enTemp = OCCASIONNEL;
			break;

		case 2:
			enTemp = REGULIER;
			break;
		case 3:
			enTemp = TRES_REGULIER;
			break;
		default:
			AffichageConsole(pstConsole, "Erreur dans le choix:\n");
			AffichageConsole(pstConsole, "OCCASIONNEL(1)\n");
			AffichageConsole(pstConsole, "REGULIER(2)\n");
			AffichageConsole(pstConsole, "TRES REGULIER(3)\n\n");
			break;
		}
	} while (dFrequentation < 1 || dFrequentation >3);

	InitClient(pstClient, dNumClient, sNomTemp, sPrenomTemp, sAdresseTemp, enTemp);
}

void SupprimerClient(struct etClient* pstClient)
{
	int dNull = 0;
	char cNull = '\0';

	setclientNum(pstClient, dNull);
	setClientNom(pstClient, &cNull);
	setClientPrenom(pstClient, &cNull);
	setClientAdresse(pstClient, &cNull);
	setClientFrequentation(pstClient, INCONNUE);
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