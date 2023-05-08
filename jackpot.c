#include <allegro.h>
#include <time.h>

void jackpot_game(){
    allegro_init();
    install_keyboard();

    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);


    BITMAP *background = load_bitmap("background.bmp", NULL);
    BITMAP *symbole_1 = load_bitmap("../images/symbole_1.bmp", NULL);
    BITMAP *symbole_2 = load_bitmap("../images/symbole_2.bmp", NULL);
    BITMAP *symbole_3 = load_bitmap("../images/symbole_3.bmp", NULL);


    int manivelle_active = 0;
    int symbole_1_tire = 0;
    int symbole_2_tire = 0;
    int symbole_3_tire = 0;
    int jackpot_gagne = 0;


    while (!key[KEY_ESC]) {

        if (key[KEY_SPACE] && !manivelle_active) {
            manivelle_active = 1;


            srand(time(NULL));
            symbole_1_tire = rand() % 3 + 1;
            symbole_2_tire = rand() % 3 + 1;
            symbole_3_tire = rand() % 3 + 1;


            draw_sprite(screen, background, 0, 0);


            if (symbole_1_tire == 1) {
                draw_sprite(screen, symbole_1, 50, 200);
            } else if (symbole_1_tire == 2) {
                draw_sprite(screen, symbole_2, 50, 200);
            } else if (symbole_1_tire == 3) {
                draw_sprite(screen, symbole_3, 50, 200);
            }

            if (symbole_2_tire == 1) {
                draw_sprite(screen, symbole_1, 200, 200);
            } else if (symbole_2_tire == 2) {
                draw_sprite(screen, symbole_2, 200, 200);
            } else if (symbole_2_tire == 3) {
                draw_sprite(screen, symbole_3, 200, 200);
            }

            if (symbole_3_tire == 1) {
                draw_sprite(screen, symbole_1, 350, 200);
            } else if (symbole_3_tire == 2) {
                draw_sprite(screen, symbole_2, 350, 200);
            } else if (symbole_3_tire == 3) {
                draw_sprite(screen, symbole_3, 350, 200);
            }

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
