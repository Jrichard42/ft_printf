/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:07:26 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 20:18:59 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

static int	fill_sign(t_printf *env, char *s, int *len)
{
	if (s[0] == '-')
	{
		copy_to_buff(env, "-", 1);
		return (1);
	}
	else if (env->format.signing != 0)
	{
		if (env->format.signing == 1)
			copy_to_buff(env, " ", 1);
		else
			copy_to_buff(env, "+", 1);
		++(*len);
		return (2);
	}
}

void		convert_d_i(t_printf *env, va_list *ap)
{
	int		nb;
	char	*s;
	int		len;
	int		sign;

	sign = 0;
	nb = va_arg(*ap, int);
	if (!(s = ft_itoa(nb)))
		return ;
	len = ft_strlen(s);
	sign = fill_sign(env, s, &len);

	if (env->format.precision != -1 && env->format.precision > len)
		len = env->format.precision;
	if (env->format.padding != 2)
		padding(env, env->format.min_field - len, 0);
	if (sign == 1)
		copy_to_buff(env, s + 1, len - 1);
	else if (sign == 2)
		copy_to_buff(env, s, len - 1);
	else
		copy_to_buff(env, s, len);
	padding(env, env->format.min_field - len, 0);
	ft_strdel(&s);
}
