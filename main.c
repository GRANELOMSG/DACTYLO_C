#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

// Declaration des différentes procédures
void transaction();
void accueil();
void aide();
void configuration();
void commencer();
void netoyage();

// Global variable to store words
char mots[MAX_WORDS][WORD_LENGTH];
int wordCount = 0;
// La fonction principale
int main() {
    transaction();
    accueil();
    return 0;
}
//Procédure de transaction pour afficher les noms pendant quelque secondes et fait disparaitre
void transaction() {
    netoyage();
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\tUDBL - DACTYLOGICIEL\n\t\t\t\t\t====================\n");
    printf("MONGA-ILUNGA GRACIA\nMONGA-SEYA GRANEL\nMOZA-FATUMA BENEDICTE\nMPENGE-MULUMBU LOIS");
    sleep(5);  // L'affichage de 5 secondes
    netoyage();
}
// Procédure d'aceuill qui contient les différents menus a choisir
void accueil() {
    int choix;
    do {
        printf("\n=== Ecran d'Accueil ===\n");
        printf("1. Demarrer\n");
        printf("2. Configurer\n");
        printf("3. Aide\n");
        printf("4. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                commencer();
                break;
            case 2:
                configuration();
                break;
            case 3:
                aide();
                break;
            case 4:
                printf("Quitter l'application...\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 4);
}
// Procédure aide qui contient les informations sur l'application (programme)
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
// Procédure de configuration qui contient la base des données contenant les mots
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
// Procédure pour commencer le jeu
void commencer() {
    if (wordCount == 0) {
        printf("Veuillez d'abord configurer les mots.\n");
        return;
    }

    netoyage();
    printf("\n=== Demarrer le Jeu ===\n");
    int nbmots;
    printf("Entrez le nombre de mots a saisir dans la partie: ");
    scanf("%d", &nbmots);

    if (nbmots > wordCount) {
        printf("Nombre de mots disponibles insuffisant.\n");
        return;
    }

    char joueur1[50], joueur2[50];
    printf("Entrez le pseudo du joueur 1: ");
    scanf("%s", joueur1);
    printf("Entrez le pseudo du joueur 2: ");
    scanf("%s", joueur2);

    int joueur1Time = 0, joueur2Time = 0;
    char input[WORD_LENGTH];

    srand(time(NULL));

    // Joueur 1
    printf("\n%s, c'est a vous!\n", joueur1);
    for (int i = 0; i < nbmots; i++) {
        int randomIndex = rand() % wordCount;
        printf("Mot %d: %s\n", i + 1, mots[randomIndex]);

        clock_t startTime = clock();
        do {
            printf("Entrez le mot: ");
            scanf("%s", input);
        } while (strcmp(input, mots[randomIndex]) != 0);
        clock_t endTime = clock();

        joueur1Time += (int)(endTime - startTime) / CLOCKS_PER_SEC;
    }

    // Joueur 2
    printf("\n%s, c'est a vous!\n", joueur2);
    for (int i = 0; i < nbmots; i++) {
        int randomIndex = rand() % wordCount;
        printf("Mot %d: %s\n", i + 1, mots[randomIndex]);

        clock_t startTime = clock();
        do {
            printf("Entrez le mot: ");
            scanf("%s", input);
        } while (strcmp(input, mots[randomIndex]) != 0);
        clock_t endTime = clock();

        joueur2Time += (int)(endTime - startTime) / CLOCKS_PER_SEC;
    }

    // affichage de resultat
    printf("\nResultats:\n");
    printf("%s: %d secondes\n", joueur1, joueur1Time);
    printf("%s: %d secondes\n", joueur2, joueur2Time);
    if (joueur1Time < joueur2Time) {
        printf("Le joueur %s est plus rapide!\n", joueur1);
    } else if (joueur1Time > joueur2Time) {
        printf("Le joueur %s est plus rapide!\n", joueur2);
    } else {
        printf("Egalite parfaite!\n");
    }

    printf("Appuyez sur la touche (ENTER) pour retourner au menu principal...\n");
    getchar();
    getchar();
    netoyage();
}
// Procédure qui permet de nétoyer l'écran
void netoyage() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
