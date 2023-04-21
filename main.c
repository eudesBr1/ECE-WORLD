#include <stdlib.h>
#include <time.h>
#include "allegro.h"
#include "stdio.h"

typedef struct player{
    int x,y,ticket,points;
    char* name;
    BITMAP *haut[3];
    BITMAP *bas[3];
    BITMAP *droite[3];
    BITMAP *gauche[3];
    int position[3];
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
    goku.haut[0] = create_sub_bitmap(GOKUTEMPLATE,0,149,32,48);
    goku.gauche[0] = create_sub_bitmap(GOKUTEMPLATE,0,46,32,49);
    goku.droite[0] = create_sub_bitmap(GOKUTEMPLATE,0,96,32,49);
    goku.bas[0] = create_sub_bitmap(GOKUTEMPLATE,0,0,32,49);
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
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        blit(carte,buffer,goku.x,goku.y,0,0,screen->w,screen->h);
        if(key[KEY_LEFT]){
            goku.x -= 2;
            draw_sprite(buffer,goku.gauche[0],goku.x,goku.y);
        }
        if(key[KEY_RIGHT]){
            goku.x += 2;
            draw_sprite(buffer,goku.droite[0],goku.x,goku.y);
        }
        if(key[KEY_UP]) {
            goku.y -= 2;
            draw_sprite(buffer,goku.haut[0],goku.x,goku.y);
        }
        if(key[KEY_DOWN]){
            goku.y += 2;
            draw_sprite(buffer,goku.bas[0],goku.x,goku.y);
        }
        rest(10);
        }
    allegro_exit();
    return 1;

}
END_OF_MAIN()