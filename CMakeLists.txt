cmake_minimum_required(VERSION 3.23)
project(ECE-WORLD C)

set(CMAKE_C_STANDARD 11)

add_executable(ECE-WORLD main.c GameBallon.c init_ecran.c deplacementPersonnage.c creationPersonnage.c affichageMenuVille.c Collision.c "Debut de partie.c" Guitare_Hero.c courseHippique.c coinFlip.c jackpot.c Pong_game.c marios_bros.c penalty.c saveLoad.c preuve_conception_marp.c)

target_link_libraries(ECE-WORLD -lmingw32 -lalleg44)
