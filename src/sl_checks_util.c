//
// Created by Jose Manuel Florido Perena on 5/12/23.
//
#include "../inc/so_long.h"

char	**ft_map_2_array(void)
{
	int		fd;
	char	**map;
	int 	lines = 0;
	int 	i = 0;

	map = NULL;
	fd = open("maps/map_0.ber", O_RDONLY);
	if (fd == -1)
		printf("File open error");
	else
	{
		while (get_next_line(fd))
			lines++;
		printf("Lineas: %d\n", lines);
		close(fd);
		map = malloc (sizeof (char *) * lines);
		fd = open("maps/map_0.ber", O_RDONLY);
		while (i < lines)
		{
			map[i] = get_next_line(fd);
			printf("Linea %d: %s\n", i, map[i]);
			i++;
		}
		close(fd);
	}
	return (map);
}