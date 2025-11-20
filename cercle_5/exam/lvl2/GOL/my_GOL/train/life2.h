#ifndef LIFE2_H
#define LIFE2_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game
{
    int     heigth;
    int     width;
    int     iteration;
    char    alive;
    char    dead;
    int     i;
    int     j;
    int     draw;
    char    **map;
}t_game;

#endif