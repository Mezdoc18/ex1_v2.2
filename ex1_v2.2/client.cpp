#include <iostream>
#include <string.h>
#include "client.h"
#include "console.h"

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

void setClient(struct etClient* pstClient, int dNumero, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut)
{
	pstClient->dNumClient = dNumero;
	strcpy_s(pstClient->sNom, TAILLE_NOM, sAjoutNom);
	strcpy_s(pstClient->sPrenom, TAILLE_PRENOM, sAjoutPrenom);
	strcpy_s(pstClient->sAdresse, TAILLE_ADRESSE, sAjoutAdresse);
	pstClient->enFrequentation = enStatut;
}

void AjoutClient(struct etClient* pstClient, int Index, struct etConsole* pstConsole, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut)
{
	// Gestion NUMERO CLIENT
	//Choix ici d'une attribution automatique de 1 à 20

	int dNumClient = Index + 1;
	char sNumClient[12] = {'\0'};

	// transforme int en string
	_itoa_s(dNumClient, sNumClient, 10);
	AffichageConsole(pstConsole, "\nLe numero attribue au client est ");
	AffichageConsole(pstConsole, sNumClient);
	AffichageConsole(pstConsole, "\n");
	
	setClient(pstClient, dNumClient, sAjoutNom, sAjoutPrenom, sAjoutAdresse, enStatut);
}

void SupprimerClient(struct etClient* pstClient)
{
	int dNull = 0;
	char sNull[1] = { '\0' };

	pstClient->dNumClient = 0;
	strcpy_s(pstClient->sNom, sNull);
	strcpy_s(pstClient->sPrenom, sNull);
	strcpy_s(pstClient->sAdresse, sNull);
	pstClient->enFrequentation = INCONNUE;

}

void AfficherClient(struct etClient* pstClient, struct etConsole* pstConsole)
{
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

		AffichageConsole(pstConsole, "\nNOM: ");
		getClientPrenom(pstClient, recupPrenom);
		AffichageConsole(pstConsole, recupPrenom);

		AffichageConsole(pstConsole, "\nADRESSE: ");
		getClientAdresse(pstClient, recupAdresse);
		AffichageConsole(pstConsole, recupAdresse);
		
		if (pstClient->enFrequentation == TRES_REGULIER)
		{
			AffichageConsole(pstConsole, "\nSTATUT: TRES REGULIER\n\n");
		}
		else if (pstClient->enFrequentation == REGULIER)
		{
			AffichageConsole(pstConsole, "\nSTATUT: REGULIER\n\n");
		}
		else if (pstClient->enFrequentation == OCCASIONNEL)
		{
			AffichageConsole(pstConsole, "\nSTATUT: OCCASIONNEL\n\n");
		}
		else
		{
			printf("Erreur dans le status de frequentation\n");
		}
	}		
}

int AfficherClientParFrequentation(struct etClient* pstClient, struct etConsole* pstConsole, enum etStatClient enFrequentation)
{
	int dClientTrouve = 0;

	if (pstClient->dNumClient != 0 && pstClient->enFrequentation == enFrequentation)
	{
		char recupNum[12] = { '\0' };
		char recupNom[TAILLE_NOM] = { '\0' };
		char recupPrenom[TAILLE_PRENOM] = { '\0' };
		char recupAdresse[TAILLE_ADRESSE] = { '\0' };

		AffichageConsole(pstConsole, "\n");
		AffichageConsole(pstConsole, "NUM CLIENT: ");
		int dNumClient = getClientNum(pstClient);
		_itoa_s(dNumClient, recupNum, 10);
		AffichageConsole(pstConsole, recupNum);

		AffichageConsole(pstConsole, "\nNOM: ");
		getClientNom(pstClient, recupNom);
		AffichageConsole(pstConsole, recupNom);

		AffichageConsole(pstConsole, "\nPRENOM: ");
		getClientPrenom(pstClient, recupPrenom);
		AffichageConsole(pstConsole, recupPrenom);

		AffichageConsole(pstConsole, "\nADRESSE: ");
		getClientAdresse(pstClient, recupAdresse);
		AffichageConsole(pstConsole, recupAdresse);
		AffichageConsole(pstConsole, "\n\n");

		dClientTrouve = 1;
	}

	return dClientTrouve;
}