
#ifndef examen2ndsemestre_H
#define examen2ndsemestre_H

#define MAX 100

typedef struct {
    char titre[100];
    char auteur[100];
    int annee;
    int isbn;
    int emprunte;
} Livre;

typedef struct {
    int isbn;
    char nom_eleve[100];
    char date[11];
} Emprunt;

void ajouterLivre();
void afficherLivres();
void rechercherLivre();
void supprimerLivre();
void emprunterLivre();
void retournerLivre();
void afficherStatistiques();

#endif
