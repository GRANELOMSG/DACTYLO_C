#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

// Proc�dure de configuration qui contient la base des donn�es contenant les mots
void configuration() {
    netoyage();
    printf("\n=== Configurer ===\n");
    printf("Entrez le nombre de mots a ajouter: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (wordCount < MAX_WORDS) {
            printf("Entrez le mot %d: ", wordCount + 1);
            scanf("%s", mots[wordCount]);
            wordCount++;
        } else {
            printf("Base de donnees de mots pleine.\n");
            break;
        }
    }
    printf("Configuration terminee. Appuyez sur la touche (ENTER) pour retourner au menu principal...\n");
    getchar();
    getchar();
}

