#include <stdio.h>
#include "Expo.h"

int main() {
    int choix;
    do {
        printf("\n=== MENU BIBLIOTHEQUE ===\n");
        printf("1. Ajouter un livre\n2. Afficher tous les livres\n3. Rechercher un livre\n4. Supprimer un livre\n5. Emprunter un livre\n6. Retourner un livre\n7. Afficher les statistiques\n0. Quitter\nChoix : ");
        scanf("%d", &choix); getchar();
        switch (choix) {
            case 1: ajouterLivre();
             break;
            case 2: afficherLivres();
             break;
            case 3: rechercherLivre();
             break;
            case 4: supprimerLivre();
             break;
            case 5: emprunterLivre();
             break;
            case 6: retournerLivre(); 
            break;
            case 7: afficherStatistiques();
             break;
        }
    } while (choix != 0);
    return 0;
}
