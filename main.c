/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 19:40:01 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

#include <limits.h>

int	main(int argc, char **argv)
{
	int len;
	int len2;
	char *s;
	int i;

	ft_putstr("    mine : ");
	len = ft_printf("p%.0u\n", 0);
	ft_putstr("not mine : ");
	len2 = printf("p%.0u\n", 0);
	printf("my len = %d, not my len = %d\n", len, len2);
}
