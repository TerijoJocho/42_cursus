#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_element
{
    char    vide;
    char    obstacle;
    char    plein;
    int     nb_ligne;
}t_element;

typedef struct s_map
{
    int     heigth;
    int     width;
    char    **grid;
}t_map;

typedef struct s_square
{
    int i;
    int j;
    int size;
}t_square;

int convert_file2(char* argv);
int exec_bsq2(FILE* file);

#endif