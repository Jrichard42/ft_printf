/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:49:46 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/09 18:53:34 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_MODIFIER_H
# define LENGTH_MODIFIER_H

# include "ft_printf.h"

typedef struct	s_ptr_length
{
	char 		c;
	void		(*length)(t_printf *env, const char *restrict s);
}				t_ptr_length;

void			length_h(t_printf *env, const char *restrict s);
void			length_l(t_printf *env, const char *restrict s);
void			length_j(t_printf *env, const char *restrict s);
void			length_z(t_printf *env, const char *restrict s);

#endif
