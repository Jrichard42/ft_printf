/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:59:19 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 20:44:27 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*create_basetab(int base, char notation)
{
	char			*basetab;
	int				i;
	char			c;

	i = 0;
	c = '0';
	if (!(basetab = ft_memalloc((base + 1) * sizeof(*basetab))))
		return (NULL);
	while (i < base)
	{
		basetab[i++] = c++;
		if (c == '9' + 1)
		{
			if (notation == 0)
				c = 'a';
			else
				c = 'A';
		}
	}
	return (basetab);
}

static int			count_size(unsigned int nb, int base)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		++i;
	}
	return (i);
}

static void			convert_base(char *ret, char *basetab,
		unsigned int nb, int size_ret)
{
	int				base;

	base = ft_strlen(basetab);
	if (nb == 0)
	{
		ret[0] = '0';
		return ;
	}
	while (nb)
	{
		ret[size_ret] = basetab[nb % base];
		--size_ret;
		nb /= base;
	}
}

char				*ft_itoa_base(int nb, int base, char notation)
{
	char			*basetab;
	int				size_ret;
	char			*ret;
	unsigned int	nb2;

	size_ret = 0;
	if (base == 10)
		return (ft_itoa(nb));
	else if (base > 1 && base < 36)
	{
		nb2 = (unsigned int)nb;
		if (!(basetab = create_basetab(base, notation)))
			return (NULL);
		size_ret += count_size(nb2, base);
		if (!(ret = ft_memalloc((size_ret + 1) * sizeof(*ret))))
			return (NULL);
		convert_base(ret, basetab, nb2, size_ret - 1);
		ft_strdel(&basetab);
		return (ret);
	}
	return (NULL);
}
