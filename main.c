#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

// Declaration des diff�rentes proc�dures
void transaction();
void accueil();
void aide();
void configuration();
void commencer();
void netoyage();


// Proc�dure aide qui contient les informations sur l'application (programme)
void aide() {
    netoyage();
    printf("\n=== Aide ===\n");
    printf("Description de l'application: UDBL - DACTYLOGICIEL\n");
    printf("Version: 1.0\n");
    printf("Concepteurs:\n\tMONGA-ILUNGA GRACIA\n\tMONGA-SEYA GRANEL\n\tMOZA-FATUMA BENEDICTE\n\tMPENGE-MULUMBU LOIS\n");
    printf("Date de conception: Juin/2024\n");
    printf("Autres informations...\n");
    printf("\nAppuyez sur une touche pour retourner au menu principal...\n");
    getchar();
    getchar();
}
