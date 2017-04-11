/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:10:15 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/11 20:26:43 by jrichard         ###   ########.fr       */
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
}

static char	*get_nb(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier == HH)
		return (ft_itoa((unsigned char)va_arg(*ap, unsigned int)));
	if (env->format.length_modifier == H)
		return (ft_itoa((unsigned short)va_arg(*ap, unsigned int)));
	if (env->format.length_modifier == L)
		return (ft_ltoa(va_arg(*ap, unsigned long)));
	if (env->format.length_modifier == LL)
		return (ft_ltoa(va_arg(*ap, unsigned long long)));
	if (env->format.length_modifier == J)
		    return (ft_ltoa(va_arg(*ap, unsigned long long)));
	if (env->format.length_modifier == Z)
		return (ft_ltoa(va_arg(*ap, size_t)));
	return (ft_itoa(va_arg(*ap, unsigned int)));
}

void		convert_u(t_printf *env, va_list *ap)
{
	char	*s;
	char	sign;
	int		size_nb;

	sign = 0;
	s = get_nb(env, ap);
	get_size_nb(env, &s, &size_nb, &sign);
	if (env->format.precision != -1)
		env->format.padding = 0;
	if (env->format.padding != 2 && env->format.padding != 1)
		padding(env, env->format.min_field - size_nb, 0);
	padding_precision(env, size_nb - ft_strlen(s));
	copy_to_buff(env, s, ft_strlen(s));
	padding(env, env->format.min_field - size_nb, 0);
	ft_strdel(&s);
}
