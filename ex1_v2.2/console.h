#pragma once

enum etChoixMenu
{
	INIT_CHOIX_MENU,
	AJOUT_CLIENT,
	SUPPRESSION_CLIENT,
	AFFICHAGE_CLIENT,
	EXIT_MENU
};
struct etConsole
{
	int evitwarning = 0;
};

void InitConsole(struct etConsole* pConsole);

void AffichageConsole(struct etConsole* pConsole, const char* string);

int LireIntConsole(struct etConsole* pConsole);

void LireTabCharConsole(struct etConsole* pConsole, char* tResultLect, const int dTailleMaxBuffer);