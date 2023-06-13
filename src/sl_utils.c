/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:09:16 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/13 19:13:12 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	**ft_map_2_array(char *map_route) //TODO funcion con mas de 25 lineas
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
		return (NULL);
	else
	{
		while (get_next_line(fd))
			lines++;
		close(fd);
		map = malloc (sizeof (char *) * (lines + 1));
		fd = open(map_route, O_RDONLY);
		while (i < lines)
		{
			map[i] = get_next_line(fd);
			map[i][ft_strlen(map[i]) - 1] = '\0';
			i++;
		}
		map[i] = NULL;
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
	int		lines;

	lines = 0;
	while (map && map[lines] != NULL)
		lines++;
	map_size.x = ft_strlen(map[0]);
	map_size.y = lines;
	return (map_size);
}


/*
 * #FT_START_POSIT
 * 		Get the position of the player starting point
 *
 * #PARAMETERS
 *		- char **map --> The map converted into a char **
 *
 * #RETURN
 * 		- a t_coord with the position of the 'P' or 'p' in coordinates.
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


/*
 * #FT_COUNT_C
 * 		Get the count of c/C characters within the map
 *
 * #PARAMETERS
 *		- char **map --> The map converted into a char **
 *
 * #RETURN
 * 		- count -> the count of the mentioned character.
 */
int	ft_count_c(char **map)
{
	int	lines;
	int	cols;
	int	count;

	lines = -1;
	count = 0;
	while (map && map[++lines])
	{
		cols = -1;
		while (map[lines][++cols])
		{
			if (map[lines][cols] == 'c' || map[lines][cols] == 'C')
				count++;
		}
	}
	return (count);
}
