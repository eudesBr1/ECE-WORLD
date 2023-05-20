#include "Mabibli.h"

void display(int y, float x, BITMAP *buffer, BITMAP *symbole_3,BITMAP *background, int jeton) {
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
    textprintf_ex(buffer,font,550,20, makecol(255,255,255),-1, "TICKET: %d" ,jeton);

    //stretch_blit(background,buffer,0,0,background->w,background->h,0,0,screen->w,screen->h);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    //stretch_sprite(background,buffer,0,0,background->w,background->h);
}

void defilement( int i, float position_actuelle, int x, BITMAP *buffer, BITMAP *symbole_3, BITMAP *background,  float position_retenu, int jeton,float k) {

    /*for (float j = 0; j < i; j++) {
        k = (2.45 * j) / i;
        position_actuelle = position_actuelle + (-(k * k) + 2.45 * k);
        display(position_actuelle, x, buffer, symbole_3, background, jeton);
        printf("%f`\n",k);
        //printf("%d\n",i);
        printf("%f\n",position_actuelle);
        if (position_actuelle > position_retenu + 60) {

            position_retenu = position_actuelle;
        }
    }*/
    for (int j = 0; j <46 ; ++j) {
        position_actuelle = position_actuelle+2*j;
        display(position_actuelle, x, buffer, symbole_3, background, jeton);
        rest(50);
        //printf("%f\n",position_actuelle);
    }
    for (int g = 46; g>0  ; --g) {
        position_actuelle = position_actuelle+2*g;
        //printf("lol");
        display(position_actuelle, x, buffer, symbole_3, background, jeton);
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
    int JETON = 5;
    int JETONboucle = 1;
    int JETONboucle2 = 1;
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
            display(position_actuelle1, x1, buffer, symbole_3, background, JETON);
            random1 = rand() % 6;
            position_actuelle2 = position[1];
            display(position_actuelle2, x2, buffer, symbole_3, background, JETON);
            random1 = rand() % 6;
            position_actuelle3 = position[1];
            display(position_actuelle3, x3, buffer, symbole_3, background, JETON);
            boucle = 1;
            JETONboucle2 = JETONboucle;
            printf("1");

            //stretch_blit(background, buffer, 0, 0, background->w, background->h, 0, 0, screen->w, screen->h);
            blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
        }
        while (JETONboucle == JETONboucle2) {
            if (key[KEY_ESC]) {
                break;
            }
            while (boucle == 1 && !key[KEY_ESC]) {

                if (key[KEY_E]) {
                   // printf("lol");
                    int resultat = rand() % 3;
                    finition = resultat_position[resultat];
                    resultat = rand() % 3;
                    printf("%d\n",finition);
                    finition2 = resultat_position[resultat];
                    resultat = rand() % 3;
                    printf("%d\n",finition2);
                    finition3 = resultat_position[resultat];
                    printf("%d\n",finition3);
                    float k = 0;
                    float i = -position_actuelle1 + finition;
                    float i2 = -position_actuelle2 + finition2;
                    float i3 = -position_actuelle3 + finition3;
                    float positionretenu = position_actuelle1;
                    float positionretenu2 = position_actuelle2;
                    float positionretenu3 = position_actuelle3;
                    position_actuelle1=position_actuelle1+finition;
                    position_actuelle2=position_actuelle2+finition2;
                    position_actuelle3=position_actuelle3+finition3;
                    printf("zebi");

                    defilement(i, position_actuelle1, x1, buffer, symbole_3, background, positionretenu, JETON,k);
                    //display(finition, x1, buffer, symbole_3, background, JETON);
                    defilement(i2, position_actuelle2, x2, buffer, symbole_3, background, positionretenu2, JETON,k);
                    //display(finition2, x2, buffer, symbole_3, background, JETON);
                    defilement(i3, position_actuelle3, x3, buffer, symbole_3, background, positionretenu3, JETON,k);
                    //display(finition3, x3, buffer, symbole_3, background, JETON);
                    printf("lola");

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