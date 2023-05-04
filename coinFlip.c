//
// Created by eudes on 03/05/2023.
//
#include "Mabibli.h"
void coinFlip(t_player *player,t_player *player2){
    BITMAP *buffer;
    buffer = create_bitmap(screen->w,screen->h);
    clear(buffer);
    BITMAP *fondCoinflip = load_bitmap("../images/fondCoinflip.bmp",NULL);
    BITMAP *templateCoin;
    templateCoin = load_bitmap("../images/coinFlip.bmp",NULL);
    BITMAP *coin[18];
    coin[0] = create_sub_bitmap(templateCoin,0,0,115,120);
    coin[1] = create_sub_bitmap(templateCoin,117,0,100,120);
    coin[2] = create_sub_bitmap(templateCoin,214,0,90,120);
    coin[3] = create_sub_bitmap(templateCoin,300,0,75,120);
    coin[4] = create_sub_bitmap(templateCoin,375,0,50,120);
    coin[5] = create_sub_bitmap(templateCoin,430,115,75,120);
    coin[6] = create_sub_bitmap(templateCoin,505,115,90,120);
    coin[7] = create_sub_bitmap(templateCoin,595,115,100,120);
    coin[8] = create_sub_bitmap(templateCoin,695,115,115,120);
    coin[9] = create_sub_bitmap(templateCoin,0,115,115,120);
    coin[10] = create_sub_bitmap(templateCoin,117,115,100,120);
    coin[11] = create_sub_bitmap(templateCoin,214,115,90,120);
    coin[12] = create_sub_bitmap(templateCoin,300,115,75,120);
    coin[13] = create_sub_bitmap(templateCoin,375,115,50,120);
    coin[14] = create_sub_bitmap(templateCoin,430,0,75,120);
    coin[15] = create_sub_bitmap(templateCoin,505,0,90,120);
    coin[16] = create_sub_bitmap(templateCoin,595,0,100,120);
    coin[17] = create_sub_bitmap(templateCoin,695,0,115,120);

    int i=0;
    int n=0;
    int nombreDeToursPiece = rand()%8+6;
    printf("%d",nombreDeToursPiece);
    #define vitesseAnimationPiece 8
    while (!key[KEY_ESC] && n<=nombreDeToursPiece){
        while (!key[KEY_ESC] && i<72){
            stretch_blit(fondCoinflip,buffer,0,0,fondCoinflip->w,fondCoinflip->h,0,0,screen->w,screen->h);
            draw_sprite(buffer,coin[(i/vitesseAnimationPiece)%18],screen->w/2-coin[0]->w/2,screen->h/2-coin[0]->h/2+90);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(2);
            clear(buffer);
            i++;
        }
        printf("pile\n");
        while (!key[KEY_ESC] && i<72*2){
            stretch_blit(fondCoinflip,buffer,0,0,fondCoinflip->w,fondCoinflip->h,0,0,screen->w,screen->h);
            draw_sprite(buffer,coin[(i/vitesseAnimationPiece)%18],screen->w/2-coin[0]->w/2,screen->h/2-coin[0]->h/2+90);
            blit(buffer,screen,0,0,0,0,screen->w,screen->h);
            rest(2);
            clear(buffer);
            i++;
        }
        printf("face\n");
        i=0;
    }
}