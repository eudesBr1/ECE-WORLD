//
// Created by antoi on 21/04/2023.
//

#ifndef ECE_WORLD_MABIBLI_H
#define ECE_WORLD_MABIBLI_H

#endif //ECE_WORLD_MABIBLI_H

#include <stdlib.h>
#include <time.h>
#include "allegro.h"
#include <string.h>
#include <time.h>
#include "stdio.h"


#define NBticketStart 5
#define w_tuile screen->w/6
#define vitesse 2
#define qtAnim 40
#define TailleBalx 64
#define TailleBaly 192
#define h_tuile 200
#define avancAnim 1
#define tailleTab 4
typedef struct ballon{
    int x,y;            ///coordonées propre a chaque ballon
    BITMAP *img;        ///image du ballon en fonction de la couleur donnée
    int couleur;        ///couleur aléatoire pour chaque ballon
    int speed;          ///vitesse de chaque ballon aléatoire
    int countAnim;      /// animation pour l'explosion du ballon
    int alive;          /// 0 mort et 1 vivant
}t_ballon;

typedef struct player{
    int x,y,ticket,points,nbJoueurs;
    char name[16];
    BITMAP *haut[4];
    BITMAP *bas[4];
    BITMAP *droite[4];
    BITMAP *gauche[4];
    int position;
    int animation;
    int cheval;
}t_player;


typedef struct tuiles{
    BITMAP *tuiles[4][8];
    int couleur[4][8];
}t_tuiles;
void initEcran();
void gameInit(t_player players[4]);
void ballon(t_player *player);
int collision(t_player perso);
void game_GUITARE(t_player *players);
t_player mouvementPersonnageFleche(t_player *player);
t_player mouvementPersonnageZQSD(t_player *player);
t_player creationPersonnageGoku(t_player *player);
void affichageVille(t_player *players);
void courseHippique(t_player *player);
void debutCourse(t_player *player);
void game_PONG(t_player player[4],int numJoueur);
int coinFlip();