//
// Created by antoi on 21/04/2023.
//

#include "Mabibli.h"

void Parametres(int *vitesse_max,int *vitesse_min,BITMAP *buffer)
{
    int width = text_length(font, "PARAMETRES");
    int height = text_height(font);
    int condition = 0;
    BITMAP *para = create_bitmap(width,height);
    rectfill(para,0,0,para->w,para->h, makecol(255,0,255));

    BITMAP *retour;
    retour = load_bitmap("../images/boutton_retour.bmp",NULL);
    if (!retour){
        allegro_message("Pb de l'image boutton_retour.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int blanc = makecol(255, 255, 255);
    int noir = makecol(0,0,0);
    int beige = makecol(127,255,197);
    int saumon = makecol(255, 178, 127);
    do {
        clear(buffer);
        rectfill(buffer, 0, 0, buffer->w, buffer->h / 9, blanc);
        rectfill(buffer, 0, buffer->h/9, buffer->w, buffer->h/9+50, saumon);
        textout_ex(para,font,"PARAMETRES",0,0, noir,-1);
        stretch_sprite(buffer,para,buffer->w/2-220,9,440,buffer->h/9+60);
        textout_centre_ex(buffer, font, "VITESSE MAX", 45, 3*screen->h/9, blanc, -1);
        textout_centre_ex(buffer,font,"VITESSE MIN",45,6*screen->h/9, makecol(255,50,50),-1);
        if (mouse_x <= (100) && mouse_x >= (0) && mouse_y >= (screen->h - 100) && mouse_y <= (screen->h)) {
            stretch_sprite(buffer, retour, 0, buffer->h - 130, 150, 150);
            if (mouse_b == 1){
                condition=1;
            }
        }
        else
            stretch_sprite(buffer, retour, 0, buffer->h - 100, 100, 100);
        rectfill(buffer,2*screen->w/9,3*screen->h/9-10,7*screen->w/9,3*screen->h/9+10,blanc);
        for (int i = 0; i < 6; i++) {
            if ((mouse_x > ((screen->w*(i+2)))/9 && mouse_x < ((screen->w*(i+2.5))/9) && (mouse_y > (3*screen->h/9-50) && mouse_y < (3*screen->h/9+50)))||*vitesse_max == i + 7) {
                rectfill(buffer, (screen->w*(i+2))/9, (3*screen->h/9-50), ((screen->w*(i+2.5))/9), (3*screen->h/9+50), beige);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (3*screen->h/9+65), beige, -1, "%d", i + 7);
                if (mouse_b == 1){
                    *vitesse_max = i+7;
                }

            }
            else {
                rectfill(buffer, (screen->w*(i+2))/9, (3*screen->h/9-50), ((screen->w*(i+2.5))/9), (3*screen->h/9+50), blanc);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (3*screen->h/9+65), blanc, -1, "%d", i + 7);
            }
        }
        rectfill(buffer,2*screen->w/9,6*screen->h/9-10,7*screen->w/9,6*screen->h/9+10,blanc);
        for (int i = 0; i < 6; i++) {
            if ((mouse_x > ((screen->w*(i+2)))/9 && mouse_x < ((screen->w*(i+2.5))/9) && (mouse_y > (6*screen->h/9-50) && mouse_y < (6*screen->h/9+50)))||*vitesse_min == i + 1) {
                rectfill(buffer, (screen->w*(i+2))/9, (6*screen->h/9-50), ((screen->w*(i+2.5))/9), (6*screen->h/9+50), beige);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (6*screen->h/9+65), beige, -1, "%d", i + 1);
                if (mouse_b == 1){
                    *vitesse_min = (i+1);
                }

            }
            else {
                rectfill(buffer, (screen->w*(i+2))/9, (6*screen->h/9-50), ((screen->w*(i+2.5))/9), (6*screen->h/9+50), blanc);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (6*screen->h/9+65), blanc, -1, "%d", i + 1);
            }

        }

        stretch_sprite(buffer,mouse_sprite,mouse_x,mouse_y,mouse_sprite->w*4,mouse_sprite->h*4);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    } while (!condition);
    rest(200);
}


