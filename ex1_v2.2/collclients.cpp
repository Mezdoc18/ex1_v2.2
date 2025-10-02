#include <iostream>
#include <string.h>
#include "collclients.h"

void InitCollClients(struct etCollClients* pstCollCl)
{
	pstCollCl->dNbreClients = 0;
}

int SetNouveauClient(struct etCollClients* pstCollCl)
{
	// dNbreclients correspond au nbre de clients encodés MAIS correspond également en tant qu'indice à la prochaine place libre dans le tab
	int dI = pstCollCl->dNbreClients;
		

	//s'il reste de la place dans le tableau
	if (dI < TAILLETAB_CLIENT )
	{
	

	}
}