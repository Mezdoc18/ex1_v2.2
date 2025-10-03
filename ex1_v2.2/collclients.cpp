#include <iostream>
#include "collclients.h"


int isTabPleinAndNumber(struct etCollClient* pstCollClient);
{
	if (pstCollClient->dNbreClient < TAILLETAB_CLIENT)
		{
			return pstCollClient->dNbreClient;
		}
	else 
		return TABLEAU_PLEIN;
}