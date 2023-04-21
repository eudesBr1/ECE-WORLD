#include <stdlib.h>
#include <time.h>
#include "allegro.h"
#include "stdio.h"
#define vitesse 1.25
typedef struct player{
    int x,y,ticket,points;
    char* name;
    BITMAP *haut[3];
    BITMAP *bas[3];
    BITMAP *droite[3];
    BITMAP *gauche[3];
    int position[3];
    int animation;
}t_player;


t_player ballon(t_player player){
    BITMAP;
}

void initEcran(){
    set_color_depth(desktop_color_depth());
    if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0)) != 0) {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

int main(){
    allegro_init();
    t_player goku;
    goku.x=100;
    goku.y=100;
    initEcran();
    install_keyboard();
    install_mouse();
    BITMAP *carte;
    BITMAP *GOKUTEMPLATE;
    BITMAP *GOKU;
    BITMAP *buffer= create_bitmap(screen->w,screen->h);
    clear(buffer);
    GOKUTEMPLATE = load_bitmap("../images/gokuSprite.bmp",NULL);
    if (!GOKUTEMPLATE){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 3; ++i) {
        goku.haut[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,149,32,48);
    }
    for (int i = 0; i < 3; ++i) {
        goku.gauche[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,46,32,49);
    }
    for (int i = 0; i < 3; ++i) {
        goku.droite[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,96,32,49);
    }
    for (int i = 0; i < 3; ++i) {
        goku.bas[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,0,32,48);
    }
    // Créer un sous-bitmap pour extraire le premier sprite
    BITMAP *spriteTemplate = create_sub_bitmap(GOKUTEMPLATE, 0, 0, 32, 48);

    // Créer un nouveau bitmap pour votre personnage
    GOKU = create_bitmap(spriteTemplate->w, spriteTemplate->h);

    // Copier le sprite extrait dans votre nouveau bitmap
    clear_bitmap(GOKU);
    blit(spriteTemplate, GOKU, 0, 0, 0, 0, spriteTemplate->w, spriteTemplate->h);
    carte = load_bitmap("../images/map_pokemon.bmp",NULL);
    if (!carte){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    //stretch_blit(carte,screen,0,0,carte->w,carte->h,0,0,screen->w,screen->h);
    goku.animation=0;
    while (!key[KEY_ESC]){
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        blit(carte,buffer,goku.x,goku.y,0,0,screen->w,screen->h);
        if(key[KEY_LEFT]){
            goku.x -= vitesse;
            draw_sprite(buffer,goku.gauche[goku.animation/10],goku.x,goku.y);
        }
        if(key[KEY_RIGHT]){
            goku.x += vitesse;
            draw_sprite(buffer,goku.droite[goku.animation/10],goku.x,goku.y);
        }
        if(key[KEY_UP]) {
            goku.y -= vitesse;
            draw_sprite(buffer,goku.haut[goku.animation/10],goku.x,goku.y);
        }
        if(key[KEY_DOWN]){
            goku.y += vitesse*3;
            draw_sprite(buffer,goku.bas[goku.animation/10],goku.x,goku.y);
        }
        rest(10);
        goku.animation++;
        if (goku.animation==30){
            goku.animation=0;
        }
     //   printf("%d",goku.animation);
        }
    allegro_exit();
    return 1;
}
END_OF_MAIN()