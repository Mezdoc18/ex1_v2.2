#include <iostream>
#include <string.h>
#include "client.h"

void setclientNum(struct etClient* pstClient, int dNum)
{
	pstClient->dNumClient = dNum;
}

void setClientNom(struct etClient* pstClient, const char* NouveauNom)
{
	strcpy_s(pstClient->sNom, sizeof(pstClient->sNom), NouveauNom);
}

void setClientPrenom(struct etClient* pstClient, const char* NouveauPrenom)
{
	strcpy_s(pstClient->sPrenom, sizeof(pstClient->sPrenom), NouveauPrenom);
}

void setclientAdresse(struct etClient* pstClient, const char* NouvelleAdresse)

{
	strcpy_s(pstClient->sAdresse, sizeof(pstClient->sAdresse), NouvelleAdresse);
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
	strcpy_s(NomClient, sizeof(NomClient), pstClient->sNom);
}

void getClientPrenom(struct etClient* pstClient, char* PrenomClient)
{
	strcpy_s(PrenomClient, sizeof(PrenomClient), pstClient->sNom);
}

void getClientAdresse(struct etClient* pstClient, char* AdresseClient)
{
	strcpy_s(AdresseClient, sizeof(AdresseClient), pstClient->sNom);
}

enum etStatClient getClientFrequentation(struct etClient* pstClient)
{
	return pstClient->enFrequentation;
}