/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:19:39 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/14 18:13:41 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"
#include "libft.h"
#include "ft_printf.h"

int	parse_str(t_printf *env, const char *restrict s, va_list *ap)
{
	++env->i;
	while (s[env->i])
	{
		if (check_flags(env, s))
			;
		else if (ft_isdigit(s[env->i]))
			check_min_field(env, s);
		else if (s[env->i] == '.')
			check_precision(env, s);
		else
		{
			if (check_length_modifier(env, s))
				;
			else
			{
				check_conversion(env, s, ap);
				reset_format(&(env->format));
				return (1);
			}
		}
		++env->i;
	}
	return (1);
}
