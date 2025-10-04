#pragma once
#include "client.h"
#define LISTE_VIDE 1
#define PLACE_DISPONIBLE 2
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

int AjouterClientDansCollection(struct etCollClient* pstCollClient, struct etConsole* pstConsole);

void VideBuffer();