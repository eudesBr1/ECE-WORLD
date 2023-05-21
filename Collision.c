//
// Created by antoi on 26/04/2023.
//
#include "Mabibli.h"

void animation()
{
    for (int i = 2*screen->w/3; i > 0 ; i--)

    {
        circle(screen,screen->w/2+1,screen->h/2,i, makecol(0,0,0));
        circle(screen,screen->w/2,screen->h/2,i, makecol(0,0,0));
    }
}


int collision(t_player *perso,BITMAP *fond,int *numJoueur){



    int x = perso[*numJoueur].x*1000/1920;
    int y = perso[*numJoueur].y*920/1080;
    int w = W_PERSO*1000/1920;
    int hauteur = H_PERSO*920/1080;

    int foot = makecol(0,255,255);
    int course = makecol(165,255,127);
    int guitare = makecol(255,0,110);
    int pong = makecol(0,38,255);
    int jackpot = makecol(182,255,0);
    int tir = makecol(128, 128, 128);
    //int mario = makecol(255,55,55);



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

    ///maintenant on va chercher a voir si le joueur cherche a rentrer dans un jeux ( pour tous les jeux on rentre par en bas sauf pour la course de cheval ou on doit rentrer par la gauche vers la droite)

    if (h == foot)
    {
        renvoie = renvoie*17;
        if (key[KEY_E])
        {
            animation();
            penalty(perso);
            *numJoueur+=1;
        }
    }
    if (h == course)
    {
        renvoie = renvoie*17;
        if (key[KEY_E])
        {
            animation();
            courseHippique(perso);
            *numJoueur+=1;
        }
    }
    if (h == guitare)
    {
        renvoie = renvoie*17;
        if (key[KEY_E])
        {
            animation();
            game_GUITARE(&perso[*numJoueur]);
            *numJoueur+=1;
        }

    }
    if (h == pong)
    {
        renvoie = renvoie*17;
        if (key[KEY_E])
        {
            animation();
            game_PONG(perso,*numJoueur);
            *numJoueur+=1;
        }

    }
    if (h == tir)
    {
        renvoie = renvoie*17;
        if (key[KEY_E])
        {
            animation();
            ballon(perso);
            *numJoueur+=1;
        }

    }
    if (h == jackpot)
    {
        renvoie = renvoie*17;
        if (key[KEY_E])
        {
            animation();
            jackpot_game();
            *numJoueur+=1;
        }

    }

    return renvoie;
}