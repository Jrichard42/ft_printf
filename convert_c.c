/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:16:00 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 20:38:47 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

int			convert_c(t_printf *env, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1, 0);
	copy_to_buff(env, &c, 1);
	padding(env, env->format.min_field - 1, 0);
	return (1);
}
