#include <stdio.h>
#include <string.h>
#include "Expo.h"

Livre T[MAX];
int nbLivres = 0;
void ajouterLivre() {
    if (nbLivres >= MAX) return;
    printf("Titre : ");
    gets(T[nbLivres].titre);
    printf("Auteur : ");
    gets(T[nbLivres].auteur);
    printf("Annee : "); scanf("%d", &T[nbLivres].annee);
    printf("ISBN : "); scanf("%d", &T[nbLivres].isbn); getchar();
    nbLivres++;
}

void emprunterLivre() {
    int isbn;
    printf("ISBN du livre a emprunter : ");
    scanf("%d", &isbn);
    getchar();

    for (int i = 0; i < nbLivres; i++) {
        if (T[i].isbn == isbn) {
            if (T[i].emprunte == 1) {
                printf("Ce livre est deja emprunte.\n");
                return;
            }

            T[i].emprunte = 1;
            Tab[nbEmprunts].isbn = isbn;

            printf("Nom de l'eleve : ");
            scanf(" %[^\n]", Tab[nbEmprunts].nom_eleve);

            printf("Date (jj/mm/aaaa) : ");
            scanf(" %[^\n]", Tab[nbEmprunts].date);

            printf("%s a emprunte le livre \"%s\" le %s.\n",Tab[nbEmprunts].nom_eleve, T[i].titre, Tab[nbEmprunts].date);
            nbEmprunts++;
            printf("Livre emprunte avec succes.\n");
            return;
        }
    }
    printf("Livre introuvable.\n");
}

void retournerLivre() {
    int isbn;
    printf("ISBN du livre à retourner : ");
    scanf("%d", &isbn);
    getchar();
    for (int i = 0; i < nbLivres; i++) {
        if (T[i].isbn == isbn) {
            if (T[i].emprunte == 0) {
                printf("Ce livre n'est pas emprunter.\n");
                return;
            }
            T[i].emprunte = 0;
            for (int j = 0; j < nbEmprunts; j++) {
                if (Tab[j].isbn == isbn) {
                    for (int k = j; k < nbEmprunts - 1; k++) {
                        Tab[k] = Tab[k + 1];
                    }
                    nbEmprunts--;
                    break;
                }
            }
            printf("Livre retourner avec succes.\n");
            return;
        }
    }
printf("Livre introuvable.\n");
}

void afficherLivres() {
    for (int i = 0; i < nbLivres; i++) {
        printf("%d. %s - %s (%d) ISBN: %d\n", i+1, T[i].titre, T[i].auteur, T[i].annee, T[i].isbn);
        if (T[i].emprunte == 1) {
    printf("Emprunte");
} else {
    printf("Disponible");
}

    }
}
void rechercherLivre() {
    char recherche[100];
    int choix;
    int trouve = 0;
    puts("1. Par titre");
    puts("2. Par auteur");
    getchar();
    puts("Choix : ");
    scanf("%d", &choix);
    printf("Recherche : ");
    fflush(stdin);
    gets(recherche);
    for (int i = 0; i < nbLivres; i++) {
        if ((choix == 1 && strcasecmp(T[i].titre, recherche) == 0) ||
            (choix == 2 && strcasecmp(T[i].auteur, recherche) == 0)) {
            printf("%s - %s (%d) ISBN: %d ", T[i].titre, T[i].auteur, T[i].annee, T[i].isbn);
            trouve = 1;
        }
    }
            fflush(stdin);
    if(!(trouve)){
        printf("\nAucun livre ne correspond a votre recherche ATTOISSE Mohamed.");
        }
}

void supprimerLivre() {
    int isbn;
    printf("ISBN du livre a supprimer : ");
    scanf("%d", &isbn);
    getchar();

    for (int i = 0; i < nbLivres; i++) {
        if (T[i].isbn == isbn) {
            for (int j = i; j < nbLivres - 1; j++) {
                T[j] = T[j + 1];
            }
            nbLivres--;
            break;
        }
    }
}