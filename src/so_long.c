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
 * 		representar y el numero de veces que mostramos esa imagen
 *
 * 		# El mapa ("maps/map_0.ber") se carga en un char **
 *
 *
 * -- PROXIMO --
 *
 *		# Comenzar con los chequeos (ver notion)
 *			- Es rectangular? Numero de columnas > numero de filas
 *			- Tiene algun caracter que no debe o duplicados inicio(P) o salida(E)?
 *			- Tiene solucion (FloodFill)
 *			- Esta cerrado? Su perimetro son 1?
 *
 */

int main(void)
{
	void *mlx_ptr;
	void *mlx_win;
	t_image	img;
	char	**test;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, width, height, "JMF NEW WINDOW");

//	while (_x < _y)
//	{
//		my_mlx_pixel_put(&img, _x, 4, 0x00FF0000);
//		my_mlx_pixel_put(&img, 4, _x, 0x00FF0000);
//		_x++;
//	}
//	_x = 4;
//	while (_y > _x)
//	{
//		my_mlx_pixel_put(&img, 150, _y, 0x00FF0000);
//		my_mlx_pixel_put(&img, _y, 150, 0x00FF0000);
//		_y--;
//	}
//	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);

	img.img = mlx_xpm_file_to_image(mlx_ptr, "textures/grass_redim.xpm", &img.width_im, &img.height_im);
	if (!img.img)
		printf ("Fallando\n");
	printf("Imagen width: %d\n", img.width_im);
	printf("Imagen height: %d\n", img.height_im);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0,0);
	test = ft_map_2_array();
	mlx_loop(mlx_ptr);
	//free(mlx_ptr);

}

//Para chequear fugas de memoria
//system("leaks __nombre programa__");