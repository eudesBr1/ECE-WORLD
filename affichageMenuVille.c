//
// Created by eudes on 23/04/2023.
//
#include "Mabibli.h"
#define largeurPersonnage1 35
#define hauteurPersonnage1 45
#define largeurPersonnage2 40
#define hauteurPersonnage2 55
void affichageVille(t_player *players){
    BITMAP *buffer= create_bitmap(screen->w,screen->h);
    clear(buffer);
    BITMAP *carte;
    /// charge carte ville
    printf("test\n");
    carte = load_bitmap("../images/map_pokemon.bmp",NULL);
    if (!carte){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    printf("test\n");
    stretch_sprite(screen,players[1].haut[players[1].animation/10 %qtAnim],players[1].x,players[1].y,largeurPersonnage2,hauteurPersonnage2);
    printf("test\n");
    while (!key[KEY_ESC]){
        printf("test\n");
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        blit(carte,buffer,players[0].x,players[0].y,0,0,screen->w,screen->h);
        printf("test\n");
        mouvementPersonnageZQSD(&players[0]);
        printf("test\n");
        mouvementPersonnageFleche(&players[1]);
        printf("test\n");

        // affiche personnage sur carte
        for (int i = 0; i < players[0].nbJoueurs; i++) {
            printf("test\n");
            if (players[i].position == 0) {
                stretch_sprite(buffer, players[i].haut[players[i].animation / 10 % qtAnim], players[i].x, players[i].y,
                               largeurPersonnage2, hauteurPersonnage2);
            }
            if (players[i].position == 1) {
                stretch_sprite(buffer, players[i].droite[players[i].animation / 10 % qtAnim], players[i].x,
                               players[i].y, largeurPersonnage2, hauteurPersonnage2);
            }
            if (players[i].position == 2) {
                stretch_sprite(buffer, players[i].bas[players[i].animation / 10 % qtAnim], players[i].x, players[i].y,
                               largeurPersonnage2, hauteurPersonnage2);
            }
            if (players[i].position == 3) {
                stretch_sprite(buffer, players[i].gauche[players[i].animation / 10 % qtAnim], players[i].x,
                               players[i].y, largeurPersonnage2, hauteurPersonnage2);
            }
        }
        rest(20);
        if (key[KEY_SPACE]) game_GUITARE(&players[0]);
        if (key[KEY_H]) courseHippique(&players[0]);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(carte);
    for (int i = 0; i < 4; ++i) {
        destroy_bitmap(players[1].droite[i]);
        destroy_bitmap(players[1].gauche[i]);
        destroy_bitmap(players[1].haut[i]);
        destroy_bitmap(players[1].bas[i]);
    }
}