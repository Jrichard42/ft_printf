/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 23:36:45 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int len;
	int len2;
	int i;
	wchar_t s[] = L"罅纗èe";

	int test = s[0];

//0000 0000 0000 0000 0111 1111 0100 0101
//0000 0000 0000 0000 0000 0000 0100 0101    -> 0x000000FF
//0000 0000 0000 0000 0111 1111 0000 0000    -> 0x0000FF00

//0000 0000 0000 0000 0111 1111 0100 0101


//11100001   10001000   10110100

	setlocale(LC_ALL, "en_US.UTF-8");
	/*char plop[] = {0xe1, 0x88, 0xb4};
	write (1, &plop, 3);
	printf("plop%C\n", test);
	printf("toto %d toto\n", test);
	printf ("MB_CUR_MAX = %d\n", MB_CUR_MAX);
*/
	ft_putstr("    mine : ");
	len = ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_putstr("not mine : ");
	len2 = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("my len = %d, not my len = %d\n", len, len2);
}
