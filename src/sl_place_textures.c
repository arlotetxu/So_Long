/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_place_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:07:27 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/13 19:09:04 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
 * #FT_PLACE_TEXTURE
 * 		The function receives the texture route and position vector
 * 		    to place it in the window.
 *
 * #PARAMETERS
 *		- char *texture --> route to each texture.
 *		- t_gen_p general_p -> struct with the needed program pointers
 *		    (mlx_ptr & win_ptr)
 *		- int x -> texture X position
 *		- int y -> texture Y position
 *
 * #RETURN
 * 		- Nothing.
 */
void	ft_place_texture(t_gen_p general_p, char *texture, int x, int y)
{
	t_image	img_;

	img_.img = mlx_xpm_file_to_image(general_p.mlx_ptr, texture,
			&img_.width_im, &img_.height_im);
	if (!img_.img)
	{
		ft_printf("Error.\nTexture file is corrupted.\n");
		ft_close(&general_p);
	}
	mlx_put_image_to_window(general_p.mlx_ptr, general_p.win_ptr,
		img_.img, x, y);
}

/*
 * #FT_PASS_IMAGE
 * 		Receiving each map characters, determine the right texture and
 * 		    call ft_place_texture to apply it on each position in the window.
 *
 * #PARAMETERS
 *		- char map_char --> Each map character.
 *		- t_gen_p general_p -> struct with the needed program pointers
 *		    (mlx_ptr & win_ptr)
 *		- int x -> texture X position
 *		- int y -> texture Y position
 *
 * #RETURN
 * 		- Nothing.
 */
void	ft_pass_image(char map_char, t_gen_p general_p, int x, int y)
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

/*
 * #FT_PASS_CHAR
 * 		Get each map character and passes it to the function
 * 		    ft_pass_image. Depending on the read character,
 * 		    the ft_pass_image determine the route for the right
 * 		    texture, what is placed with the function ft_place-texture
 *
 * #PARAMETERS
 *		- char **map --> The map converted into a char **
 *		- t_gen_p general_p -> struct with the needed program pointers
 *		    (mlx_ptr & win_ptr)
 *
 * #RETURN
 * 		- Nothing.
 */
void	ft_paint_map(t_gen_p general_p)
{
	int	lines;
	int	cols;
	int	x;
	int	y;

	lines = 0;
	y = 0;
	while (general_p.map[lines])
	{
		cols = 0;
		x = 0;
		while (general_p.map[lines][cols])
		{
			ft_pass_image(general_p.map[lines][cols], general_p, x, y);
			x = x + 80;
			cols++;
		}
		lines++;
		y = y + 80;
	}
}
