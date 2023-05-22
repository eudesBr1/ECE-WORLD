//
// Created by antoi on 30/04/2023.
//

#include <math.h>
#include "Mabibli.h"
int calcul_speed(int iteration,int speed_base,int acceleration){

    return speed_base + iteration / 500 * acceleration;

}

void settings(int *speed,int *acceleration,BITMAP *buffer)
{
    int width = text_length(font, "PARAMETRES");
    int height = text_height(font);
    int condition = 0;
    BITMAP *para = create_bitmap(width,height);
    rectfill(para,0,0,para->w,para->h, makecol(255,0,255));

    BITMAP *retour;
    retour = load_bitmap("../images/boutton_retour.bmp",NULL);
    if (!retour){
        allegro_message("Pb de l'image boutton_retour.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int blanc = makecol(255, 255, 255);
    int noir = makecol(0,0,0);
    int beige = makecol(127,255,197);
    int saumon = makecol(255, 178, 127);
    do {
        clear(buffer);
        rectfill(buffer, 0, 0, buffer->w, buffer->h / 9, blanc);
        rectfill(buffer, 0, buffer->h/9, buffer->w, buffer->h/9+50, saumon);
        textout_ex(para,font,"PARAMETRES",0,0, noir,-1);
        stretch_sprite(buffer,para,buffer->w/2-220,9,440,buffer->h/9+60);
        textout_centre_ex(buffer, font, "VITESSE_BASE", 45, 3*screen->h/9, blanc, -1);
        textout_centre_ex(buffer,font,"ACCELERATION ; ",45,6*screen->h/9, makecol(255,50,50),-1);
        if (mouse_x <= (100) && mouse_x >= (0) && mouse_y >= (screen->h - 100) && mouse_y <= (screen->h)) {
            stretch_sprite(buffer, retour, 0, buffer->h - 130, 150, 150);
            if (mouse_b == 1){
                condition=1;
            }
        }
        else
            stretch_sprite(buffer, retour, 0, buffer->h - 100, 100, 100);
        rectfill(buffer,2*screen->w/9,3*screen->h/9-10,7*screen->w/9,3*screen->h/9+10,blanc);
        for (int i = 0; i < 6; i++) {
            if ((mouse_x > ((screen->w*(i+2)))/9 && mouse_x < ((screen->w*(i+2.5))/9) && (mouse_y > (3*screen->h/9-50) && mouse_y < (3*screen->h/9+50)))||*speed == i + 1) {
                rectfill(buffer, (screen->w*(i+2))/9, (3*screen->h/9-50), ((screen->w*(i+2.5))/9), (3*screen->h/9+50), beige);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (3*screen->h/9+65), beige, -1, "%d", i + 1);
                if (mouse_b == 1){
                    *speed = i+1;
                }

            }
            else {
                rectfill(buffer, (screen->w*(i+2))/9, (3*screen->h/9-50), ((screen->w*(i+2.5))/9), (3*screen->h/9+50), blanc);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (3*screen->h/9+65), blanc, -1, "%d", i + 1);
            }
        }
        rectfill(buffer,2*screen->w/9,6*screen->h/9-10,7*screen->w/9,6*screen->h/9+10,blanc);
        for (int i = 0; i < 6; i++) {
            if ((mouse_x > ((screen->w*(i+2)))/9 && mouse_x < ((screen->w*(i+2.5))/9) && (mouse_y > (6*screen->h/9-50) && mouse_y < (6*screen->h/9+50)))||*acceleration == i + 1) {
                rectfill(buffer, (screen->w*(i+2))/9, (6*screen->h/9-50), ((screen->w*(i+2.5))/9), (6*screen->h/9+50), beige);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (6*screen->h/9+65), beige, -1, "%d", i + 1);
                if (mouse_b == 1){
                    *acceleration = i+1;
                }

            }
            else {
                rectfill(buffer, (screen->w*(i+2))/9, (6*screen->h/9-50), ((screen->w*(i+2.5))/9), (6*screen->h/9+50), blanc);
                textprintf_centre_ex(buffer, font, (screen->w*(i+2.25))/9, (6*screen->h/9+65), blanc, -1, "%d", i + 1);
            }

        }

        stretch_sprite(buffer,mouse_sprite,mouse_x,mouse_y,mouse_sprite->w*4,mouse_sprite->h*4);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    } while (!condition);
    rest(300);
}

