//
// Created by eudes on 01/05/2023.
//
#include "Mabibli.h"

void courseHippique(t_player *player){
    while (!key[KEY_ESC]){
        BITMAP *buffer;
        buffer = create_bitmap(screen->w,screen->h);
        BITMAP *fondCourseHippique;
        fondCourseHippique = load_bitmap("../images/courseHippique.bmp",NULL);
        if (!fondCourseHippique){
            allegro_message("Pb de l'image courseHippique.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
        stretch_blit(fondCourseHippique, buffer, 0, 0, fondCourseHippique->w, fondCourseHippique->h, 0, 0, fondCourseHippique->w, screen->h);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    }
}