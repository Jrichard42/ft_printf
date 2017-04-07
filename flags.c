/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:40:41 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 05:57:27 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	alternate_flag(t_printf *env)
{
	env->format.alternate = 1;
}

void	padding1_flag(t_printf *env)
{
	if (env->format.padding != 2)
		env->format.padding = 1;
}

void	padding2_flag(t_printf *env)
{
	env->format.padding = 2;
}

void	signing1_flag(t_printf *env)
{
	if (env->format.signing != 2)
		env->format.signing = 1;
}

void	signing2_flag(t_printf *env)
{
	env->format.signing = 2;
}
