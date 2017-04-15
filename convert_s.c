/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 14:03:37 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 22:35:44 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

int			convert_s(t_printf *env, va_list *ap)
{
	char	*s;
	int		len;
	char	nulltab[7];

	ft_strcpy(nulltab, "(null)\0");
	s = va_arg(*ap, char *);
	if (!s)
		s = nulltab;
	len = ft_strlen(s);
	if (env->format.precision != -1 && env->format.precision < len)
		len = env->format.precision;
	if (env->format.padding != 2)
		padding(env, env->format.min_field - len, 0);
	copy_to_buff(env, s, len);
	padding(env, env->format.min_field - len, 0);
	return (1);
}
