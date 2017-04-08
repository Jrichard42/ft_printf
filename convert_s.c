/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 14:03:37 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/08 14:04:42 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion.h"

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
