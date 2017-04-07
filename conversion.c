/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:22:37 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 20:16:21 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

void		padding(t_printf *env, int size, char overwrite)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (env->format.padding == 1)
		c = '0';
	if (overwrite)
		c = overwrite;
	while (i < size)
	{
		copy_to_buff(env, &c, 1);
		++i;
	}
	env->format.min_field = 0;
}

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

void		convert_s(t_printf *env, va_list *ap)
{
	char	*s;
	int		len;
	//	wchar_t	*s;

	s = va_arg(*ap, char *); //change ?
	len = ft_strlen(s);
	if (env->format.precision != -1 && env->format.precision < len)
		len = env->format.precision;
	if (env->format.padding != 2)
		padding(env, env->format.min_field - len, 0);
	copy_to_buff(env, s, len);
	padding(env, env->format.min_field - len, 0);
}
