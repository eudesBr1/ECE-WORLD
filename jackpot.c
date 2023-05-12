#include "Mabibli.h"


void jackpot_game(){
    BITMAP *background ;
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    background = load_bitmap("../images/background.bmp", NULL);
    MIDI *music;
    music = load_midi("sounds/mainTheme.mid");
    if (!background){
        allegro_message("Pb de l'image background");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *symbole_1;
    symbole_1 = load_bitmap("../images/symbole_1.bmp", NULL);
    if (!symbole_1){
        allegro_message("Pb de l'image symbole");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *symbole_2;
    symbole_2= load_bitmap("../images/symbole_2.bmp", NULL);
    if (!symbole_2){
        allegro_message("Pb de l'image symbole 2");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *symbole_3;
    symbole_3= load_bitmap("../images/symbole_3.bmp", NULL);
    if (!symbole_3){
        allegro_message("Pb de l'image symbole 3");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    int manivelle_active = 0;
    int symbole_1_tire = 0;
    int symbole_2_tire = 0;
    int symbole_3_tire = 0;
    int jackpot_gagne = 0;

    stretch_blit(background,screen,0,0,background->w,background->h,0,0,screen->w,screen->h);

    while (!key[KEY_ESC]) {



        if (key[KEY_SPACE] && !manivelle_active) {

            for (int i = 0; i < 100; ++i) {
                clear(buffer);

                stretch_blit(background,buffer,0,0,background->w,background->h,0,0,screen->w,screen->h);
                circlefill(background,535,190,17, makecol(rand() % 255 + 1,rand() % 255 + 1,rand() % 255 + 1));
                rectfill(background,00,0,30,900, makecol(rand() % 255 + 1,rand() % 255 + 1,rand() % 255 + 1));
                rectfill(background,580 ,0,screen->w,900, makecol(rand() % 255 + 1,rand() % 255 + 1,rand() % 255 + 1));




                manivelle_active = 1;


                symbole_1_tire = rand() % 3 + 1;
                symbole_2_tire = rand() % 3 + 1;
                symbole_3_tire = rand() % 3 + 1;


                if (symbole_1_tire == 1) {
                    draw_sprite(buffer, symbole_1, 560, 450);
                    rest(10);
                } else if (symbole_1_tire == 2) {
                    draw_sprite(buffer, symbole_2, 560, 450);
                    rest(10);
                } else if (symbole_1_tire == 3) {
                    draw_sprite(buffer, symbole_3, 560, 450);
                    rest(10);
                }

                if (symbole_2_tire == 1) {
                    draw_sprite(buffer, symbole_1, 885, 450);
                    rest(10);
                } else if (symbole_2_tire == 2) {
                    draw_sprite(buffer, symbole_2, 885, 450);
                    rest(10);
                } else if (symbole_2_tire == 3) {
                    draw_sprite(buffer, symbole_3, 885, 450);
                    rest(10);
                }

                if (symbole_3_tire == 1) {
                    draw_sprite(buffer, symbole_1, 1200, 450);
                    rest(10);
                } else if (symbole_3_tire == 2) {
                    draw_sprite(buffer, symbole_2, 1200, 450);
                    rest(10);
                } else if (symbole_3_tire == 3) {
                    draw_sprite(buffer, symbole_3, 1200, 450);

                }
                blit(buffer,screen,0,0,0,0,screen->w,screen->h);
                rest(0.01*i*i);

            }
            int symb1=symbole_1_tire;
            int symb2=symbole_2_tire;
            int symb3=symbole_3_tire;
            for (int i = 0; i < 3; ++i) {
                if (symb1  == 1) {
                    draw_sprite(buffer, symbole_1, 560, 450);
                    rest(10);
                } else if (symb1  == 2) {
                    draw_sprite(buffer, symbole_2, 560, 450);
                    rest(10);
                } else if (symb1 == 3) {
                    draw_sprite(buffer, symbole_3, 560, 450);
                    rest(10);
                }

                if (symb2 == 1) {
                    draw_sprite(buffer, symbole_1, 885, 450);
                    rest(10);
                } else if (symb2== 2) {
                    draw_sprite(buffer, symbole_2, 885, 450);
                    rest(10);
                } else if (symb2 == 3) {
                    draw_sprite(buffer, symbole_3, 885, 450);
                    rest(10);
                }

                if (symb3 == 1) {
                    draw_sprite(buffer, symbole_1, 1200, 450);
                    rest(10);
                } else if (symb3 == 2) {
                    draw_sprite(buffer, symbole_2, 1200, 450);
                    rest(10);
                } else if (symb3== 3) {
                    draw_sprite(buffer, symbole_3, 1200, 450);

                }
                blit(buffer,screen,0,0,0,0,screen->w,screen->h);
                rest(1000);
            }
            manivelle_active = 0;

            // Vérification du jackpot

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
