/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 22:50:51 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/16 16:08:04 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "conversion.h"

static void			put_wchar(t_printf *env, wchar_t c)
{
	unsigned char	tab[16];
	int				i;
	int				mask;
	unsigned char	first_byte;

	mask = 0x3f;
	first_byte = 0;
	i = 0;
	while (c != 0)
	{
		tab[i] = 128 | (c & mask);
		c = c >> 6;
		first_byte = (first_byte >> 1) + 128;
		++i;
	}
	--i;
	if ((tab[i] & first_byte) == 128)
		tab[i] |= first_byte;
	else
		tab[++i] = first_byte;
	while (i >= 0)
		copy_to_buff(env, (char *)&(tab[i--]), 1);
}

int					convert_c2(t_printf *env, va_list *ap)
{
	wchar_t			c;
	wchar_t			tmp;
	int				size_nb;

	c = va_arg(*ap, wchar_t);
	size_nb = 0;
	tmp = c;
	while (tmp)
	{
		tmp = tmp >> 1;
		++size_nb;
	}
	if (size_nb > MB_CUR_MAX * 8)
		return (0);
	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1, 0);
	if (size_nb <= 7 || MB_CUR_MAX == 1)
		copy_to_buff(env, (char *)&c, 1);
	else
		put_wchar(env, c);
	padding(env, env->format.min_field - 1, 0);
	return (1);
}
