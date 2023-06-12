/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:38:36 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/31 13:25:11 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Deberás implementar las siguientes conversiones: cspdiuxX % */

/* The len variable is passed as argument because the prinf function
 * return the total length of the string it prints, so you should consider
 * not only the variable values but also the string before the values:
 * a = "Hello";
 * printf("This is a test %s", a);
 * the value printf returns is:
 * "This is a test " (15 characters)
 * "Hello" (5 characters)
 * Total length = 15 + 5 = 20
 *
Format Specifier	                    Type
%c	                                    Character
%d		                                Signed integer
%e or %E	                            Scientific notation of floats
%f	                                    Float values
%g or %G	                            Similar as %e or %E
%hi	                                    Signed integer (short)
%hu	                                    Unsigned Integer (short)
%i	                                    Unsigned integer
%l or %ld or %li	                    Long
%lf	                                    Double
%Lf	                                    Long double
%lu	                                    Unsigned int or unsigned long
%lli or %lld	                        Long long
%llu	                                Unsigned long long
%o	                                    Octal representation
%p	                                    Pointer
%s	                                    String
%u	                                    Unsigned int
%x or %X	                            Hexadecimal representation
%n	                                    Prints nothing
%%	                                    Prints % character
 */

int	ft_check_id(va_list ap, char id)
{
	int	len_;

	len_ = 0;
	if (id == 'c')
		len_ = ft_putchar(va_arg(ap, int));
	else if (id == 's')
		len_ = ft_putstr(va_arg(ap, char *));
	else if (id == 'p')
		len_ = ft_putstr("0x") + ft_puthexa(va_arg(ap, unsigned long int), 'x');
	else if (id == 'd' || id == 'i')
		len_ = ft_putnbr(va_arg(ap, int));
	else if (id == 'u')
		len_ = ft_putnbr_u(va_arg(ap, unsigned int));
	else if (id == 'x' || id == 'X')
		len_ = ft_puthexa(va_arg(ap, unsigned int), id);
	else if (id == '%')
		len_ = ft_putchar('%');
	return (len_);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len = len + ft_check_id(ap, str[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

/*int	main(void)
{
	int	*a;
	int	b;

	a = 0;
	b = ft_printf("%d", -10);
	printf("%d", b);
	ft_printf("CHAR Created: %c more\n", 'c');
	printf("CHAR Original: %c more\n\n", 'c');
	ft_printf("STRING Created: %s more\n", "This is a string");
	printf("STRING Original: %s more\n\n", "This is a string");
	ft_printf("POINTER Created: %p more\n", a);
	printf("POINTER Original: %p more\n\n", NULL);
	ft_printf("POINTER Created: %x more\n", (unsigned int)a);
	printf("POINTER Original: %x more\n\n", (unsigned int)a);
	ft_printf("NUMBER Created: %d more\n", 1234);
	printf("NUMBER Original: %d more\n\n", 1234);
	ft_printf("NUMBER(i) Created: %i more\n", 4321);
	printf("NUMBER(i) Original: %i more\n\n", 4321);
	ft_printf("NUMBER(u) Created: %u more\n", 120453652);
	printf("NUMBER(u) Original: %d more\n\n", 120453652);
	ft_printf("HEXA LOWER Created: %x more\n", -1);
	printf("HEXA LOWER Original: %x more\n\n", -1);
	ft_printf("HEXA UPPER Created: %X more\n", 52145874);
	printf("HEXA UPPER Original: %X more\n\n", 52145874);
	ft_printf("PERCENTAGE Created: %% more\n");
	printf("PERCENTAGE Original: %% more\n\n");
	return (0);
}*/
