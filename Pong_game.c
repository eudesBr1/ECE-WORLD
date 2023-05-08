//
// Created by antoi on 08/05/2023.
//
#include "Mabibli.h"

void parametres(int *speed,int *opposant,BITMAP *buffer,t_player player[4],int numJoueur)
{
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
        rectfill(buffer,0,0,buffer->w,100,blanc);
        rectfill(buffer, 0, 100, buffer->w, 110, saumon);
        textout_centre_ex(buffer, font, "PARAMETRES", buffer->w / 2, 50, noir, -1);
        textout_centre_ex(buffer, font, "VITESSE", 30, 200, blanc, -1);
        textout_centre_ex(buffer,font,"OPPOSANT ; ",30,300, makecol(255,50,50),-1);
        if (mouse_x <= (100) && mouse_x >= (0) && mouse_y >= (screen->h - 100) && mouse_y <= (screen->h)) {
            stretch_sprite(buffer, retour, 0, buffer->h - 130, 150, 150);
            if (mouse_b == 1){
                return;
            }
        }
        else
            stretch_sprite(buffer, retour, 0, buffer->h - 100, 100, 100);

        rectfill(buffer,100,198,600,202,blanc);
        for (int i = 0; i < 6; i++) {
            if (mouse_x > (100 + 100 * i) && mouse_x < (120 + 100 * i) && (mouse_y > (190) && mouse_y < (210))){
                if (*speed == i + 1) {
                    rectfill(buffer, 100 + 100 * i, 190, 120 + 100 * i, 210, beige);
                    textprintf_centre_ex(buffer, font, 110 + 100 * i, 220, beige, -1, "%d", i + 1);

                }
            else {
                rectfill(buffer, 100 + 100 * i, 190, 120 + 100 * i, 210, blanc);
                textprintf_centre_ex(buffer, font, 110 + 100 * i, 220, blanc, -1, "%d", i + 1);
            }
        }
        }
        for (int j = 0; j < player[0].nbJoueurs; j++) {
            if ((mouse_x>(100+100*j)&&mouse_x<(170+100*j)&&(mouse_y>(300)&&mouse_y<(370))&& numJoueur != j)||*opposant == j)
            {
                rectfill(buffer,100+100*j,300,170+100*j,370,saumon);
                stretch_sprite(buffer,player[j].bas[1],102+100*j,302,64,64);
                if (mouse_b == 1){
                    *opposant = j;
                }
            }
            else if (numJoueur != j){
                rectfill(buffer,100+100*j,300,170+100*j,370,beige);
                stretch_sprite(buffer,player[j].bas[1],102+100*j,302,64,64);
            }
        }
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    } while (!key[KEY_ESC]);

}

void game_PONG(t_player player[4],int numJoueur){
    int nb_Joueur = player[0].nbJoueurs;
    int speed = 1;
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

    show_mouse(screen);

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
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);

    }

    if (nb_Joueur>1)
    {

    }
}