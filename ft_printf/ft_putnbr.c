/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:50:16 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/22 11:36:55 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(int nbr)
{
	int	len;
	int	aux;

	len = 0;
	aux = nbr;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	if (aux > 0)
		return (len);
	else
		return (len + 1);
}

int	ft_putnbr(int nbr)
{
	int	aux;

	aux = nbr;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (ft_nbr_len(aux));
}

/*int	main(void)
{
	int nb;

	nb = -200000;
	ft_putnbr(nb);
	printf("\nValor de len: %d\n", ft_nbr_len(nb));
}*/
