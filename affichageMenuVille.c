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
        exit(EXIT_FAILURE);
    }
    stretch_blit(buffer,buuffer,0,0,buffer->w,buffer->h,0,0,buuffer->w,buuffer->h);
    rect(buuffer,ecranx*buffer->w/TAILLEMINICARTE_W,ecrany*buffer->h/TAILLEMINICARTE_W,(ecranx+zoom_w)*buffer->w/TAILLEMINICARTE_W,(ecrany+zoom_h)*buffer->w/TAILLEMINICARTE_H,makecol(127,127,127));
    stretch_sprite(buuffer,contours,0,0,buuffer->w,buuffer->h);
    blit(buuffer,buffer,0,0,ecranx+zoom_w-TAILLEMINICARTE_W,ecrany+zoom_h-TAILLEMINICARTE_H,TAILLEMINICARTE_H,TAILLEMINICARTE_H);

}

void tab_score(t_player players[4],BITMAP *buffer,int numJoueur)
{
    clear(buffer);
    BITMAP *SCORE;
    int width = text_length(font, "SCORE");
    int height = text_height(font);
    SCORE = create_bitmap(width, height);
    rectfill(buffer,0,0,wTABscore,screen->h, makecol(195,195,195));
    rectfill(SCORE, 0, 0, width, height, makecol(0, 0, 170));
    
    int blanc = makecol(255, 255, 255);
    int noir = makecol(0, 0, 0);
    int red = makecol(255, 55, 55);
    int gris = makecol(127,127,127);

    textout_ex(SCORE, font, "SCORE", 0, 0, blanc, -1);
    stretch_blit(SCORE, buffer, 0, 0, SCORE->w, SCORE->h, 0, 0, wTABscore, screen->h/5);

    line(buffer, wTABscore / 3, screen->h / 5, wTABscore / 3, screen->h, noir);
    line(buffer,2*wTABscore/3,screen->h/5,2*wTABscore/3, screen->h, noir);
    textprintf_centre_ex(buffer, font,wTABscore/2,screen->h/5-height, blanc, -1, "TICKETS");
    textprintf_centre_ex(buffer, font,5*wTABscore/6,screen->h/5-height, blanc, -1, "POINTS");
    
    
    for (int i = 0; i < players[0].nbJoueurs; i++)
    {
        clear(SCORE);

        if (i == numJoueur) {
            clear(SCORE);
            rectfill(SCORE, 0, 0, SCORE->w, SCORE->h, red);
            textprintf_centre_ex(SCORE, font, SCORE->w / 2, 0, gris, -1, "%d", players[i].ticket);
            stretch_blit(SCORE,buffer,0,0,SCORE->w,SCORE->h,wTABscore/3+1,(1+i)*screen->h/5+1,wTABscore/3-2,screen->h/5-2);

            clear(SCORE);
            rectfill(SCORE, 0, 0, SCORE->w, SCORE->h, red);
            textprintf_centre_ex(SCORE, font, SCORE->w / 2, 0, gris, -1, "%d", players[i].points);
            stretch_blit(SCORE,buffer,0,0,SCORE->w,SCORE->h,2*wTABscore/3+1,(1+i)*screen->h/5+1,wTABscore/3-2,screen->h/5-2);


        } else
        {
            clear(SCORE);
            rectfill(SCORE, 0, 0, SCORE->w, SCORE->h, gris);
            textprintf_centre_ex(SCORE, font, SCORE->w / 2, 0, red, -1, "%d", players[i].ticket);
            stretch_blit(SCORE,buffer,0,0,SCORE->w,SCORE->h,wTABscore/3+1,(1+i)*screen->h/5+1,wTABscore/3-2,screen->h/5-2);

            clear(SCORE);
            rectfill(SCORE, 0, 0, SCORE->w, SCORE->h, gris);
            textprintf_centre_ex(SCORE, font, SCORE->w / 2, 0, red, -1, "%d", players[i].points);
            stretch_blit(SCORE,buffer,0,0,SCORE->w,SCORE->h,2*wTABscore/3+1,(1+i)*screen->h/5+1,wTABscore/3-2,screen->h/5-2);
        }
        line(buffer,0,i*screen->h/5,wTABscore,i*screen->w/5,noir);
        stretch_sprite(buffer,players[i].bas[1],0,(i+1)*screen->h/5,wTABscore/3,(1)*screen->h/5);
        textprintf_ex(buffer,font,0,(i+1)*screen->h/5, makecol(129,128,67),-1,"%s",players[i].name);

    }

    blit(buffer,screen,0,0,screen->w-wTABscore,0,wTABscore,screen->h);
    destroy_bitmap(SCORE);
}

