#pragma once

enum etStatClient
{
	OCCASIONNEL = 0,
	REGULIER,
	TRES_REGULIER
};



struct etClient
{
	int dNumClient;
	char sNom[40];
	char sPrenom[30];
	char sAdresse[80];
	enum etStatClient enFrequentation;
};

// setters

void setclientNum(struct etClient* pstClient, int dNum);

void setClientNom(struct etClient* pstClient, const char* NouveauNom);

void setClientPrenom(struct etClient* pstClient, const char* NouveauPrenom);

void setclientAdresse(struct etClient* pstClient, const char* NouvelleAdresse);

void setClientFrequentation(struct etClient* pstClient, enum etStatClient Frequentation);

// getters

int getClientNum(struct etClient* pstclient);

void getClientNom(struct etClient* pstClient, const char* NomClient);

void getClientPrenom(struct etClient* pstClient, const char* PrenomClient);

void getClientAdresse(struct etClient* pstClient, const char* AdresseClient);

enum etStatClient getClientFrequentation(struct etClient* pstClient);