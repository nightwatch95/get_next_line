/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:54:50 by vjacks            #+#    #+#             */
/*   Updated: 2018/11/28 16:46:29 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memset;
	size_t	i;

	memset = NULL;
	if ((memset = (size_t*)malloc(size * sizeof(size_t))))
	{
		i = 0;
		while (i < size)
		{
			((unsigned char*)memset)[i] = '\0';
			++i;
		}
	}
	return (memset);
}
