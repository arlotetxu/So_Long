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
		free(str[i++]);
	free(str[i]);
	free(str);
	//printf("Exit (free) completado!!\n");
}
