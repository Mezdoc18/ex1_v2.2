#include <iostream>
#include <string.h>
#include "collclients.h"

void InitCollClients(struct etCollClients* pstCollCl)
{
	pstCollCl->dNbreClients = 0;
}

int SetNouveauClient(struct etCollClients* pstCollCl)
{
	// dNbreclients correspond au nbre de clients encod�s MAIS correspond �galement en tant qu'indice � la prochaine place libre dans le tab
	int dI = pstCollCl->dNbreClients;
		

	//s'il reste de la place dans le tableau
	if (dI < TAILLETAB_CLIENT )
	{
	

	}
}