#include <allegro.h>
#include <time.h>

int main()
{
    allegro_init(); // Initialisation d'Allegro
    install_keyboard(); // Installation du clavier

    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

    // Chargement de l'arrière-plan
    BITMAP *background = load_bitmap("background.bmp", NULL);

    // Chargement des sprites des symboles
    BITMAP *symbole_1 = load_bitmap("symbole_1.bmp", NULL);
    BITMAP *symbole_2 = load_bitmap("symbole_2.bmp", NULL);
    BITMAP *symbole_3 = load_bitmap("symbole_3.bmp", NULL);

    // Initialisation des variables du jeu
    int manivelle_active = 0;
    int symbole_1_tire = 0;
    int symbole_2_tire = 0;
    int symbole_3_tire = 0;
    int jackpot_gagne = 0;

    // Boucle principale du jeu
    while(!key[KEY_ESC])
    {
        // Si la touche espace est appuyée, on active la manivelle
        if(key[KEY_SPACE] && !manivelle_active)
        {
            manivelle_active = 1;

            // Tirage aléatoire des symboles
            srand(time(NULL));
            symbole_1_tire = rand() % 3 + 1;
            symbole_2_tire = rand() % 3 + 1;
            symbole_3_tire = rand() % 3 + 1;

            // Affichage de l'arrière-plan
            draw_sprite(screen, background, 0, 0);

            // Affichage des symboles
            if(symbole_1_tire == 1)
            {
                draw_sprite(screen, symbole_1, 50, 200);
            }
            else if(symbole_1_tire == 2)
            {
                draw_sprite(screen, symbole_2, 50, 200);
            }
            else if(symbole_1_tire == 3)
            {
                draw_sprite(screen, symbole_3, 50, 200);
            }

            if(symbole_2_tire == 1)
            {
                draw_sprite(screen, symbole_1, 200, 200);
            }
            else if(symbole_2_tire == 2)
            {
                draw_sprite(screen, symbole_2, 200, 200);
            }
            else if(symbole_2_tire == 3)
            {
                draw_sprite(screen, symbole_3, 200, 200);
            }

            if(symbole_3_tire == 1)
            {
                draw_sprite(screen, symbole_1, 350, 200);
            }
            else if(symbole_3_tire == 2)
            {
                draw_sprite(screen, symbole_2, 350, 200);
            }
            else if(symbole_3_tire == 3)
            {
                draw_sprite(screen, symbole_3, 350, 200);
            }

            // Vérification du jackpot
            if(symbole_1_tire == symbole_2_tire && symbole_1_tire == symbole_3_tire)
            {
                jackpot_gagne = 1;//
// Created by malik on 29/04/2023.
//
