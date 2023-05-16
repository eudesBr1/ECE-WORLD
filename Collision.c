//
// Created by antoi on 26/04/2023.
//
#include "Mabibli.h"


int collision(t_player perso,BITMAP *fond){



    int x = perso.x*1000/1920;
    int y = perso.y*920/1080;
    int w = W_PERSO*1000/1920;
    int hauteur = H_PERSO*920/1080;


    int h = getpixel(fond,x+w/2,y);
    int d = getpixel(fond,x+w,y+hauteur/2);
    int b = getpixel(fond,x+w/2,y+hauteur);
    int g = getpixel(fond,x,y+hauteur/2);

    int noir = makecol(0,0,0);

    int renvoie = 1;


   // printf("%d/%d\t %d/%d/%d/%d/%d\n",x,y,noir,h,d,b,g);

    //multiple de 3 si le personnage peut monter
    //multiple de 5 si le personnage peut aller a droite
    //multiple de 7 si le personnage peut descendre
    //multiple de 11 si le personnage peut aller a gauche


    if (h != noir)
        renvoie = renvoie*3;
    if (d != noir)
        renvoie = renvoie*5;
    if (b != noir)
        renvoie = renvoie*7;
    if (g != noir)
        renvoie = renvoie*11;


    return renvoie;
}