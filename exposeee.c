#include <stdio.h>
#include <string.h>
#include "Expo.h"

Livre livres[MAX];
Emprunt emprunts[MAX];
int nbLivres = 0;
int nbEmprunts = 0;

void ajouterLivre() {
    if (nbLivres >= MAX) return;
    printf("Titre : ");
    gets(livres[nbLivres].titre);
    printf("Auteur : ");
    gets(livres[nbLivres].auteur);
    printf("Annee : "); scanf("%d", &livres[nbLivres].annee);
    printf("ISBN : "); scanf("%d", &livres[nbLivres].isbn); getchar();
    livres[nbLivres].emprunte = 0;
    nbLivres++;
}

void afficherLivres() {
    for (int i = 0; i < nbLivres; i++) {
        printf("%d. %s - %s (%d) ISBN: %d - %s\n", i+1, livres[i].titre, livres[i].auteur, livres[i].annee, livres[i].isbn);
        if (livres[i].emprunte == 1) {
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
    printf("1. Par titre\n2. Par auteur\nChoix : ");
    scanf("%d", &choix); getchar();
    printf("Recherche : "); fgets(recherche, 100, stdin);
    recherche[strcspn(recherche, "\n")] = 0;
    for (int i = 0; i < nbLivres; i++) {
        if ((choix == 1 && strcmp(livres[i].titre, recherche) == 0) ||
            (choix == 2 && strcmp(livres[i].auteur, recherche) == 0)) {
            printf("%s - %s (%d) ISBN: %d - %s\n", livres[i].titre, livres[i].auteur, livres[i].annee, livres[i].isbn, livres[i].emprunte ? "Emprunte" : "Disponible");
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun livre ne correspond a la recherche.\n");
    }
}

void supprimerLivre() {
    int isbn;
    printf("ISBN du livre a supprimer : ");
     scanf("%d", &isbn);
     getchar();
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].isbn == isbn) {
            for (int j = i; j < nbLivres - 1; j++) {
                livres[j] = livres[j + 1];
            }
            nbLivres--;
            break;
        }
    }
}

void emprunterLivre() {
    if (nbEmprunts >= MAX)
    return;
    int isbn;
    printf("ISBN du livre a emprunter : ");
    scanf("%d", &isbn);
    getchar();
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].isbn == isbn && livres[i].emprunte == 0) {
            livres[i].emprunte = 1;
            emprunts[nbEmprunts].isbn = isbn;
            printf("Nom de l'eleve : ");
            gets(emprunts[nbEmprunts].nom_eleve);
//             emprunts[nbEmprunts].nom_eleve[strcspn(emprunts[nbEmprunts].nom_eleve, "\n")] = 0;
            printf("Date (jj/mm/aaaa) : ");
//            gets(emprunts[nbEmprunts].date); emprunts[nbEmprunts].date[strcspn(emprunts[nbEmprunts].date, "\n")] = 0;
            nbEmprunts++;
            break;
        }
    }
}

void retournerLivre() {
    int isbn;
    printf("ISBN du livre retourne : "); scanf("%d", &isbn); getchar();
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].isbn == isbn && livres[i].emprunte == 1) {
            livres[i].emprunte = 0;
            for (int j = 0; j < nbEmprunts; j++) {
                if (emprunts[j].isbn == isbn) {
                    for (int k = j; k < nbEmprunts - 1; k++) {
                        emprunts[k] = emprunts[k + 1];
                    }
                    nbEmprunts--;
                    break;
                }
            }
            break;
        }
    }
}

void afficherStatistiques() {
    int dispo = 0, occupe = 0;
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].emprunte) occupe++;
        else dispo++;
    }
    printf("Total : %d\nDisponibles : %d\nEmpruntes : %d\n", nbLivres, dispo, occupe);
}
