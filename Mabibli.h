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


#define H_PERSO 32
#define W_PERSO 32
#define wTABscore 300

#define NBticketStart 5
#define w_tuile screen->w/6
#define vitesse 2
#define TAILLEMINICARTE_W 1000*2/20
#define TAILLEMINICARTE_H 920*2/20
#define qtAnim 40
#define POINTSpourGAGNER 10
#define TailleBalx 64
#define TailleBaly 192
#define h_tuile 200
#define H_BORDS 100
#define W_BORDS 30
#define SPEED_PONGISTES 15
#define RAYON 20
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
    int position;       ///0 haut, 1 droite, 2 bas, 3 gauche
    int animation;
    int cheval;
    int bitmap;
    int perso_sur_bmp;
}t_player;

typedef struct pong{
    int x,y;
    int point;
    int bx,by;
    int dx,dy;
    char *name;
}t_pong;

typedef struct ballonFootball{
    BITMAP *effet[6];
    float positionX;
    float positionY;
    int animation;
    float tailleBallon;
    float rapidite;
    int coin;
    float modificateur;
    float diminution;
}t_ballonFoot;

typedef struct gardienBut{
    BITMAP *position[14];
    float positionX;
    float positionY;
    int animation;
    int hauteur;
    int largeur;
    float elan;
    float dX;
    float dY;
    int arret;
    float modifieur;
}t_gardien;

typedef struct tuiles{
    BITMAP *tuiles[4][8];
    int couleur[4][8];
    int pressed[4][8];
}t_tuiles;



void initEcran();
void gameInit(t_player players[4]);
void ballon(t_player *player);
int collision(t_player perso,BITMAP *fond);
void game_GUITARE(t_player *players);
t_player mouvementPersonnageFleche(t_player *player);
void mouvementPersonnageZQSD(t_player player[4],int numJoueur,int collision_res);
t_player creationPersonnageGoku(t_player *player);
void affichageVille(t_player players[4]);
void courseHippique(t_player *player);
void debutCourse(t_player *player);
void jackpot_game();
void game_PONG(t_player player[4],int numJoueur);
int coinFlip();
void penalty(t_player *player);
void charger_skin(t_player players[4],int numJoueur);
void bougerGardien(t_gardien *gardien);
int choixAnimationGardien(t_gardien gardien,int b);
void actionPenalty(t_player *player,t_gardien *gardien, t_ballonFoot ballon,int b);
void finPenalty(t_player *player,t_gardien *gardien, t_ballonFoot *ballon,int b);
void sauvegarde(t_player *player);
void charger(t_player player[4]);