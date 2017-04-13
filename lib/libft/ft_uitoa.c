/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:00 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 18:03:02 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_length(unsigned int nbr)
{
	int ret;

	ret = 0;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		++ret;
	}
	return (ret + 1);
}

char		*ft_uitoa(unsigned int nbr)
{
	char	*str;
	int		i;

	i = get_length(nbr);
	if ((str = (char *)malloc((i + 1) * sizeof(*str))))
	{
		str[i--] = '\0';
		while (nbr / 10)
		{
			str[i] = (nbr % 10) + 48;
			nbr = nbr / 10;
			--i;
		}
		str[i] = nbr % 10 + 48;
		return (str);
	}
	return (NULL);
}
