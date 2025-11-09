#ifndef MY_BSQ_H
#define MY_BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// strucuture pour les elements donnés à la première ligne
typedef struct s_elements
{
    int n_lines;
    char empty;
    char obstacle;
    char full;
} t_elements;

// structure pour la map
typedef struct s_map
{
    char** grid;
    int height;
    int width;
} t_map;

//structure pour le carré à dessiner
typedef struct s_square
{
    int size;
    int i;
    int j;
} t_square;

int execute_my_bsq(FILE* file);
int my_convert_file_pointer(char* name);

#endif