//
// Created by Jose Manuel Florido Pereña on 14/5/23.
//
#include "../inc/so_long.h"

/*
 * #FT_EXITING
 * 		Frees the 2 dim arrays created
 *
 * #PARAMETER
 * 		- char **str --> array to make the free process.
 *
 * #RETURN
 */
void	ft_exiting(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

/*
 * #FT_CLOSE
 * 		Frees the 2 dim arrays created and destroy the window
 *
 * #PARAMETER
 * 		- char **map --> array to make the free process. The map converted to a char **
 * 		- t_gen_p --> All the pointers needed to run the mlx program
 *
 * #RETURN
 * 		- 0
 */
int	ft_close(t_gen_p *general)
{
	ft_exiting(general->map);
	mlx_destroy_window(general->mlx_ptr, general->win_ptr);
	free(general->mlx_ptr);
	exit (0);
}
