
//
// Created by eudes on 23/04/2023.
//
#include "Mabibli.h"

void affichageVille(t_player player){
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
    while (!key[KEY_ESC]){
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        blit(carte,buffer,player.x,player.y,0,0,screen->w,screen->h);
        mouvementPersonnageZQSD(&player);
        //   mouvementPersonnageFleche(&goku);
        /// affiche personnage sur carte
        if (player.position==0){
            draw_sprite(buffer,player.haut[player.animation/10],player.x,player.y);
        }
        if (player.position==1){
            draw_sprite(buffer,player.droite[player.animation/10],player.x,player.y);
        }
        if (player.position==2){
            draw_sprite(buffer,player.bas[player.animation/10],player.x,player.y);
        }
        if (player.position==3){
            draw_sprite(buffer,player.gauche[player.animation/10],player.x,player.y);
        }
        rest(9);
        if (key[KEY_SPACE]) ballon(player,buffer);
    }
}