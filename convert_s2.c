/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:26:35 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/16 01:53:16 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libft.h"
#include "conversion.h"

/*int					get_real_precision(t_printf *env, wchar_t *s, int len)
{
	wchar_t			c;

	if (!s)
	{
		if (env->format.precision != -1 && env->format.precision < len)
			return (env->format.precision);
		else
			return (len);
	}
	else if (env->format.precision != -1 && env->format.precision < len)
	{
		while (*s)
		{
			c = *s;
		}
	}
}*/

static int			put_wchar(t_printf *env, wchar_t c, int len)
{
	unsigned char	tab[16];
	int				i;
	int				ret;
	unsigned char	first_byte;

	first_byte = 0;
	i = 0;
	while (c != 0)
	{
		tab[i] = 128 | (c & 0x3f);
		c = c >> 6;
		first_byte = (first_byte >> 1) + 128;
		++i;
	}
	--i;
	if ((tab[i] & first_byte) == 128)
		tab[i] |= first_byte;
	else
		tab[++i] = first_byte;
	ret = i;
	if (i > len && len != -1)
		return (0);
	while (i >= 0)
		copy_to_buff(env, (char *)&(tab[i--]), 1);
	return (ret + 1);
}

static int			check_char(wchar_t c)
{
	wchar_t			tmp;
	int				size_nb;

	size_nb = 0;
	tmp = c;
	while (tmp)
	{
		tmp = tmp >> 1;
		++size_nb;
	}
	if (size_nb > MB_CUR_MAX * 8)
		return (-1);
	if (size_nb <= 7 || MB_CUR_MAX == 1)
		return (0);
	else
		return (1);
}

static int			put_str_in_tab(t_printf *env, wchar_t *s, int len)
{
	int				i;
	int				ret;
	int				ret2;

	i = 0;
	while (s[i] != 0 && len)
	{
		ret = check_char(s[i]);
		if (ret == -1)
			return (-1);
		if (!ret)
		{
			copy_to_buff(env, (char *)&(s[i]), 1);
			--len;
		}
		else
		{
			ret2 = put_wchar(env, s[i], len);
			len -= ret2;
			if (ret2 == 0)
				return (0);
		}
		++i;
	}
	return (1);
}

int					convert_s2(t_printf *env, va_list *ap)
{
	wchar_t			*s;
	int				len;
	char			nulltab[7];

	ft_strcpy(nulltab, "(null)\0");
	s = va_arg(*ap, wchar_t *);
	if (s)
		len = ft_wcslen(s);
	else
		len = ft_strlen(nulltab);
	if (env->format.precision != -1 && env->format.precision < len)
		len = env->format.precision;
	if (env->format.padding != 2)
		padding(env, env->format.min_field - len, 0);
	if (s)
	{
		if (put_str_in_tab(env, s, len) == -1)
			return (-1);
	}
	else
		copy_to_buff(env, nulltab, len);
	padding(env, env->format.min_field - len, 0);
	return (1);
}
