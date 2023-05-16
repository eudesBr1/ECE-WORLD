#include "Mabibli.h"


#define WHITE makecol(255,255,255)
#define BLACK makecol(0,0,0)



int mousex, mousey, leftClick;
int startScreenMode = 1;
int mainMenuMode = 0;
int gameMode = 0;
int inputIndex;
int lifeline = 5;

int gamePlayMode = 1;
int points = 0;


BITMAP *buffer;
BITMAP* buffers;


void clearScreen()
{
    rectfill(buffer, 0, 0, 640, 480, BLACK);
}

void clearScreens()
{
    rectfill(buffers, 0, 0, 640, 480, BLACK);
}

void loadBackgroundImage(char *filename)
{
    BITMAP *background;
    background = load_bitmap(filename, NULL);
    if (!background)
    {
        allegro_message("couldnt load bg");
        return;
    }
    //blit(background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    stretch_blit(background,buffer,0,0,background->w,background->h,0,0,screen->w,screen->h);
    destroy_bitmap(background);
}



int maxi(int a, int b)
{
    if (a >= b)
        return a;

    else
        return b;
}

int mini(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}


//pixel perfect method for collision detection
int pixel_perfect_colision(int x1, int y1, BITMAP * obj1, int x2, int y2, BITMAP * obj2)
{
    int i, j;
    int collision = FALSE;

    //if rectangles intersect
    if (!((x1 > x2 + obj2->w) || (y1 > y2 + obj2->h) || (x2 > x1 + obj1->w) || (y2 > y1 + obj1->h)))
    {

        int top = maxi(y1, y2);
        int low = mini(y1 + obj1->h, y2 + obj2->h);
        int left = maxi(x1, x2);
        int right = mini(x1 + obj1->w, x2 + obj2->w);

        for (i = top; i < low && !collision; i++)
        {
            for (j = left; j < right && !collision; j++)
            {
                if (getpixel(obj1, j - x1, i - y1) != makecol(255, 0, 255) && getpixel(obj2, j - x2, i - y2) != makecol(255, 0, 255)) {
                    collision = TRUE;
                }

            }
        }
    }

    return collision;
}





//local variable
float teta = 0.0;
float beta = 0.0;

