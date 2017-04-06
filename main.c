/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/04 10:56:21 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int len;
	int len2;

	ft_putstr("    mine : ");
	len = ft_printf("plo%#10-20s^\n", "toto");
	ft_putstr("not mine : ");
	len2 = printf("pi%#.2# +21.2 +-21.12+0.2#4s^\n", "toto", 45, 'd', toto);
	printf("my len = %d, not my len = %d\n", len, len2);
}
