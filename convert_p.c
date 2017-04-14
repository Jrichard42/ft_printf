/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:48:33 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/14 21:28:54 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

static void	padding_precision(t_printf *env, int size)
{
	int		i;
	char	c;

	i = 0;
	c = '0';
	while (i < size)
	{
		copy_to_buff(env, &c, 1);
		++i;
	}
}

static void	get_size_nb(t_printf *env, char **s, int *size_nb, char *sign)
{
	if ((*s)[0] == '0' && env->format.precision == 0)
	{
		*sign = '0';
		++(*s);
	}
	*size_nb = ft_strlen(*s);
	if (env->format.precision != -1 && env->format.precision > *size_nb)
		*size_nb = env->format.precision;
	*size_nb += 2;
}

static char *get_nb(t_printf *env, va_list *ap)
{
	return (ft_ltoa_base((unsigned long long)va_arg(*ap, void *), 16, 0));
}

void		convert_p(t_printf *env, va_list *ap)
{
	char	*s;
	char	sign;
	int		size_nb;

	sign = 0;
	s = get_nb(env, ap);
	get_size_nb(env, &s, &size_nb, &sign);
	if (env->format.padding != 0)
		copy_to_buff(env, "0x", 2);	
	if (env->format.padding != 2)
		padding(env, env->format.min_field - size_nb, 0);
	if (env->format.padding == 0)
		copy_to_buff(env, "0x", 2);
	size_nb -= 2;
	padding_precision(env, size_nb - ft_strlen(s));
	size_nb += 2;
	copy_to_buff(env, s, ft_strlen(s));
	padding(env, env->format.min_field - size_nb, 0);
	if (sign == '0')
		--s;
	ft_strdel(&s);
}
