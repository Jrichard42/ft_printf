/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 21:49:21 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/14 20:15:24 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		get_length(long long nbr)
{
	int		ret;

	ret = 0;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		++ret;
	}
	if (nbr < 0)
		return (ret + 2);
	else
		return (ret + 1);
}

char			*ft_ltoa(long long nbr)
{
	char		*str;
	int			i;

	i = get_length(nbr);
	if ((str = (char *)malloc((i + 1) * sizeof(*str))))
	{
		str[i--] = '\0';
		while (nbr / 10)
		{
			if (nbr < 0)
				str[i] = -(nbr % 10) + 48;
			else
				str[i] = (nbr % 10) + 48;
			nbr = nbr / 10;
			--i;
		}
		if (nbr < 0)
		{
			nbr = -nbr;
			str[0] = '-';
		}
		str[i] = nbr % 10 + 48;
		return (str);
	}
	return (NULL);
}
