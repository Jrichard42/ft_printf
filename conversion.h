/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:20:11 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 20:06:47 by jrichard         ###   ########.fr       */
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

void			padding(t_printf *env, int size, char overwrite);
void			convert_no(t_printf *env,const char *restrict s);
void			convert_percent(t_printf *env, va_list *ap);
void			convert_s(t_printf *env, va_list *ap);
void			convert_d_i(t_printf *env, va_list *ap);

#endif
