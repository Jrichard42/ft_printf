/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:20:11 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 22:28:01 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "stdarg.h"
# include "ft_printf.h"

typedef struct	s_ptr_convert
{
	char		c;
	void		(*convert)(t_printf *env, va_list *ap);
}				t_ptr_convert;

char			*ft_ltoa(long long nb);
void			convert_no(t_printf *env,const char *restrict s);
void			convert_percent(t_printf *env, va_list *ap);
void			convert_s(t_printf *env, va_list *ap);
void			convert_s2(t_printf *env, va_list *ap);
void			convert_d_i(t_printf *env, va_list *ap);
void			convert_D(t_printf *env, va_list *ap);
void			convert_c(t_printf *env, va_list *ap);
void			convert_u(t_printf *env, va_list *ap);
void			convert_U(t_printf *env, va_list *ap);
void			convert_x(t_printf *env, va_list *ap);
void			convert_x2(t_printf *env, va_list *ap);
void			convert_o(t_printf *env, va_list *ap);
void			convert_O(t_printf *env, va_list *ap);
void			convert_p(t_printf *env, va_list *ap);

#endif
