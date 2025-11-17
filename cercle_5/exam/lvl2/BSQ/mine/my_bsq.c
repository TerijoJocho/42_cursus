#include "my_bsq.h"

/*---------UTILS----------*/
char* ft_substr(char* line, int size)
{
    char* str = (char*)malloc(size + 1);
    if (!str)
        return (NULL);

    for (int i = 0; i < size; i++)
        str[i] = line[i];

    str[size] = '\0';
    return (str);
}

void free_map(char** map)
{
    int i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i += 1;
        }
        free(map);
    }
}

int element_control(char** map, char c1, char c2)
{
    int i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (map[i][j] != c1 && map[i][j] != c2)
                return (-1);
            j +=1;
        }
        i +=1;
    }
    return (0);
}

/*--------------FONCTIONS IMPORTANTES-----------*/
/*Verification des elements de la premiere ligne*/
int load_elements(FILE* file, t_elements* elements)
{
    //on lis dans le file la 1er ligne puis on stocke les elements dans notre struct
    int ret = fscanf(file, "%d %c %c %c", &(elements->n_lines), &(elements->empty), &(elements->obstacle), &(elements->full));

    //on verifie qu'il y en a 4
    if (ret != 4)
        return (-1);

    //on verifie s'ils respectent le sujet
    if (elements->n_lines <= 0)
        return (-1);
    if (elements->empty == elements->full || elements->empty == elements->obstacle || elements->obstacle == elements->full)
        return (-1);
    if (elements->empty < 32 || elements->empty > 126)
        return (-1);
    if (elements->obstacle < 32 || elements->obstacle > 126)
        return (-1);
    if (elements->full < 32 || elements->full > 126)
        return (-1);

    return (0);
}

/*enregistrement et verif de la map*/
int load_map(FILE* file, t_map* map, t_elements* elements)
{
    //on initialise notre map char** a la taille n_lines avec des lignes NULL
    map->height = elements->n_lines;
    map->grid = (char**)calloc(map->height + 1, sizeof(char*));
    if (!map->grid)
        return (-1);

    char* line = NULL;
    size_t len = 0;

    //on enleve le '\n' que fscanf n'a pas lu
    if (getline(&line, &len, file) == -1)
    {
        if (line)
            free(line);
        free_map(map->grid);
        return (-1);
    }

    //on va lire chaque lignes du file et copier les ligne dans la map
    for (int i = 0; i < map->height; i += 1)
    {
        //on lis la ligne
        int read = getline(&line, &len, file);
        if (read == -1)
        {
            if (line)
                free(line);
            free_map(map->grid);
            return (-1);
        }
        //on verifie qu'il y a bien un '\n', si oui on l'enlève
        if (line[read - 1] == '\n')
            read -= 1;
        else
        {
            free(line);
            free_map(map->grid);
            return (-1);
        }
        //on stock la ligne dans la grid
        map->grid[i] = ft_substr(line, read);
        if (!(map->grid[i]))
        {
            free(line);
            free_map(map->grid);
            return (-1);
        }
        //on verifie si les lignes font la meme tailles
        if (i == 0)
        {
            map->width = read;
            //+ si elles ont au moins une colonne
            if (map->width <= 0)
            {
                free(line);
                free_map(map->grid);
                return (-1);
            }
        }
        else
        {
            if (map->width != read)
            {
                free(line);
                free_map(map->grid);
                return (-1);
            }
        }
    }
    //on verifie que la map est formée des bon caractères
    if (element_control(map->grid, elements->empty, elements->obstacle) == -1)
    {
        free(line);
        free_map(map->grid);
        return (-1);
    }

    free(line);
    return (0);
}

/*retourne le plus petit des trois*/
int find_min(int n1, int n2, int n3)
{
    int min = n1;

    if (n2 < min)
        min = n2;
    if (n3 < min)
        min = n3;
    return (min);
}

/*On cherche le big carré*/
void    find_big_square(t_map* map, t_square* square, t_elements* elements)
{
    //on créer une matrix qu'on rempli de '0'
    int matrix[map->height][map->width];
    for (int i = 0; i < map->height; i += 1)
    {
        for (int j = 0; j < map->width; j += 1)
            matrix[i][j] = 0;
    }

    //grace aux calculs on trouve la taille du carré en plus des coins où il commence
    for (int i = 0; i < map->height; i += 1)
    {
        for (int j = 0; j < map->width; j += 1)
        {
            if (map->grid[i][j] == elements->obstacle) //obstacle -> pas possible de faire un carré
                matrix[i][j] = 0;
            else if (i == 0 || j == 0) //on a une case pour faire le carré à coté de chaque bords
            {
                matrix[i][j] = 1;
            }
            else //on calcul ici la taille max du carré -> on regarde pour chaque (i,j) le nb de cases libres à coté(haut, gauche, diag)
            {
                int min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
                matrix[i][j] = min + 1;
            }
            //lorsqu'on trouve une taille de carré plus grande, on met à jour la size et les coins en haut à gauche
            if (matrix[i][j] > square->size)
            {
                square->size = matrix[i][j];
                square->i = i - matrix[i][j] + 1;
                square->j = j - matrix[i][j] + 1;
            }
        }
        /*---------PRINT TEST------------*/
        // for (int k = 0; k < map->height; k += 1)
        // {
        //     for (int l = 0; l < map->width; l += 1)
        //         printf("%d", matrix[k][l]);
        //     printf("\n");
        // }
        // printf("square.size=%d, square.i=%d, square.j=%d\n", square->size, square->i, square->j);
        /*---------------------*/
    }
}

void    print_filled_square(t_map* map, t_square* square, t_elements* elements)
{
    //on remplace dans la map les bons éléments
    for (int i = square->i; i < square->i + square->size; i += 1)
    {
        for (int j = square->j; j < square->j + square->size; j += 1)
            map->grid[i][j] = elements->full;
    }

    //on print la map avec des '\n'
    for (int i = 0; i < map->height; i += 1)
        fprintf(stdout, "%s\n", map->grid[i]);
}

/*On execute notre programme bsq*/
int execute_my_bsq(FILE* file)
{
    //on enregistre + verifie les elements de la premiere ligne
    t_elements elements;
    if (load_elements(file, &elements) == -1)
        return (-1);
    
    //on enregistre la map
    t_map   map;
    if (load_map(file, &map, &elements) == -1)
        return (-1);

    //on cherche le plus grand carré
    t_square    square;
    square.size = 0;
    square.i = 0;
    square.j = 0;
    find_big_square(&map, &square, &elements);

    //on remplit la map puis on l'affiche sur le stdout
    print_filled_square(&map, &square, &elements);

    free_map(map.grid);
    return (0);
}

/*
* Le programme demarre, on converti le fichier reçus en paramètre en FILE*
*/
int my_convert_file_pointer(char* name)
{
    FILE* file = fopen(name, "r"); //on ouvre le fichier en mode lecture
    if (!file)
        return (-1);

    int res = 0;
    res = execute_my_bsq(file);
    fclose(file);
    return (res);
}