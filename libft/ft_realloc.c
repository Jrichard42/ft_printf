/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:26:53 by jrichard          #+#    #+#             */
/*   Updated: 2017/04/14 16:02:04 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void		*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_strcpy((char *)new, (char *)ptr);
		ft_memdel(&ptr);
	}
	return (new);
}
