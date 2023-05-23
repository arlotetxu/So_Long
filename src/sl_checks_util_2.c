//
// Created by Jose Manuel Florido Pereña on 20/5/23.
//
#include "../inc/so_long.h"

/*
 * #FT_DUPLI_MAP
 * 		- The function duplicates in a char** the original map.
 *
 * #PARAMETERS
 * 		- char **map -> Original map conveter into a char**
 * 		- t_coord -> the size of the original map (x, y)
 *
 * #RETURN
 * 		- A char** with the original map copy
 */
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
//	for (int i = 0; i < size.y; ++i)
//		printf("%s\n", map[i]);
//	printf("---------------------------\n");
//	for (int i = 0; i < size.y; ++i)
//		printf("%s\n", copy_map[i]);
//	printf("\n");
//TODO Liberar los malloc generados aqui tras hacer las comprobaciones necesarias
	return (copy_map);
}

/*
 * #FT_FILL_MAP
 * 		- This function converts all the characters in the given map as parameter
 * 			in 'X' characters except if the read char is a '1' or is an 'X'.
 * 			By doing this, later on, reading the modified map, we can determine
 * 			if the map has a solution or not (I can convert all the
 * 			collectables - c / C - and the exit - e / E - in a 'X').
 *
 * 	#PARAMETERS
 * 		- char **map -> the copy of the original map
 * 		- t_coord size -> the size of the map, needed to control if we go out
 * 			of the map when changing the characters
 * 		- t_coord start -> Initial point to start the changing. In this case
 * 			is the start position in the map ('p' / 'P')
 *
 * 	#RETURN
 *
 */

void	ft_fill_map(char **map, t_coord size, t_coord start)
{
	if (start.y < 0 || start.y >= size.y || start.x < 0 || start.x >= size.x
		|| map[start.y][start.x] == 'X' || map[start.y][start.x] == '1')
		return ;
	map[start.y][start.x] = 'X';
	ft_fill_map(map, size, (t_coord){start.x - 1, start.y});
	ft_fill_map(map, size, (t_coord){start.x + 1, start.y});
	ft_fill_map(map, size, (t_coord){start.x, start.y - 1});
	ft_fill_map(map, size, (t_coord){start.x, start.y + 1});
}

/*
 * #FT_FLOOD_FILL
 * 		Calls the rest of function to copy the original map and change its
 * 			values to check if the map has a solution
 *
 * 	#PARAMETERS
 * 		- char **map -> The original map
 *
 * 	#RETURN
 * 		The copied map modified to be checked later on
 */

char	**ft_flood_fill(char **map)
{
	char	**map_copy;
	t_coord	map_size;
	t_coord	start_p;

	map_copy = ft_dupli_map(map, ft_map_size(map));
	map_size = ft_map_size(map_copy);
	start_p = ft_start_posit(map_copy);
//	printf("------------COPIA---------------\n");
//	for (int i = 0; i < map_size.y; ++i)
//		printf("%s\n", map_copy[i]);
	//ft_fill_map(map_copy, map_size, start_p, tab[begin.y][begin.x]);
	ft_fill_map(map_copy, map_size, start_p);
//	printf("------------COPIA MODIF---------------\n");
//	for (int i = 0; i < map_size.y; ++i)
//		printf("%s\n", map_copy[i]);
//	printf("-----------ORIGINAL----------------\n");
//	for (int i = 0; i < map_size.y; ++i)
//		printf("%s\n", map[i]);
	return (map_copy);
}

//TODO Crear funcion para comprobar que no me quedan coleccionables (C) ni tengo la salida (E)
int	ft_check_map_valid(char **map, t_coord size)
{
	int		lines;
	int		cols;
	int		count;
	char	**copy_map2;

	lines = 0;
	count = 0;
	copy_map2 = ft_flood_fill(map);
	while (lines < size.y)
	{
		cols = -1;
		while (++cols < size.x)
		{
			if (copy_map2[lines][cols] == 'c' || copy_map2[lines][cols] == 'C'
				|| copy_map2[lines][cols] == 'e' || copy_map2[lines][cols] == 'E')
				count++;
		}
		lines++;
	}
	//ft_exiting(copy_map2);
	printf("Valor de count antes de salir: %d\n", count);
	if (count == 0)
		return (1);
	return (perror("Error.\nIt_is not possible to complete the map"), 0);
}
