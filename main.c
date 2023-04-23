#include "Mabibli.h"

int main(){
    allegro_init();
    t_player goku;
    t_player naruto;
    initEcran();
    install_keyboard();
    install_mouse();
    BITMAP *carte;
    srand(time(NULL));
    BITMAP *buffer= create_bitmap(screen->w,screen->h);
    clear(buffer);
    creationPersonnage(&goku);

    carte = load_bitmap("../images/map_pokemon.bmp",NULL);
    if (!carte){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while (!key[KEY_ESC]){
        blit(buffer,screen,0,0,0,0,screen->w, screen->h);
        blit(carte,buffer,goku.x,goku.y,0,0,screen->w,screen->h);
        mouvementPersonnageZQSD(&goku);
     //   mouvementPersonnageFleche(&goku);
        if (goku.position==0){
            draw_sprite(buffer,goku.haut[goku.animation/10],goku.x,goku.y);
        }
        if (goku.position==1){
            draw_sprite(buffer,goku.droite[goku.animation/10],goku.x,goku.y);
        }
        if (goku.position==2){
            draw_sprite(buffer,goku.bas[goku.animation/10],goku.x,goku.y);
        }
        if (goku.position==3){
            draw_sprite(buffer,goku.gauche[goku.animation/10],goku.x,goku.y);
        }

        rest(9);

        if (key[KEY_SPACE])
            ballon(goku,buffer);
        }
    allegro_exit();
    return 1;
}
END_OF_MAIN()
