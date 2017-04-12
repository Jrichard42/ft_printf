/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_DOU.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:05:48 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/12 04:38:35 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

void		convert_D(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier < L)
		env->format.length_modifier = L;
	convert_d_i(env, ap);
}

void		convert_U(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier < L)
		env->format.length_modifier = L;
	convert_u(env, ap);
}

void		convert_O(t_printf *env, va_list *ap)
{
	if (env->format.length_modifier < L)
		env->format.length_modifier = L;
	convert_o(env, ap);
}
