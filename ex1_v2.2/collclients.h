#pragma once
#include "client.h"
#define SUCCES 0
#define LISTE_VIDE 1
#define PLACE_DISPONIBLE_AJOUT_EN_COURS 2
#define TABLEAU_PLEIN 3

#define TAILLETAB_CLIENT 20

struct etCollClient
{
	struct etClient tClients[TAILLETAB_CLIENT];
	int dNbreClient;

};

void initCollClient(struct etCollClient* pstCollClient);

// Vérifie si place libre
int isTabFull(struct etCollClient* pstCollClient);

int isTabEmpty(struct etCollClient* pstCollClient);

int AjouterClient(struct etCollClient* pstCollClient, char sAjoutNom[], char sAjoutPrenom[], char sAjoutAdresse[], enum etStatClient enStatut);

void AfficherCollClient(struct etCollClient* pstCollClient, struct etConsole* pstConsole);

int SupprimerClient(struct etCollClient* pstCollClient, int ClientASupp);

void VideBuffer();

int GetNbreClient(struct etCollClient* pstCollClient);