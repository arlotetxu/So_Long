//Header

#include "../inc/so_long.h"

# define width 800
# define height 600

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void) {
	void *mlx_ptr;
	void *mlx_win;
	t_image	img;
	int 	_x = 4;
	int 	_y = 150;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, width, height, "JMF NEW WINDOW");
	img.img = mlx_new_image(mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								  &img.line_length, &img.endian);
	while (_x < _y)
	{
		my_mlx_pixel_put(&img, _x, 4, 0x00FF0000);
		my_mlx_pixel_put(&img, 4, _x, 0x00FF0000);
		_x++;
	}
	_x = 4;
	while (_y > _x)
	{
		my_mlx_pixel_put(&img, 150, _y, 0x00FF0000);
		my_mlx_pixel_put(&img, _y, 150, 0x00FF0000);
		_y--;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	//free(mlx_ptr);
}