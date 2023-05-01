//
// Created by eudes on 01/05/2023.
//
#include "Mabibli.h"

void courseHippique(t_player *player){
    int coordonneesPiste=0;
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    BITMAP *fondCourseHippique;
    fondCourseHippique = load_bitmap("../images/courseHippique.bmp",NULL);
    if (!fondCourseHippique){
        allegro_message("Pb de l'image courseHippique.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    while (!key[KEY_ESC] && coordonneesPiste<1300){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(1);
        coordonneesPiste +=1;
        printf("Coordonnes piste %d\n",coordonneesPiste);
        printf("taille screen %d\n",buffer->w);
    }
}