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
 * #FT_MAP_SIZE
 * 		Get the map size in x & y values
 *
 * #PARAMETERS
 *		- char **map --> The map converted into a char **
 *
 * #RETURN
 * 		- The map size expressed in x (columns) & y (rows) values.
 */

t_coord	ft_map_size(char **map)
{
	t_coord	map_size;
	int	cols;
	int	lines;

	lines = 0;
	cols = 0;
	while (map[lines])
	{
		cols = 0;
		while (map[lines][cols])
			cols++;
		lines++;
	}
	map_size.x = cols;
	map_size.y = lines;
	//printf("map_size.x: %d\n", map_size.x);
	//printf("map_size.y: %d\n", map_size.y);
	return (map_size);
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
