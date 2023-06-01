//
// Created by Jose Manuel Florido Perena on 5/27/23.
//
#include "../inc/so_long.h"

void	ft_place_texture(t_general_p general_p, char *texture, int x, int y)
{
	t_image	img_;

	img_.img = mlx_xpm_file_to_image(general_p.mlx_ptr, texture, &img_.width_im, &img_.height_im);
	mlx_put_image_to_window(general_p.mlx_ptr, general_p.win_ptr, img_.img, x, y);
}


void	ft_pass_image(char map_char, t_general_p general_p, int x, int y)
{
	if (map_char == '1')
		ft_place_texture(general_p, WALL, x, y);
	else if (map_char == '0')
		ft_place_texture(general_p, FREE_, x, y);
	else if (map_char == 'c' || map_char == 'C')
		ft_place_texture(general_p, POO, x, y);
	else if (map_char == 'P' || map_char == 'p')
		ft_place_texture(general_p, TOILET, x, y);
	else if (map_char == 'e' || map_char == 'E')
		ft_place_texture(general_p, EXIT, x, y);
}

void	ft_pass_char(char **map, t_general_p general_p)
{
	int	lines;
	int	cols;
	int	x;
	int	y;

	lines = 0;
	y = 0;
	while (map[lines])
	{
		cols = 0;
		x = 0;
		while (map[lines][cols])
		{
			ft_pass_image(map[lines][cols], general_p, x, y);
			x = x + 80;
			cols++;
		}
		lines++;
		y = y + 80;
	}
}
