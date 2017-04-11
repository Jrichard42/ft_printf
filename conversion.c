/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:22:37 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/11 17:07:41 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

void		convert_no(t_printf *env, const char *restrict s)
{
	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1, 0);
	copy_to_buff(env, &(s[env->i]), 1);
	padding(env, env->format.min_field - 1, 0);
}

void		convert_percent(t_printf *env, va_list *ap)
{
	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1, 0);
	copy_to_buff(env, "%", 1);
	padding(env, env->format.min_field - 1, 0);
}
