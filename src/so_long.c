/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:13:52 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/13 19:14:26 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_so_long(t_gen_p general_p)
{
	t_image		img;

	general_p.mlx_ptr = mlx_init();
	img.img = mlx_xpm_file_to_image (general_p.mlx_ptr,
			FREE_, &img.width_im, &img.height_im);
	general_p.win_ptr = mlx_new_window (general_p.mlx_ptr,
			ft_map_size (general_p.map).x * img.width_im,
			ft_map_size (general_p.map).y * img.height_im, "WINNING THE POO");
	ft_paint_map(general_p);
	mlx_hook(general_p.win_ptr, 2, 1L << 0, ft_input_key, &general_p);
	mlx_hook(general_p.win_ptr, 17, 1L << 17, ft_close, &general_p);
	mlx_loop(general_p.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_gen_p	general;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror("Error.\nChecking file"), 0);
		general.map = ft_map_2_array(argv[1]);
		if (ft_check_map_ext(argv[1]) == 0
			|| ft_check_maps_rectangle(general.map) == 0
			|| ft_check_map_leaks(general.map) == 0
			|| ft_check_nostd_elements(general.map) == 0
			|| ft_check_std_elements(general.map) == 0
			|| ft_check_map_valid(general.map, ft_map_size(general.map)) == 0)
		{
			ft_exiting(general.map);
			return (0);
		}
		ft_so_long(general);
	}
	ft_exiting(general.map);
	free(general.mlx_ptr);
	return (0);
}

//Para chequear fugas de memoria
//system("leaks __nombre programa__");