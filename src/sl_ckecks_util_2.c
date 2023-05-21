//
// Created by Jose Manuel Florido Pereña on 20/5/23.
//
#include "../inc/so_long.h"

//Tras recorrer el mapa, si quedan coleccionables o no he llegado a  la salida
// entonces el mapa es irresoluble
char	**ft_dupli_map(char **map, t_coord size)
{
	char **copy_map;
	int i;
	int j;

	copy_map = malloc(sizeof(char *) * size.y);
	if (copy_map == NULL)
		return (NULL);
	i = -1;
	while (++i < size.y)
	{
		copy_map[i] = malloc(size.x + 1);
		j = -1;
		while (++j < size.x)
			copy_map[i][j] = map[i][j];
		copy_map[i][size.x] = '\0';
	}
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", map[i]);
	printf("\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", copy_map[i]);
	printf("\n");
	return (copy_map);
}

/*void	fill(char **map, t_coord size, t_coord start, char to_fill)
{
	if (start.y < 0 || start.y >= size.y || start.x < 0 || start.x >= size.x
		|| map[start.y][start.x] != to_fill)
		return;

	map[start.y][start.x] = 'X';
	fill(map, size, (t_coord){start.x - 1, start.y}, to_fill);
	fill(map, size, (t_coord){start.x + 1, start.y}, to_fill);
	fill(map, size, (t_coord){start.x, start.y - 1}, to_fill);
	fill(map, size, (t_coord){start.x, start.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_coord size, t_coord begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}*/