/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:47:26 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/03 19:26:52 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_printf
{
	int			ret;
	int			i;
	char		alternate; //#
	char		padding; //0-
	char		signing; //+space
	int			min_field;
	int			precision;
}				t_printf;

int				ft_printf(const char *restrict format, ...);

#endif
