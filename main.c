#include "Mabibli.h"

int main(){
    allegro_init();
    t_player *players;
    //t_player goku;
    //t_player naruto;
    initEcran();
    install_keyboard();
    install_mouse();
    srand(time(NULL));
    coinFlip(players,players);
    players =  gameInit();
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
