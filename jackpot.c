#include "Mabibli.h"

void affichage(int y, float x, BITMAP *buffer, BITMAP *symbole_3,BITMAP *background, int ticket) {
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
    int set = 0;
    int finition, finition2, finition3;

    int arret = 0;
    int ticket = 5;
    int ticketset = 1;
    int ticketset2 = 1;
    int x1 = 443;
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


            int random1 = rand() % 6;
            position_actuelle1 = position[1];
            affichage(position_actuelle1, x1, buffer, symbole_3, background, ticket);
            random1 = rand() % 6;
            position_actuelle2 = position[1];
            affichage(position_actuelle2, x2, buffer, symbole_3, background, ticket);
            random1 = rand() % 6;
            position_actuelle3 = position[1];
            affichage(position_actuelle3, x3, buffer, symbole_3, background, ticket);
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

                position_actuelle1 = position[1];
                affichage(position_actuelle1, x1, buffer, symbole_3, background, ticket);
                random1 = rand() % 6;
                position_actuelle2 = position[1];
                affichage(position_actuelle2, x2, buffer, symbole_3, background, ticket);
                random1 = rand() % 6;
                position_actuelle3 = position[1];
                affichage(position_actuelle3, x3, buffer, symbole_3, background, ticket);
                if (key[KEY_L]) {
                    printf("cr7");
                    set = 0;
                    ticketset2 = 0;

                }
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
                    set = 2;
                }

                while (set == 2) {

                    if (finition == finition2 || finition3 == finition2 || finition == finition3) {
                        if (finition == finition2 && finition3 == finition2) {
                            ticket = ticket + 1;
                            printf("you won");
                            for (int p = 0; p < 30; p++) {
                                masked_blit(win2, buffer, 0, 0, 450, 50, buffer->w,
                                            buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(200);
                                masked_blit(background, buffer, 0, 0, 0, 50, buffer->w, buffer->h);
                                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                                rest(100);
                            }

                        } else {
                            for (int p = 0; p < 30; p++) {
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
                        for (int p = 0; p < 30; p++) {
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
                        set=1;


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