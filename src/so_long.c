//Header

#include "../inc/so_long.h"

# define width 800
# define height 600

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
 *
 *
 * -- PROXIMO --
 *
 *		# Comenzar con los chequeos (ver notion)
 *			- Comprobar si la extension del mapa es .ber
 *
 */

//void	ft_so_long(char **argv)
void	ft_so_long(void)
{
	void *mlx_ptr;
	void *mlx_win;
	t_image	img;
	//char	**test = NULL;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, width, height, "JMF NEW WINDOW"); //TODO Dimensionar la ventana acorde al numero de pixels a representar
	img.img = mlx_xpm_file_to_image(mlx_ptr, "textures/grass_redim.xpm", &img.width_im, &img.height_im);
	if (!img.img)
		printf ("Fallando\n");
	//IMPRIMO LOS VALORES DE WIDTH Y HEIGHT DE LA IMAGEN PUESTA
//	printf("Imagen width: %d\n", img.width_im);
//	printf("Imagen height: %d\n", img.height_im);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0,0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 80,0);
	mlx_loop(mlx_ptr);
}

int	main(int argc, char **argv)
{
	char	**map_array;
	int 	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror("Error.\nChecking file"), 0);
		map_array = ft_map_2_array(argv[1]);
//		//METER LOS CONDICIONALES PARA EJECUCION DE LOS CHEQUEOS
		if (ft_check_map_ext(argv[1]) == 0
			|| ft_check_maps_rectangle(map_array) == 0
			|| ft_check_map_leaks(map_array) == 0
			|| ft_check_nostd_elements(map_array) == 0
			|| ft_check_std_elements(map_array) == 0
			|| ft_check_map_valid(map_array, ft_map_size(map_array)) == 0)
		{
			ft_exiting(map_array);
			return (0);
		}
		ft_so_long();
	}
	//ft_exiting(map_array);
	//free(mlx_ptr);
	return (0);
}

//Para chequear fugas de memoria
//system("leaks __nombre programa__");