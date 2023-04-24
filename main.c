#include "Mabibli.h"

int main(){
    allegro_init();
    t_player goku;
    t_player naruto;
    initEcran();
    install_keyboard();
    install_mouse();

    srand(time(NULL));

    creationPersonnage(&goku);
    //TODO mettre break pour jeu ballon
    affichageVille(goku);

 //   allegro_exit();
    return 1;
}
END_OF_MAIN()
