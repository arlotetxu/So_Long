//
// Created by Jose Manuel Florido Pereña on 21/5/23.
//
#include "../inc/so_long.h"

/*
 * #FT_MAP_2_ARRAY
 * 		converts the given map in .ber format into an 2 dimensional
 * 		array thanks to the functionality of Get_Next_Line program.
 *
 * #PARAMETERS
 * 		- char *map_route --> This parameter is the route of the .ber file (map)
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
		close(fd);
		map = malloc (sizeof (char *) * lines);
		fd = open(map_route, O_RDONLY);
		while (i < lines)
			map[i++] = get_next_line(fd);
		close(fd);
	}
	return (map);
}

/*
 * #FT_MAP_ROWS
 * 		Counts the number of rows the map has
 *
 * #PARAMETERS
 *		- char **map --> The map converted into a char **
 *
 * #RETURN
 * 		- The number of rows in interger data type.
 */
int	ft_map_rows(char **map)
{
	int lines;

	lines = 0;
	while (map[lines])
		lines++;
	return (lines);
}

/*
 * #FT_MAP_ROWS
 * 		Counts the number of rows the map has
 *
 * #PARAMETERS
 *		- char **map --> The map converted into a char **
 *
 * #RETURN
 * 		- The number of rows in interger data type.
 */
int	ft_map_columns(char **map)
{
	int cols;
	int lines;

	lines = 0;
	cols = 0;
	while (map[lines])
	{
		cols = 0;
		while (map[lines][cols])
			cols++;
		lines++;
	}
	return (cols);
}

/*
 *
 */
t_coord	ft_start_posit(char **map)
{
	t_coord	start_coor;
	int				lines;
	int				cols;

	lines = 0;
	start_coor.x = 0;
	start_coor.y = 0;
	while (map[lines])
	{
		cols = 0;
		while (map[lines][cols])
		{
			if (map[lines][cols] == 'P' || map[lines][cols] == 'p')
			{
				start_coor.x = cols;
				start_coor.y = lines;
				return (start_coor);
			}
			cols++;
		}
		lines++;
	}
	return (start_coor);
}