void checkPtrNull(void *ptr) {
    if (ptr == NULL) {
        printf("Error\n");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}


void game_marios() {
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    install_keyboard();
    install_mouse();
    install_timer();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    buffer = create_bitmap(640, 480);
    buffers = create_bitmap(640, 480);

    set_mouse_sprite_focus(15, 15);
    show_mouse(screen);





    //create bitmaps
    BITMAP *sky = load_bitmap("../images/122.bmp", NULL);
    BITMAP *mario = load_bitmap("../images/mario.bmp", NULL);

    //settings for intro page
    BITMAP *day = load_bitmap("../images/11.bmp", NULL);


    //background sprite
    //enemies
    BITMAP *enemy1 = load_bitmap("../images/ico2.bmp", NULL);
    BITMAP *enemy2 = load_bitmap("../images/beetle_1.bmp", NULL);
    BITMAP *fireball1 = load_bitmap("../images/firework1.bmp", NULL);
    BITMAP *fireball2 = load_bitmap("../images/firework2.bmp", NULL);

    //coins
    BITMAP *coin1 = load_bitmap("../images/coin_0.bmp", NULL);
    BITMAP *bonus = load_bitmap("../images/bonus.bmp", NULL);

    //flag
    BITMAP *crown = load_bitmap("../images/crown.bmp", NULL);

    //enemy for night mode
    BITMAP *bridge = load_bitmap("../images/bridge_1.bmp", NULL);

    //point to collect for night mode is stars
    BITMAP *star = load_bitmap("../images/star_0.bmp", NULL);


    while (!key[KEY_ESC]) {
        clearScreen();
        mousex = mouse_x;
        mousey = mouse_y;
        leftClick = (mouse_b & 1);

        if (startScreenMode == 1) {

            loadBackgroundImage("../images/super_mario_bros.bmp");

            textout_centre_ex(buffer, font, "To turn off/on the music PRESS CTRL+M", 320, 400, WHITE, BLACK);
            textout_centre_ex(buffer, font, "Dodge enemies, collect coins and capture the flag to win.", 320, 420,
                              WHITE, BLACK);
            textout_centre_ex(buffer, font, "Press ENTER to begin", 320, 440, WHITE, BLACK);
            textout_centre_ex(buffer, font, "Press ESC to terminate", 320, 460, WHITE, BLACK);

            blit(buffer, screen, 0, 0, 0, 0, 640, 480);

            printf("1 %d\n", mainMenuMode);
            if (mainMenuMode == 1) {
                textout_ex(sky, font, "MarioBros (ESC to quit)", 0, 1, BLACK, WHITE);
                textout_ex(sky, font, "Press Ctrl+H for Help", 460, 1, BLACK, WHITE);

                printf("2\n");

                if (key[KEY_LCONTROL] && key[KEY_H] || key[KEY_RCONTROL] && key[KEY_H]) {
                    textout_ex(sky, font, "Moving Your Sprites: ", 180, 35, BLACK, WHITE);
                    textout_ex(sky, font, " > to move right ", 180, 45, BLACK, WHITE);
                    textout_ex(sky, font, " < to move left ", 180, 55, BLACK, WHITE);
                    textout_ex(sky, font, " ^ to jump up", 180, 65, BLACK, WHITE);

                    textout_ex(sky, font, " Lifelines will reduce upon colliding with enemies.", 130, 85, BLACK, WHITE);
                }


                //draw
                //Reference: https://rpg.hamsterrepublic.com/ohrrpgce/Free_Sprites
                set_trans_blender(225, 225, 255, 128);


                draw_sprite(buffers, sky, 0, 0);
                draw_sprite_ex(sky, mario, 385, 227, DRAW_SPRITE_NORMAL, DRAW_SPRITE_NO_FLIP);

                textout_ex(sky, font, "Game Mode", 485, 340, WHITE, BLACK);

                printf("3\n");

                //selection
                textout_centre_ex(sky, font, "Press F1: Day Mode", 540, 360, WHITE, BLACK);
                textout_centre_ex(sky, font, "Press F2: Night Mode", 540, 380, WHITE, BLACK);

                draw_sprite(screen, buffers, 0, 0);
                clear(buffers);

                //if selected F1: Day Mode
                if (key[KEY_F1]) {
                    mainMenuMode = 0;
                    gamePlayMode = 1;
                    clearScreens();
                }




            }



            printf("lol\n");
            if (gamePlayMode == 1) {
                printf("4\n");
                draw_sprite(buffers, day, 0, 0);



                int x = 10, y = 10;
                int velx, vely;
                velx = vely = 0;
                const int gravity = 1;
                int groundheight = 350;
                int screenScrollXPosition = 0;
                int width = SCREEN_W;

                while (gamePlayMode == 1) {
                    printf("5\n");
                    clearScreens();
                    printf("5\n");

                    draw_sprite(buffers, day, screenScrollXPosition, 0);


                    teta += 2.5;

                    //coins worth 1 point
                    rotate_sprite(day, coin1, 50, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 100, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 150, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 200, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 250, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 300, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 350, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 400, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 450, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 500, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 550, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 600, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 650, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 700, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 750, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 800, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 850, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 900, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 950, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 1000, 300, ftofix(teta));

                    rotate_sprite(day, coin1, 2000, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 2100, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 2200, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 2300, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 2400, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 2500, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 2600, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 2700, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 2800, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 2900, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 3000, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 4000, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 4100, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 4100, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 4200, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 4300, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 4400, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 4500, 300, ftofix(teta));
                    rotate_sprite(day, coin1, 4800, 350, ftofix(teta));
                    rotate_sprite(day, coin1, 4900, 300, ftofix(teta));

                    //worth 15 points
                    rotate_sprite(day, bonus, 400, 250, ftofix(0));
                    rotate_sprite(day, bonus, 800, 250, ftofix(0));
                    rotate_sprite(day, bonus, 1200, 250, ftofix(0));
                    rotate_sprite(day, bonus, 1800, 250, ftofix(0));
                    rotate_sprite(day, bonus, 2300, 250, ftofix(0));
                    rotate_sprite(day, bonus, 2900, 250, ftofix(0));
                    rotate_sprite(day, bonus, 3400, 250, ftofix(0));
                    rotate_sprite(day, bonus, 4100, 250, ftofix(0));
                    rotate_sprite(day, bonus, 4700, 250, ftofix(0));
                    rotate_sprite(day, bonus, 5100, 250, ftofix(0));
                    rotate_sprite(day, bonus, 5600, 250, ftofix(0));

                    //randomly put enemies everywhere
                    //enemy type 1
                    draw_sprite(day, enemy1, 445, 390);
                    draw_sprite(day, enemy1, 676, 390);
                    draw_sprite(day, enemy1, 885, 390);
                    draw_sprite(day, enemy1, 1034, 390);
                    draw_sprite(day, enemy1, 1645, 390);
                    draw_sprite(day, enemy1, 2676, 390);
                    draw_sprite(day, enemy1, 2999, 390);
                    draw_sprite(day, enemy1, 3385, 390);
                    draw_sprite(day, enemy1, 4145, 390);
                    draw_sprite(day, enemy1, 4676, 390);

                    //enemy type 2
                    draw_sprite(day, enemy2, 300, 385);
                    draw_sprite(day, enemy2, 4500, 385);
                    draw_sprite(day, enemy2, 3500, 385);

                    //fireball1
                    draw_sprite(day, fireball1, 345, 385);
                    draw_sprite(day, fireball1, 2020, 385);
                    draw_sprite(day, fireball1, 3030, 385);
                    draw_sprite(day, fireball1, 4040, 385);
                    draw_sprite(day, fireball1, 845, 385);
                    draw_sprite(day, fireball1, 1485, 385);

                    //fireball2
                    draw_sprite(day, fireball2, 500, 385);
                    draw_sprite(day, fireball2, 1000, 385);
                    draw_sprite(day, fireball2, 2000, 385);
                    draw_sprite(day, fireball2, 3000, 385);
                    draw_sprite(day, fireball2, 4000, 385);
                    draw_sprite(day, fireball2, 5005, 385);


                    printf("5\n");
                    if (day == NULL)
                        printf("day\n");
                    else if (crown == NULL)
                        printf("crown");

                    draw_sprite(day, crown, 6250, 350);

                    printf("6\n");
                    if (key[KEY_ESC]) {
                        break;
                    }

                    printf("6\n");


                    //deal with collisions for coins
                    // dealing with collision with coins
                    //add points and destroy the sprite

                    if (pixel_perfect_colision(x, y, mario, 50 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 100 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 150 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 200 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 250 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 300 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 350 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 400 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 450 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 500 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 550 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 600 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 650 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 700 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 750 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 800 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 850 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 900 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 950 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1000 + screenScrollXPosition, 300, coin1) == TRUE) {
                        points = points + 1;


                    }


                    if (pixel_perfect_colision(x, y, mario, 2000 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2100 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2200 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2300 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2400 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2500 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2600 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2700 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2800 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2900 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3000 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4000 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4100 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4100 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4200 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4300 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4400 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4500 + screenScrollXPosition, 300, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4800 + screenScrollXPosition, 350, coin1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4900 + screenScrollXPosition, 300, coin1) == TRUE) {
                        points = points + 1;


                    }


                    if (pixel_perfect_colision(x, y, mario, 400 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 800 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1200 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1800 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2300 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2900 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3400 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3100 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4700 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 5100 + screenScrollXPosition, 250, bonus) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 5600 + screenScrollXPosition, 250, bonus) == TRUE) {
                        points = points + 15;


                    }


                    //they as in who whom is he who
                    if (pixel_perfect_colision(x, y, mario, 445 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 676 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 885 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1034 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1645 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2676 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2999 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3385 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4145 + screenScrollXPosition, 390, enemy1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4676 + screenScrollXPosition, 390, enemy1) == TRUE) {
                        lifeline = lifeline - 1;


                        if (lifeline == 0) {
                            textout_ex(day, font, "You lost! Try again :) ", x + 5, 15, BLACK, WHITE);
                            gamePlayMode = 0;
                            break;
                        }
                    }


                    if (pixel_perfect_colision(x, y, mario, 300 + screenScrollXPosition, 385, enemy2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4500 + screenScrollXPosition, 385, enemy2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3500 + screenScrollXPosition, 385, enemy2) == TRUE) {
                        lifeline = lifeline - 1;


                        if (lifeline == 0) {
                            textout_ex(day, font, "You lost! Try again :) ", x + 5, 15, BLACK, WHITE);
                            gamePlayMode = 0;
                            break;
                        }

                    }

                    if (pixel_perfect_colision(x, y, mario, 345 + screenScrollXPosition, 385, fireball1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2020 + screenScrollXPosition, 385, fireball1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3030 + screenScrollXPosition, 385, fireball1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4040 + screenScrollXPosition, 385, fireball1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 845 + screenScrollXPosition, 385, fireball1) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1485 + screenScrollXPosition, 385, fireball1) == TRUE) {
                        lifeline = lifeline - 1;


                        if (lifeline == 0) {
                            textout_ex(day, font, "You lost! Try again :) ", x + 5, 150, BLACK, WHITE);
                            gamePlayMode = 0;
                            break;
                        }

                    }


                    if (pixel_perfect_colision(x, y, mario, 500 + screenScrollXPosition, 385, fireball2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 1000 + screenScrollXPosition, 385, fireball2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 2000 + screenScrollXPosition, 385, fireball2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 3000 + screenScrollXPosition, 385, fireball2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 4000 + screenScrollXPosition, 385, fireball2) == TRUE ||
                        pixel_perfect_colision(x, y, mario, 5005 + screenScrollXPosition, 385, fireball2) == TRUE) {
                        lifeline = lifeline - 1;


                        if (lifeline == 0) {
                            textout_ex(day, font, "You lost! Try again :)", x + 5, 15, BLACK, WHITE);
                            gamePlayMode = 0;
                            break;
                        }
                    }

                    //pressing left, right and up
                    //include for gravitational effect when the character (mario) is jumping up

                    if (key[KEY_LEFT]) {
                        velx = -1;
                        screenScrollXPosition = screenScrollXPosition + 5;
                        width = width - 5;


                        //make sure the scrolling doesn't go beyond the identified areas
                        if (screenScrollXPosition > 0) {
                            screenScrollXPosition = screenScrollXPosition - 5;
                            width = width + 5;
                            x = 10;
                        }


                    } else if (key[KEY_RIGHT]) {
                        velx = 1;
                        screenScrollXPosition = screenScrollXPosition - 10;
                        width = width + 10;

                        //make sure the scrolling doesn't pass the length of the game
                        if (x > 610) {

                            //game is over
                            textprintf_ex(day, font, 6200, 15, BLACK, WHITE, " Health: %i", lifeline);
                            textprintf_ex(day, font, 6200, 30, BLACK, WHITE, " Points: %i", points);
                            textout_ex(day, font, "Nice work winner! MarioBros (ESC to quit)", 6200, 60, BLACK, WHITE);


                            screenScrollXPosition = screenScrollXPosition + 10;
                            width = width - 10;
                            x = 610;

                        }

                    } else {
                        velx = 0;
                    }

                    if (key[KEY_UP] && y >= groundheight) {
                        vely = -15;
                        width = width + 30;
                    }

                    vely += gravity;
                    x += velx;
                    y += vely;

                    if (y >= groundheight) {
                        y = groundheight;
                    }

                    draw_sprite(buffers, mario, x, y);
                    rest(30);

                    draw_sprite(screen, buffers, 0, 0);

                    //ESCAPE to quit
                    textout_ex(day, font, "MarioBros (ESC to quit at anytime)", 10, 5, BLACK, WHITE);
                    textprintf_ex(day, font, 10, 15, BLACK, WHITE, " Health: %i", lifeline);
                    textprintf_ex(day, font, 10, 30, BLACK, WHITE, " Points: %i", points);
                }


            }

            set_mouse_sprite(NULL);
            //MapFreeMem();



            //destroy
            destroy_bitmap(buffer);
            destroy_bitmap(mario);
            destroy_bitmap(sky);
            destroy_bitmap(enemy1);
            destroy_bitmap(enemy2);
            destroy_bitmap(buffers);
            destroy_bitmap(coin1);


            allegro_exit();
        }
//
// Created by Abdelkader on 12/05/2023.
//
    }
}