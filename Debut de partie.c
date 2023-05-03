//
// Created by antoi on 27/04/2023.
//

#include "Mabibli.h"

/// au début de la partie on cherche a savoir le nombre de joueur présent

void gameInit(t_player *players){
    BITMAP *buffer;
    int nbJoueur = 0;
    int i,j;
    char charac;
    char buuffname[16] = {0} ;
    int blanc = makecol(255,255,255);
    buffer = create_bitmap(screen->w,screen->h);
    for (i = 0; i < 4; i++) {
        rectfill(buffer, 0, 0, screen->w, screen->h, makecol(0, 0, 0));
        textout_ex(buffer, font, "Chargement du jeu .", 50, 50, blanc, -1);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        clear(buffer);
        rest(400);
        rectfill(buffer, 0, 0, screen->w, screen->h, makecol(0, 0, 0));
        textout_ex(buffer, font, "Chargement du jeu ..", 50, 50, blanc, -1);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        clear(buffer);
        rest(400);
        rectfill(buffer, 0, 0, screen->w, screen->h, makecol(0, 0, 0));
        textout_ex(buffer, font, "Chargement du jeu ...", 50, 50, blanc, -1);
        if (i==3)
            textout_right_ex(buffer,font,"Press ENTER to continue",screen->w,screen->h-50,blanc,-1);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        clear(buffer);
        fflush(stdin);
        rest(100);
    }

    do {
        textout_centre_ex(buffer, font, "Indiquez le nombre de jouers ?", screen->w / 2, screen->h / 2 - 100,blanc, -1);
        textout_centre_ex(buffer, font, "(entre 1 et 4 joueurs)", screen->w/2, screen->h / 2 - 60,blanc, -1);
        fflush(stdin);
        charac = readkey();
        fflush(stdin);
        textprintf_centre_ex(buffer, font, screen->w / 2, screen->h / 2, blanc, -1, "%c", charac);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        clear(buffer);
        // printf("%d/%c\n", charac,charac);
        if ((charac<= 52 && charac >= 49)){
            if (charac == 49)
                nbJoueur = 1;
            else if (charac == 50)
                nbJoueur = 2;
            else if (charac == 51)
                nbJoueur = 3;
            else if (charac == 52)
                nbJoueur = 4;
            players = (t_player*) malloc(sizeof (t_player)*nbJoueur);
            rest(100);
            break;
        }
    } while (1);
    ///on initialise alors chaque joueur avec leurs noms et leur personnages
    for (i = 0; i < nbJoueur; i++) {
        players[i].points = 0;
        players[i].ticket = NBticketStart;
        for (j = 0; j < 16;) {
            textprintf_centre_ex(buffer, font, screen->w / 2, screen->h / 2 - 100, blanc, -1,"Joueur %d écris ton pseudo", i+1);
            textout_centre_ex(buffer, font, "(maximum 16 caractères)", screen->w/2, screen->h / 2 - 60, blanc, -1);
            charac = readkey();
            if (charac == 8 && j>=1){
                buuffname[j-1] = 0;
                j--;
            }
            else {
                buuffname[j] = charac;
                j++;
            }
            textprintf_centre_ex(buffer, font, screen->w / 2, screen->h / 2, blanc, -1, "%s",buuffname);
            //printf("%s/%d\t%d\n",buuffname,j,charac);
            blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);clear(buffer);
            clear(buffer);
            if (key[KEY_ENTER] && j>1)
                j = 16;
        }
        players[i].name = malloc(sizeof(buuffname));
        players[i].name = buuffname;

        for (j = 0; j < 16; j++) {
            buuffname[j] = 0;
        }

    }


}