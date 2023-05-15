#include "Mabibli.h"
//#include "marios_bros.c"
int main(){
    allegro_init();
    t_player players[4];
    //t_player goku;
    //t_player naruto;
    initEcran();
    install_keyboard();
    install_mouse();
    srand(time(NULL));
    //coinFlip(players,players);
    //jackpot_game();
    //game_marios();
    gameInit(players);
    //ballon(players);
    //game_PONG(players,1);
    //game_GUITARE(&players[0]);
    /// crée personnage de ville
    //creationPersonnageGoku(&goku);
    //creationPersonnageNaruto(&naruto);
    //TODO mettre break pour jeu ballon
    /// affiche ville menu
    affichageVille(players);

 //   allegro_exit();
    return 1;
}
END_OF_MAIN()
