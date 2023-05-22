#include "Mabibli.h"

void affichage(int y, float x, BITMAP *buffer, BITMAP *symbole_3,BITMAP *background, int ticket)
///fonction permettant l a ffichage des images ainsi que le nombre de ticket
{
    blit(symbole_3, buffer, 0, 0, x, y, symbole_3->w, symbole_3->h);
    //stretch_blit(background,buffer,0,0,background->w,background->h,0,0,symbole_3->w,symbole_3->h);
  //stretch_sprite(symbole_3,buffer,0,0,symbole_3->w,symbole_3->h);
    rectfill(buffer, 0, 0, screen->w, 349, makeacol(177, 60, 255, 250));
    rectfill(buffer, 1200, 349, screen->w, screen->h, makeacol(177, 60, 255, 250));
   masked_blit(background, buffer, 0, 0, 0, 50, background->w, background->h);
    textprintf_ex(buffer,font,550,20, makecol(255,255,255),-1, "TICKET: %d" ,ticket);

    //stretch_blit(background,buffer,0,0,background->w,background->h,0,0,screen->w,screen->h);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    //stretch_sprite(background,buffer,0,0,background->w,background->h);
}


void defilement(  float coordonees_actuelle, int x, BITMAP *buffer, BITMAP *symbole_3, BITMAP *background ,int ticket)
///fonction permettant de defiler les symbole  a l aide d'une boucle d'accélération et une boucle de deceleration
{


    for (int j = 0; j <46 ; ++j) {///boucle d'accélération
        coordonees_actuelle = coordonees_actuelle+2*j;
        affichage(coordonees_actuelle, x, buffer, symbole_3, background, ticket);
        rest(50);
        //printf("%f\n",coordonees_actuelle);
    }
    for (int g = 46; g>0  ; --g) {/// boucle de deceleration
        coordonees_actuelle = coordonees_actuelle+2*g;
        //printf("lol");
        affichage(coordonees_actuelle, x, buffer, symbole_3, background, ticket);
        rest(50);
        //printf("%f\n",coordonees_actuelle);
    }

}

