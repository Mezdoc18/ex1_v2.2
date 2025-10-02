#pragma once
#include "client.h"
#define LISTE_VIDE 1

#define TAILLETAB_CLIENT 20

struct etCollClients
{
	struct etClient tClients[TAILLETAB_CLIENT];
	int dNbreClientOccupe;

};