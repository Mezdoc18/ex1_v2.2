#include <iostream>
#include <string.h>
#include "console.h"
#include "collclients.h"

void InitConsole(struct etConsole* pConsole)
{
    pConsole->evitwarning = 0;
}

void AffichageConsole(struct etConsole* pConsole, const char *string)
{
    printf("%s", string);
}

int LireIntConsole(struct etConsole* pConsole)
{
    int dTemp = 0;
    scanf_s("%d", &dTemp);
    VideBuffer();
    return dTemp;
}

void LireTabCharConsole(struct etConsole* pConsole, char *tResultLect, const int dTailleMaxBuffer)
{
    gets_s(tResultLect, dTailleMaxBuffer);  
}

void VideBuffer()
{
    char c = '\0';
    while (c = (getchar()) != '\n' && c != EOF);
}