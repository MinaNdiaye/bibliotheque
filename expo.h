#ifndef EXPO_H
#define EXPO_H

#define MAX 100

typedef struct {
    char titre[100];
    char auteur[100];
    int annee;
    int isbn;
    int emprunte;
} Livre;

void ajouterLivre();

#endif
