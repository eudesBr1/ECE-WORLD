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

void minicarte(BITMAP* buffer, int zoom_w,int zoom_h,int ecranx, int ecrany)
{
    BITMAP *buuffer;
    buuffer = create_bitmap(TAILLEMINICARTE_W,TAILLEMINICARTE_H);
    BITMAP *contours;
    contours = load_bitmap("../images/contours.bmp",NULL);
    if (!contours){
        allegro_message("Pb de l'image contours chargee");
        allegro_exit();
        exit(
                EXIT_FAILURE);
    }
    stretch_blit(buffer,buuffer,0,0,buffer->w,buffer->h,0,0,buuffer->w,buuffer->h);
    rect(buuffer,ecranx*buffer->w/TAILLEMINICARTE_W,ecrany*buffer->h/TAILLEMINICARTE_W,(ecranx+zoom_w)*buffer->w/TAILLEMINICARTE_W,(ecrany+zoom_h)*buffer->w/TAILLEMINICARTE_H,makecol(127,127,127));
    stretch_sprite(buuffer,contours,0,0,buuffer->w,buuffer->h);
    blit(buuffer,buffer,0,0,ecranx+zoom_w-TAILLEMINICARTE_W,ecrany+zoom_h-TAILLEMINICARTE_H,TAILLEMINICARTE_H,TAILLEMINICARTE_H);

}

void tab_score(t_player players[4],BITMAP *buffer)
{
    clear(buffer);
    BITMAP *SCORE;
    int width = text_length(font, "SCORE");
    int height = text_height(font);
    SCORE = create_bitmap(width, height);
    rectfill(buffer,0,0,wTABscore,screen->h, makecol(195,195,195));
    rectfill(SCORE, 0, 0, width, height, makecol(0, 0, 170));
    textout_ex(SCORE, font, "SCORE", 0, 0, makecol(255, 255, 255), -1);
    stretch_blit(SCORE, buffer, 0, 0, SCORE->w, SCORE->h, 0, 0, wTABscore, screen->h/5);
    for (int i = 0; i < players[0].nbJoueurs; i++)
    {
        stretch_sprite(buffer,players[i].bas[1],0,(i+1)*screen->h/5,wTABscore/3,(1)*screen->h/5);
        textprintf_ex(buffer,font,0,(i+1)*screen->h/5, makecol(129,128,67),-1,"%s",players[i].name);

    }

    blit(buffer,screen,0,0,screen->w-wTABscore,0,wTABscore,screen->h);
    destroy_bitmap(SCORE);
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

            ///dessin des joueurs sur la carte

            stretch_blit(carte,buffer,0,0,carte->w,carte->h,0,0,screen->w,screen->h);

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
            mouvementPersonnageZQSD(players,tour);
            minicarte(buffer,zoom_w,zoom_h,ecranx,ecrany);
            stretch_blit(buffer,screen,ecranx,ecrany,zoom_w,zoom_h,0,0,screen->w-wTABscore,screen->h);
            tab_score(players,buffer);
            rest(50);
            if (key[KEY_RIGHT])
            {
                tour++;
                tour = tour % players[0].nbJoueurs;
            }
        }
    } while (!check_defaite(players));

}