/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:08 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/08 14:41:46 by jrichard         ###   ########.fr       */
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
		env->ret += ft_strlen(env->buff);
		ft_bzero(&env->buff, PRINTF_BUFF);
		env->i_buff = 0;
	}
	ft_strncpy(env->buff + env->i_buff, s, size);
	env->i_buff += size;
}

void			reset_format(t_format *format)
{
	ft_memset(format, 0, sizeof(*format));
	format->precision = -1;
}

void			init_env(t_printf *env)
{
	reset_format(&(env->format));
	ft_bzero(&(env->buff), PRINTF_BUFF);
	env->i = 0;
	env->i_buff = 0;
	env->ret = 0;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_printf	env;

	init_env(&env);
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
