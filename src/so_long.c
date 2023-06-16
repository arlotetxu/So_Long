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

/*
 * ---- STATUS ----
 *
 * -- HECHO --
 *
 * 		# Creada la ventana. OJO, Hay que dimensionarla a los pixeles necesarios segun los pixeles de la imagen a
 * 			representar y el numero de veces que mostramos esa imagen
 * 		# Creada funcion para hacer los frees de array bidimensionales
 * 			sl_exit.c -> void	ft_exiting(char **str)
 * 		# Creada funcion para imprimir "Error" en caso de error
 * 			sl_exit.c -> void	ft_error_exit(void)
 * 		# El mapa ("maps/map_0.ber") se carga en un char **
 * 			sl_utils.c -> char	**ft_map_2_array(char *map_route)
 * 		# Creada funcion para conocer las filas y columnas de un mapa (devuelve desde 1)
 * 			sl_utils.c -> t_coord	ft_map_size(char **map)
 * 		# Comprobamos si el mapa dado es un rectangulo
 * 			sl_checks_util.c -> int	ft_check_maps_rectangle(char **map)
 * 		#Comprobamos si el mapa dado esta cerrado
 * 			sl_checks_util.c -> int	ft_check_map_leaks(char **map)
 * 		# Creada funcion para comprobar la cantidad de elementos std
 * 			sl_checks_util.c -> int	ft_check_std_elements(char **map)
 * 		# Creada funcion para comprobar si hay caracteres no permitidos
 * 			sl_checks_util.c -> int	ft_check_nostd_elements(char **map)
 * 		# Creada funcion para comprobar si el mapa es resolube
 * 			sl_checks_util_2.c -> int	ft_check_map_valid(char **map, t_coord size)
 * 		# Creada funcion para comprobar si la extension del mapa es .ber
 * 			sl_checks_util_2.c -> int	ft_check_map_ext(char *map_route)
 * 		# Creadas funciones para pintar el mapa
 * 			sl_place_textures.c -> void	ft_pass_char(char **map, t_gen_p
 general_p)
 * 			sl_place_textures.c -> void	ft_pass_image(char map_char, t_gen_p
 general_p, int x, int y)
 * 			sl_place_textures.c -> void	ft_place_texture(t_gen_p
 general_p, char *texture, int x, int y)
 *		# Creadas las funciones para hacer los movimientos
 *			so_long.c -> mlx_hook(general_p.win_ptr, 2, 1L << 0, ft_input_key, &general_p)
 *			sl_movements.c -> void	ft_do_mov(t_coord prev_coord, t_coord next_coord, t_gen_p general)
 *			sl_movements.c -> int	ft_check_map_value(t_coord prev_coord, t_coord next_coord, t_gen_p general)
 *			sl_movements.c -> int	ft_check_mov(int key_num, t_gen_p general)
 *			sl_movements.c -> int	ft_input_key(int key_num, t_gen_p *general)
 *		# Creada llamada a evento a close cuando se clicka en la x de la ventana
 *		# Integrado el programa ft_printf para realizar las impresiones de texto en pantalla
 *		# Cabeceras añadidas
 *
 *
 *
 * -- PROXIMO --
 *
 *		# Comprobar que los ficheros xmp para poner las texturas no estan corruptosbeceras
 *		# Comprobar el leak que se produce con el fsanitize
 *		# norminette
 */

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