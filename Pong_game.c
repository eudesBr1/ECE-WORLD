//
// Created by antoi on 08/05/2023.
//
#include "Mabibli.h"

void parametres(int *speed,int *opposant,BITMAP *buffer,t_player player[4],int numJoueur)
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
        textout_centre_ex(buffer, font, "VITESSE", 45, 3*screen->h/9, blanc, -1);
        textout_centre_ex(buffer,font,"OPPOSANT ; ",45,2*screen->h/3, makecol(255,50,50),-1);
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
            if ((mouse_x > ((screen->w*(i+2)))/9 && mouse_x < ((screen->w*(i+2.5))/9) && (mouse_y > (3*screen->h/9-50) && mouse_y < (3*screen->h/9+50)))||*speed == i + 1) {
                    rectfill(buffer, (screen->w*(i+2))/9, (3*screen->h/9-50), ((screen->w*(i+2.5))/9), (3*screen->h/9+50), beige);
                    textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (3*screen->h/9+65), beige, -1, "%d", i + 1);
                if (mouse_b == 1){
                    *speed = i+1;
                }

            }
            else {
                    rectfill(buffer, (screen->w*(i+2))/9, (3*screen->h/9-50), ((screen->w*(i+2.5))/9), (3*screen->h/9+50), blanc);
                    textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (3*screen->h/9+65), blanc, -1, "%d", i + 1);
            }

        }
        for (int j = 0; j < player[0].nbJoueurs; j++) {
            if ((mouse_x > ((screen->w*(j+1))/6) && mouse_x < ((screen->w*(j+2))/6) && (mouse_y > (2*screen->h/4) && mouse_y < (3.5*screen->h/4))&& numJoueur != j)||*opposant == j) {
                rectfill(buffer,((screen->w*(j+1))/6),(2*screen->h/4),(screen->w*(j+2)/6),(3.5*screen->h/4),saumon);
                stretch_sprite(buffer,player[j].bas[1],((screen->w*(j+1))/6),(2*screen->h/4),screen->w/6,1.5*screen->h/4);
                textprintf_centre_ex(buffer, font, ((screen->w*(j+1.5))/6), (3.7*screen->h/4), blanc, -1, "%s", player[j].name + 1);
                if (mouse_b == 1){
                    *opposant = j;
                }
            }
            else if (numJoueur != j){
                rectfill(buffer,((screen->w*(j+1))/6),(2*screen->h/4),(screen->w*(j+2)/6),(3.5*screen->h/4),beige);
                stretch_sprite(buffer,player[j].bas[1],((screen->w*(j+1))/6),(2*screen->h/4),screen->w/6,1.5*screen->h/4);
                textprintf_centre_ex(buffer, font, ((screen->w*(j+1.5))/6), (3.7*screen->h/4), blanc, -1, "%s", player[j].name + 1);
            }
        }
        stretch_sprite(buffer,mouse_sprite,mouse_x,mouse_y,mouse_sprite->w*4,mouse_sprite->h*4);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    } while (!condition);
    rest(200);
}

void game_PONG(t_player player[4],int numJoueur){
    int nb_Joueur = player[0].nbJoueurs;
    int speed = 1;
    int grossissement = 0;
    int choixOpposant;
    int condition = 0;
    BITMAP *buffer = create_bitmap(screen->w,screen->h);
    BITMAP *pong;
    pong = load_bitmap("../images/Pong.bmp",NULL);
    if (!pong){
        allegro_message("Pb de l'image Pong.bmp");
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

    while (!condition){
        stretch_blit(pong, buffer, 0, 0, pong->w, pong->h, 0, 0, buffer->w, buffer->h);
        if (mouse_x <= (screen->w / 2 + h_tuile) && mouse_x >= (screen->w / 2 - h_tuile) &&mouse_y >= (screen->h / 2 - 38) && mouse_y <= (screen->h / 2 + 38)) {
            stretch_blit(pong, buffer, 0, 0, pong->w, pong->h, 0, 0, screen->w, screen->h);
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
            stretch_blit(pong, buffer, 0, 0, pong->w, pong->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - h_tuile, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w - 110, screen->h - 110, 130, 130);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            if (mouse_b == 1) {
                printf("parametres ouverts\n");
                parametres(&speed,&choixOpposant,buffer,player,numJoueur);
            }
        }
        ///affichage si le boutton quit est au niveau de la souris
        else if (mouse_x <= (150) && mouse_x >= (0) && mouse_y >= (screen->h - 80) && mouse_y <= (screen->h)) {
            stretch_blit(pong, buffer, 0, 0, pong->w, pong->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - h_tuile, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
            stretch_sprite(buffer, quit_button, 0, screen->h - h_tuile, 200, 90);
            if (mouse_b == 1) {
                destroy_bitmap(buffer);
                destroy_bitmap(play_boutton);
                destroy_bitmap(pong);
                destroy_bitmap(settings_button);
                destroy_bitmap(quit_button);
                return;
            }
        }
        ///affichage normal
        else {
            stretch_blit(pong, buffer, 0, 0, pong->w, pong->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - h_tuile, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
        }
        stretch_sprite(buffer,mouse_sprite,mouse_x,mouse_y,mouse_sprite->w*4,mouse_sprite->h*4);
        //blit(mouse_sprite,buffer,0,0,mouse_x,mouse_y,mouse_sprite->w,mouse_sprite->h);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
    }
    for (int i = 0; i < 200; i++)
    {
        grossissement +=i;
        stretch_blit(pong,buffer,0,0,pong->w,pong->h,0-grossissement,0-grossissement,pong->w+grossissement,pong->h+grossissement);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    }

    if (nb_Joueur>1)
    {

    }
}