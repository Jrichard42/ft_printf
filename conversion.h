/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:20:11 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/16 16:04:28 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "stdarg.h"
# include "ft_printf.h"

typedef struct	s_ptr_convert
{
	char		c;
	int			(*convert)(t_printf *env, va_list *ap);
}				t_ptr_convert;

char			*ft_ltoa(long long nb);
int				convert_no(t_printf *env, const char *restrict s);
int				convert_percent(t_printf *env, va_list *ap);
int				convert_s(t_printf *env, va_list *ap);
int				convert_s2(t_printf *env, va_list *ap);
int				convert_d_i(t_printf *env, va_list *ap);
int				convert_d2(t_printf *env, va_list *ap);
int				convert_c(t_printf *env, va_list *ap);
int				convert_c2(t_printf *env, va_list *ap);
int				convert_u(t_printf *env, va_list *ap);
int				convert_u2(t_printf *env, va_list *ap);
int				convert_x(t_printf *env, va_list *ap);
int				convert_x2(t_printf *env, va_list *ap);
int				convert_o(t_printf *env, va_list *ap);
int				convert_o2(t_printf *env, va_list *ap);
int				convert_p(t_printf *env, va_list *ap);
int				convert_b(t_printf *env, va_list *ap);

#endif
