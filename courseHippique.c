//
// Created by eudes on 01/05/2023.
//
#include "Mabibli.h"
void debutCourse(t_player *player);
void courseHippique(t_player *player){
    ///charge image menu et boutons
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    BITMAP *menuCourseHippique;
    menuCourseHippique = load_bitmap("../images/courseHippiqueFond.bmp",NULL);
    BITMAP *boutonQuitter;
    boutonQuitter = load_bitmap("../images/quit_boutton.bmp",NULL);
    BITMAP *boutonStart;
    boutonStart = load_bitmap("../images/boutonStartCourse.bmp",NULL);
    ///affichage menu
    while (!key[KEY_ESC] && !key[KEY_G]){
        stretch_blit(menuCourseHippique,buffer,0,0,menuCourseHippique->w,menuCourseHippique->h,0,0,screen->w,screen->h);
        printf("%d\n",mouse_y);
        if (mouse_x>20 && mouse_x<200 && mouse_y>screen->h-60 && mouse_y<screen->h-10){
            stretch_sprite(buffer, boutonQuitter, 0, screen->h - 80, 260, 80);
            stretch_sprite(buffer,boutonStart,screen->w/2-60,screen->h/2+30,120,70);
            if (mouse_b == 1){
                destroy_bitmap(buffer);
                destroy_bitmap(menuCourseHippique);
                destroy_bitmap(boutonQuitter);
                return;
            }
        }
        else if (mouse_x>screen->w/2-60 && mouse_x<screen->w/2+60 && mouse_y> screen->h/2+30 && mouse_y < screen->h/2+130){
            stretch_sprite(buffer, boutonQuitter, 20, screen->h - 60, 180, 50);
            stretch_sprite(buffer,boutonStart,screen->w/2-80,screen->h/2+15,160,100);
            if (mouse_b == 1){
                debutCourse(player);
            }
        }
        else{
            stretch_sprite(buffer, boutonQuitter, 20, screen->h - 60, 180, 50);
            stretch_sprite(buffer,boutonStart,screen->w/2-60,screen->h/2+30,120,70);
        }
        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        clear(buffer);
        //rest(1);
    }
    rest(50);
}
void debutCourse(t_player *player){
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
    ///decoupe animation cheval
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
    ///animation confettis
    BITMAP *confettis[14];
    BITMAP *templateConfettis;
    templateConfettis = load_bitmap("../images/confettis.bmp",NULL);
    for (int i = 0; i < 7; ++i) {
        confettis[2*i] = create_sub_bitmap(templateConfettis,10,289*i,270,270);
        confettis[2*i+1] = create_sub_bitmap(templateConfettis,290,289*i,270,270);
    }
    int i=0;
    int k = 2;
    int avanceeCheval1=10;
    int avanceeCheval2=10;
    int h=0;
    int positionXconfettis;
    int positionyconfettis;
    ///la camera avance pendant la course
    while (!key[KEY_ESC] && coordonneesPiste<1300){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,250,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,450,tailleCheval,tailleCheval);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        /// avancee aleatoire cheval 1
        srand(time(NULL)* time(NULL));
        avanceeCheval2 += rand()%8-3;
        rest(40);
        /// avancement camera piste
        coordonneesPiste +=10;
    //    printf("Coordonnes cheval %d\n",avanceeCheval1);
        /// avancee aleatoire cheval 2
        srand(time(NULL));
        avanceeCheval1 += rand()%8-3;
        i++;
        k++;
        if (i==16) i=0;
        if (k==16) k=0;
    }
    ///la camera attend a la ligne d'arrivée que les chevaux arrivent
    while (!key[KEY_ESC] && avanceeCheval1<screen->w/2 && avanceeCheval2<screen->w/2){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,250,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,450,tailleCheval,tailleCheval);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        //   srand(time(NULL));
        avanceeCheval2 += rand()%8+7;
        rest(40);
        ///la camera n'avance plus
        //  coordonneesPiste +=10;
        printf("Coordonnes cheval %d\n",avanceeCheval1);
        //  srand(time(NULL));
        avanceeCheval1 += rand()%8+7;
        i++;
        k++;
        if (i==16) i=0;
        if (k==16) k=0;
    }
    while (!key[KEY_ESC] && avanceeCheval1<screen->w && avanceeCheval2<screen->w){
        #define tailleConfetis 80
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,250,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,450,tailleCheval,tailleCheval);
        stretch_sprite(buffer,confettis[h%13],screen->w/2,screen->h/2-100,tailleConfetis,tailleConfetis);
        stretch_sprite(buffer,confettis[h%13],screen->w/2,screen->h/2+50,tailleConfetis,tailleConfetis);
        stretch_sprite(buffer,confettis[h%13],screen->w/2,screen->h-30,tailleConfetis,tailleConfetis);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        h++;
        //   srand(time(NULL));
        avanceeCheval2 += rand()%8+7;
        rest(40);
        ///la camera n'avance plus
        //  coordonneesPiste +=10;
        printf("Coordonnes cheval %d\n",avanceeCheval1);
        //  srand(time(NULL));
        avanceeCheval1 += rand()%8+7;
        i++;
        k++;
        if (i==16) i=0;
        if (k==16) k=0;
    }
    ///test cheval qui franchit la ligne en premier
    if (400+avanceeCheval1>400+avanceeCheval2){
        allegro_message("Cheval 1 a gagne !\n");
    }
    if (400+avanceeCheval1<400+avanceeCheval2){
        allegro_message("Cheval 2 a gagne !\n");
    }
    destroy_bitmap(templateCheval);
    destroy_bitmap(fondCourseHippique);
    for (int i = 0; i < 4; ++i) {
        destroy_bitmap(cheval1[i]);
    }
}