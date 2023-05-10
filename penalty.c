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
    ballon.positionY=screen->h-200;
    for (int i = 0; i <= 2; ++i) {
        ballon.effet[i]= create_sub_bitmap(templateBallon,500*i+30,30,500,500);
    }
    for (int i = 3; i < 5; ++i) {
        ballon.effet[i] = create_sub_bitmap(templateBallon,500*i+30,670,500,500);
    }
    int b=0;
    int coin;
    BITMAP *gardien[10];
    int hauteurGardien = 210;
    int largeurGardien = 115;
    for (int i = 0; i <= 2; ++i) {
        gardien[i] = create_sub_bitmap(templateGardien,350*i+40,40,350,470);
    }
    for (int i = 3; i <= 5; ++i) {
        gardien[i] = create_sub_bitmap(templateGardien,350*i+40,40,350,470);
    }
    ///commence le duel rien ne se passe
    while (!key[KEY_ESC] && !key[KEY_E]){
        clear(buffer);
        stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
        stretch_sprite(buffer,ballon.effet[0],ballon.positionX,ballon.positionY,ballon.tailleBallon,ballon.tailleBallon);
        stretch_sprite(buffer,gardien[(b/30)%3],screen->w/2-largeurGardien/2,screen->h/2-50,largeurGardien,hauteurGardien);
        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,screen->w,screen->h);
        rest(1);
        if (mouse_b == 1){
            ///le ballon tourne et se deplace
           if (mouse_x > 690 && mouse_x<873 && mouse_y>530 && mouse_y<640){
               b=0;
               //monte 1.6 fois plus vite que va vers la gauche
               while (!key[KEY_ESC]){
                   clear(buffer);
                   stretch_blit(fondStade,buffer,0,0,fondStade->w,fondStade->h,0,0,screen->w,screen->h);
                   stretch_sprite(buffer,gardien[(b/30)%3],screen->w/2-largeurGardien/2,screen->h/2,largeurGardien,hauteurGardien);
                   stretch_sprite(buffer,ballon.effet[(b/10)%3],screen->w/2-ballon.tailleBallon/2,screen->h-200-b,ballon.tailleBallon-b/30,ballon.tailleBallon-b/30);
                   blit(buffer,screen,0,0,0,0,screen->w,screen->h);
                   rest(1);
                   b++;
               }
           }
        }
        b++;
    }

}