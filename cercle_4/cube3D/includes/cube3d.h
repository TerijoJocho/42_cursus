

#ifndef CUBE3D_H
#define CUBE3D_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

int    ft_get_file(char *argv);
int    ft_parse_file(char **lines);

#endif