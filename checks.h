/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 18:31:52 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 19:44:29 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "ft_printf.h"

int		check_flags(t_printf *env, const char *restrict s);
void	check_min_field(t_printf *env, const char *restrict s);
void	check_precision(t_printf *env, const char *restrict s);
int		check_conversion(t_printf *env, const char *restrict s, va_list *ap);
int		check_length_modifier(t_printf *env, const char *restrict s);

#endif
