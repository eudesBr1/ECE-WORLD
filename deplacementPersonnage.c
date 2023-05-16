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



void mouvementPersonnageZQSD(t_player player[4],int numJoueur,int collision_res){




    if(key[KEY_A] && (collision_res%11==0)){
        player[numJoueur].x -= vitesse;
        player[numJoueur].position = 3;
        player[numJoueur].animation+=3;
        player[numJoueur].animation = player[numJoueur].animation % 29;

    }
    if(key[KEY_D] && (collision_res%5==0)){
        player[numJoueur].x += vitesse;
        player[numJoueur].position=1;
        player[numJoueur].animation+=3;
        player[numJoueur].animation = player[numJoueur].animation % 29;

    }
    if(key[KEY_W] && (collision_res%3==0)) {
        player[numJoueur].y -= vitesse;
        player[numJoueur].position=0;
        player[numJoueur].animation+=3;
        player[numJoueur].animation = player[numJoueur].animation % 29;

    }
    if(key[KEY_S] && (collision_res%7==0)){
        player[numJoueur].y += vitesse;
        player[numJoueur].position=2;
        player[numJoueur].animation+=3;
        player[numJoueur].animation = player[numJoueur].animation % 29;

    }
    if (!key[KEY_W] && !key[KEY_S] && !key[KEY_D] && !key[KEY_A]){
        player[numJoueur].animation=0;
    }

}