void verif_score(int column, t_tuiles *tuiles, int *score, int offset, BITMAP *tuilePLEINE[4], int *erreurs) {
    int numLigne;
    printf("%d",offset);
    if (offset<70){
        numLigne = 1;
    } else{
        numLigne = 0;
    }
    if (offset>70)
        numLigne = 2;
    //printf("\t%d",numLigne);
    //printf("\t %d:%d\n",numLigne,tuiles->couleur[column][numLigne]);
    if (tuiles->couleur[column][numLigne] < 4) {
        (*score)++;
        tuiles->tuiles[column][numLigne] = tuilePLEINE[column];
        tuiles->couleur[column][numLigne] = 9;

        // deRemplacer l'image par une image ou les  blancs adjacents par du gris foncé

    } else if (tuiles->couleur[column][numLigne] == 9){
        return;
    }
    else if (tuiles->pressed[column][numLigne])
    {
        return;

    } else {

        tuiles->pressed[column][numLigne] = 1;
        *erreurs+=1;
        return;

    }
}

void scroll_background(BITMAP *buffer, BITMAP *background[10], int game_iteration, int *offset,t_tuiles *tuiles,int speed_base,int acceleration,int *erreur_return) {
    int speed = calcul_speed(game_iteration,speed_base,acceleration);

    printf("off set : %d\n",*offset);
    //printf("test 1\n");

    *offset = (*offset + speed);

    //printf("test 2\n");

    if (*offset >= h_tuile) {
        //printf("%d\t",*erreur_return);
        for (int j = 0; j < 4; ++j) {
                if (tuiles->couleur[j][0] <= 3) {
                    printf("test");
                    *erreur_return+=1;
                }
        }
        //printf("%d\n",*erreur_return);

        //printf("scroll_background %d\n", speed);
        for (int i = 0; i <= 7; i++) {
            for (int j = 0; j < 4; ++j) {
                    tuiles->tuiles[j][i] = tuiles->tuiles[j][i + 1];
                    tuiles->couleur[j][i] = tuiles->couleur[j][i + 1];
                    // printf("test col %d\n",j);
                    if (i == 7) {
                        tuiles->couleur[j][i] = 10;
                        tuiles->pressed [j][i] = 0;
                    }
                }

                //printf("test ligne %d\n",i);

            }

        }
        *offset = *offset % h_tuile;
        int dessin;
        for (int lignes = 0; lignes <= 7; lignes++) {
            for (int colonnes = 0; colonnes < 4; colonnes++) {
                dessin = rand() % 4;
                //printf("%d %d\t%d/%d\n",tuiles->couleur[colonnes][lignes],dessin,colonnes,lignes);
                if (!dessin && tuiles->couleur[colonnes][lignes] == 10) {
                    tuiles->couleur[colonnes][lignes] = colonnes;
                    //printf("test\n");
                    tuiles->tuiles[colonnes][lignes] = background[tuiles->couleur[colonnes][lignes]];
                    //printf("test\n");
                    //printf("test\n");
                } else if (tuiles->couleur[colonnes][lignes] == 10) {
                    tuiles->couleur[colonnes][lignes] = 3 + dessin;
                    tuiles->tuiles[colonnes][lignes] = background[tuiles->couleur[colonnes][lignes]];
                }
                stretch_blit(tuiles->tuiles[colonnes][lignes], buffer, 0, 0, tuiles->tuiles[colonnes][lignes]->w,
                             tuiles->tuiles[colonnes][lignes]->h,
                             (screen->w + colonnes * screen->w) / 6, screen->h - h_tuile * lignes + *offset,
                             screen->w / 6,
                             h_tuile);
                //  printf("%d\t%d/%d\n",tuiles->couleur[colonnes][lignes],colonnes,lignes);

            }
        }
    }

