#include "Mabibli.h"

void affichage(int y, float x, BITMAP *buffer, BITMAP *symbole_3,BITMAP *background, int ticket) {
    blit(symbole_3, buffer, 0, 0, x, y, symbole_3->w, symbole_3->h);
    //stretch_blit(background,buffer,0,0,background->w,background->h,0,0,symbole_3->w,symbole_3->h);
  //stretch_sprite(symbole_3,buffer,0,0,symbole_3->w,symbole_3->h);
    rectfill(buffer, 0, 0, screen->w, 349, makeacol(177, 60, 255, 250));
    rectfill(buffer, 1200, 349, screen->w, screen->h, makeacol(177, 60, 255, 250));
    /*rectfill(buffer, 1000, 0, 0, 300, makecol(22, 16, 16));
    rectfill(buffer, 1000, 500, 0, 700, makecol(22, 16, 16));
    rectfill(buffer, 300, 0, 0, 1200, makecol(22, 16, 16));
    rectfill(buffer, 700, 0, 1000, 1200, makecol(22, 16, 16));
    rectfill(buffer, 300, 500, 700, 1200, makecol(22, 16, 16));*/
   masked_blit(background, buffer, 0, 0, 0, 50, background->w, background->h);
    textprintf_ex(buffer,font,550,20, makecol(255,255,255),-1, "TICKET: %d" ,ticket);

    //stretch_blit(background,buffer,0,0,background->w,background->h,0,0,screen->w,screen->h);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    //stretch_sprite(background,buffer,0,0,background->w,background->h);
}

void defilement(  float position_actuelle, int x, BITMAP *buffer, BITMAP *symbole_3, BITMAP *background ,int ticket) {


    for (int j = 0; j <46 ; ++j) {
        position_actuelle = position_actuelle+2*j;
        affichage(position_actuelle, x, buffer, symbole_3, background, ticket);
        rest(50);
        //printf("%f\n",position_actuelle);
    }
    for (int g = 46; g>0  ; --g) {
        position_actuelle = position_actuelle+2*g;
        //printf("lol");
        affichage(position_actuelle, x, buffer, symbole_3, background, ticket);
        rest(50);
        //printf("%f\n",position_actuelle);
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
    if (!symbole_3) {
        allegro_message("Pb de l'image win");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    int position0 = -4425;
    int position1 = -4380;
    int position2 = -4337;
    int position3 = -4303;
    int position4 = -4260;
    int position5 = -4215;
    int position[] = {position0, position1, position2, position3, position4, position5};

    int resultat_position0 = 5;
    int resultat_position1 = 163;
    int resultat_position2 = 320;

    int resultat_position[] = {resultat_position0, resultat_position1, resultat_position2 };


    float position_actuelle1 = 0;
    float position_actuelle2 = 0;
    float position_actuelle3 = 0;
    int boucle = 0;
    int finition, finition2, finition3;

    int arret = 0;
    int ticket = 5;
    int ticketboucle = 1;
    int ticketboucle2 = 1;
    int x1 = 443;
    int x2 = 681;
    int x3 = 926;

    //stretch_blit(background, screen, 0, 0, background->w, background->h, 0, 0, screen->w, screen->h);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    //stretch_blit(buffer,screen,0,0,buffer->w,buffer->h,0,0,screen->w,screen->h)
    while (!key[KEY_ESC]) {
        clear(buffer);

        while (boucle == 0 && arret == 0) {
            //printf("%d",boucle);
            if (key[KEY_ESC]) {
                break;
            }


            int random1 = rand() % 6;
            position_actuelle1 = position[1];
            affichage(position_actuelle1, x1, buffer, symbole_3, background, ticket);
            random1 = rand() % 6;
            position_actuelle2 = position[1];
            affichage(position_actuelle2, x2, buffer, symbole_3, background, ticket);
            random1 = rand() % 6;
            position_actuelle3 = position[1];
            affichage(position_actuelle3, x3, buffer, symbole_3, background, ticket);
            boucle = 1;
            ticketboucle2 = ticketboucle;
            printf("1");

            //stretch_blit(background, buffer, 0, 0, background->w, background->h, 0, 0, screen->w, screen->h);
            blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
        }
        while (ticketboucle == ticketboucle2) {
            if (key[KEY_ESC]) {
                break;
            }
            while (boucle == 1 && !key[KEY_ESC]) {

                if (key[KEY_J]) {
                    // printf("lol");
                    int resultat = rand() % 3;
                    finition = resultat_position[resultat];
                    resultat = rand() % 3;
                    printf("%d\n", finition);
                    finition2 = resultat_position[resultat];
                    resultat = rand() % 3;
                    printf("%d\n", finition2);
                    finition3 = resultat_position[resultat];
                    printf("%d\n", finition3);

                    position_actuelle1 = position_actuelle1 + finition;
                    position_actuelle2 = position_actuelle2 + finition2;
                    position_actuelle3 = position_actuelle3 + finition3;
                    printf("zebi");

                    defilement(position_actuelle1, x1, buffer, symbole_3, background, ticket);
                    //affichage(finition, x1, buffer, symbole_3, background, ticket);
                    defilement(position_actuelle2, x2, buffer, symbole_3, background, ticket);
                    //affichage(finition2, x2, buffer, symbole_3, background, ticket);
                    defilement(position_actuelle3, x3, buffer, symbole_3, background, ticket);
                    //affichage(finition3, x3, buffer, symbole_3, background, ticket);
                    printf("lola");
                    boucle = 2;
                }
            }
                while (boucle == 2) {

                    if (finition == finition2 || finition3 == finition2 || finition == finition3) {
                        if (finition == finition2 && finition3 == finition2) {
                            ticket=ticket+1;
                            printf("you won");
                            for (int p=0; p<50; p++) {
                                masked_blit(win, buffer, 0, 0, (background->w/2), (background->h/2), buffer->w, buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(50);
                                //masked_blit(background, buffer, 0, 0, (background->w/2), 385-(background->h/2), buffer->w, buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(50);
                            }

                        } else {
                            printf("you nearly won\n");

                        }
                    } else {
                        printf("too bad\n");
                        ticket=ticket-1;
                    }
                    affichage(0, 0, buffer, symbole_3, background, ticket);
                    boucle = 3;

                    printf("kilo\n");
                }
                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                printf("howard\n");
                while (boucle==3) {

                    if (key[KEY_E]) {
                        printf("cr7");
                        boucle = 0;
                        ticketboucle2=0;

                    }
                    else{
                        boucle=1;
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