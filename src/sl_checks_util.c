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
	int	lines;
	int	chars;
	int	i;

	lines = 0;
	while (map[lines])
	{
		chars = 0;
		while (map[lines][chars])
			chars++;
		lines++;
	}
	lines--;
	chars--;
	i = -1;
	while (++i < chars)
		if (map[0][i] != '1' || map[lines][i] != '1')
			return (perror("Error.\nThe map is not closed"), 0);
	i = -1;
	while (++i < lines)
		if (map[i][0] != '1' || map[i][chars - 1] != '1')
			return (perror("Error.\nThe map is not closed"), 0);
	return (1);
}


//TODO Crear funcion para comprobar que el mapa solo contiene los caracteres permitidos

/*
 * #FT_CHECK_STD_ELEMENTS
 * 		checks if the given map has the right quantity of elements
 * 		- At least 1 collectable (c or C)
 * 		- Only 1 Exit (e or E)
 * 		- Only 1 Initial Position (p or P)
 *
 * #PARAMETERS
 * 		- char **map --> Is the .ber file converted to a char array.
 *
 * #RETURN
 * 		- 0 if the .ber does not fulfil with the elements number.
 * 		- 1 if the .ber is OK.
 */

int	ft_check_std_elements(char **map)
//TODO La funcion tiene mas de 25 lineas. Quizas haya que segmentarla
{
	int	lines = 0;
	int	i;
	int	count_c = 0;
	int	count_e = 0;
	int	count_p = 0;

	while (map[lines])
		lines++;
	lines--;
	while (lines >= 0)
	{
		i = -1;
		while (map[lines][++i])
		{
			if (map[lines][i] == 'c' || map[lines][i] == 'C')
				count_c++;
			else if (map[lines][i] == 'e' || map[lines][i] == 'E')
				count_e++;
			else if (map[lines][i] == 'p' || map[lines][i] == 'P')
				count_p++;
		}
		lines--;
	}
	if (count_c < 1 || count_e != 1 || count_p != 1)
		return (perror("Number of elements incorrect"), 0);
	return (1);
}
