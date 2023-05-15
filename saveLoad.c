//
// Created by eudes on 15/05/2023.
//
#include "Mabibli.h"
void sauvegarde(t_player *player){
    FILE *fichierSave= fopen("sauvegardeJoueur.txt","w");
    if (fichierSave == NULL){
        printf("fichier save non ouvert");
        return;
    }
    for (int i = 0; i < player[0].nbJoueurs; ++i) {
        fprintf(fichierSave, "%d %d %d %d %d %s %d %d %d %d %d\n",
                player[i].x, player[i].y, player[i].ticket, player[i].points, player[0].nbJoueurs,
                player[i].name, player[i].position, player[i].animation, player[i].cheval,player[i].bitmap,player[i].perso_sur_bmp);
    }
}

t_player charger(){
    t_player player[4];
    FILE *fichierSave = fopen("sauvegardeJoueur.txt", "r");
    if (fichierSave == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
    for (int i = 0; i < 4; ++i) {
        fscanf(fichierSave, "%d %d %d %d %d %s %d %d %d %d %d",
               &player[i].x, &player[i].y, &player[i].ticket, &player[i].points, &player[i].nbJoueurs,
               player[i].name, &player[i].position, &player[i].animation, &player[i].cheval,&player[i].bitmap,&player[i].perso_sur_bmp);
    }
    fclose(fichierSave);
    return player[4];
}
