/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:50:16 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/22 11:42:43 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_u_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int nbr)
{
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10);
		ft_putnbr_u(nbr % 10);
	}
	return (ft_nbr_u_len(nbr));
}

/*int	main(void)
{
	unsigned int nb;

	nb = 0;
	ft_putnbr_u(nb);
	printf("\nValor de len: %d\n", ft_nbr_u_len(nb));
}*/
