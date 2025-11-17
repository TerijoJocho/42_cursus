#include "life.h"

void    free_map(t_game* game)
{
    if (game->map)
    {
        for (int i = 0; i < game->height; i++)
        {
            if (game->map[i])
                free(game->map[i]);
        }
        free(game->map);
    }
}

void    print_map(t_game* game)
{
    for (int k = 0; k < game->height; k++)
    {
        for (int l = 0; l < game->width; l++)
        {
            putchar(game->map[k][l]);
        }
        putchar('\n');
    }
}

int init_game(t_game* game, char** argv)
{
    game->width = atoi(argv[1]);
    game->height = atoi(argv[2]);
    game->iterations = atoi(argv[3]);
    if (game->width <= 0 || game->height <= 0 || game->iterations < 0)
        return (-1);
    game->alive = '0';
    game->dead = ' ';
    game->i = 0;
    game->j = 0;
    game->draw = 0;
    game->map = (char**)malloc(sizeof(char*) * (game->height));
    if (!game->map)
        return (-1);
    for (int k = 0; k < game->height; k++)
    {
        game->map[k] = (char*)malloc(sizeof(char) * (game->width));
        if (!game->map[k])
        {
            free_map(game);
            return (-1);
        }

        for (int l = 0; l < game->width; l++)
        {
            game->map[k][l] = game->dead;
        }
    }
    return (0);
}

void    fill_map(t_game* game)
{
    char    buf;
    while (read(0, &buf, 1) == 1)
    {
        switch (buf)
        {
            case 'w':
                if (game->i > 0)
                    game->i--;
                break;
            case 's':
                if (game->i < game->height + 1)
                    game->i++;
                break;
            case 'a':
                if (game->j > 0)
                    game->j--;
                break;
            case 'd':
                if (game->j < game->width + 1)
                    game->j++;
                break;
            case 'x':
                game->draw = !(game->draw);
                break;
            default:
                break;
        }
        if (game->draw)
        {
            if ((game->i >= 0) && (game->i < game->height) && (game->j >= 0) && (game->j < game->width))
                game->map[game->i][game->j] = game->alive;
        }
    }
}

int count_voisins(t_game* game, int i, int j)
{
    int count = 0;

    //on va lire les voisins d'une cellule de -1 à 1
    for (int di = -1; di < 2; di++)
    {
        for (int dj = -1; dj < 2; dj++)
        {
            //on esqive la cellule en question
            if ((di == 0) && (dj == 0))
                continue;
            
            //on enregistre les coords du voisins
            int ni = i + di;
            int nj = j + dj;
            if ((ni >= 0) && (nj >= 0) && (ni < game->height) && (nj < game->width))
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
    //on creer une copie de la map vide
    char**  temp = (char**)malloc(sizeof(char*) * game->height);
    if (!temp)
        return (-1);
    for (int i = 0; i < game->height; i++)
    {
        temp[i] = (char*)malloc(sizeof(char) * game->width);
        if (!(temp[i]))
            return (-1);
    }

    //on iter sur la map
    for (int i = 0; i < game->height; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            //on compte les voisins de la cellule
            int voisins = count_voisins(game, i ,j);

            //si la cellule est vivante
            if (game->map[i][j] == game->alive)
            {
                //et qu'elle a 2 ou 3 voisins on la laisse vivante dans temp
                if (voisins == 2 || voisins == 3)
                    temp[i][j] = game->alive;
                //sinon elle meurt
                else
                    temp[i][j] = game->dead;
            }
            //si la cellule est morte
            else 
            {
                //et qu'elle a 3 voisins elle est vivante dans temp
                if (voisins == 3)
                    temp[i][j] = game->alive;
                //sinon elle reste morte
                else
                    temp[i][j] = game->dead; 
            }
        }
    }
    free_map(game);
    game->map = temp;
    return (0);
}

int main(int argc, char** argv)
{
    if (argc != 4)
        return (1);
    
    t_game  game;
    if (init_game(&game, argv) == -1)
        return (-1);

    fill_map(&game);

    for (int i = 0; i < game.iterations; i++)
    {
        if (play(&game) == -1)
        {
            free_map(&game);
            return (-1);
        }
    }

    print_map(&game);
    free_map(&game);

    return (0);
}