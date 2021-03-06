/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:19:39 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/29 17:21:09 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "conversion.h"
#include "length_modifier.h"
#include "libft.h"

static const t_ptr_flag		g_ptr_flag[6] = {{'#', &alternate_flag},
	{'0', padding1_flag},
	{'-', padding2_flag},
	{' ', signing1_flag},
	{'+', signing2_flag},
	{0, NULL}
};

static const t_ptr_convert	g_ptr_convert[17] = {{'%', &convert_percent},
	{'s', &convert_s},
	{'S', &convert_s2},
	{'d', &convert_d_i},
	{'D', &convert_d2},
	{'i', &convert_d_i},
	{'c', &convert_c},
	{'C', &convert_c2},
	{'u', &convert_u},
	{'U', &convert_u2},
	{'x', &convert_x},
	{'X', &convert_x2},
	{'o', &convert_o},
	{'O', &convert_o2},
	{'p', &convert_p},
	{'b', &convert_b},
	{0, NULL}
};

static const t_ptr_length	g_ptr_length[6] = {{'h', &length_h},
	{'l', &length_l},
	{'j', &length_j},
	{'z', &length_z},
	{0, NULL}
};

int						check_flags(t_printf *env, const char *restrict s)
{
	int					i2;

	i2 = 0;
	while (g_ptr_flag[i2].flag)
	{
		if (s[env->i] == g_ptr_flag[i2].type)
		{
			g_ptr_flag[i2].flag(env);
			return (1);
		}
		++i2;
	}
	return (0);
}

void					check_min_field(t_printf *env, const char *restrict s)
{
	env->format.min_field = ft_atoi(s + env->i);
	while (s && ft_isdigit(s[env->i]))
		++env->i;
	--env->i;
}

void					check_precision(t_printf *env, const char *restrict s)
{
	++env->i;
	if (ft_isdigit(s[env->i]))
	{
		env->format.precision = ft_atoi(s + env->i);
		while (s && ft_isdigit(s[env->i]))
			++env->i;
	}
	else
		env->format.precision = 0;
	--env->i;
}

int						check_conversion(t_printf *env,
		const char *restrict s, va_list *ap)
{
	int					i2;

	i2 = 0;
	while (g_ptr_convert[i2].convert)
	{
		if (s[env->i] == g_ptr_convert[i2].c)
		{
			if (!g_ptr_convert[i2].convert(env, ap))
				return (0);
			break ;
		}
		++i2;
	}
	if (!g_ptr_convert[i2].convert)
		convert_no(env, s);
	return (1);
}

int						check_length_modifier(t_printf *env,
		const char *restrict s)
{
	int					i2;

	i2 = 0;
	while (g_ptr_length[i2].length)
	{
		if (s[env->i] == g_ptr_length[i2].c)
		{
			g_ptr_length[i2].length(env, s);
			return (1);
		}
		++i2;
	}
	return (0);
}
