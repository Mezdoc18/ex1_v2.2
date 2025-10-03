#pragma once
#include "client.h"
#define LISTE_VIDE 1
#define TABLEAU_PLEIN 3

#define TAILLETAB_CLIENT 20

struct etCollClient
{
	struct etClient tClients[TAILLETAB_CLIENT];
	int dNbreClient;

};

// V�rifie si place libre et retourne la prochaine place de dispo pour un nouveau client
int isTabPleinAndNumber(struct etCollClient* pstCollClient);