/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/13 23:30:49 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

#include <limits.h>

int	main(int argc, char **argv)
{
	int len;
	int len2;
	int i;
	wchar_t s[50] = L"Salut G\x82rard !";
	char happy[] = { 0xe2, 0x98, 0xba };


	ft_putstr("    mine : ");
	len = ft_printf("p%S chiffre\n", s);
	ft_putstr("not mine : ");
	len2 = printf("p%S chiffre\n", happy);
	printf("my len = %d, not my len = %d\n", len, len2);
}
