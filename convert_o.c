/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 04:28:13 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 20:48:23 by jrichard         ###   ########.fr       */
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
	if (env->format.alternate == 1 &&
			(*size_nb < (int)(ft_strlen(*s) + 1)) && (*s)[0] != '0')
		++(*size_nb);
}

static char	*get_nb(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier == HH)
		return (ft_itoa_base((unsigned char)va_arg(*ap, unsigned int), 8, 0));
	if (env->format.length_modifier == H)
		return (ft_itoa_base((unsigned short)va_arg(*ap, unsigned int), 8, 0));
	if (env->format.length_modifier == L)
		return (ft_ltoa_base(va_arg(*ap, unsigned long), 8, 0));
	if (env->format.length_modifier == LL)
		return (ft_ltoa_base(va_arg(*ap, unsigned long long), 8, 0));
	if (env->format.length_modifier == J)
		return (ft_ltoa_base(va_arg(*ap, unsigned long long), 8, 0));
	if (env->format.length_modifier == Z)
		return (ft_ltoa_base(va_arg(*ap, size_t), 8, 0));
	return (ft_itoa_base(va_arg(*ap, unsigned int), 8, 0));
}

int			convert_o(t_printf *env, va_list *ap)
{
	char	*s;
	char	sign;
	int		size_nb;

	sign = 0;
	s = get_nb(env, ap);
	get_size_nb(env, &s, &size_nb, &sign);
	if (env->format.precision != -1 && env->format.padding == 1)
		env->format.padding = 0;
	if (env->format.padding != 2)
		padding(env, env->format.min_field - size_nb, 0);
	padding_precision(env, size_nb - ft_strlen(s));
	copy_to_buff(env, s, ft_strlen(s));
	padding(env, env->format.min_field - size_nb, 0);
	if (sign == '0')
		--s;
	ft_strdel(&s);
	return (1);
}
