#include "bsq.h"

char*	ft_substr(char*	str, int size)
{
	char*	res = (char*)malloc(size + 1);
	if (!res)
		return (NULL);

	for (int i = 0; i < size; i++)
		res[i] = str[i];

	res[size] = '\0';

	return (res);
}

void	free_map(char** map)
{
	if (map)
	{
		int	i = 0;
		while (map[i] != NULL)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}

int	get_element(FILE* file, t_element* element)
{
	int	n = fscanf(file, "%d%c%c%c", &(element->nb_ligne), &(element->vide), &(element->obstacle), &(element->plein));

	if (n != 4)
		return (-1);
	char*	buf = NULL;
	size_t	len = 0;
	if (getline(&buf, &len, file) > 1)
		return (-1);
	free(buf);

	if (element->nb_ligne <= 0)
		return (-1);
	if (element->obstacle == element->plein || element->obstacle == element->vide || element->vide == element->plein)
		return (-1);
	if (element->obstacle < 32 || element->obstacle > 126)
		return (-1);
	if (element->vide < 32 || element->vide > 126)
		return (-1);
	if (element->plein < 32 || element->plein > 126)
		return (-1);
	return (0);
}

int	get_map(FILE* file, t_map* map, t_element* element)
{
	map->height = element->nb_ligne;
	map->grid = (char**)calloc(map->height + 1, sizeof(char*));
	if (!map->grid)
		return (-1);

	char*	buf = NULL;
	size_t	len = 0;

	for (int i = 0; i < map->height; i++)
	{
		int	n = getline(&buf, &len, file);

		if (n == -1)
		{
			if (buf)
				free(buf);
			return (-1);
		}
		if (buf[n-1] == '\n')
			n -= 1;
		else
		{
			if (buf)
				free(buf);
			return (-1);
		}

		map->grid[i] = ft_substr(buf, n);
		if (!(map->grid[i]))
		{
			if (buf)
				free(buf);
			return (-1);
		}

		if (i == 0)
		{
			map->width = n;
			if (map->width <= 0)
			{
				if (buf)
					free(buf);
				return (-1);
			}
		}
		else
		{
			if (n != map->width)
			{
				if (buf)
					free(buf);
				printf("LOG - ici\n");
				return (-1);
			}
		}
	}

	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j] != element->vide && map->grid[i][j] != element->obstacle)
				return (-1);
		}
	}

	free(buf);
	return (0);
}

int	find_min(int n1, int n2, int n3)
{
	int min = n1;
	if (min > n2)
		min = n2;
	if (min > n3)
		min = n3;
	return (min);
}

void	find_big_square(t_map* map, t_square* square, t_element* element)
{
	int	matrix[map->height][map->width];
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->height; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->height; j++)
		{
			if (map->grid[i][j] == element->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int	min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
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

void	print_square(t_map* map, t_square* square, t_element* element)
{
	for (int i = square->i; i < square->i + square->size; i++)
	{
		for (int j = square->j; j < square->j + square->size; j++)
		{
			map->grid[i][j] = element->plein;
		}
	}

	for (int i = 0; i < map->height; i++)
	{
		fprintf(stdout, "%s\n", map->grid[i]);
	}
}

int	exec_bsq(FILE* file)
{
	t_element	element;
	if (get_element(file, &element) == -1)
		return (-1);

	t_map	map;
	if (get_map(file, &map, &element) == -1)
	{
		free_map(map.grid);
		return (-1);
	}

	t_square	square;
	square.size = 0;
	square.i = 0;
	square.j = 0;
	find_big_square(&map, &square, &element);

	print_square(&map, &square, &element);
	free_map(map.grid);
	return (0);
}

int	convert_file(char* input)
{
	FILE* file = fopen(input, "r");
	if (!file)
		return (-1);

	int res = 0;
	res = exec_bsq(file);
	fclose(file);
	return (res);
}