void game_GUITARE(t_player *players)
{
    int speed = 1;
    int acceleration = 1;
    int game_iteration = 0;
    t_tuiles tuiles;
    int score = 0; /// Nombre de touches touchées par le joueur
    int offset = 0; /// Valeur de décalage du terrain sur l'écran

    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    int condition = 0;
    BITMAP *loadingscreen;
    loadingscreen = load_bitmap("../images/guitar_hero.bmp",NULL);
    if (!loadingscreen){
        allegro_message("Pb de l'image guitar_hero.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *play_boutton;
    play_boutton = load_bitmap("../images/Boutton_jouer.bmp",NULL);
    if (!play_boutton){
        allegro_message("Pb de l'image Boutton_jouer.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *settings_button;
    settings_button = load_bitmap("../images/setting_button.bmp",NULL);
    if (!settings_button){
        allegro_message("Pb de l'image Boutton_jouer.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *quit_button;
    quit_button = load_bitmap("../images/quit_boutton.bmp",NULL);
    if (!quit_button){
        allegro_message("Pb de l'image quit_boutton.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *photo_guitare_grande;
    photo_guitare_grande = load_bitmap("../images/photo_guitare.bmp",NULL);
    if (!photo_guitare_grande){
        allegro_message("Pb de l'image photo_guitare.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *photo_guitare;
    photo_guitare = create_bitmap(48,48);
    stretch_sprite(photo_guitare,photo_guitare_grande,0,0,48,48);

    do {
        ///affichage si la souris est sur le boutton jouer
        if (mouse_x <= (screen->w / 2 + 100) && mouse_x >= (screen->w / 2 - 100) &&mouse_y >= (screen->h / 2 - 100) && mouse_y <= (screen->h / 2 + 100)) {
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 150, screen->h / 2 - 50, 300, 100);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
            if (mouse_b == 1) {
                //printf("debut du jeu\n");
                condition = 1;
            }
        }
            ///affichage si la souris est sur le boutton parametre
        else if (mouse_x <= (screen->w) && mouse_x >= (screen->w - 80) && mouse_y >= (screen->h - 80) &&
                 mouse_y <= (screen->h)) {
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            stretch_sprite(buffer, settings_button, screen->w - 105, screen->h -105, 130, 130);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            if (mouse_b == 1) {
                //printf("parametres ouverts\n");
                settings(&speed, &acceleration,buffer);
            }
        }
            ///affichage si le boutton quit est au niveau de la souris
        else if (mouse_x <= (150) && mouse_x >= (0) && mouse_y >= (screen->h - 80) && mouse_y <= (screen->h)) {
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, quit_button, -5, screen->h - 90, 200, 80);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
            if (mouse_b == 1) {
                destroy_bitmap(buffer);
                destroy_bitmap(play_boutton);
                destroy_bitmap(loadingscreen);
                destroy_bitmap(settings_button);
                destroy_bitmap(quit_button);
                return;
            }
        }
            ///affichage normal
        else {
            stretch_blit(loadingscreen, buffer, 0, 0, loadingscreen->w, loadingscreen->h, 0, 0, screen->w, screen->h);
            stretch_sprite(buffer, play_boutton, screen->w / 2 - 100, screen->h / 2 - 25, 200, 50);
            stretch_sprite(buffer, quit_button, 0, screen->h - 80, 150, 60);
            stretch_sprite(buffer, settings_button, screen->w - 80, screen->h - 80, 80, 80);
        }
        stretch_sprite(buffer, mouse_sprite, mouse_x, mouse_y, mouse_sprite->w * 4, mouse_sprite->h * 4);
        //blit(mouse_sprite,buffer,0,0,mouse_x,mouse_y,mouse_sprite->w,mouse_sprite->h);
        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
    }   while (!condition);
    clear(buffer);
    ///on commence par faire une animation pour commencer le jeu
    int x ;
    int y ;
    float agrandissement = 1;
    float angle = 0;
    int rayon = buffer->w/2;

    for (int i = 0; i < 350; i++) {
        x = rayon* cos(angle);
        y = rayon* sin(angle);
        stretch_blit(photo_guitare,buffer,10,10,38,38,x,y,photo_guitare->w*agrandissement,photo_guitare->h*agrandissement);
        textprintf_centre_ex(buffer, font,screen->w/2, h_tuile, makecol(255, 255, 255), 0, "azer pour les colonnes de 1 a 4");
        angle+=0.02;
        agrandissement+= 0.2;
        //printf("%d\n",i);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(5);
        clear(buffer);
    }
    ///une fois l'animation passer on va lancer le jeu

    int offsetX = screen->w/6;
    int erreurs = 0;

    ///on commence par charger les images des touches
    BITMAP *touche[7];
    touche[0] = load_bitmap("../images/TOUCHE_BLEU.bmp",NULL);
    if (!touche[0]){
        allegro_message("Pb de l'image TOUCHE_BLEU.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[1] = load_bitmap("../images/TOUCHE_JAUNE.bmp",NULL);
    if (!touche[1]){
        allegro_message("Pb de l'image TOUCHE_JAUNE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[2] = load_bitmap("../images/TOUCHE_ROUGE.bmp",NULL);
    if (!touche[2]){
        allegro_message("Pb de l'image TOUCHE_ROUGE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[3] = load_bitmap("../images/TOUCHE_VERT.bmp",NULL);
    if (!touche[3]){
        allegro_message("Pb de l'image TOUCHE_VERT.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[4] = load_bitmap("../images/TOUCHE_VIDE1.bmp",NULL);
    if (!touche[4]){
        allegro_message("Pb de l'image TOUCHE_VIDE1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[5] = load_bitmap("../images/TOUCHE_VIDE2.bmp",NULL);
    if (!touche[5]){
        allegro_message("Pb de l'image TOUCHE_VIDE2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touche[6] = load_bitmap("../images/TOUCHE_VIDE3.bmp",NULL);
    if (!touche[6]){
        allegro_message("Pb de l'image TOUCHE_VIDE3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *touchePLEINE[4];
    touchePLEINE[0] = load_bitmap("../images/TOUCHE_BLEU_PLEINE.bmp",NULL);
    if (!touchePLEINE[0]){
        allegro_message("Pb de l'image TOUCHE_BLEU_PLEINE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touchePLEINE[1] = load_bitmap("../images/TOUCHE_JAUNE_PLEINE.bmp",NULL);
    if (!touchePLEINE[1]){
        allegro_message("Pb de l'image TOUCHE_JAUNE_PLEINE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touchePLEINE[2] = load_bitmap("../images/TOUCHE_ROUGE_PLEINE.bmp",NULL);
    if (!touchePLEINE[2]){
        allegro_message("Pb de l'image TOUCHE_ROUGE_PLEINE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    touchePLEINE[3] = load_bitmap("../images/TOUCHE_VERT_PLEINE.bmp",NULL);
    if (!touchePLEINE[3]){
        allegro_message("Pb de l'image TOUCHE_VERT_PLEINE.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j < 4; j++) {
            tuiles.tuiles[j][i] = create_bitmap(860,860);
            tuiles.couleur[j][i] = 10;
            tuiles.pressed[j][i] = 0;
        }
    }
    srand(time(NULL));
    ///on dessine le score sur le buffer
    while (!key[KEY_ESC]){
        clear_to_color(buffer, makecol(0, 0, 0)); // Clear du buffer
        scroll_background(buffer,touche,game_iteration,&offset,&tuiles,speed,acceleration,&erreurs);
        calcul_speed(game_iteration,speed,acceleration);
        // Gérer les entrées de l'utilisateur et le score
        int column = -1;
        if (key[KEY_Q]) {
            column = 0;
        } if (key[KEY_W]) {
            column = 1;
        } if (key[KEY_E]) {
            column = 2;
        } if (key[KEY_R]) {
            column = 3;
        }
        /// Si une touche a été enfoncée, on appelle la fonction qui gère le score et modifie la couleur de la tuile
        if (column != -1) {
            verif_score(column, &tuiles, &score, offset, touchePLEINE, &erreurs);

            /// On affiche le cercle rouge correspondant à l'endroit où le joueur est en train d'appuyer
            circlefill(buffer, offsetX + column * w_tuile + w_tuile/2, screen->h - 2 - 50, 5,
                       makecol(255, 0, 0));
        }


        // Dessiner une ligne en bas de l'écran, 50 pixels plus haut
        hline(buffer, 0, screen->h - 1 - 50, screen->w - 1, makecol(255, 0, 0));

        // Afficher le score

        textprintf_ex(buffer, font, 10, 10, makecol(255, 255, 255), -1, "Score: %d", score);
        textprintf_ex(buffer, font, 10, 25, makecol(255, 255, 255), -1, "Erreurs: %d", erreurs);


        // Copier le buffer sur l'écran

        blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
        if (erreurs >= 5){
            //allegro_message("fin du jeux vouas avez fait un score de %d",score);
            if (score<10){
              //  allegro_message("pas de chance ... vous pouvez réessayer");
                players->ticket--;
                return;
            } else if (score<20){
                //allegro_message("pas mal continuez de vous entrainez vous remportez un points mais perdez un ticket");
                players->ticket--;
                players->points++;
                return;
            }else if (score<30){
                //allegro_message("vous etes fort vous remportez un point");
                players->points++;
                return;
            } else if (score < 50){
                //allegro_message("un sur homme vous gagnez 2 points");
                players->points+=2;
                return;
            } else if (score > 50){
                //allegro_message("etes vous humains ? vous remportez 2 points et 1 tickets ");
                players->points+=2;
                players->ticket++;
                return;
            }
        }

        rest(20);
        game_iteration++;
    }
    rest(500);

}
