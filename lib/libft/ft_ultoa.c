/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:00:08 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 18:02:29 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		get_length(unsigned long long nbr)
{
	int		ret;

	ret = 0;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		++ret;
	}
	return (ret + 1);
}

char			*ft_ultoa(unsigned long long nbr)
{
	char		*str;
	int			i;

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
