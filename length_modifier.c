/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 18:46:43 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 18:33:16 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "length_modifier.h"
#include "libft.h"
#include "ft_printf.h"

void					length_h(t_printf *env, const char *restrict s)
{
	if (s[env->i + 1] == 'h' && env->format.length_modifier < HH)
	{
		env->format.length_modifier = HH;
		++env->i;
	}
	else if (env->format.length_modifier < H)
		env->format.length_modifier = H;
}

void					length_l(t_printf *env, const char *restrict s)
{
	if (s[env->i + 1] == 'l' && env->format.length_modifier < LL)
	{
		env->format.length_modifier = LL;
		++env->i;
	}
	else if (env->format.length_modifier < L)
		env->format.length_modifier = L;
}

void					length_j(t_printf *env, const char *restrict s)
{
	(void)s;
	if (env->format.length_modifier < J)
		env->format.length_modifier = J;
}

void					length_z(t_printf *env, const char *restrict s)
{
	(void)s;
	if (env->format.length_modifier < Z)
		env->format.length_modifier = Z;
}
