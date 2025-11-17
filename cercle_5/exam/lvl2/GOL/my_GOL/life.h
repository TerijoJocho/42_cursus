#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
    int     width;
    int     height;
    int     iterations;
    char    alive;
    char    dead;
    int     i;
    int     j;
    int     draw;
    char    **map;
} t_game;

#endif