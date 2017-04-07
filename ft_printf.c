/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:08 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 20:15:41 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "conversion.h"
#include "libft.h"
#include "ft_printf.h"

int				copy_to_buff(t_printf *env, const char *s, int size)
{
	if (env->i_buff + size >= PRINTF_BUFF - 1)
	{
		ft_putstr(env->buff);
		env->ret += ft_strlen(env->buff);
		ft_bzero(&env->buff, PRINTF_BUFF);
		env->i_buff = 0;
	}
	ft_strncpy(env->buff + env->i_buff, s, size);
	env->i_buff += size;
}

void			reset_env(t_printf *env)
{
	ft_bzero(&(env->format), sizeof(env->format));
	env->format.precision = -1;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_printf	env;

	reset_env(&env);
	va_start(ap, format);
	while (format[env.i])
	{
		if (format[env.i] == '%')
			parse_str(&env, format, &ap);
		else
			copy_to_buff(&env, &format[env.i], 1);
		++env.i;
	}
	va_end(ap);
	ft_putstr(env.buff);
	env.ret += ft_strlen(env.buff);
	return (env.ret);
}
