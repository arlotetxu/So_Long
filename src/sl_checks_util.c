//
// Created by Jose Manuel Florido Perena on 5/12/23.
//
#include "../inc/so_long.h"

/*
 * #FT_CHECK_MAPS_RECTANGLE
 * 		checks if the given map is a rectangle.
 * 			rectangle: same nums of columns on each line
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
	t_coord	map_size;
	int		lines;
	int 	cols;

	map_size = ft_map_size(map);
//	printf("Map_size.x - colums en ft_check_maps_rectangle: %d\n", map_size.x);
//	printf("Map_size.y - rows en ft_check_maps_rectangle: %d\n", map_size.y);
	lines = 0;
	while (map[lines])
	{
		cols = 0;
		while (map[lines][cols])
			cols++;
		if (cols - 1 != map_size.x)
			return (perror("Error.\nThe map is not a rectangle"), 0);
		lines++;
	}
	return (1);
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

	lines = ft_map_size(map).y;
	chars = ft_map_size(map).x;
	i = -1;
	while (++i < chars)
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			return (perror("Error.\nThe map is not closed"), 0);
	i = 0;
	while (++i < lines)
		if (map[i][0] != '1' || map[i][chars - 1] != '1')
			return (perror("Error.\nThe map is not closed"), 0);
	return (1);
}

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
{
	int	lines;
	int	i;
	int	count_c = 0;
	int	count_e = 0;
	int	count_p = 0;

	lines = ft_map_size(map).y - 1;
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
		return (perror("Error.\nNumber of elements incorrect"), 0);
	return (1);
}

/*
 * #FT_CHECK_NOSTD_ELEMENTS
 * 		checks if the given map has only the allowed elements
		- 1 / 0 / c / C / e / E / p / P
 *
 * #PARAMETERS
 * 		- char **map --> Is the .ber file converted to a char array.
 *
 * #RETURN
 * 		- 0 if the .ber file contains not allowed characters.
 * 		- 1 if the .ber is OK.
 */

int	ft_check_nostd_elements(char **map)
{
	int	lines;
	int	i;
	t_coord	map_size;

	map_size = ft_map_size(map);
	lines = -1;
	while (++lines < map_size.y)
	{
		i = -1;
		while (map[lines][++i])
		{
			if (map[lines][i] != '1' && map[lines][i] != '0' &&
					map[lines][i] != 'e' && map[lines][i] != 'E' &&
					map[lines][i] != 'c' && map[lines][i] != 'C' &&
					map[lines][i] != 'p' && map[lines][i] != 'P' &&
					map[lines][i] != '\n')
				return (perror("Error.\nElements in the map not allowed"), 0);
		}
	}
	return (1);
}
