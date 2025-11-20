#include "life2.h"

void    free_map(char** map)
{
    if (map)
    {
        int i = 0;
        while(map[i] != NULL)
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

int init_game(t_game* game, char** argv)
{
    game->heigth = atoi(argv[1]);
    game->width = atoi(argv[2]);
    game->iteration = atoi(argv[3]);
    if (game->heigth <= 0 || game->width <= 0 || game->iteration < 0)
        return (-1);
    game->alive = '0';
    game->dead = ' ';
    game->i = 0;
    game->j = 0;
    game->draw = 0;
    game->map = malloc(sizeof(char*) * game->heigth);
    if (!(game->map))
        return (-1);
    for (int i = 0; i < game->heigth; i++)
    {
        game->map[i] = malloc(sizeof(char) * (game->width + 1));
        if (!game->map[i])
        {
            free_map(game->map);
            return (-1);
        }

        for (int j = 0; j < game->width; j++)
            game->map[i][j] = game->dead;

        game->map[i][game->width] = '\0';
    }
    return (0);
}

void    get_map(t_game* game)
{
    char    buf;
    while (read(0, &buf, 1) == 1)
    {
        switch(buf)
        {
            case 'w':
                if (game->i > 0)
                    game->i--;
                break;
            case 's':
                if (game->i < game->heigth)
                    game->i++;
                break;
            case 'a':
                if (game->j > 0)
                    game->j--;
                break;
            case 'd':
                if (game->j < game->width)
                    game->j++;
                break;
            case 'x':
                game->draw = !(game->draw);
                break;
        }

        if (game->draw)
        {
            if ((game->i >= 0) && (game->i < game->heigth) && (game->j >= 0) && (game->j < game->width))
                game->map[game->i][game->j] = game->alive;
        }
    }
}

int count_voisin(t_game* game, int i, int j)
{
    int count = 0;

    for (int di = -1; di < 2; di++)
    {
        for (int dj = -1; dj < 2; dj++)
        {
            if (di == 0 && dj == 0)
                continue;
            
            int ni = i + di;
            int nj = j + dj;
            if ((ni >= 0) && (nj >= 0) && (ni < game->heigth) && (nj < game->width))
            {
                if (game->map[ni][nj] == game->alive)
                    count++;
            }
        }
    }

    return (count);
}

int play(t_game* game)
{
    char**  temp = malloc(sizeof(char*) * game->heigth);
    if (!temp)
        return (-1);
    for (int i = 0; i < game->heigth; i++)
    {
        temp[i] = malloc(sizeof(char) * (game->width + 1));
        if (!temp[i])
            return (-1);
        temp[i][game->width] = '\0';
    }

    for (int i = 0; i < game->heigth; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            int voisin = count_voisin(game, i, j);

            if (game->map[i][j] == game->alive)
            {
                if (voisin == 2 || voisin == 3)
                    temp[i][j] = game->alive;
                else
                    temp[i][j] = game->dead;
            }
            else
            {
                if (voisin == 3)
                    temp[i][j] = game->alive;
                else
                    temp[i][j] = game->dead;
            }
        }
    }

    free_map(game->map);
    game->map = temp;
    return (0);
}

void    print_map(t_game* game)
{
    for (int i = 0; i < game->heigth; i++)
    {
        for (int j = 0; j < game->width; j++)
            putchar(game->map[i][j]);
        putchar('\n');
    }
}

int main(int argc, char** argv)
{
    if (argc != 4)
        return (-1);

    t_game  game;
    if (init_game(&game, argv) == -1)
        return (-1);
    
    get_map(&game);

    for (int i = 0; i < game.iteration; i++)
    {
        if (play(&game) == -1)
        {
            free_map(game.map);
            return (-1);
        }
    }

    print_map(&game);
    free_map(game.map);
    return (0);
}