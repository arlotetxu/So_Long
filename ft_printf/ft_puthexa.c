/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:27:40 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/22 11:09:50 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long int nbr)
{
	int	len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void	ft_print_hexa(unsigned long int nbr, char m)
{
	char	*ref_u;
	char	*ref_l;

	ref_u = (char [16]){'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	ref_l = (char [16]){'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	if (nbr < 16)
	{
		if (m == 'x')
			write(1, &ref_l[nbr], 1);
		else if (m == 'X')
			write(1, &ref_u[nbr], 1);
	}
	if (nbr >= 16)
	{
		ft_print_hexa(nbr / 16, m);
		ft_print_hexa(nbr % 16, m);
	}
}

int	ft_puthexa(unsigned long int nbr, char m)
{
	ft_print_hexa(nbr, m);
	return (ft_hex_len(nbr));
}

/*int main(void)
{
	ft_puthexa(1254, 'x');
}*/