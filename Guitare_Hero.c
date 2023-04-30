//
// Created by antoi on 30/04/2023.
//

#include "Mabibli.h"

void game_GUITARE(t_player *players)
{
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
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
    show_mouse(screen);
    do {
        if (mouse_x<=(screen->w/2+100)&&mouse_x>=(screen->w / 2 - 100)&&mouse_y>=(screen->h/2-38)&&mouse_y<=(screen->h / 2 + 38)){
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 150, screen->h / 2 - 38, 300, 75);
            stretch_sprite(buffer, settings_button, screen->w -80, screen->h - 80, 80, 80);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        } else if (mouse_x<=(screen->w)&&mouse_x>=(screen->w - 80)&&mouse_y>=(screen->h-80)&&mouse_y<=(screen->h)){
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w -110, screen->h - 110, 130, 130);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        }
        else {
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, settings_button, screen->w -80, screen->h - 80, 80, 80);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        }
    }   while (!key[KEY_ESC]);
}
