/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:56:25 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/09 17:00:57 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "ft_printf.h"

typedef struct	s_ptr_flag
{
	char		type;
	void		(*flag)(t_printf *env);
}				t_ptr_flag;

void			alternate_flag(t_printf *env);
void			padding1_flag(t_printf *env);
void			padding2_flag(t_printf *env);
void			signing1_flag(t_printf *env);
void			signing2_flag(t_printf *env);

#endif
