#include "Mabibli.h"

int main(){
    allegro_init();
    t_player players[4];
    //t_player goku;
    //t_player naruto;
    initEcran();
    install_sound(DIGI_AUTODETECT ,MIDI_AUTODETECT,NULL);
    install_keyboard();
    install_mouse();
    srand(time(NULL));
    gameInit(players);
  //  courseHippique(players);
    /// affiche ville menu
     affichageVille(players);
 //   allegro_exit();
    return 1;
}
END_OF_MAIN()