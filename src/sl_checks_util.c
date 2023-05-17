//
// Created by Jose Manuel Florido Perena on 5/12/23.
//
#include "../inc/so_long.h"

/*
 * #FT_MAP_2_ARRAY
 * 		converts the given map in .ber format into an 2 dimensional
 * 		array thanks to the functionality of Get_Next_Line program.
 *
 * #PARAMETERS
 * 		- char **map_route --> This parameter is the route of the .ber file (map)
 * 		added at execution time.
 *
 * #RETURN
 * 		- The program return the bidimensional array.
 */

char	**ft_map_2_array(char *map_route)
{
	int		fd;
	char	**map;
	int		lines;
	int		i;

	map = NULL;
	lines = 0;
	i = 0;
	fd = open(map_route, O_RDONLY);
	if (fd == -1)
		printf("File open error");
	else
	{
		while (get_next_line(fd))
			lines++;
		//printf("Lineas: %d\n", lines);
		close(fd);
		map = malloc (sizeof (char *) * lines);
		fd = open(map_route, O_RDONLY);
		while (i < lines)
		{
			map[i++] = get_next_line(fd);
			//printf("Linea %d: %s\n", i, map[i]);
			//i++;
		}
		close(fd);
	}
	return (map);
}

/*
 * #FT_CHECK_MAPS_RECTANGLE
 * 		checks if the given map is a rectangle.
 * 		**rectangle: all rows have the same number of characters
 * 		**rectangle: more columns than rows
 *
 * #PARAMETERS
 * 		- char **map --> Is the .ber file converted to a char array.
 *
 * #RETURN
 * 		- 0 if the .ber converted is not a rectangle.
 * 		- 1 if the .ber file converted is a rectangle.
 */

int	ft_check_maps_rectangle(char **map)
{
	int	rows;
	int	columns;
	int	col_base;

	col_base = 0;
	while (map[0][col_base])
		col_base++;
	//printf("Col_base: %d\n", col_base);
	rows = 0;
	while (map[rows])
	{
		columns = 0;
		while (map[rows][columns])
			columns++;
		//printf("Fila %d - Columnas: %d\n", rows, columns);
		if (columns != col_base)
			return (perror("Error.\nThe map is not a rectangle"), 0);
		rows++;
	}
	if (columns > rows)
		return (1);
	return (0);
}

/*
 * #FT_CHECK_MAP_LEAKS
 * 		checks if the given map is has 1 on all its perimeter.
 * 		If the functions discover a character not equal to 1, it
 * 		returns 0. Otherwise, it returns 1;
 *
 * #PARAMETERS
 * 		- char **map --> Is the .ber file converted to a char array.
 *
 * #RETURN
 * 		- 0 if the .ber has leaks on its perimeter.
 * 		- 1 if the .ber has no leaks.
 */

int	ft_check_map_leaks(char **map)
{
	int lines = 0;
	int chars = 0;
	int i = 0;

	while (map[lines])
	{
		chars = 0;
		while (map[lines][chars])
			chars++;
		lines++;
	}
	lines--;
	chars--;
	i = 0;
	while (i < chars)
	{
		if (map[0][i] != '1' || map[lines][i] != '1')
		{
			//ft_error_exit();
			return (perror("Error.\nThe map is not closed"), 0);
		}
		i++;
	}
	i = 0;
	while (i < lines)
	{
		if (map[i][0] != '1' || map[i][chars - 1] != '1')
		{
			//ft_error_exit();
			return (perror("Error.\nThe map is not closed"), 0);
		}
		i++;
		//printf("Lines: %d\n", lines);
	}
	//printf("Llego al final\n");
	return (1);
}