void ballon(t_player *player){
    BITMAP *buffer = create_bitmap(screen->w,screen->h);
    int bleu = makecol(0,162,232);
    int compteur_apparition = 0;
    int noir = makecol(0,0,0);
    int blanc = makeacol(255, 255, 255, 0);
    int vitesse_max = 6;
    int vitesse_min = 2;
    BITMAP *acceuil_base;
    acceuil_base = load_bitmap("../images/tir_ballon.bmp",NULL);
    if (!acceuil_base){
        allegro_message("Pb de l'image tir_ballon");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *play_boutton;
    play_boutton = load_bitmap("../images/Boutton_jouer.bmp",NULL);
    if (!play_boutton){
        allegro_message("Pb de l'image Boutton_jouer.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *settings_button;
    settings_button = load_bitmap("../images/setting_button.bmp",NULL);
    if (!settings_button){
        allegro_message("Pb de l'image Boutton_jouer.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *quit_button;
    quit_button = load_bitmap("../images/quit_boutton.bmp",NULL);
    if (!quit_button){
        allegro_message("Pb de l'image quit_boutton.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *bmpEXPLOSION;
    bmpEXPLOSION = load_bitmap("../images/sprite_explosion.bmp",NULL);
    if (!bmpEXPLOSION){
        allegro_message("Pb de l'image sprite_explosion");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *ballon_apparition;
    ballon_apparition = load_bitmap("../images/apparition_ballon.bmp",NULL);
    if (!ballon_apparition){
        allegro_message("Pb de l'image sprite_explosion");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    /// découpage de la sprite explosion et apparition ballon
    BITMAP *explosion[4];
    BITMAP *apparition[6];
    for (int i = 0; i <= 4; i++) {
        explosion[i] = create_sub_bitmap(bmpEXPLOSION,bmpEXPLOSION->w*i/5,0,bmpEXPLOSION->w/5,bmpEXPLOSION->h);
    }
    for (int i = 0; i <= 6; i++) {
        apparition[i] = create_sub_bitmap(ballon_apparition,ballon_apparition->w*i/7,0,ballon_apparition->w/7,ballon_apparition->h);
    }
    int condition = 0;
    do {
        clear(buffer);
        stretch_blit(acceuil_base,buffer,0,0,acceuil_base->w,acceuil_base->h,0,0,screen->w,screen->h);
        if (mouse_x <= (screen->w / 2 + h_tuile) && mouse_x >= (screen->w / 2 - h_tuile) &&mouse_y >= (screen->h / 2 - 38) && mouse_y <= (screen->h / 2 + 38)) {
            stretch_blit(acceuil_base, buffer, 0, 0, acceuil_base->w, acceuil_base->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 150, screen->h / 2 - 38, 300, 75);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            if (mouse_b == 1) {
                printf("debut du jeu\n");
                condition = 1;
            }
        }
            ///affichage si la souris est sur le boutton parametre
        else if (mouse_x <= (screen->w) && mouse_x >= (screen->w - 80) && mouse_y >= (screen->h - 80) &&
                 mouse_y <= (screen->h)) {
            stretch_blit(acceuil_base, buffer, 0, 0, acceuil_base->w, acceuil_base->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - h_tuile, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w - 110, screen->h - 110, 130, 130);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            if (mouse_b == 1) {
                //printf("parametres ouverts\n");
                Parametres(&vitesse_max,&vitesse_min,buffer);
            }
        }
            ///affichage si le boutton quit est au niveau de la souris
        else if (mouse_x <= (150) && mouse_x >= (0) && mouse_y >= (screen->h - 80) && mouse_y <= (screen->h)) {
            stretch_blit(acceuil_base, buffer, 0, 0, acceuil_base->w, acceuil_base->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - h_tuile, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
            stretch_sprite(buffer, quit_button, 0, screen->h - h_tuile, 200, 90);
            if (mouse_b == 1) {
                destroy_bitmap(buffer);
                destroy_bitmap(play_boutton);
                destroy_bitmap(acceuil_base);
                destroy_bitmap(settings_button);
                destroy_bitmap(quit_button);
                return;
            }
        }
            ///affichage normal
        else {
            stretch_blit(acceuil_base, buffer, 0, 0, acceuil_base->w, acceuil_base->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - h_tuile, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
        }
        stretch_sprite(buffer,mouse_sprite,mouse_x,mouse_y,mouse_sprite->w*4,mouse_sprite->h*4);
        //blit(mouse_sprite,buffer,0,0,mouse_x,mouse_y,mouse_sprite->w,mouse_sprite->h);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);


    } while (condition!=1&&condition!=2);
    ///initialisation du jeux
    int score = 0;
    float timer = 0;
    t_ballon tabBall[10];
    for (int i = 0; i < 10; i++) {
        tabBall[i].x = rand()%(screen->w-250)+125;
        tabBall[i].y = rand()%(screen->h-350)+175;
        tabBall[i].alive = 1;
        tabBall[i].couleur = rand()%4;
        tabBall[i].countAnim = 0;
        if (tabBall[i].couleur == 0)
        {
            tabBall[i].img = load_bitmap("../images/Ballon_Bleu.bmp",NULL);
            if (!tabBall[i].img){
                allegro_message("Pb de l'image ballon Bleu");
                allegro_exit();
                exit(EXIT_FAILURE);
            }

        }
        if (tabBall[i].couleur == 1)
        {
            tabBall[i].img = load_bitmap("../images/ballon_Jaune.bmp",NULL);
            if (!tabBall[i].img){
                allegro_message("Pb de l'image ballon Jaune");
                allegro_exit();
                exit(EXIT_FAILURE);
            }

        }
        if (tabBall[i].couleur == 2)
        {
            tabBall[i].img = load_bitmap("../images/Ballon_Rouge.bmp",NULL);
            if (!tabBall[i].img){
                allegro_message("Pb de l'image ballon rouge");
                allegro_exit();
                exit(EXIT_FAILURE);
            }

        }
        if (tabBall[i].couleur == 3)
        {
            tabBall[i].img = load_bitmap("../images/Ballon_Vert.bmp",NULL);
            if (!tabBall[i].img){
                allegro_message("Pb de l'image ballon Vert");
                allegro_exit();
                exit(EXIT_FAILURE);
            }

        }

        tabBall[i].speed = rand()%(vitesse_max-vitesse_min)+vitesse_min;
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

    BITMAP *buffer2;
    buffer2 = create_bitmap(screen->w,screen->h);

    for (int i = 0; i < 100000; ++i) {
        if (condition == 2)
            break;
        clear(buffer);
        rectfill(buffer,0,0,buffer->w,buffer->h, bleu);
        rectfill(buffer,100,150,buffer->w-100,buffer->h-150, noir);

        textout_ex(buffer, font, "Jeux des ballons", 300, 70, blanc, -1);
        if (i == 0){
            rectfill(buffer2,0,0,buffer->w,buffer->h, bleu);
            rectfill(buffer2,100,150,buffer->w-100,buffer->h-150, noir);
            textout_ex(buffer2, font, "Jeux des ballons", 300, 70, blanc, -1);
        }
        char message[50];

        char pos_x[5];
        sprintf(pos_x,"%d",mouse_x);
        strcpy(message,"x = ");
        strcat(message,pos_x);
        textout_ex(buffer, font, message, 10, 10, blanc, -1);

        if (i == 0){
            textout_ex(buffer2, font, message, 10, 10, blanc, -1);
        }

        char pos_y[5];
        sprintf(pos_y,"%d",mouse_y);
        strcpy(message,"y = ");
        strcat(message,pos_y);
        textout_ex(buffer, font, message, 10, 25, blanc, -1);

        if (i==0){
            textout_ex(buffer2, font, message, 10, 25, blanc, -1);
        }

        char points[5];
        sprintf(points,"%d",score);
        strcpy(message,"SCORE = ");
        strcat(message,points);
        textout_ex(buffer, font, message,screen->w/2, 120, blanc, -1);

        if (i==0){
            textout_ex(buffer2, font, message,screen->w/2, 120, blanc, -1);
        }


        char temps[5];
        sprintf(temps,"%f",timer);
        strcpy(message,"temps = ");
        strcat(message,temps);
        textout_ex(buffer, font, message,screen->w-100, 300, blanc, -1);

        if (i==0){
            textout_ex(buffer2, font, message,screen->w-100, 300, blanc, -1);
        }


        while (compteur_apparition<=69)
        {
            clear(buffer2);
            buffer2 = buffer;
            for (int j = 0; j < 10; j++)
            {
                stretch_sprite(buffer2,apparition[(69-compteur_apparition)/10],tabBall[j].x,tabBall[j].y,64,64);

            }
            blit(buffer2,screen,0,0,0,0,screen->w,screen->h);
            compteur_apparition++;
            rest(20);
        }


        ///dessin des 10 ballons
        for (int j = 0; j < 10; j++) {
            if (tabBall[j].alive){
                tabBall[j].x += tabBall[j].speed*(rand()%3-1);
                stretch_sprite(buffer,tabBall[j].img,tabBall[j].x,tabBall[j].y,TailleBalx,TailleBaly);
                //stretch_blit(tabBall[j].img,buffer,0,0,tabBall[j].img->w,tabBall[j].img->h,tabBall[j].x,tabBall[j].y,32,32);
                if (tabBall[j].x<=100)
                    tabBall[j].x = 100;
                if (tabBall[j].x>=buffer->w-100)
                    tabBall[j].x = buffer->w-100;
                if (tabBall[j].y<=150)
                    tabBall[j].y = 150;
                if (tabBall[j].y>=buffer->h-150)
                    tabBall[j].y= buffer->h-150;
                tabBall[j].y += tabBall[j].speed*(rand()%3-1);

                if (mouse_b==1&&(mouse_x>=tabBall[j].x&&mouse_x<=tabBall[j].x+TailleBalx)&&(mouse_y>=tabBall[j].y&&mouse_y<=tabBall[j].y+TailleBaly)) {
                    tabBall[j].alive = 0;
                    score++;
                }
            }
            else if (tabBall[j].countAnim < 10){
                stretch_sprite(buffer,explosion[0],tabBall[j].x,tabBall[j].y,64,64);
                tabBall[j].countAnim++;
            }
            else if (tabBall[j].countAnim < 20){
                stretch_sprite(buffer,explosion[1],tabBall[j].x,tabBall[j].y,64,64);
                tabBall[j].countAnim++;
            }
            else if (tabBall[j].countAnim < 30){
                stretch_sprite(buffer,explosion[2],tabBall[j].x,tabBall[j].y,64,64);
                tabBall[j].countAnim++;
            }
            else if (tabBall[j].countAnim < 40){
                stretch_sprite(buffer,explosion[3],tabBall[j].x,tabBall[j].y,64,64);
                tabBall[j].countAnim++;
            }
            else if (tabBall[j].countAnim < 50){
                stretch_sprite(buffer,explosion[4],tabBall[j].x,tabBall[j].y,64,64);
                tabBall[j].countAnim++;
            }
        }
        if ((mouse_x>=100&&mouse_x<=buffer->w-100)&&(mouse_y<=screen->h-150&&mouse_y>=150)){
            stretch_sprite(buffer,spriteViseur,mouse_x-30,mouse_y-30,60,60);
        }
        blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
        rest(5);
        timer = (0.015*i);
        if (score == 10){
            clear(buffer);
            allegro_message("bravo vous avez fini en %f secondes",timer);
            if (timer <= 10){
                allegro_message("vous avez fini en moins de 10 secondes remportez donc 1 points et 2 tickets");
                player->ticket+=2;
                player->points++;
            }
            else if (timer <= 15){
                allegro_message("vous avez fini en moins de 15 secondes vous remportez donc 1 points et 1 ticket");
                player->ticket++;
                player->points++;
            }
            break;
        }
    }
}