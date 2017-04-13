/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:07:26 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 18:06:24 by jrichard         ###   ########.fr       */
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
	if ((*s)[0] == '-')
	{
		*sign = '-';
		++(*s);
	}
	else if (env->format.signing == 1)
		*sign = ' ';
	else if (env->format.signing == 2)
		*sign = '+';
	*size_nb = ft_strlen(*s);
	if (env->format.precision != -1 && env->format.precision > *size_nb)
		*size_nb = env->format.precision;
	if (*sign == '-' || *sign == '+' || *sign == ' ')
		++(*size_nb);
}

static char	*get_nb(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier == HH)
		return (ft_itoa((signed char)va_arg(*ap, int)));
	if (env->format.length_modifier == H)
		return (ft_itoa((short)va_arg(*ap, int)));
	if (env->format.length_modifier == L)
		return (ft_ltoa(va_arg(*ap, long)));
	if (env->format.length_modifier == LL)
		return (ft_ltoa(va_arg(*ap, long long)));
	if (env->format.length_modifier == J)
		return (ft_ltoa(va_arg(*ap, long long)));
	if (env->format.length_modifier == Z)
		return (ft_uitoa(va_arg(*ap, size_t)));
	return (ft_itoa(va_arg(*ap, int)));
}

static void	print_padding(t_printf *env, char *s, char sign, int size_nb)
{
	if (env->format.padding != 2 && env->format.padding != 1)
		padding(env, env->format.min_field - size_nb, 0);
	if (sign == '-' || sign == '+' || sign == ' ')
	{
		copy_to_buff(env, &sign, 1);
		if (env->format.padding == 1)
			padding(env, env->format.min_field - size_nb, 0);
		padding_precision(env, size_nb - 1 - ft_strlen(s));
	}
	else
	{
		if (env->format.padding == 1)
			padding(env, env->format.min_field - size_nb, 0);
		padding_precision(env, size_nb - ft_strlen(s));
	}
}

void		convert_d_i(t_printf *env, va_list *ap)
{
	char	*s;
	char	sign;
	int		size_nb;

	sign = 0;
	s = get_nb(env, ap);
	get_size_nb(env, &s, &size_nb, &sign);
	if (env->format.precision != -1 && env->format.padding == 1)
		env->format.padding = 0;
	print_padding(env, s, sign, size_nb);
	copy_to_buff(env, s, ft_strlen(s));
	padding(env, env->format.min_field - size_nb, 0);
	if (sign == '-' || sign == '0')
		--s;
	ft_strdel(&s);
}
