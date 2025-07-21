
void afficherStatistiques() {
    int dispo = 0, occupe = 0;
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].emprunte) occupe++;
        else dispo++;
    }
    printf("\n+--------------------+\n");
    printf("|   STATISTIQUES     |\n");
    printf("+--------------------+\n");
    printf("| Total       : %d |\n",nbLivres);
    printf("| Disponibles : %d |\n",dispo);
    printf("| Empruntés   : %d |\n",occupe);
    printf("+--------------------+\n");
}
