//
// Created by eudes on 10/05/2023.
//
#include "Mabibli.h"

void penalty(t_player *player){
     ///charge image menu et boutons
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
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
        gardien.position[10+i] = create_sub_bitmap(templateGardien,800*i+40,1965,800,410);
    }
    ballon.rapidite=550;
    ///commence le duel rien ne se passe
    while (!key[KEY_ESC] && !key[KEY_T]){
        bougerGardien(&gardien);
        clear(buffer);
        stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
        stretch_sprite(buffer,ballon.effet[0],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
        stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(1);
        if (mouse_b == 1){
            actionPenalty(player,gardien,ballon,b);
            rest(10);
        }
        b++;
        ballon.positionX=screen->w/2-ballon.tailleBallon/2;
        ballon.positionY=screen->h-150;
        ballon.tailleBallon = 100;
        //    gardien.positionX=screen->w/2-gardien.largeur/2;
        //   gardien.positionY=screen->h/2+50;
}
}
void actionPenalty(t_player *player,t_gardien gardien, t_ballonFoot ballon,int b){
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
    if (mouse_x > 690 && mouse_x<873 && mouse_y>530 && mouse_y<640){
         b=0;
        ///haut gauche
        // 250 gauche 400 haut
        while (!key[KEY_ESC] && ballon.positionX > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(1);
            ballon.positionX-=ballon.rapidite/100;
            ballon.positionY-=ballon.rapidite*1.9/100;
            ballon.tailleBallon-=0.8;
            b++;
            bougerGardien(&gardien);
        }
    }
    if (mouse_x > 690 && mouse_x<873 && mouse_y>640 && mouse_y<760){
        b=0;
        ///bas gauche
        // 250 gauche 280 haut
        while (!key[KEY_ESC] && ballon.positionX > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(1);
            ballon.positionX-=ballon.rapidite/100;
            ballon.positionY-=ballon.rapidite*1.2/100;
            //   printf("%f\n",ballon.positionY);
            ballon.tailleBallon-=0.8;
            b++;
            bougerGardien(&gardien);
        }
    }
    if (mouse_x > 873 && mouse_x<1000 && mouse_y>530 && mouse_y<640){
        b=0;
        ///haut milieu
        //400 haut
        while (!key[KEY_ESC] && ballon.positionY > 520){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(1);
            ballon.positionY-=ballon.rapidite/100;
            ballon.tailleBallon-=0.7;
            b++;
            bougerGardien(&gardien);
        }
    }
    if (mouse_x > 873 && mouse_x<1000 && mouse_y>640 && mouse_y<760){
        b=0;
        ///bas milieu
        //250 haut
        while (!key[KEY_ESC] && ballon.positionY > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(1);
            ballon.positionY-=ballon.rapidite/100;
            ballon.tailleBallon-=0.8;
            b++;
            bougerGardien(&gardien);
        }
    }
    if (mouse_x > 1000 && mouse_x<1260 && mouse_y>530 && mouse_y<640){
        b=0;
        ///haut droite
        //monte 1.9 fois plus vite que va vers la gauche 250 droite 400 haut
        while (!key[KEY_ESC] && ballon.positionX < 1170){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(1);
            ballon.positionX+=ballon.rapidite/100;
            ballon.positionY-=ballon.rapidite*1.55/100;
            ballon.tailleBallon-=0.8;
            b++;
            bougerGardien(&gardien);
        }
    }
    if (mouse_x > 1000 && mouse_x<1260 && mouse_y>640 && mouse_y<760){
        b=0;
        ///bas droite
        //280 haut 250 droite
        while (!key[KEY_ESC] && ballon.positionY > 700){
            clear(buffer);
            stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
            stretch_sprite(buffer,gardien.position[choixAnimationGardien(gardien,b)],gardien.positionX,gardien.positionY,gardien.largeur,gardien.hauteur);
            stretch_sprite(buffer,ballon.effet[(b/10)%3],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(1);
            ballon.positionY-=ballon.rapidite/100;
            ballon.positionX+=ballon.rapidite*1.2/100;
            ballon.tailleBallon-=0.8;
            gardien.animation=(b/30)%3;
            b++;
            bougerGardien(&gardien);
        }
    }
    finPenalty(player,gardien,ballon,b);
}
void finPenalty(t_player *player,t_gardien gardien, t_ballonFoot ballon,int b){
    if ((ballon.positionX+ballon.tailleBallon/2)>gardien.positionX && (ballon.positionX+ballon.tailleBallon/2)< gardien.positionX+gardien.largeur){
        if ((ballon.positionY+ballon.tailleBallon/2)>gardien.positionY && (ballon.positionY-ballon.tailleBallon/2)>gardien.positionY+gardien.largeur){
            printf("%f %f\n",ballon.positionY-ballon.tailleBallon/2,gardien.positionY+gardien.largeur);
            printf("penalty sauve !\n");
        }
    }
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
    if (gardien.dY<-1.5 && gardien.dX<0){
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
    else{
        anim=(b/60)%3;
    }

    return anim;
}