void pause(t_player player[4],BITMAP *pausePlay[2],BITMAP *buffer)
{
    BITMAP *quit_button;
    quit_button = load_bitmap("../images/quit_boutton.bmp", NULL);
    if (!quit_button) {
        allegro_message("Pb de l'image quit_boutton.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *carte;
    carte = create_bitmap(screen->w,screen->h);
    blit(buffer,carte,0,0,0,0,screen->w,screen->h);
   // carte = buffer;

    while (1)
    {
        blit(carte,buffer,0,0,0,0,screen->w,screen->h);

        if (mouse_x<=screen->w/2+150&&mouse_x>=screen->w/2-150 && mouse_y<=screen->h/2+150 && mouse_y >=screen->h/2-150){

            stretch_sprite(buffer,pausePlay[0],screen->w/2-155,screen->h/2-150,300,300);
            stretch_sprite(buffer,quit_button,0,screen->h-50,120,50);
            if (mouse_b == 1){
                destroy_bitmap(quit_button);
                return;
            }
        }else if (mouse_x<=120&&mouse_x>=0 && mouse_y<=screen->h && mouse_y >=screen->h-50){
            stretch_sprite(buffer, pausePlay[1], screen->w / 2 - 145, screen->h / 2 - 150, 300, 300);
            stretch_sprite(buffer, quit_button, 0, screen->h - 75, 175, 75);
            if (mouse_b == 1){
                sauvegarde(player);
                allegro_exit();
                exit(EXIT_SUCCESS);
            }
        } else
        {
            stretch_sprite(buffer, pausePlay[1], screen->w / 2 - 145, screen->h / 2 - 150, 300, 300);
            stretch_sprite(buffer, quit_button , 0, screen->h - 50, 120, 50);
        }


        stretch_sprite(buffer,mouse_sprite,mouse_x,mouse_y,mouse_sprite->w*2,mouse_sprite->h*2);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        stretch_blit(buffer,screen,0,0,screen->w,screen->h,0,0,screen->w,screen->h);

        clear(buffer);
    }
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
    BITMAP *pause_play;
    pause_play = load_bitmap("../images/pause_play.bmp", NULL);
    if (!pause_play) {
        allegro_message("Pb de l'image pause_play.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *pausePlay[2];
    for (int i = 0; i < 2; i++) {
        pausePlay[i] = create_sub_bitmap(pause_play,pause_play->w/2*i,0,pause_play->w/2,pause_play->h);
    }
    BITMAP *carte_dessus;
    /// charge carte ville par dessus
    carte_dessus = load_bitmap("../images/map_pokemon_dessus.bmp",NULL);
    if (!carte_dessus){
        allegro_message("Pb de l'image chargee map_pokemon_dessus.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *fond;
    fond = load_bitmap("../images/map_collision.bmp",NULL);
    if (!fond){
        allegro_message("Pb de récupération de map_collision.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int collision_res;

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

            if (key[KEY_ESC])
            {
                pause(players,pausePlay,buffer);
            }

            collision_res = collision(players[tour],fond);

            mouvementPersonnageZQSD(players,tour,collision_res);


            stretch_sprite(buffer,carte_dessus,0,0,screen->w,screen->h);


            minicarte(buffer,zoom_w,zoom_h,ecranx,ecrany);


            stretch_blit(buffer,screen,ecranx,ecrany,zoom_w,zoom_h,0,0,screen->w-wTABscore,screen->h);

            tab_score(players,buffer,tour);


            rest(50);
            if (key[KEY_RIGHT])
            {
                tour++;
                tour = tour % players[0].nbJoueurs;
            }
        }
    } while (!check_defaite(players));

}