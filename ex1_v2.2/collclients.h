#pragma once
#include "client.h"
#define LISTE_VIDE 1

#define TAILLETAB_CLIENT 20

struct etCollClients
{
	struct etClient tClients[TAILLETAB_CLIENT];
	int dNbreClients;

};

// setters

void InitCollClients(struct etCollClients* pstCollCl);

int SetNouveauClient(struct etCollClients* pstCollCl);