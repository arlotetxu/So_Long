//
// Created by Jose Manuel Florido Pereña on 1/4/23.
//

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;
//put your functions here
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

#endif //SO_LONG_H