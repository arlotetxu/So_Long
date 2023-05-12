//
// Created by Jose Manuel Florido Pereña on 1/4/23.
//

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../Get_Next_line/get_next_line.h"


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	width_im;
	int 	height_im;
}				t_image;
//put your functions here
//CHECKS
char	**ft_map_2_array(void);

#endif //SO_LONG_H