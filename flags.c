/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:40:41 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/04 10:27:56 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	alternate_flag(t_printf *env)
{
	env->alternate = 1;
}

void	padding1_flag(t_printf *env)
{
	if (env->padding != 2)
		env->padding = 1;
}

void	padding2_flag(t_printf *env)
{
	env->padding = 2;
}

void	signing1_flag(t_printf *env)
{
	if (env->signing != 2)
		env->signing = 1;
}

void	signing2_flag(t_printf *env)
{
	env->signing = 2;
}
