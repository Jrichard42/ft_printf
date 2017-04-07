/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:26 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 06:27:08 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRINTF_BUFF 4096

typedef struct	s_format
{
	char		alternate;
	char		padding;
	char		signing;
	int			min_field;
	int			precision;
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
void			reset_env(t_printf *env);

#endif
