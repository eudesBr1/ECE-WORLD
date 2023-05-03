//
// Created by eudes on 22/04/2023.
//
#include "Mabibli.h"

t_player creationPersonnageGoku(t_player *player){
    BITMAP *GOKUTEMPLATE;
    GOKUTEMPLATE = load_bitmap("../images/gokuSprite.bmp",NULL);
    if (!GOKUTEMPLATE){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *GOKU;
    // crée un sous-bitmap pour extraire le premier sprite
    BITMAP *spriteTemplate = create_sub_bitmap(GOKUTEMPLATE, 0, 0, 32, 48);

    // cree un nouveau bitmap pour votre personnage
    GOKU = create_bitmap(spriteTemplate->w, spriteTemplate->h);

    // copie le sprite extrait dans  nouveau bitmap
    clear_bitmap(GOKU);
    blit(spriteTemplate, GOKU, 0, 0, 0, 0, spriteTemplate->w, spriteTemplate->h);
    for (int i = 0; i < tailleTab; ++i) {
        player->haut[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,149,32,48);
    }
    for (int i = 0; i < tailleTab; ++i) {
        player->gauche[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,46,32,50);
    }
    for (int i = 0; i < tailleTab; ++i) {
        player->droite[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,96,32,48);
    }
    for (int i = 0; i < tailleTab; ++i) {
        player->bas[i] = create_sub_bitmap(GOKUTEMPLATE,32*i,0,32,48);
    }
    player->animation=0;
    player->x=150;
    player->y=300;
    return *player;
}
t_player creationPersonnageNaruto(t_player *player){
    BITMAP *NARUTOTEMPLATE;
    NARUTOTEMPLATE = load_bitmap("../images/sprite naruto.bmp",NULL);
    if (!NARUTOTEMPLATE){
        allegro_message("Pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *NARUTO;
    // crée un sous-bitmap pour extraire le premier sprite
    BITMAP *spriteTemplate = create_sub_bitmap(NARUTOTEMPLATE, 0, 0, 75, 48);

    // cree un nouveau bitmap pour votre personnage
    NARUTO = create_bitmap(spriteTemplate->w, spriteTemplate->h);

    // copie le sprite extrait dans  nouveau bitmap
    clear_bitmap(NARUTO);
    blit(spriteTemplate, NARUTO, 0, 0, 0, 0, spriteTemplate->w, spriteTemplate->h);
    for (int i = 0; i < tailleTab; ++i) {
        player->haut[i] = create_sub_bitmap(NARUTOTEMPLATE,75*i,260,75,89);
    }
    for (int i = 0; i < tailleTab; ++i) {
        player->gauche[i] = create_sub_bitmap(NARUTOTEMPLATE,75*i,100,75,93);
    }
    for (int i = 0; i < tailleTab; ++i) {
        player->droite[i] = create_sub_bitmap(NARUTOTEMPLATE,75*i,183,75,93);
    }
    for (int i = 0; i < tailleTab; ++i) {
        player->bas[i] = create_sub_bitmap(NARUTOTEMPLATE,75*i,0,75,93);
    }
    player->animation=0;
    player->x=150;
    player->y=170;
    return *player;
}
