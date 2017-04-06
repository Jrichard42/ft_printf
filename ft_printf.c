/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:08 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/04 11:35:33 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "flags.h"
#include "conversion.h"
#include "libft.h"
#include "ft_printf.h"

static t_ptr_flag		g_ptr_flag[6] = {{'#', &alternate_flag},
	{'0', padding1_flag},
	{'-', padding2_flag},
	{' ', signing1_flag},
	{'+', signing2_flag},
	{0, NULL}
};

static t_ptr_convert	g_ptr_convert[3] = {{'%', &convert_percent},
	{'s', &convert_s},
	{0, NULL}
};

static int				init_flags(t_printf *env, const char *restrict s)
{
	int					i2;

	i2 = 0;
	while (g_ptr_flag[i2].flag)
	{
		if (s[env->i] == g_ptr_flag[i2].type)
		{
			g_ptr_flag[i2].flag(env);
			break ;
		}
		++i2;
	}	
	if (!g_ptr_flag[i2].flag)
		return (-1);
	return (1);
}

static void				init_min_field(t_printf *env, const char *restrict s)
{
	env->min_field = ft_atoi(s + env->i);
	while (s && ft_isdigit(s[env->i]))
		++env->i;
}

static void				init_precision(t_printf *env, const char *restrict s)
{
	++env->i;
	if (ft_isdigit(s[env->i]))
	{
		env->precision = ft_atoi(s + env->i);
		while (s && ft_isdigit(s[env->i]))
			++env->i;
	}
}

static int				parse_format(t_printf *env, const char *restrict s, va_list *ap)
{
	int					i2;
	int					ret;

	i2 = 0;
	ret = 0;
	while (s[env.i])
	{
		ret = init_flags(env, s);
		if (ft_isdigit(s[env->i]))
			init_min_field(env, s);
		if (s[env->i] == '.')
			init_precision(env, s);
	}

	++env->i;
	init_flags(env, s);
	if (ft_isdigit(s[env->i]))
		init_min_field(env, s);
	if (s[env->i] == '.')
		init_precision(env, s);
	while (g_ptr_convert[i2].convert)
	{
		if (s[env->i] == g_ptr_convert[i2].c)
		{
			g_ptr_convert[i2].convert(env, ap);
			break ;
		}
		++i2;
	}
	if (!g_ptr_convert[i2].convert)
		convert_no(env, s);
	//reset env;
}

int						ft_printf(const char *restrict format, ...)
{
	va_list				ap;
	t_printf			env;

	ft_bzero(&env, sizeof(env));
	va_start(ap, format);
	while (format[env.i])
	{
		if (format[env.i] == '%')
			parse_format(&env, format, &ap);
		else
		{
			ft_putchar(format[env.i]);
			++env.ret;
		}
		++env.i;
	}
	va_end(ap);
	return (env.ret);
}
