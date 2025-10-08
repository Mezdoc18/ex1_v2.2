#pragma once
#include "client.h"

#define SUCCES 0
#define LISTE_VIDE 1
#define PLACE_DISPONIBLE 2
#define TABLEAU_PLEIN 3
#define ANNUL_SUPP 5

#define TAILLETAB_CLIENT 3

struct etCollClient
{
	struct etClient tClients[TAILLETAB_CLIENT];
	int dPlaceLibreClient;
	int dIDClient;

};

void initCollClient(struct etCollClient* pstCollClient);

// Vérifie si place libre
int isTabFull(struct etCollClient* pstCollClient);

int AjouterClientDansCollection(struct etCollClient* pstCollClient, struct etConsole* pstConsole);

void AfficherCollClient(struct etCollClient* pstCollClient, struct etConsole* pstConsole);

void AffichCollClientParFrequentation(struct etCollClient* pstCollClient, struct etConsole* pstConsole, enum etStatClient enChoixFrequ);

int SupprimerClientDeLaColl(struct etCollClient* pstCollClient, struct etConsole* pstConsole);

int GetNbreClient(struct etCollClient* pstCollClient);