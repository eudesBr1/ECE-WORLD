//
// Created by eudes on 23/04/2023.
//
#include "Mabibli.h"


int check_defaite(t_player players[4])
{
    for (int i = 0; i < players[0].nbJoueurs; i++) {
        if (players[i].ticket == 0 ){
            return i+1;
        }
    }
    return 0;
}
void tab_score(t_player players[4],BITMAP *buffer)
{

}

void affichageVille(t_player players[4]){
    int zoom_w = 400;
    int zoom_h = 300;
    int ecranx,ecrany;
    BITMAP *buffer= create_bitmap(screen->w,screen->h);
    clear(buffer);
    BITMAP *carte;
    /// charge carte ville
    carte = load_bitmap("../images/map_pokemon.bmp",NULL);
    if (!carte){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    do {
        clear(buffer);

        for (int tour = 0; tour < 10;) {
            if (players[tour].y + zoom_h/2 >= screen->h)
            {
                ecrany = screen->h-zoom_h;

            } else if (players[tour].y- zoom_h/2 <= 0)
            {
                ecrany = 0;

            } else
            {
                ecrany = players[tour].y-zoom_h/2;
            }

            if (players[tour].x + zoom_w/2  >= screen->w)
            {
                ecranx = screen->w-zoom_w;

            } else if (players[tour].x - zoom_w / 2 <= 0)
            {
                ecranx = 0;

            } else
            {
                ecranx = players[tour].x-zoom_w/2;
            }
            stretch_blit(carte,buffer,0,0,carte->w,carte->h,0,0,screen->w,screen->h);
            mouvementPersonnageZQSD(players,tour);

            ///dessin des joueurs sur la carte

            for (int i = 0; i < players[0].nbJoueurs; i++) {
                if (players[i].position == 0)
                {
                    stretch_sprite(buffer, players[i].haut[players[i].animation/10], players[i].x, players[i].y, W_PERSO, H_PERSO);
                }
                if (players[i].position == 1)
                {
                    stretch_sprite(buffer, players[i].droite[players[i].animation/10], players[i].x, players[i].y, W_PERSO, H_PERSO);
                }
                if (players[i].position == 2)
                {
                    stretch_sprite(buffer, players[i].bas[players[i].animation/10], players[i].x, players[i].y, W_PERSO, H_PERSO);
                }
                if (players[i].position == 3)
                {
                    stretch_sprite(buffer, players[i].gauche[players[i].animation/10], players[i].x, players[i].y, W_PERSO, H_PERSO);
                }
            }
            stretch_blit(buffer,screen,ecranx,ecrany,zoom_w,zoom_h,0,0,screen->w-wTABscore,screen->h);
            rest(50);
            if (key[KEY_RIGHT])
            {
                tour++;
                tour = tour % players[0].nbJoueurs;
            }
        }
    } while (!check_defaite(players));

}