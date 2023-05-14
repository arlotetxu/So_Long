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
 * 		# El mapa ("maps/map_0.ber") se carga en un char **
 * 			sl_checks_util.c -> char	**ft_map_2_array(char *map_route)
 * 		# Comprobamos si el mapa dado es un triangulo
 * 			sl_checks_util.c -> int	ft_check_maps_rectangle(char **map)
 * 		# Creada funcion para hacer los frees de array bidimensionales
 * 			sl_exit.c -> void	ft_exiting(char **str)
 *
 *
 * -- PROXIMO --
 *
 *		# Comenzar con los chequeos (ver notion)
 *			- Es rectangular? Numero de columnas > numero de filas --> HECHO.
 *			- Tiene algun caracter que no debe o duplicados inicio(P) o salida(E)?
 *			- Tiene solucion (FloodFill)
 *			- Esta cerrado? Su perimetro son 1?
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
	mlx_win = mlx_new_window(mlx_ptr, width, height, "JMF NEW WINDOW");

	img.img = mlx_xpm_file_to_image(mlx_ptr, "textures/grass_redim.xpm", &img.width_im, &img.height_im);
	if (!img.img)
		printf ("Fallando\n");
	//IMPRIMO LOS VALORES DE WIDTH Y HEIGHT DE LA IMAGEN PUESTA
//	printf("Imagen width: %d\n", img.width_im);
//	printf("Imagen height: %d\n", img.height_im);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0,0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 80,0);
	//COMPRUEBO SI LA FUNCION ft_map_2_array se ejecuta correctamente
	//ft_map_2_array(argv[1]);
	//printf("Testando funcion ft_map_2_array: %s\n", test[0]);
	mlx_loop(mlx_ptr);
}

int main(int argc, char **argv)
{
	char	**map_array;

	if (argc == 2)
	{
		map_array = ft_map_2_array(argv[1]);
		//METER LOS CONDICIONALES PARA EJECUCION DE LOS CHEQUEOS
		if (ft_check_maps_rectangle(map_array) == 0)
		{
			ft_exiting(map_array);
			return (0);
		}
		ft_so_long();
	}
	//free(mlx_ptr);
	return (0);
}

//Para chequear fugas de memoria
//system("leaks __nombre programa__");