//
// Created by antoi on 26/04/2023.
//
#include "Mabibli.h"


int collision(t_player *perso){
    BITMAP *fond;
    fond = load_bitmap("../images/map_collision.bmp",NULL);
    if (!fond){
        allegro_message("Pb de récupération de map_collision.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int x = (perso->x*1024/500);
    int y = (perso->y*1024/500);

    int h = getpixel(fond,x+10,y-3);
    int d = getpixel(fond,x+20,y+20);
    int b = getpixel(fond,x+10,y+40);
    int g = getpixel(fond,x,y+20);
    int noir = makecol(0,0,0);
    int renvoie = 1;
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