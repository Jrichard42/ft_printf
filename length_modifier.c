/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 18:46:43 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/09 18:54:24 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "length_modifier.h"
#include "libft.h"
#include "ft_printf.h"

void					length_h(t_printf *env, const char *restrict s)
{
	env->format.length_modifier = H;
	if (s[env->i + 1] == 'h')
	{
		env->format.length_modifier = HH;
		++env->i;
	}
}

void					length_l(t_printf *env, const char *restrict s)
{
	env->format.length_modifier = L;
	if (s[env->i + 1] == 'l')
	{
		env->format.length_modifier = LL;
		++env->i;
	}
}

void					length_j(t_printf *env, const char *restrict s)
{
	env->format.length_modifier = J;
}

void					length_z(t_printf *env, const char *restrict s)
{
	env->format.length_modifier = Z;
}
