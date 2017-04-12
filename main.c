/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/12 04:44:35 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int len;
	int len2;
	char *s;
	int i;

	ft_putstr("    mine : ");
	len = ft_printf("p%x\n", 2000000000);
	ft_putstr("not mine : ");
	len2 = printf("p%x\n", 2000000000);
	printf("my len = %d, not my len = %d\n", len, len2);
}
