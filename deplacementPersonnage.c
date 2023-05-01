//
// Created by eudes on 22/04/2023.
//
#include "Mabibli.h"

t_player mouvementPersonnageFleche(t_player *player){
    if(key[KEY_LEFT]){
        player->x -= vitesse;
        player->position = 3;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if(key[KEY_RIGHT]){
        player->x += vitesse;
        player->position=1;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if(key[KEY_UP]) {
        player->y -= vitesse;
        player->position=0;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if(key[KEY_DOWN]){
        player->y += vitesse;
        player->position=2;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if (!key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_LEFT] && !key[KEY_RIGHT]){
        player->animation=0;
    }
    return *player;
}

t_player mouvementPersonnageZQSD(t_player *player){
    if(key[KEY_A] && (collision(player))%11 == 0){
        player->x -= vitesse;
        player->position = 3;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if(key[KEY_D] && (collision(player))%5 == 0){
        player->x += vitesse;
        player->position=1;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if(key[KEY_W] && (collision(player))%3 == 0) {
        player->y -= vitesse;
        player->position=0;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if(key[KEY_S] && (collision(player))%7 == 0){
        player->y += vitesse;
        player->position=2;
        player->animation++;
        if (player->animation==40){
            player->animation=0;
        }
    }
    if (!key[KEY_W] && !key[KEY_A] && !key[KEY_S] && !key[KEY_D]){
        player->animation=0;
    }
    return *player;
}