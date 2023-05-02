//
// Created by eudes on 01/05/2023.
//
#include "Mabibli.h"

void courseHippique(t_player *player){
    #define tailleCheval 120
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
    BITMAP *templateCheval;
    templateCheval = load_bitmap("../images/spriteChevaux.bmp",NULL);
    if (!templateCheval){
        allegro_message("Pb de l'image courseHippique.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *cheval1[4];
    for (int i = 0; i < 4; ++i) {
        cheval1[i] = create_sub_bitmap(templateCheval,31*i,0,31,28);
    }
    BITMAP *cheval2[4];
    for (int i = 0; i < 4; ++i) {
        cheval2[i] = create_sub_bitmap(templateCheval,31*i,54,28,28);
    }
    BITMAP *menuCourseHippique;
    menuCourseHippique = load_bitmap("../images/courseHippiqueFond.bmp",NULL);
    stretch_blit(menuCourseHippique,buffer,0,0,menuCourseHippique->w,menuCourseHippique->h,0,0,screen->w,screen->h);
    BITMAP *templateBouton;
    BITMAP *boutonQuitter;
    templateBouton = load_bitmap("../images/quit_boutton.bmp",NULL);
    stretch_sprite(buffer, templateBouton, 30, screen->h - 100, 200, 85);
    while (!key[KEY_ESC] && !key[KEY_H]){
        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    }
    int i=0;
    int k = 2;
    int avanceeCheval1=10;
    int avanceeCheval2=10;
    while (!key[KEY_ESC] && coordonneesPiste<1300){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,250,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,450,tailleCheval,tailleCheval);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        srand(time(NULL)* time(NULL));
        avanceeCheval2 += rand()%8-3;
        rest(40);
        coordonneesPiste +=10;
        printf("Coordonnes cheval %d\n",avanceeCheval1);
        srand(time(NULL));
        avanceeCheval1 += rand()%8-3;
        i++;
        k++;
        if (i==16) i=0;
        if (k==16) k=0;
    }
    while (!key[KEY_ESC] && avanceeCheval1<screen->w/2 && avanceeCheval2<screen->w/2){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,250,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,450,tailleCheval,tailleCheval);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
     //   srand(time(NULL));
        avanceeCheval2 += rand()%8+7;
        rest(40);
      //  coordonneesPiste +=10;
        printf("Coordonnes cheval %d\n",avanceeCheval1);
      //  srand(time(NULL));
        avanceeCheval1 += rand()%8+7;
        i++;
        k++;
        if (i==16) i=0;
        if (k==16) k=0;
    }
    if (400+avanceeCheval1>400+avanceeCheval2){
        allegro_message("Cheval 1 a gagne !\n");
    }
    if (400+avanceeCheval1<400+avanceeCheval2){
        allegro_message("Cheval 2 a gagne !\n");
    }
}