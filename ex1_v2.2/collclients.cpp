#include <iostream>
#include "collclients.h"


int isTabFull(struct etCollClient* pstCollClient)
{
	if (pstCollClient->dNbreClient < TAILLETAB_CLIENT)
		{
		return PLACE_DISPONIBLE;
		}
	else 
		return TABLEAU_PLEIN;
}

/************************************************************************
dNbreClient représente le nbre de client inscrit dans le tableau
mais aussi l'indice de la place du prochain client libre dans le tableau
ex j'ai 2 clients donc occupent les tab[0] et tab[1]
donc tab[2] est libre
************************************************************************/
int PlaceTabDispo(struct etCollClient* pstCollClient)
{
	return pstCollClient->dNbreClient;
}