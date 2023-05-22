//
// Created by eudes on 10/05/2023.
//
#include "Mabibli.h"

void penalty(t_player *player){
    while (!key[KEY_ESC]){
        ///charge image menu et boutons
        BITMAP *buffer;
        buffer = create_bitmap(screen->w,screen->h);
        BITMAP *menuPenalty;
        menuPenalty = load_bitmap("../images/penalty/butDeFootLoading.bmp", NULL);
        BITMAP *boutonQuitter;
        boutonQuitter = load_bitmap("../images/quit_boutton.bmp",NULL);
        BITMAP *boutonStart;
        boutonStart = load_bitmap("../images/boutonStartCourse.bmp",NULL);
        int tailleCheval = 50;
        ///affichage menu
        while (!key[KEY_ESC] && !key[KEY_G]){
            stretch_blit(menuPenalty, buffer, 0, 0, menuPenalty->w, menuPenalty->h, 0, 0, screen->w, screen->h);
            textprintf_centre_ex(buffer,font,20,30, makecol(255,255,255),-1,"oui");
            if (mouse_x>20 && mouse_x<200 && mouse_y>screen->h-60 && mouse_y<screen->h-10){
                stretch_sprite(buffer, boutonQuitter, 0, screen->h - 80, 260, 80);
                stretch_sprite(buffer,boutonStart,screen->w/2-60,screen->h/2+30,120,70);
                if (mouse_b == 1){
                    destroy_bitmap(buffer);
                    destroy_bitmap(menuPenalty);
                    destroy_bitmap(boutonQuitter);
                    return;
                }
            }
            else if (mouse_x>screen->w/2-60 && mouse_x<screen->w/2+60 && mouse_y> screen->h/2+30 && mouse_y < screen->h/2+130){
                stretch_sprite(buffer, boutonQuitter, 20, screen->h - 60, 180, 50);
                stretch_sprite(buffer,boutonStart,screen->w/2-80,screen->h/2+15,160,100);
                if (mouse_b == 1) break;
            }

            else{
                stretch_sprite(buffer, boutonQuitter, 20, screen->h - 60, 180, 50);
                stretch_sprite(buffer,boutonStart,screen->w/2-60,screen->h/2+30,120,70);
            }
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            clear(buffer);

        }
        rest(250);
        clear(buffer);
        int choixJoueur = 10;
        do{
            stretch_blit(menuPenalty, buffer, 0, 0, menuPenalty->w, menuPenalty->h, 0, 0, screen->w, screen->h);
            for (int i = 0; i < player[0].nbJoueurs; ++i) {
                stretch_sprite(buffer,player[i].bas[1],((screen->w*(i+1))/6),(2*screen->h/4),screen->w/6,1.5*screen->h/4);
                if (mouse_x >((screen->w*(i+1))/6) && mouse_x < ((screen->w*(i+1))/6) + screen->w/6 && mouse_y > (2*screen->h/4) && mouse_y < (2*screen->h/4) + (2*screen->h/4) && mouse_b == 1){
                    choixJoueur = i;
                    printf(" choix %d",i);
                    break;
                }
            }
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            if (key[KEY_ESC]) return;
        } while ( choixJoueur == 10);
        rest(250);
        int choixJoueur2 = 10;
        do{
            stretch_blit(menuPenalty, buffer, 0, 0, menuPenalty->w, menuPenalty->h, 0, 0, screen->w, screen->h);
            for (int i = 0; i < player[0].nbJoueurs; ++i) {
                stretch_sprite(buffer,player[i].bas[1],((screen->w*(i+1))/6),(2*screen->h/4),screen->w/6,1.5*screen->h/4);
                textprintf_centre_ex(buffer,font,screen->w/2,screen->h/2, makecol(0,0,0),-1," 1er joueur est %s",player[choixJoueur].name);
                if (mouse_x >((screen->w*(i+1))/6) && mouse_x < ((screen->w*(i+1))/6) + screen->w/6 && mouse_y > (2*screen->h/4) && mouse_y < (2*screen->h/4) + (2*screen->h/4) && mouse_b == 1){
                    choixJoueur2 = i;
                    printf(" choix %d",i);
                    break;
                }
            }
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            if (key[KEY_ESC]) return;

        } while ( choixJoueur2 == 10);
        player[choixJoueur].score = 0;
        player[choixJoueur2].score = 0;
        for (int i = 0; i < 2; ++i) {
            debutPenalty(player,choixJoueur);
        }
        printf("nmb penausq %d\n",player[choixJoueur].score);

        for (int i = 0; i < 3; ++i) {
            debutPenalty(player,choixJoueur2);
        }
        printf("nmb penausq %d\n",player[choixJoueur2].score);
        if (player[choixJoueur].score < player[choixJoueur2].score){
            player[choixJoueur].ticket--;
            player[choixJoueur2].points++;
        }
        if (player[choixJoueur].score > player[choixJoueur2].score) {
            player[choixJoueur].points++;
            player[choixJoueur2].ticket--;
        }
        player[choixJoueur].score = 0;
        player[choixJoueur2].score = 0;
    }
}
int debutPenalty(t_player *player,int choixJoueur){
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    clear(buffer);
    BITMAP *fondStade = load_bitmap("../images/penalty/butDeFoot.bmp",NULL);
    if (!fondStade){
        allegro_message("Pb de l'image fondStade.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *templateBallon = load_bitmap("../images/penalty/ballonDeFoot.bmp",NULL);
    if (!templateBallon){
        allegro_message("Pb de l'image fondStade.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *templateGardien = load_bitmap("../images/penalty/gardienDeFoot.bmp",NULL);
    if (!templateGardien){
        allegro_message("Pb de l'image tempGardien.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///animation jauge tir
    BITMAP *templateJauge = load_bitmap("../images/penalty/jaugeTir.bmp",NULL);
    if (!templateJauge){
        allegro_message("Pb de l'image tempGardien.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *jauge[8];
    for (int i = 0; i < 8; ++i) {
        jauge[i] = create_sub_bitmap(templateJauge,10+107*i,35,100,860);
    }
    int valeurJauge=0;
    ///cree ballon animation puis gardien animation$
    t_ballonFoot ballon;
    ballon.tailleBallon = 100;
    ballon.positionX=screen->w/2-ballon.tailleBallon/2;
    ballon.positionY=screen->h-150;
    for (int i = 0; i <= 2; ++i) {
        ballon.effet[i]= create_sub_bitmap(templateBallon,500*i+30,30,500,500);
    }
    for (int i = 3; i < 5; ++i) {
        ballon.effet[i] = create_sub_bitmap(templateBallon,500*i+30,670,500,500);
    }
    int b=0;
    t_gardien gardien;
    gardien.hauteur = 210;
    gardien.largeur = 210;
    gardien.positionX=screen->w/2-gardien.largeur/2;
    gardien.positionY=screen->h/2+50;
    gardien.elan=5;
    gardien.arret=0;
    for (int i = 0; i <= 2; ++i) {
        gardien.position[i] = create_sub_bitmap(templateGardien,800*i+40,40,800,470);
    }
    for (int i = 0; i <= 2; ++i) {
        gardien.position[i+3] = create_sub_bitmap(templateGardien,800*i+40,520,800,470);
    }
    for (int i = 0; i <= 1; ++i) {
        gardien.position[6+i] = create_sub_bitmap(templateGardien,800*i+40,1090,800,410);
    }
    for (int i = 0; i <= 1; ++i) {
        gardien.position[8+i] = create_sub_bitmap(templateGardien,800*i+40,1485,800,410);
    }
    for (int i = 0; i <= 1; ++i) {
        gardien.position[10+i] = create_sub_bitmap(templateGardien,800*i+40,1965,800,410);
    }
    for (int i = 0; i <= 1; ++i) {
        gardien.position[12+i] = create_sub_bitmap(templateGardien,800*i+40,2385,800,410);
    }
    ///ecran avec points
    //  create_bitmap(466,278);
    int rouge = makecol(255, 55, 55);
    int gris = makecol(127, 127, 127);
    int width = text_length(font, "Au tour de ") + text_length(font,player[choixJoueur].name);
    int height = text_height(font);
    BITMAP *ecran = create_bitmap(width,height+1);
    rectfill(ecran,0,0,ecran->w,ecran->h, gris);
    textprintf_ex(ecran, font, 0,1, rouge,-1,"Au tour de %s",player[choixJoueur].name);

    ///commence le duel rien ne se passe
    while (!key[KEY_ESC] && !key[KEY_T]){
        ballon.tailleBallon = 100;
        ballon.positionX=screen->w/2-ballon.tailleBallon/2;
        ballon.positionY=screen->h-150;
        bougerGardien(&gardien);
        clear(buffer);
        stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
        stretch_sprite(buffer,ballon.effet[0],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
        stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
        stretch_sprite(buffer,jauge[valeurJauge/10],screen->w-150,400,100,500);
        stretch_blit(ecran,buffer,0,0,ecran->w,ecran->h,656,70,625,280);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(5);
        if (key[KEY_1_PAD] || key[KEY_2_PAD] || key[KEY_3_PAD] || key[KEY_4_PAD] || key[KEY_5_PAD] || key[KEY_6_PAD]){
            if (valeurJauge>0){
                ballon.rapidite=100;
                ballon.diminution=0.1;
            }
            if (valeurJauge>30){
                ballon.rapidite=150;
                ballon.diminution=0.2;
            }
            if (valeurJauge>40){
                ballon.rapidite=250;
                ballon.diminution=0.3;
            }
            if (valeurJauge>50){
                ballon.rapidite=350;
                ballon.diminution=0.5;
            }
            if (valeurJauge>60){
                ballon.rapidite=450;
                ballon.diminution=0.7;
            }
            if (valeurJauge>70){
                ballon.rapidite=550;
                ballon.diminution=0.8;
            }
            int resultat= actionPenalty(player, &gardien,ballon,b,choixJoueur);
            printf("seconde borne %d\n",resultat);
            return resultat;
            break;
            rest(110);
        }
        b++;
        valeurJauge+=2;
        valeurJauge=valeurJauge%80;
        ballon.positionX=screen->w/2-ballon.tailleBallon/2;
        ballon.positionY=screen->h-150;
        ballon.tailleBallon = 100;
        //    gardien.positionX=screen->w/2-gardien.largeur/2;
        //   gardien.positionY=screen->h/2+50;
    }
}
int actionPenalty(t_player *player,t_gardien *gardien, t_ballonFoot ballon,int b, int choixJoueur){
    ///charge image menu et boutons
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    BITMAP *fondStade = load_bitmap("../images/penalty/butDeFoot.bmp",NULL);
    if (!fondStade){
        allegro_message("Pb de l'image fondStade.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///le ballon tourne et se deplace
    if (key[KEY_4_PAD]){
        b=0;
        ///haut gauche
        // 250 gauche 400 haut
        while (!key[KEY_ESC] && ballon.positionX > 700 ){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
            ballon.positionX-=ballon.rapidite/100;
            ballon.positionY-=ballon.rapidite*1.9/100;
            ballon.tailleBallon-=ballon.diminution;
            b++;
            bougerGardien(gardien);
        }
    }
    if (key[KEY_1_PAD]){
        b=0;
        ///bas gauche
        // 250 gauche 280 haut
        while (!key[KEY_ESC] && ballon.positionX > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
            ballon.positionX-=ballon.rapidite/100;
            ballon.positionY-=ballon.rapidite*1.2/100;
            //   printf("%f\n",ballon.positionY);
            ballon.tailleBallon-=ballon.diminution;
            b++;
            bougerGardien(gardien);
        }
    }
    if (key[KEY_5_PAD]){
        b=0;
        ///haut milieu
        //400 haut
        while (!key[KEY_ESC] && ballon.positionY > 520){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
            ballon.positionY-=ballon.rapidite/100;
            ballon.tailleBallon-=ballon.diminution;
            b++;
            bougerGardien(gardien);
        }
    }
    if (key[KEY_2_PAD]){
        b=0;
        ///bas milieu
        //250 haut
        while (!key[KEY_ESC] && ballon.positionY > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
            ballon.positionY-=ballon.rapidite/100;
            ballon.tailleBallon-=ballon.diminution;
            b++;
            bougerGardien(gardien);
        }
    }
    if (key[KEY_6_PAD]){
        b=0;
        ///haut droite
        //monte 1.9 fois plus vite que va vers la gauche 250 droite 400 haut
        while (!key[KEY_ESC] && ballon.positionX < 1170){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
            ballon.positionX+=ballon.rapidite/100;
            ballon.positionY-=ballon.rapidite*1.55/100;
            ballon.tailleBallon-=ballon.diminution;
            b++;
            bougerGardien(gardien);
        }
    }
    if (key[KEY_3_PAD]){
        b=0;
        ///bas droite
        //280 haut 250 droite
        while (!key[KEY_ESC] && ballon.positionY > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
            ballon.positionY-=ballon.rapidite/100;
            ballon.positionX+=ballon.rapidite*1.2/100;
            ballon.tailleBallon-=ballon.diminution;
            gardien->animation=(b/30)%3;
            b++;
            bougerGardien(gardien);
        }
    }
    int resultat = finPenalty(player,gardien,&ballon,b,choixJoueur);
    int h=0;
    while (h<100 && !key[KEY_ESC]){
        bougerGardien(gardien);
        clear(buffer);
        if (gardien->arret==1){
            BITMAP *fondStadeResultat= load_bitmap("../images/penalty/butDeFootSave.bmp",NULL);
            stretch_blit(fondStadeResultat,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
        }
        if (gardien->arret==0){
            BITMAP *fondStadeResultat= load_bitmap("../images/penalty/butDeFootGoal.bmp",NULL);
            stretch_blit(fondStadeResultat,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,ballon.effet[0],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            stretch_sprite(buffer,gardien->position[choixAnimationGardien(*gardien,b)],gardien->positionX,gardien->positionY,gardien->largeur,gardien->hauteur);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(5);
        }
        h++;
        if (ballon.positionY<700) ballon.positionY+=3;
    }
    gardien->arret=0;
    gardien->positionX=screen->w/2-gardien->largeur/2;
    gardien->positionY=screen->h/2+50;
    printf("borne %d\n",resultat);
    return resultat;
}
int finPenalty(t_player *player,t_gardien *gardien, t_ballonFoot *ballon,int b, int choixJoueur){
    if ((ballon->positionX+ballon->tailleBallon/2)>gardien->positionX && (ballon->positionX+ballon->tailleBallon/2)< gardien->positionX+gardien->largeur){
        if ((ballon->positionY+ballon->tailleBallon/2)>gardien->positionY && (ballon->positionY-ballon->tailleBallon/2)<gardien->positionY+gardien->largeur){
            printf("\n l'arret %d \n",gardien->arret);
            gardien->arret=1;
            return 0;
            rest(5);
        }
    }
    rest(5);
    player[choixJoueur].score++;
    return 1;
}
void bougerGardien(t_gardien *gardien){
    if (gardien->positionY == screen->h/2+50){
        gardien->dX=0;
        gardien->dY=0;
        if (key[KEY_Q]){
            gardien->dX=-5;
            gardien->dY=-4;
        }
        if (key[KEY_W]){
            gardien->dY=-5;
        }
        if (key[KEY_E]){
            gardien->dX=+5;
            gardien->dY=-4;
        }
        if (key[KEY_S]){
            if (key[KEY_A]){
                gardien->positionX-=3;
            }
            if (key[KEY_D]){
                gardien->positionX+=3;
            }
        }
        else if (key[KEY_A]){
            gardien->dX=-6.5;
            gardien->dY=-1.5;
        }

        else if (key[KEY_D]){
            gardien->dX=6.5;
            gardien->dY=-1.5;
        }
    }
    if (gardien->positionY < screen->h/2+50){
        gardien->dY=(float)0.1+gardien->dY;
    }
    gardien->positionY+=gardien->dY;
    gardien->positionX+=gardien->dX;
}
int choixAnimationGardien(t_gardien gardien,int b){
    int anim=0;
    if (gardien.arret ==1 && gardien.dY<-1.5 && gardien.dX<0){
        anim=8;
    }
    else if (gardien.arret ==1 && gardien.dY<-1.5 && gardien.dX>0){
        anim=9;
    }
    else if (gardien.arret ==1 && gardien.dX<0){
        anim=12;
    }
    else if (gardien.arret ==1 && gardien.dX>0){
        anim=13;
    }

    else if (gardien.dY<-1.5 && gardien.dX<0){
        anim=6;
    }
    else if (gardien.dY<-1.5 && gardien.dX>0){
        anim=7;
    }
    else if ( gardien.dX<0){
        anim=10;
    }
    else if ( gardien.dX>0){
        anim=11;
    }
    else if (gardien.arret==1){
        anim=(b/60)%3+3;
    }
    else{
        anim=(b/60)%3;
    }

    return anim;
}