//
// Created by eudes on 15/05/2023.
//
#include "Mabibli.h"



void sauvegarde(t_player *player){
    int width;
    int height;
    BITMAP *save1;
    BITMAP *save2;
    BITMAP *save3;
    BITMAP *save1Bis;
    BITMAP *save2Bis;
    BITMAP *save3Bis;
    width = text_length(font, "Partie1111111");
    height = text_height(font);
    save1 = create_bitmap(width, height);
    save2 = create_bitmap(width, height);
    save3 = create_bitmap(width, height);
    save1Bis = create_bitmap(width, height);
    save2Bis = create_bitmap(width, height);
    save3Bis = create_bitmap(width, height);
    int rouge = makecol(255, 55, 55);
    int gris = makecol(127, 127, 127);
    rectfill(save1,0,0,save1->w,save1->w, gris);
    rectfill(save2,0,0,save1->w,save1->w, gris);
    rectfill(save3,0,0,save1->w,save1->w, gris);
    rectfill(save1Bis,0,0,save1->w,save1->w, rouge);
    rectfill(save2Bis,0,0,save1->w,save1->w, rouge);
    rectfill(save3Bis,0,0,save1->w,save1->w, rouge);
    textout_ex(save1, font, "Partie 1", 0, 0, rouge, -1);
    textout_ex(save2, font, "Partie 2", 0, 0, rouge, -1);
    textout_ex(save3, font, "Partie 3", 0, 0, rouge, -1);
    textout_ex(save1Bis, font, "Partie 1", 0, 0, gris, -1);
    textout_ex(save2Bis, font, "Partie 2", 0, 0, gris, -1);
    textout_ex(save3Bis, font, "Partie 3", 0, 0, gris, -1);
    BITMAP *buffer = create_bitmap(screen->w,screen->h);
    clear(buffer);
    clear(screen);
    char nomSave[15];
    rest(130);
    while (1){
        if(key[KEY_1] || key[KEY_1_PAD] ){
            strcpy(nomSave,"save1.txt");
            break;
        }
        if(key[KEY_2] || key[KEY_2_PAD]){
            strcpy(nomSave,"save2.txt");
            break;
        }
        if(key[KEY_3] || key[KEY_3_PAD]){
            strcpy(nomSave,"save3.txt");
            break;
        }
        if ( mouse_x>screen->w/2-10*save1->w/2 && mouse_x<screen->w/2 && mouse_y>screen->h/4+save1->h/2 && mouse_y<screen->h/4+save1->h/2+save1->h*10){
            clear(buffer);
            stretch_blit(save1Bis,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
            if (mouse_b == 1){
                strcpy(nomSave,"save1.txt");
                break;
            }
        }
        else if (mouse_x>screen->w/2-10*save1->w/2 && mouse_x<screen->w/2 && mouse_y>(screen->h/4)*2+save1->h/2 && mouse_y<(screen->h/4)*2+save1->h/2+save1->h*10){
            clear(buffer);
            stretch_blit(save1,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2Bis,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
            if (mouse_b == 1){
                strcpy(nomSave,"save2.txt");
                break;
            }
        }
        else if ( mouse_x>screen->w/2-10*save1->w/2 && mouse_x<screen->w/2 && mouse_y>(screen->h/4)*3+save1->h/2 && mouse_y<(screen->h/4)*3+save1->h/2+save1->h*10){
            clear(buffer);
            stretch_blit(save1,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3Bis,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
            if (mouse_b == 1){
                strcpy(nomSave,"save3.txt");
                break;
            }
        }
        else{
            clear(buffer);
            stretch_blit(save1,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
        }
    }
    FILE *fichierSave= fopen(nomSave,"w");
    if (fichierSave == NULL){
        printf("fichier save non ouvert");
        return;
    }
    for (int i = 0; i < player[0].nbJoueurs; ++i) {
        fprintf(fichierSave, "%d %d %d %d %d %s %d %d %d %d %d %d\n",
                player[i].x, player[i].y, player[i].ticket, player[i].points, player[0].nbJoueurs,
                player[i].name, player[i].position, player[i].animation, player[i].cheval,player[i].bitmap,player[i].perso_sur_bmp,player[i].score);
    }
    allegro_exit();
    exit(EXIT_SUCCESS);
}

void charger(t_player player[4]){
    int width;
    int height;
    BITMAP *save1;
    BITMAP *save2;
    BITMAP *save3;
    BITMAP *save1Bis;
    BITMAP *save2Bis;
    BITMAP *save3Bis;
    width = text_length(font, "Partie1111111");
    height = text_height(font);
    save1 = create_bitmap(width, height);
    save2 = create_bitmap(width, height);
    save3 = create_bitmap(width, height);
    save1Bis = create_bitmap(width, height);
    save2Bis = create_bitmap(width, height);
    save3Bis = create_bitmap(width, height);
    int rouge = makecol(255, 55, 55);
    int gris = makecol(127, 127, 127);
    rectfill(save1,0,0,save1->w,save1->w, gris);
    rectfill(save2,0,0,save1->w,save1->w, gris);
    rectfill(save3,0,0,save1->w,save1->w, gris);
    rectfill(save1Bis,0,0,save1->w,save1->w, rouge);
    rectfill(save2Bis,0,0,save1->w,save1->w, rouge);
    rectfill(save3Bis,0,0,save1->w,save1->w, rouge);
    textout_ex(save1, font, "Partie 1", 0, 0, rouge, -1);
    textout_ex(save2, font, "Partie 2", 0, 0, rouge, -1);
    textout_ex(save3, font, "Partie 3", 0, 0, rouge, -1);
    textout_ex(save1Bis, font, "Partie 1", 0, 0, gris, -1);
    textout_ex(save2Bis, font, "Partie 2", 0, 0, gris, -1);
    textout_ex(save3Bis, font, "Partie 3", 0, 0, gris, -1);
    BITMAP *buffer = create_bitmap(screen->w,screen->h);
    clear(buffer);
    clear(screen);
    char nomSave[15];
    rest(130);
    while (1){
        if(key[KEY_1] || key[KEY_1_PAD] ){
            strcpy(nomSave,"save1.txt");
            break;
        }
        if(key[KEY_2] || key[KEY_2_PAD]){
            strcpy(nomSave,"save2.txt");
            break;
        }
        if(key[KEY_3] || key[KEY_3_PAD]){
            strcpy(nomSave,"save3.txt");
            break;
        }
        if ( mouse_x>screen->w/2-10*save1->w/2 && mouse_x<screen->w/2 && mouse_y>screen->h/4+save1->h/2 && mouse_y<screen->h/4+save1->h/2+save1->h*10){
            clear(buffer);
            stretch_blit(save1Bis,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
            if (mouse_b == 1){
                strcpy(nomSave,"save1.txt");
                break;
            }
        }
        else if (mouse_x>screen->w/2-10*save1->w/2 && mouse_x<screen->w/2 && mouse_y>(screen->h/4)*2+save1->h/2 && mouse_y<(screen->h/4)*2+save1->h/2+save1->h*10){
            clear(buffer);
            stretch_blit(save1,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2Bis,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
            if (mouse_b == 1){
                strcpy(nomSave,"save2.txt");
                break;
            }
        }
        else if ( mouse_x>screen->w/2-10*save1->w/2 && mouse_x<screen->w/2 && mouse_y>(screen->h/4)*3+save1->h/2 && mouse_y<(screen->h/4)*3+save1->h/2+save1->h*10){
            clear(buffer);
            stretch_blit(save1,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3Bis,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
            if (mouse_b == 1){
                strcpy(nomSave,"save3.txt");
                break;
            }
        }
        else{
            clear(buffer);
            stretch_blit(save1,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,screen->h/4+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save2,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*2+save1->h/2,save1->w*10,save1->h*10);
            stretch_blit(save3,buffer,0,0,save1->w,save1->h,screen->w/2-10*save1->w/2,(screen->h/4)*3+save1->h/2,save1->w*10,save1->h*10);
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->h,screen->w);
            rest(1);
        }
    }
    FILE *fichierSave = fopen(nomSave, "r");
    if (fichierSave == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
    for (int i = 0; i < player[0].nbJoueurs; i++) {
        fscanf(fichierSave, "%d %d %d %d %d %s %d %d %d %d %d %d",
               &player[i].x, &player[i].y, &player[i].ticket, &player[i].points, &player[i].nbJoueurs,
               player[i].name, &player[i].position, &player[i].animation, &player[i].cheval,&player[i].bitmap,&player[i].perso_sur_bmp,&player[i].score);
        printf("%d %d %d %d %d %s %d %d %d %d %d\n",
               player[i].x, player[i].y, player[i].ticket, player[i].points, player[i].nbJoueurs,
               player[i].name, player[i].position, player[i].animation, player[i].cheval,player[i].bitmap,player[i].perso_sur_bmp);
    }

    for (int i = 0; i < player[0].nbJoueurs; ++i) {
        charger_skin(player,i);
    }
    
    fclose(fichierSave);
}
