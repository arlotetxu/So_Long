//
// Created by Jose Manuel Florido Perena on 6/2/23.
//
#include "../inc/so_long.h"

//ft_make_movement. Cambiar a 0 la posicion anterior y a P la siguiente.
//ft_check_movement.

int	ft_input_key(int key_num, t_general_p *general)
{
	if (key_num == 53 || key_num == 123)
	{
		ft_close(general);
	}
	return (0);
}
