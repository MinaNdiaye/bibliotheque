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

