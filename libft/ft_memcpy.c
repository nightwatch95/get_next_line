/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:48:17 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/02 13:57:24 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)source)[i];
		i++;
	}
	return (dest);
}
