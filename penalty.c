//
// Created by eudes on 10/05/2023.
//
#include "Mabibli.h"
void penalty(t_player *player){
     ///charge image menu et boutons

    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    BITMAP *fondStade = load_bitmap("../images/penalty/butDeFoot.bmp",NULL);
    if (!fondStade){
        allegro_message("Pb de l'image fondStade.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *templateBallon = load_bitmap("../images/penalty/ballonDeFoot.bmp",NULL);
    if (!templateBallon){
        allegro_message("Pb de l'image fondStade.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *ballon[6];
    int tailleBallon = 100;
    for (int i = 0; i < 2; ++i) {
        ballon[i]= create_sub_bitmap(templateBallon,500*i+30,30,500,500);
    }
    for (int i = 2; i < 4; ++i) {
        ballon[i] = create_sub_bitmap(templateBallon,500*i+30,670,500,500);
    }
    int b=0;
    while (!key[KEY_ESC] && !key[KEY_E]){
        clear(buffer);
        stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
        stretch_sprite(buffer,ballon[(b/10)%2],screen->w/2-tailleBallon/2,screen->h-200,tailleBallon,tailleBallon);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(1);
    }
    while (!key[KEY_ESC]){
        clear(buffer);
        stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
        stretch_sprite(buffer,ballon[(b/10)%4],screen->w/2-tailleBallon/2,screen->h-200-b,tailleBallon,tailleBallon);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(1);
        b++;
    }
}