void jackpot_game() {
    BITMAP *background;
    BITMAP *buffer;
    buffer = create_bitmap(screen->w, screen->h);
    background = load_bitmap("../images/background.bmp", NULL);
    if (!background) {
        allegro_message("Pb de l'image background");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *symbole_1;
    symbole_1 = load_bitmap("../images/symbole_1.bmp", NULL);
    if (!symbole_1) {
        allegro_message("Pb de l'image symbole");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *symbole_2;
    symbole_2 = load_bitmap("../images/symbole_2.bmp", NULL);
    if (!symbole_2) {
        allegro_message("Pb de l'image symbole 2");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *symbole_3;
    symbole_3 = load_bitmap("../images/symbole_3.bmp", NULL);
    if (!symbole_3) {
        allegro_message("Pb de l'image symbole 3");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *win;
    win = load_bitmap("../images/win.bmp", NULL);
    if (!win) {
        allegro_message("Pb de l'image win");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *win2;
    win2 = load_bitmap("../images/win2.bmp", NULL);
    if (!win2) {
        allegro_message("Pb de l'image win2");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *lose;
    lose= load_bitmap("../images/lose.bmp", NULL);
    if (!lose) {
        allegro_message("Pb de l'image lose");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *debut;
    debut= load_bitmap("../images/debut.bmp", NULL);
    if (!debut) {
        allegro_message("Pb de l'image debut");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

///coordonées de depart des symboles
    int coordonees0 = -4425;
    int coordonees1 = -4380;
    int coordonees2 = -4337;
    int coordonees3 = -4303;
    int coordonees4 = -4260;
    int coordonees5 = -4215;
    int coordonees[] = {coordonees0, coordonees1, coordonees2, coordonees3, coordonees4, coordonees5};
///coordonées d arrivés
    int resultat_coordonees0 = 5;
    int resultat_coordonees1 = 163;
    int resultat_coordonees2 = 320;

    int resultat_coordonees[] = {resultat_coordonees0, resultat_coordonees1, resultat_coordonees2 };


    float coordonees_actuelle1 = 0;
    float coordonees_actuelle2 = 0;
    float coordonees_actuelle3 = 0;
    int set = 0;
    int dest, dest2, dest3;

    int arret = 0;
    int ticket = 5;
    int ticketset = 1;
    int ticketset2 = 1;
    int x1 = 443;///absice
    int x2 = 681;
    int x3 = 926;

    //stretch_blit(background, screen, 0, 0, background->w, background->h, 0, 0, screen->w, screen->h);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    //stretch_blit(buffer,screen,0,0,buffer->w,buffer->h,0,0,screen->w,screen->h)
    while (!key[KEY_ESC]) {
        clear(buffer);

        while (set == 0 && arret == 0) {
            //printf("%d",set);
            if (key[KEY_ESC]) {
                break;
            }



            coordonees_actuelle1 = coordonees[1];
            affichage(coordonees_actuelle1, x1, buffer, symbole_3, background, ticket);

            coordonees_actuelle2 = coordonees[1];
            affichage(coordonees_actuelle2, x2, buffer, symbole_3, background, ticket);

            coordonees_actuelle3 = coordonees[1];
            affichage(coordonees_actuelle3, x3, buffer, symbole_3, background, ticket);
            set = 1;
            ticketset2 = ticketset;
            printf("1");

            //stretch_blit(background, buffer, 0, 0, background->w, background->h, 0, 0, screen->w, screen->h);
            blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);

        while (ticketset == ticketset2) {
            if (key[KEY_ESC]) {
                break;
            }

            while (set == 1 && !key[KEY_ESC]) {


                /*coordonees_actuelle1 = coordonees[1];
                affichage(coordonees_actuelle1, x1, buffer, symbole_3, background, ticket);

                coordonees_actuelle2 = coordonees[1];
                affichage(coordonees_actuelle2, x2, buffer, symbole_3, background, ticket);

                coordonees_actuelle3 = coordonees[1];
                affichage(coordonees_actuelle3, x3, buffer, symbole_3, background, ticket);*/

                stretch_sprite(buffer,debut,0,0,screen->w,screen->h);

                //masked_blit(debut, buffer, 0, 0, 500, 50, buffer->w,buffer->h);

                if (key[KEY_L]) {///pour quitter le jeu
                    printf("cr7");
                    set = 0;
                    ticketset2 = 0;

                }
                if (key[KEY_J]) {///pour lancer le jeu
                    // printf("lol");
                    clear(buffer);
                    coordonees_actuelle1 = coordonees[1];
                    affichage(coordonees_actuelle1, x1, buffer, symbole_3, background, ticket);

                    coordonees_actuelle2 = coordonees[1];
                    affichage(coordonees_actuelle2, x2, buffer, symbole_3, background, ticket);

                    coordonees_actuelle3 = coordonees[1];
                    affichage(coordonees_actuelle3, x3, buffer, symbole_3, background, ticket);
                    rest(1000);
                    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                    rest(200);
                    masked_blit(background, buffer, 0, 0, 0, 50, buffer->w, buffer->h);
                    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                    rest(100);
                    int resultat = rand() % 3;///coordonés d arrivé tiré aleatoiremnt afin d avoir des symbole aléatoire lors du jeu
                    dest = resultat_coordonees[resultat];
                    resultat = rand() % 3;
                    printf("%d\n", dest);
                    dest2 = resultat_coordonees[resultat];
                    resultat = rand() % 3;
                    printf("%d\n", dest2);
                    dest3 = resultat_coordonees[resultat];
                    printf("%d\n", dest3);

                    coordonees_actuelle1 = coordonees_actuelle1 + dest;
                    coordonees_actuelle2 = coordonees_actuelle2 + dest2;
                    coordonees_actuelle3 = coordonees_actuelle3 + dest3;
                    printf("zebi");

                    defilement(coordonees_actuelle1, x1, buffer, symbole_3, background, ticket);///appel de la fonction pour que les symboles defilent
                    //affichage(dest, x1, buffer, symbole_3, background, ticket);
                    defilement(coordonees_actuelle2, x2, buffer, symbole_3, background, ticket);
                    //affichage(dest2, x2, buffer, symbole_3, background, ticket);
                    defilement(coordonees_actuelle3, x3, buffer, symbole_3, background, ticket);
                    //affichage(dest3, x3, buffer, symbole_3, background, ticket);
                    printf("lola");
                    set = 2;
                }

                while (set == 2) {

                    if (dest == dest2 || dest3 == dest2 || dest == dest3) {
                        if (dest == dest2 && dest3 == dest2) {
                            ticket = ticket + 1;
                            printf("you won");
                            for (int p = 0; p < 23; p++) {///boucle d'affichage pour faire clignoter le message de fin
                                masked_blit(win2, buffer, 0, 0, 500, 50, buffer->w,
                                            buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(200);
                                masked_blit(background, buffer, 0, 0, 0, 50, buffer->w, buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(100);
                            }

                        } else {
                            for (int p = 0; p < 23; p++) {
                                masked_blit(lose, buffer, 0, 0, 450, 50, buffer->w,
                                            buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(200);
                                masked_blit(background, buffer, 0, 0, 0, 50, buffer->w, buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(100);
                            }

                        }
                    } else {
                        printf("too bad\n");
                        for (int p = 0; p < 23; p++) {
                            masked_blit(lose, buffer, 0, 0, 450, 50, buffer->w,
                                        buffer->h);
                            blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                            rest(200);
                            masked_blit(background, buffer, 0, 0, 0, 50, buffer->w, buffer->h);
                            blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                            rest(100);
                        }
                        ticket = ticket - 1;
                    }
                    affichage(0, 0, buffer, symbole_3, background, ticket);
                    set = 3;

                    printf("kilo\n");
                }
                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                printf("howard\n");
                while (set == 3) {


                        rest(3000);
                        set=1;///on repart au debut apres un petit temps d'attente pour relancer une game ou quitter


                }
            }
        }

            destroy_bitmap(background);
            destroy_bitmap(symbole_3);
            destroy_bitmap(buffer);
// Created by malik on 29/04/2023.
//
        }
    }
}