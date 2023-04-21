#include <stdlib.h>
#include <time.h>
#include "allegro.h"
#include "stdio.h"

typedef struct player{
    int x,y,ticket,points;
    char* name;
}player;

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
    initEcran();
    install_keyboard();
    install_mouse();
    BITMAP *carte;
    //TODO Mettre image ville menu
    carte = load_bitmap("ville_menu.bmp",NULL);
    if (!carte){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    //stretch_blit(carte,screen,0,0,carte->w,carte->h,0,0,screen->w,screen->h);
    while (!key[KEY_ESC])
        blit(carte,screen,0,0,0,0,screen->w, screen->w);

    allegro_exit();
    return 1;
}
END_OF_MAIN()