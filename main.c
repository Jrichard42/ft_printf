/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/16 16:25:05 by jrichard         ###   ########.fr       */
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
	wchar_t s[] = L"ሴሴ";

	int test = s[0];

	setlocale(LC_ALL, "en_US");
	/*char plop[] = {0xe1, 0x88, 0xb4};
	write (1, &plop, 3);
	printf("plop%C\n", test);
	printf("toto %d toto\n", test);
	printf ("MB_CUR_MAX = %d\n", MB_CUR_MAX);
*/
	char c;
	ft_putstr("    mine : ");
	len = ft_printf("%#.21#20.0#0 -+++++++0#.2#12.1#-20d\n", 42);
	ft_putstr("not mine : ");
	len2 = printf("%#.21#20.0#0 -+++++++0#.2#12.1#-20d\n", 42);
	printf("my len = %d, not my len = %d\n", len, len2);
}
