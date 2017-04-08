/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/08 14:43:27 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int len;
	int len2;

	ft_putstr("    mine : ");
	len = ft_printf("p%020.110.1s\n", "toto");
	ft_putstr("not mine : ");
	len2 = printf("p%020.110.1s\n", "toto");
	printf("my len = %d, not my len = %d\n", len, len2);
}
