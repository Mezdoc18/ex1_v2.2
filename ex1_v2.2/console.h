#pragma once
enum etChoixMenu
{
	AJOUT_CLIENT = 1,
	SUPP_CLIENT,
	AFFICH_LISTE,
	AFFICH_FREQU,
	QUITTER
};

struct etConsole
{
	int evitwarning = 0;
};

void InitConsole(struct etConsole* pConsole);

void AffichageConsole(struct etConsole* pConsole, const char* string);

int LireIntConsole(struct etConsole* pConsole);

void LireTabCharConsole(struct etConsole* pConsole, char* tResultLect, const int dTailleMaxBuffer);

void VideBuffer();