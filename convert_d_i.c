/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:07:26 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/08 15:49:33 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

static void	get_size_nb(t_printf *env, char **s, int *size_nb, char *sign)
{
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
	if (*sign)
		++(*size_nb);
}

static void	fill_sign(t_printf *env, char *s, int *len)
{
	if (s[0] == '-')
		copy_to_buff(env, "-", 1);
	else if (env->format.signing != 0)
	{
		if (env->format.signing == 1)
			copy_to_buff(env, " ", 1);
		else
			copy_to_buff(env, "+", 1);
	}
}

void		convert_d_i(t_printf *env, va_list *ap)
{
	int		nb;
	char	*s;
	char	sign;
	int		size_nb;

	nb = va_arg(*ap, int);
	sign = 0;
	if (!(s = ft_itoa(nb)))
		return ;
	get_size_nb(env, &s, &size_nb, &sign);
	if (env->format.padding != 2)
		padding(env, env->format.min_field - size_nb, 0);
	if (sign)
	{
		copy_to_buff(env, &sign, 1);
		padding(env, size_nb - 1 - ft_strlen(s), '0');
	}
	else
		padding(env, size_nb - ft_strlen(s), '0');
	copy_to_buff(env, s, ft_strlen(s));
	padding(env, env->format.min_field - size_nb, 0);
	if (sign == '-')
		--s;
	ft_strdel(&s);
}
