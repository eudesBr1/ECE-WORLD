//
// Created by antoi on 30/04/2023.
//

#include <math.h>
#include "Mabibli.h"

void game_GUITARE(t_player *players)
{
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    int condition = 0;
    BITMAP *loadingscreen;
    loadingscreen = load_bitmap("../images/guitar_hero.bmp",NULL);
    if (!loadingscreen){
        allegro_message("Pb de l'image guitar_hero.bmp");
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
    BITMAP *photo_guitare_grande;
    photo_guitare_grande = load_bitmap("../images/photo_guitare.bmp",NULL);
    if (!photo_guitare_grande){
        allegro_message("Pb de l'image photo_guitare.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *photo_guitare;
    photo_guitare = create_bitmap(48,48);
    stretch_sprite(photo_guitare,photo_guitare_grande,0,0,48,48);

    show_mouse(screen);
    do {
        ///affichage si la souris est sur le boutton jouer
        if (mouse_x<=(screen->w/2+100)&&mouse_x>=(screen->w / 2 - 100)&&mouse_y>=(screen->h/2-38)&&mouse_y<=(screen->h / 2 + 38)){
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 150, screen->h / 2 - 38, 300, 75);
            stretch_sprite(buffer, settings_button, screen->w -80, screen->h - 80, 80, 80);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
            if (mouse_b == 1){
                printf("debut du jeu\n");
                condition = 1;
            }
        }
        ///affichage si la souris est sur le boutton parametre
        else if (mouse_x<=(screen->w)&&mouse_x>=(screen->w - 80)&&mouse_y>=(screen->h-80)&&mouse_y<=(screen->h)){
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w -110, screen->h - 110, 130, 130);
            stretch_sprite(buffer, quit_button, 0, screen->h  - 80, 150, 60);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
            if (mouse_b == 1){
                printf("parametres ouverts\n");
            }
        }
        ///affichage si le boutton quit est au niveau de la souris
        else if (mouse_x<=(150)&&mouse_x>=(0)&&mouse_y>=(screen->h-80)&&mouse_y<=(screen->h)){
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);            stretch_sprite(buffer, settings_button, screen->w -80, screen->h - 80, 80, 80);
            stretch_sprite(buffer, quit_button, 0, screen->h - 100, 200, 90);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
            if (mouse_b==1){
                destroy_bitmap(buffer);
                destroy_bitmap(play_boutton);
                destroy_bitmap(loadingscreen);
                destroy_bitmap(settings_button);
                destroy_bitmap(quit_button);
                destroy_bitmap(photo_guitare);
                return;
            }
        }
        ///affichage normal
        else {
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, quit_button, 0, screen->h  - 80, 150, 60);
            stretch_sprite(buffer, settings_button, screen->w -80, screen->h - 80, 80, 80);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        }
    }   while (!condition);
    condition = 0;
    clear(buffer);
    ///on commence par faire une animation pour commencer le jeu
    int x = 0;
    int y = 0;
    float agrandissement = 1;
    float angle = 0;
    int rayon = buffer->w/2;

    for (int i = 0; i < 350; i++) {
        x = rayon* cos(angle);
        y = rayon* sin(angle);
        stretch_blit(photo_guitare,buffer,10,10,38,38,x,y,photo_guitare->w*agrandissement,photo_guitare->h*agrandissement);
        textprintf_centre_ex(buffer,font,screen->w/2,100, makecol(255,255,255),0,"azer pour les colonnes de 1 a 4");
        angle+=0.02;
        agrandissement+= 0.2;
        printf("%d\n",i);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(10);
        clear(buffer);
    }
    ///une fois l'animation passer on va lancer le jeu
    ///on commence par charger les images des touches
    BITMAP *touche[6];
    touche[0] = load_bitmap("../images/TOUCHE_BLEU.bmp",NULL);
    if (!touche[0]){
        allegro_message("Pb de l'image TOUCHE_BLEU.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[1] = load_bitmap("../images/TOUCHE_JAUNE.bmp",NULL);
    if (!touche[1]){
        allegro_message("Pb de l'image TOUCHE_JAUNE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[2] = load_bitmap("../images/TOUCHE_ROUGE.bmp",NULL);
    if (!touche[2]){
        allegro_message("Pb de l'image TOUCHE_ROUGE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[3] = load_bitmap("../images/TOUCHE_VERT.bmp",NULL);
    if (!touche[3]){
        allegro_message("Pb de l'image TOUCHE_VERT.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[4] = load_bitmap("../images/TOUCHE_VIDE1.bmp",NULL);
    if (!touche[4]){
        allegro_message("Pb de l'image TOUCHE_VIDE1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[5] = load_bitmap("../images/TOUCHE_VIDE2.bmp",NULL);
    if (!touche[5]){
        allegro_message("Pb de l'image TOUCHE_VIDE2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[6] = load_bitmap("../images/TOUCHE_VIDE3.bmp",NULL);
    if (!touche[6]){
        allegro_message("Pb de l'image TOUCHE_VIDE3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    rest(500);


}
