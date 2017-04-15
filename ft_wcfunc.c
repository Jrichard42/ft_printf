/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 01:49:32 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/16 01:53:02 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int					ft_wclen(wchar_t c)
{
	int				nb_byte;
	unsigned char	last;
	unsigned char	first_byte;

	first_byte = 0;
	nb_byte = 0;
	last = 0;
	while (c != 0)
	{
		last = 128 | (c & 0x3f);
		c = c >> 6;
		first_byte = (first_byte >> 1) + 128;
		++nb_byte;
	}
	if ((last & first_byte) != 128)
		++nb_byte;
	return (nb_byte);
}

int					ft_wcslen(wchar_t *s)
{
	int ret;

	ret = 0;
	while (*s)
	{
		ret += ft_wclen(*s);
		++s;
	}
	return (ret);
}
