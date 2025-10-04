#pragma once
#define TAILLE_NOM 40
#define TAILLE_PRENOM 30
#define TAILLE_ADRESSE 80
enum etStatClient
{
	INCONNUE = 0,
	OCCASIONNEL,
	REGULIER,
	TRES_REGULIER
};



struct etClient
{
	int dNumClient;
	char sNom[TAILLE_NOM];
	char sPrenom[TAILLE_PRENOM];
	char sAdresse[TAILLE_ADRESSE];
	enum etStatClient enFrequentation;
};


// setters

void setclientNum(struct etClient* pstClient, int dNum);

void setClientNom(struct etClient* pstClient, char* NouveauNom);

void setClientPrenom(struct etClient* pstClient, char* NouveauPrenom);

void setClientAdresse(struct etClient* pstClient, char* NouvelleAdresse);

void setClientFrequentation(struct etClient* pstClient, enum etStatClient Frequentation);

// getters

int getClientNum(struct etClient* pstclient);

void getClientNom(struct etClient* pstClient, char* NomClient);

void getClientPrenom(struct etClient* pstClient, char* PrenomClient);

void getClientAdresse(struct etClient* pstClient, char* AdresseClient);

enum etStatClient getClientFrequentation(struct etClient* pstClient);

// fonctions autres

void LireDataNouvClientViaConsole(struct etClient* pstClient, int Index, struct etConsole* pstConsole);

void InitClient(struct etClient* pstClient, int dNumero, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut);

void SupprimerClient(struct etClient* pstClient);

int AfficherClient(struct etClient* pstClient, struct etConsole *pstConsole);

