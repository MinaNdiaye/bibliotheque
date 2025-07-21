
void afficherStatistiques() {
    int dispo = 0, occupe = 0;
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].emprunte) occupe++;
        else dispo++;
    }
    printf("Total : %d\nDisponibles : %d\nEmpruntes : %d\n", nbLivres, dispo, occupe);
}
