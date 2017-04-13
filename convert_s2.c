/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:26:35 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 23:30:47 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"
#include "conversion.h"

void		convert_s2(t_printf *env, va_list *ap)
{
	wchar_t	*s;
	int		len;

	s = va_arg(*ap, wchar_t *);
	len = ft_strlen((char *)s);
	printf ("plop %d plop\n", len);
	/*if (env->format.precision != -1 && env->format.precision < len)
		len = env->format.precision;
	if (env->format.padding != 2)
		padding(env, env->format.min_field - len, 0);
	copy_to_buff(env, s, len);
	padding(env, env->format.min_field - len, 0);*/
}
