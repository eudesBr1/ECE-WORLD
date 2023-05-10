//
// Created by eudes on 01/05/2023.
//
#include "Mabibli.h"
#include "string.h"
#define tailleCheval 120
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
        textprintf_centre_ex(buffer,font,20,30, makecol(255,255,255),-1,"oui");
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
                rest(200);
                if (1==1){
                        while (1){
                            clear(buffer);
                            BITMAP *pancarte = load_bitmap("../images/pancarteJoueur1CourseHippique.bmp",NULL);
                            if (!pancarte){
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
                            for (int i = 0; i < player[0].nbJoueurs; ++i) {
                                player[i].cheval=0;
                            }
                            for (int i = 0; i < player[0].nbJoueurs; ++i) {
                                do {
                                    BITMAP *cheval1;
                                    cheval1 = create_sub_bitmap(templateCheval,0,0,31,28);
                                    BITMAP *cheval3;
                                    BITMAP *cheval2;
                                    cheval2 = create_sub_bitmap(templateCheval,0,54,28,28);
                                    cheval3 = create_sub_bitmap(templateCheval,28,163,35,25);
                                    stretch_blit(menuCourseHippique,buffer,0,0,menuCourseHippique->w,menuCourseHippique->h,0,0,screen->w,screen->h);
                                    stretch_sprite(buffer,pancarte,screen->w/2-500/2,screen->h/2-300,500,80);
                                    stretch_sprite(buffer,cheval1,100,screen->h/2,tailleCheval*3,tailleCheval*3);
                                    stretch_sprite(buffer,cheval2,screen->w-tailleCheval*3-100,screen->h/2,tailleCheval*3,tailleCheval*3);
                                    stretch_sprite(buffer,cheval3,screen->w/2-tailleCheval*1.5,screen->h/2,tailleCheval*3,tailleCheval*3);

                                    for (int j = 0; j < player[0].nbJoueurs; ++j) {
                                        if (player[j].cheval==3) textprintf_right_ex(buffer,font,screen->w-tailleCheval*3,screen->h-100, makecol(255,255,255),-1,"%s  choix Cheval 3\n",player[i].name);
                                    }
                                    for (int j = 0; j < player[0].nbJoueurs; ++j) {
                                        if (player[j].cheval==2) textprintf_right_ex(buffer,font,screen->w/2-tailleCheval*1.5,screen->h-100, makecol(255,255,255),-1,"%s choix Cheval 2\n",player[i].name);
                                    }
                                    for (int j = 0; j < player[0].nbJoueurs; ++j) {
                                        if (player[j].cheval==1) textprintf_right_ex(buffer,font,100,screen->h-100, makecol(255,255,255),-1,"%s choix Cheval 1\n",player[i].name);

                                    }


                                    blit(buffer,screen,0,0,0,0,screen->w,screen->h);
                                    show_mouse(screen);
                                    rest(2);
                                    if ( mouse_x>100 && mouse_x< 100+tailleCheval*3 && mouse_y>screen->h/2 && mouse_y< screen->h/2+tailleCheval*3){
                                        if (mouse_b == 1){
                                            printf("Joueur %d choix Cheval 1\n",player[0].nbJoueurs);
                                            player[i].cheval=1;
                                            debutCourse(player);
                                            break;
                                        }
                                    }
                                    if ( mouse_x>screen->w/2-tailleCheval*1.5 && mouse_x< screen->w/2-tailleCheval*1.5+tailleCheval*3 && mouse_y>screen->h/2 && mouse_y< screen->h/2+tailleCheval*3){
                                        if (mouse_b == 1){
                                            printf("Joueur %d choix Cheval 2\n",player[0].nbJoueurs);
                                            player[i].cheval=2;
                                            break;
                                        }
                                    }
                                    if ( mouse_x>screen->w-tailleCheval*3-100 && mouse_x< screen->w-tailleCheval*3-100+tailleCheval*3 && mouse_y>screen->h/2 && mouse_y< screen->h/2+tailleCheval*3){
                                        if (mouse_b == 1){
                                            printf("Joueur %d choix Cheval 3\n",player[0].nbJoueurs);
                                            player[i].cheval=3;
                                            break;
                                        }
                                    }

                                }while (player[i].cheval==0);
                            }
                    }
                }else{
                    while (1){
                        clear(buffer);
                        BITMAP *pancarte = load_bitmap("../images/pancarteJoueur1CourseHippique.bmp",NULL);
                        if (!pancarte){
                            allegro_message("Pb de l'image courseHippique.bmp");
                            allegro_exit();
                            exit(EXIT_FAILURE);
                        }
                        stretch_blit(menuCourseHippique,buffer,0,0,menuCourseHippique->w,menuCourseHippique->h,0,0,screen->w,screen->h);
                        stretch_sprite(buffer,pancarte,screen->w/2-300/2,screen->h/2-100,300,60);
                        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
                        show_mouse(screen);
                        rest(2);
                        if (mouse_b == 1){
                            debutCourse(player);
                            break;
                        }
                    }
                }
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
    cheval2[0] = create_sub_bitmap(templateCheval,28,163,35,25);
    cheval2[1] = create_sub_bitmap(templateCheval,86,163,35,25);
    cheval2[2] = create_sub_bitmap(templateCheval,147,163,35,25);
    cheval2[3] = create_sub_bitmap(templateCheval,205,163,35,25);


    BITMAP *cheval3[4];
    for (int i = 0; i < 4; ++i) {
        cheval3[i] = create_sub_bitmap(templateCheval,31*i,54,28,28);
    }
    ///animation confettis
    BITMAP *confettis[14];
    BITMAP *templateConfettis;
    templateConfettis = load_bitmap("../images/confettis.bmp",NULL);
    for (int i = 0; i < 7; ++i) {
        confettis[2*i] = create_sub_bitmap(templateConfettis,10,289*i,270,270);
        confettis[2*i+1] = create_sub_bitmap(templateConfettis,290,289*i,270,270);
    }
    ///animation main decompte
    BITMAP *main[6];
    BITMAP *templateMain = load_bitmap("../images/sprite_main.bmp",NULL);
    if (!templateMain){
        allegro_message("Pb de l'image templateMain.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 2; ++i) {
        main[i] = create_sub_bitmap(templateMain,300*i,0,350,templateMain->h);
    }
    for (int i = 0; i < 3; ++i) {
        main[i+2] = create_sub_bitmap(templateMain,640+370*i,0,400,templateMain->h);
    }
    ///sprite animation go
    BITMAP *go = load_bitmap("../images/go.bmp",NULL);
    int i=0;
    int k = 2;
    int j=3;
    int avanceeCheval1=300;
    int avanceeCheval2=300;
    int avanceeCheval3=300;
    int h=0;
    int decompte =0;
    ///depart de la course
    while (!key[KEY_ESC] && decompte<5){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[0],avanceeCheval1,350,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[0],avanceeCheval2,700,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval3[0],avanceeCheval3,525,tailleCheval,tailleCheval);
        stretch_sprite(buffer,main[4-decompte],screen->w/2,screen->h/2,200,400);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        decompte++;
        rest(1000);
    }
    stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
    stretch_sprite(buffer,cheval1[0],avanceeCheval1,350,tailleCheval,tailleCheval);
    stretch_sprite(buffer,cheval2[0],avanceeCheval2,700,tailleCheval,tailleCheval);
    stretch_sprite(buffer,cheval3[0],avanceeCheval3,525,tailleCheval,tailleCheval);
    stretch_sprite(buffer,go,screen->w/2,screen->h/2,570,180);
    blit(buffer,screen,0,0,0,0,screen->w,screen->h);
    rest(1000);
    ///la camera avance pendant la course
    while (!key[KEY_ESC] && coordonneesPiste<1300){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,350,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,700,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval3[j/4],avanceeCheval3,525,tailleCheval,tailleCheval);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        /// avancee aleatoire cheval 1
        srand(time(NULL)* time(NULL));
        avanceeCheval1 += rand()%8-3;
        rest(40);
        /// avancement camera piste
        coordonneesPiste +=10;
    //    printf("Coordonnes cheval %d\n",avanceeCheval1);
        /// avancee aleatoire cheval 2
        srand(time(NULL));
        avanceeCheval2 += rand()%8-3;

        /// avancee aleatoire cheval 3
        srand(time(NULL));
        avanceeCheval3 += rand()%8-3;

        i++;
        k++;
        j++;
        if (i==16) i=0;
        if (k==16) k=0;
        if (j==16) j=0;

    }
    ///la camera attend a la ligne d'arrivée que les chevaux arrivent
    while (!key[KEY_ESC] && avanceeCheval1<screen->w/2 && avanceeCheval2<screen->w/2-300){
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,350,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,700,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval3[j/4],avanceeCheval3,525,tailleCheval,tailleCheval);

        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        //   srand(time(NULL));
        avanceeCheval2 += rand()%8+7;
        rest(40);
        ///la camera n'avance plus
        //  coordonneesPiste +=10;
        printf("Coordonnes cheval %d\n",avanceeCheval1);
        srand(time(NULL));
        avanceeCheval1 += rand()%8+7;
        srand(time(NULL));
        avanceeCheval3 += rand()%8+7;
        i++;
        k++;
        j++;
        if (i==16) i=0;
        if (k==16) k=0;
        if (j==16) j=0;
    }
    while (!key[KEY_ESC] && avanceeCheval1<screen->w && avanceeCheval2<screen->w){
        #define tailleConfetis 80
        stretch_blit(fondCourseHippique, buffer, coordonneesPiste, 0, fondCourseHippique->w,fondCourseHippique->h,0,0,fondCourseHippique->w,buffer->h);
        stretch_sprite(buffer,cheval1[i/4],avanceeCheval1,350,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval2[k/4],avanceeCheval2,700,tailleCheval,tailleCheval);
        stretch_sprite(buffer,cheval3[j/4],avanceeCheval3,525,tailleCheval,tailleCheval);
        stretch_sprite(buffer,confettis[h%13],screen->w/2,250,tailleConfetis,tailleConfetis);
        stretch_sprite(buffer,confettis[h%13],screen->w/2,screen->h/2+50,tailleConfetis,tailleConfetis);
        stretch_sprite(buffer,confettis[h%13],screen->w/2,screen->h-100,tailleConfetis,tailleConfetis);
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
        srand(time(NULL));
        avanceeCheval3 += rand()%8+7;
        i++;
        k++;
        j++;
        if (i==16) i=0;
        if (k==16) k=0;
        if (j==16) j=0;
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
    for (int i = 0; i < 4; ++i) {
        destroy_bitmap(main[i]);
    }
}