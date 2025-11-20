#include "bsq.h"

char*   ft_substr(char* line, int start, int size)
{
    char*   str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    
    for (int i = start; i < size; i++)
        str[i] = line[i];
    
    str[size] = '\0';
    return (str);
}

void    free_map(char** map)
{
    if (map)
    {
        int i = 0;
        while (map[i] != NULL)
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

int get_element(FILE* file, t_element* element)
{
    int n = fscanf(file, "%d%c%c%c", &(element->nb_ligne), &(element->vide), &(element->obstacle), &(element->plein));

    if (n != 4)
        return (-1);
    
    char*   buf = NULL;
    size_t  len = 0;
    if(getline(&buf, &len, file) > 1)
    {
        free(buf);
        return (-1);
    }
    free(buf);

    if(element->vide < 32 || element->vide > 126)
        return (-1);
    if(element->obstacle < 32 || element->obstacle > 126)
        return (-1);
    if(element->plein < 32 || element->plein > 126)
        return (-1);
    if (element->vide == element->obstacle || element->vide == element->plein || element->plein == element->obstacle)
        return (-1);
    return (0);
}

int get_map(FILE* file, t_element* element, t_map* map)
{
    map->heigth = element->nb_ligne;
    map->grid = (char**)calloc(map->heigth + 1, sizeof(char*));
    if (!map->grid)
        return (-1);
    
    char*   buf = NULL;
    size_t  len = 0;
    for (int i = 0; i < map->heigth; i++)
    {
        int n = getline(&buf, &len, file);

        if (n == -1)
        {
            free(buf);
            return (-1);
        }

        if (buf[n-1] == '\n')
            n -= 1;
        else
        {
            free(buf);
            return (-1);
        }

        map->grid[i] = ft_substr(buf, 0, n);
        if (!(map->grid[i]))
        {
            free(buf);
            return (-1);
        }

        if (i == 0)
        {
            map->width = n;
            if (map->width <= 0)
            {
                free(buf);
                return (-1);
            }
        }
        else
        {
            if (n != map->width)
            {
                free(buf);
                return (-1);
            }
        }

        for (int j = 0; j < map->width; j++)
        {
            if (map->grid[i][j] != element->vide && map->grid[i][j] != element->obstacle)
            {
                free(buf);
                return (-1);
            }
        }
    }
    return (0);
}

int find_min(int n1, int n2, int n3)
{
    int min = n1;
    if (min > n2)
        min = n2;
    if (min > n3)
        min = n3;
    return (min);
}

void    find_big_square(t_element* element, t_map* map, t_square* square)
{
    int matrix[map->heigth][map->width];
    for (int i = 0; i < map->heigth; i++)
    {
        for (int j = 0; j < map->heigth; j++)
        {
            matrix[i][j] = 0;
        }
    }
    
    for (int i = 0; i < map->heigth; i++)
    {
        for (int j = 0; j < map->heigth; j++)
        {
            if (map->grid[i][j] == element->obstacle)
                matrix[i][j] = 0;
            else if (i == 0 || j == 0)
                matrix[i][j] = 1;
            else
            {
                int min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
                matrix[i][j] = min + 1;
            }

            if (matrix[i][j] > square->size)
            {
                square->size = matrix[i][j];
                square->i = i - matrix[i][j] + 1;
                square->j = j - matrix[i][j] + 1;
            }
        }
    }
}

void    print_big_square(t_element* element, t_map* map, t_square* square)
{
    for (int i = square->i; i < square->i + square->size; i++)
    {
        for (int j = square->j; j < square->j + square->size; j++)
        {
            map->grid[i][j] = element->plein;
        }
    }

    for (int i = 0; i < map->heigth; i++)
    {
        fprintf(stdout, "%s\n", map->grid[i]);
    }
}

int exec_bsq2(FILE* file)
{
    t_element   element;
    if (get_element(file, &element) == -1)
        return (-1);
    
    t_map   map;
    if (get_map(file, &element, &map) == -1)
    {
        free_map(map.grid);
        return (-1);
    }

    t_square    square;
    square.i = 0;
    square.j = 0;
    square.size = 0;
    find_big_square(&element, &map, &square);

    print_big_square(&element, &map, &square);
    free_map(map.grid);
    return (0);
}

int convert_file2(char* argv)
{
    FILE* file = fopen(argv, "r");
    if (!file)
        return (-1);
    
    int res = 0;
    res = exec_bsq2(file);
    fclose(file);
    return (res);
}