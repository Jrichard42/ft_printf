/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 10:06:00 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 07:12:26 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		copy_to_buff(t_printf *env, char *s, int size)
{
	if (env->i_buff + size >= PRINTF_BUFF - 1)
	{
		env->ret += PRINTF_BUFF - 1;
		ft_bzero(&env->buff, PRINTF_BUFF);
		env->i_buff = 0;
	}
	ft_strncpy(env->buff, s, size);
}

void	reset_env(t_printf *env)
{
	ft_bzero(env, sizeof(*env));
	env->format.precision = -1;
}
