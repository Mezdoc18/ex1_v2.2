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

void InitAJoutClient(struct etClient* pstClient, int dNumero, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut);

// getters

int getClientNum(struct etClient* pstclient);

void getClientNom(struct etClient* pstClient, char* NomClient);

void getClientPrenom(struct etClient* pstClient, char* PrenomClient);

void getClientAdresse(struct etClient* pstClient, char* AdresseClient);

enum etStatClient getClientFrequentation(struct etClient* pstClient);

// fonctions autres

void Supprimer(struct etClient* pstClient);

int AfficherClient(struct etClient* pstClient, struct etConsole *pstConsole);

