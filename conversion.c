/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:22:37 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 06:00:55 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

void		padding(t_printf *env, int size)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (env->format.padding == 1)
		c = '0';
	while (i < size)
	{
		ft_putchar(c);
		++i;
	}
	env->format.min_field = 0;
}

void		convert_no(t_printf *env, const char *restrict s)
{
	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1);
	ft_putchar(s[env->i]);
	padding(env, env->format.min_field - 1);
}

void		convert_percent(t_printf *env, va_list *ap)
{
	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1);
	ft_putstr("%");
	padding(env, env->format.min_field - 1);
}

void		convert_s(t_printf *env, va_list *ap)
{
	char	*s;
	int		len;
//	wchar_t	*s;

	s = va_arg(*ap, char *); //change ?
	len = ft_strlen(s);
	if (env->format.padding != 2)
		padding(env, env->format.min_field - len);
	ft_putstr(s);
	padding(env, env->format.min_field - len);
}
