#include <iostream>
#include <string.h>
#include "client.h"

void setclientNum(struct etClient* pstClient, int dNum)
{
	pstClient->dNumClient = dNum;
}

void setClientNom(struct etClient* pstClient, char* NouveauNom)
{
	strcpy_s(pstClient->sNom, TAILLE_NOM, NouveauNom);
}

void setClientPrenom(struct etClient* pstClient, char* NouveauPrenom)
{
	strcpy_s(pstClient->sPrenom, TAILLE_PRENOM, NouveauPrenom);
}

void setclientAdresse(struct etClient* pstClient, char* NouvelleAdresse)

{
	strcpy_s(pstClient->sAdresse, TAILLE_ADRESSE, NouvelleAdresse);
}

void setClientFrequentation(struct etClient* pstClient, enum etStatClient Frequentation)
{
	pstClient->enFrequentation = Frequentation;
}

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
	setclientNum(pstClient, dNumero);
	setClientNom(pstClient, sAjoutNom);
	setClientPrenom(pstClient, sAjoutPrenom);
	setclientAdresse(pstClient, sAjoutAdresse);
	setClientFrequentation(pstClient, enStatut);
}