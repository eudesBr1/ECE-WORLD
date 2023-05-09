#include "Mabibli.h"

void jackpot_game(){
    BITMAP *background ;
    background = load_bitmap("../images/background.bmp", NULL);
    if (!background){
        allegro_message("Pb de l'image guitar_hero.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *symbole_1;
    symbole_1 = load_bitmap("../images/symbole_1.bmp", NULL);
    if (!symbole_1){
        allegro_message("Pb de l'image guitar_hero.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *symbole_2;
    symbole_2= load_bitmap("../images/symbole_2.bmp", NULL);
    if (!symbole_2){
        allegro_message("Pb de l'image guitar_hero.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *symbole_3;
    symbole_3= load_bitmap("../images/symbole_3.bmp", NULL);
    if (!symbole_3){
        allegro_message("Pb de l'image guitar_hero.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    int manivelle_active = 0;
    int symbole_1_tire = 0;
    int symbole_2_tire = 0;
    int symbole_3_tire = 0;
    int jackpot_gagne = 0;

    while (!key[KEY_ESC]) {
        stretch_blit(background,screen,0,0,background->w,background->h,0,0,screen->w,screen->h);
        if (key[KEY_SPACE] && !manivelle_active) {
            manivelle_active = 1;


            srand(time(NULL));
            symbole_1_tire = rand() % 3 + 1;
            symbole_2_tire = rand() % 3 + 1;
            symbole_3_tire = rand() % 3 + 1;



            if (symbole_1_tire == 1) {
                draw_sprite(screen, symbole_1, 700, 400);
                rest(10);
            } else if (symbole_1_tire == 2) {
                draw_sprite(screen, symbole_2, 700, 400);
                rest(10);
            } else if (symbole_1_tire == 3) {
                draw_sprite(screen, symbole_3, 700, 400);
                rest(10);
            }

            if (symbole_2_tire == 1) {
                draw_sprite(screen, symbole_1, 900, 400);
                rest(10);
            } else if (symbole_2_tire == 2) {
                draw_sprite(screen, symbole_2, 900, 400);
                rest(10);
            } else if (symbole_2_tire == 3) {
                draw_sprite(screen, symbole_3, 900, 400);
                rest(10);
            }

            if (symbole_3_tire == 1) {
                draw_sprite(screen, symbole_1, 1100, 400);
                rest(10);
            } else if (symbole_3_tire == 2) {
                draw_sprite(screen, symbole_2, 1100, 400);
                rest(10);
            } else if (symbole_3_tire == 3) {
                draw_sprite(screen, symbole_3, 1100, 400);

            }
            rest(10000);

            // Vérification du jackpot
            if (symbole_1_tire == symbole_2_tire && symbole_1_tire == symbole_3_tire) {
                jackpot_gagne = 1;
            }
        }


        vsync();
    }


    destroy_bitmap(background);
    destroy_bitmap(symbole_1);
    destroy_bitmap(symbole_2);
    destroy_bitmap(symbole_3);


    allegro_exit();

}//
// Created by malik on 29/04/2023.
//
