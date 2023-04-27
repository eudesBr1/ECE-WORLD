//
// Created by antoi on 21/04/2023.
//

#include "Mabibli.h"

void ballon(t_player *player, BITMAP *buffer){
    BITMAP *acceuil_base;
    acceuil_base = load_bitmap("../images/tir_ballon.bmp",NULL);
    if (!acceuil_base){
        allegro_message("Pb de l'image tir_ballon");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *acceuil_zoom;
    acceuil_zoom = load_bitmap("../images/tir_ballon1.bmp",NULL);
    if (!acceuil_zoom){
        allegro_message("Pb de l'image tir_ballon1");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
    int condition;
    do {
        if (((mouse_x >= 250 && mouse_x <= 550) && (mouse_y >= 400 && mouse_y <= 550)) == 0) {
            stretch_blit(acceuil_base, buffer, 0, 0, acceuil_base->w, acceuil_base->h, 0, 0, 800, 600);
        } else {
            stretch_blit(acceuil_zoom, buffer, 0, 0, acceuil_zoom->w, acceuil_zoom->h, 0, 0, 800, 600);
            if (mouse_b == 1)
                condition = 1;
        }
        blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
        if (key[KEY_ESC]){
            rest(500);
            break;
        }
    } while (condition!=1);
    ///initialisation du jeux
    int score = 0;
    condition = 0;
    float timer = 0;
    t_ballon tabBall[10];
    for (int i = 0; i < 10; i++) {
        tabBall[i].x = rand()%560+120;
        tabBall[i].y = rand()%360+170;
        tabBall[i].alive = 1;
        tabBall[i].couleur = makeacol(rand()%50,rand()%150+100,rand()%50,0);
        tabBall[i].speed = rand()%5+6;
    }

    ///dessin de l'aire de jeux
    clear(buffer);

    BITMAP *viseur;
    viseur = load_bitmap("../images/viseur.bmp",NULL);
    if (!viseur){
        allegro_message("Pb de l'image viseur.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *spriteViseur;
    spriteViseur = create_bitmap(50, 50);
    stretch_blit(viseur, spriteViseur,0,0,viseur->w,viseur->h,0,0, spriteViseur->w,spriteViseur->h);

    for (int i = 0; i < 100000; ++i) {
        clear(buffer);
        rectfill(buffer,0,0,buffer->w,buffer->h, makeacol(255,30,30,0));
        rectfill(buffer,100,150,buffer->w-100,buffer->h-50, makeacol(0,0,0,0));
        textout_ex(buffer,font,"Jeux des ballons",300,70, makeacol(255,255,255,0),-1);
        char message[50];

        char pos_x[5];
        sprintf(pos_x,"%d",mouse_x);
        strcpy(message,"x = ");
        strcat(message,pos_x);
        textout_ex(buffer,font,message,10,10, makeacol(255,255,255,0),-1);

        char pos_y[5];
        sprintf(pos_y,"%d",mouse_y);
        strcpy(message,"y = ");
        strcat(message,pos_y);
        textout_ex(buffer,font,message,10,25, makeacol(255,255,255,0),-1);

        char points[5];
        sprintf(points,"%d",score);
        strcpy(message,"SCORE = ");
        strcat(message,points);
        textout_ex(buffer,font,message,screen->w/2,120, makeacol(255,255,255,0),-1);

        char temps[5];
        sprintf(temps,"%f",timer);
        strcpy(message,"temps = ");
        strcat(message,temps);
        textout_ex(buffer,font,message,screen->w-100,300, makeacol(255,255,255,0),-1);

        if ((mouse_x>=100&&mouse_x<=700)&&(mouse_y<=550&&mouse_y>=150)){
            draw_sprite(buffer,spriteViseur,mouse_x-25,mouse_y-25);
        }
        ///dessin des 10 ballons
        for (int j = 0; j < 10; j++) {
            if (tabBall[j].alive){
                circlefill(buffer,tabBall[j].x,tabBall[j].y,20,tabBall[j].couleur);
                tabBall[j].x += tabBall[j].speed*(rand()%3-1);
                if (tabBall[j].x<=120)
                    tabBall[j].x = 120;
                if (tabBall[j].x>=680)
                    tabBall[j].x = 680;
                if (tabBall[j].y<=170)
                    tabBall[j].y = 170;
                if (tabBall[j].y>=530)
                    tabBall[j].y= 530;

                tabBall[j].y += tabBall[j].speed*(rand()%3-1);
                if (mouse_b==1&&(mouse_x>=tabBall[j].x-20&&mouse_x<=tabBall[j].x+20)&&(mouse_y>=tabBall[j].y-20&&mouse_y<=tabBall[j].y+20)) {
                    tabBall[j].alive = 0;
                    score++;
                }
            }
        }
        blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
        rest(5);
        timer = (0.015*i);
        if (score == 10){
            clear(buffer);
            allegro_message("bravo vous avez fini en %f secondes",timer);
            if (timer <= 10){
                allegro_message("vous avez fini en moins de 10 secondes remportez donc 1 points et 2 tickets");
                player.ticket+=2;
                player.points++;
            }
            else if (timer <= 15){
                allegro_message("vous avez fini en moins de 15 secondes vous remportez donc 1 points et 1 ticket");
                player.ticket++;
                player.points++;
            }
            break;
        }
    }
}