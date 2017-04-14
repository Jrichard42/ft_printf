/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:08 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/14 19:10:47 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "conversion.h"
#include "libft.h"
#include "ft_printf.h"

void		padding(t_printf *env, int size, char overwrite)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (env->format.padding == 1)
		c = '0';
	if (overwrite)
		c = overwrite;
	while (i < size)
	{
		copy_to_buff(env, &c, 1);
		++i;
	}
	env->format.min_field = 0;
}

void			copy_to_buff(t_printf *env, const char *s, int size)
{
	while (size)
	{
		if (size >= PRINTF_BUFF - env->i_buff)
		{
			ft_strncpy(env->buff + env->i_buff, s, PRINTF_BUFF - env->i_buff - 1);
			size -= PRINTF_BUFF - env->i_buff - 1;
			env->ret += PRINTF_BUFF - env->i_buff - 1;
			write(1, env->buff, PRINTF_BUFF);
			ft_bzero(&env->buff, PRINTF_BUFF);
			env->i_buff = 0;
		}
		else
		{
			ft_strncpy(env->buff + env->i_buff, s, size);
			env->ret += size;
			env->i_buff += size;
			size = 0;
		}
	}
}

void			reset_format(t_format *format)
{
	ft_memset(format, 0, sizeof(*format));
	format->precision = -1;
	format->length_modifier = NONE;
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
		if (format[env.i])
			++env.i;
	}
	va_end(ap);
	write(1, env.buff, env.i_buff);
	return (env.ret);
}
