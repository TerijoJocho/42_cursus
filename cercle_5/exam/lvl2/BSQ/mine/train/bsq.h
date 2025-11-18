#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>

typedef struct s_map
{
	int		height;
	int		width;
	char	**grid;
}t_map;

typedef struct s_element
{
	char	vide;
	char	obstacle;
	char	plein;
	int		nb_ligne;
}t_element;

typedef struct s_square
{
	int	size;
	int	i;
	int	j;
}t_square;


int	exec_bsq(FILE* file);
int	convert_file(char* input);
#endif
