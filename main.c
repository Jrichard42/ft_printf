/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:04:07 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/07 13:37:35 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int len;
	int len2;

	ft_putstr("    mine : ");
	len = ft_printf("plopinouchetdelamuerta\n", "toto");
	ft_putstr("not mine : ");
	len2 = printf("pplopinouchetdelamuerta\n", "toto");
	printf("my len = %d, not my len = %d\n", len, len2);
}
