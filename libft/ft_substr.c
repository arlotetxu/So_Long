/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:23:38 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/22 14:56:32 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_substr ---> Creates a substring of 'len' bytes starting 
  				 in the 'start'.

  SYNOPSIS
  ***********
  char	*ft_substr(char const *s, unsigned int start, size_t len)

  DESCRIPTION
  ***********
  The ft_substr creates a substring starting from the start value
  parameter and with the total size of 'len' parameter.
  
  PARAMETERS
  **********
  *s ---> String to modify.
  start ---> The initial byte to start the substring
  len ---> maximum size of the resultant string

  RETURN VALUE
  ************
  - The function returns a pointer to the new string (malloc).
  
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
