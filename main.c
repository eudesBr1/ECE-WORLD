#include <stdlib.h>
#include <time.h>
#include "allegro.h"
#include "stdio.h"

typedef struct player{
    int x,y,ticket,points;
    char* name;
    BITMAP *haut[4];
    BITMAP *bas[4];
    BITMAP *droite[4];
    BITMAP *gauche[4];
}t_player;


void ballon(BITMAP *buffer){
    int condition = 0;
    BITMAP *chargement_ballon;
    chargement_ballon = load_bitmap("tir_ballon.bmp",NULL);
    if (!chargement_ballon){
        allegro_message("Pb de l'image ballon");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *boutton_enfoncer;

    show_mouse(screen);
    boutton_enfoncer = load_bitmap("tir_ballon1.bmp",NULL);
    if (!boutton_enfoncer){
        allegro_message("Pb de l'image ballon");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        blit(chargement_ballon, buffer, 0,0,0,100,chargement_ballon->w, chargement_ballon->h);
        blit(buffer, screen, 0,0,0,0, buffer->w, buffer->h);
    }
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
    goku.x=10;
    goku.y=10;
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
    GOKUTEMPLATE = create_sub_bitmap(GOKUTEMPLATE,0,0,32,48);
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
    while (!key[KEY_ESC]){
        blit(carte,buffer,goku.x,goku.y,0,0,screen->w,screen->h);
        draw_sprite(buffer,GOKU,goku.x,goku.y);
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        if(key[KEY_LEFT]) goku.x -= 2;
        if(key[KEY_RIGHT]) goku.x += 2;
        if(key[KEY_UP]) goku.y -= 2;
        if(key[KEY_DOWN]) goku.y += 2;
        rest(10);
        if (key[KEY_SPACE])
            ballon(buffer);
        }
    allegro_exit();
    return 1;

}
END_OF_MAIN()