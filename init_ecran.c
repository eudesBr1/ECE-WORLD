//
// Created by antoi on 21/04/2023.
//

#include "Mabibli.h"

void initEcran(){
    set_color_depth(desktop_color_depth());
        if ((set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1920, 1080, 0, 0)) != 0) {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}