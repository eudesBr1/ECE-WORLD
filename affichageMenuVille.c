//
// Created by eudes on 23/04/2023.
//
#include "Mabibli.h"
#define largeurPersonnage1 35
#define hauteurPersonnage1 45
#define largeurPersonnage2 40
#define hauteurPersonnage2 55
void affichageVille(t_player *player,t_player *player2){
    BITMAP *buffer= create_bitmap(screen->w,screen->h);
    clear(buffer);
    BITMAP *carte;
    /// charge carte ville
    carte = load_bitmap("../images/map_pokemon.bmp",NULL);
    if (!carte){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    stretch_sprite(screen,player2->haut[player2->animation/10 %qtAnim],player2->x,player2->y,largeurPersonnage2,hauteurPersonnage2);
    while (!key[KEY_ESC]){
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        blit(carte,buffer,player->x,player->y,0,0,screen->w,screen->h);
        mouvementPersonnageZQSD(player);
        mouvementPersonnageFleche(player2);
        // affiche personnage sur carte
        if (player->position==0){
            stretch_sprite(buffer,player->haut[player->animation/10 %qtAnim],player->x,player->y,largeurPersonnage1,hauteurPersonnage1);
        }
        if (player->position==1){
            stretch_sprite(buffer,player->droite[player->animation/10 %qtAnim],player->x,player->y,largeurPersonnage1,hauteurPersonnage1);
        }
        if (player->position==2){
            stretch_sprite(buffer,player->bas[player->animation/10 %qtAnim],player->x,player->y,largeurPersonnage1,hauteurPersonnage1);
        }
        if (player->position==3){
            stretch_sprite(buffer,player->gauche[player->animation/10 %qtAnim],player->x,player->y,largeurPersonnage1,hauteurPersonnage1);
        }
        ///affichage joueur 2 ville
        if (player2->position==0){
            stretch_sprite(buffer,player2->haut[player2->animation/10 %qtAnim],player2->x,player2->y,largeurPersonnage2,hauteurPersonnage2);
        }
        if (player2->position==1){
            stretch_sprite(buffer,player2->droite[player2->animation/10 %qtAnim],player2->x,player2->y,largeurPersonnage2,hauteurPersonnage2);
        }
        if (player2->position==2){
            stretch_sprite(buffer,player2->bas[player2->animation/10 %qtAnim],player2->x,player2->y,largeurPersonnage2,hauteurPersonnage2);
        }
        if (player2->position==3){
            stretch_sprite(buffer,player2->gauche[player2->animation/10 %qtAnim],player2->x,player2->y,largeurPersonnage2,hauteurPersonnage2);
        }
        printf("%d\n",player->animation %qtAnim);
        rest(20);
        if (key[KEY_SPACE]) game_GUITARE(player);
        if (key[KEY_H]) courseHippique(player);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(carte);
    for (int i = 0; i < 4; ++i) {
        destroy_bitmap(player->droite[i]);
        destroy_bitmap(player->gauche[i]);
        destroy_bitmap(player->haut[i]);
        destroy_bitmap(player->bas[i]);
    }
}