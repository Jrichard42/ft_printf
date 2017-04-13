/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:26 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 16:22:36 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define PRINTF_BUFF 4096

typedef enum    e_type
{
	NONE,
	HH,
	H,
	L,
	LL,
	J,
	Z
}               s_type;

typedef struct	s_format
{
	char		alternate;
	char		padding;
	char		signing;
	int			min_field;
	int			precision;
	s_type		length_modifier;
}				t_format;

typedef struct	s_printf
{
	char		buff[PRINTF_BUFF];
	t_format	format;
	int			i;
	int			i_buff;
	int			ret;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
void			copy_to_buff(t_printf *env, const char *s, int size);
void			padding(t_printf *env, int size, char overwrite);
void			reset_format(t_format *format);
void			reset_env(t_printf *env);
int				parse_str(t_printf *env, const char *restrict s, va_list *ap);

#endif
