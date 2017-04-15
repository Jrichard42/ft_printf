/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dou2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:05:48 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 20:47:29 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

int			convert_d2(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier < L)
		env->format.length_modifier = L;
	convert_d_i(env, ap);
	return (1);
}

int			convert_u2(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier < L)
		env->format.length_modifier = L;
	convert_u(env, ap);
	return (1);
}

int			convert_o2(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier < L)
		env->format.length_modifier = L;
	convert_o(env, ap);
	return (1);
}
