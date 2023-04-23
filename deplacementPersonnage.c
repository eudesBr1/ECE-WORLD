//
// Created by eudes on 22/04/2023.
//
#include "Mabibli.h"

t_player mouvementPersonnage(t_player *player){
    if(key[KEY_LEFT]){
        player->x -= vitesse;
        player->position = 3;
        player->animation++;
        if (player->animation==30){
            player->animation=0;
        }
    }
    if(key[KEY_RIGHT]){
        player->x += vitesse;
        player->position=1;
        player->animation++;
        if (player->animation==30){
            player->animation=0;
        }
    }
    if(key[KEY_UP]) {
        player->y -= vitesse;
        player->position=0;
        player->animation++;
        if (player->animation==30){
            player->animation=0;
        }
    }
    if(key[KEY_DOWN]){
        player->y += vitesse;
        player->position=2;
        player->animation++;
        if (player->animation==30){
            player->animation=0;
        }
    }
    return *player;
}