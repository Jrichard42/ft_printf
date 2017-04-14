/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 22:50:51 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/15 01:43:48 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "conversion.h"

void		convert_c2(t_printf *env, va_list *ap)
{
	wchar_t	c;
	int		len;
	unsigned char	tab[16];
	int		i;
	int		mask;
	unsigned char	first_byte;

	c = va_arg(*ap, wchar_t);
	mask = 0x3f;
	first_byte = 128;
	i = 0;
	printf ("BLABLA   %i\n", first_byte & c & mask);
	while ((first_byte & c) != 0)
	{
		tab[i] = 128;
		tab[i] |= c & mask;
		c = c >> 6;
		first_byte = (first_byte >> 1) + 128;
		printf ("BLABLA   %i\n", first_byte);
		++i;
	}
	tab[i] = first_byte + c;
	while (i >= 0)
	{
		printf ("TOTO   %i\n", tab[i]);
		//write(1, &(tab[i]), 1);
		--i;
	}
	


	//if (MB_CUR_MAX < (int)sizeof(wchar_t))
	//	printf("connard\n");
	//printf("%#x\n", c & 0xffffff00);
	//if ((int)c == 0x457F)
	//	printf ("SUCESS\n");
/*	if (env->format.padding != 2)
		padding(env, env->format.min_field - 1, 0);
	copy_to_buff(env, &c, 1);
	padding(env, env->format.min_field - 1, 0);*/
}

//0000 0000 0000 0000 0111 1111 0100 0101

//10100111    10111101   10000101
//
//00111101    10000000   10111101
//
//10111101
