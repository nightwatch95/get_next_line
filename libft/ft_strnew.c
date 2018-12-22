/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:15:46 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/05 19:26:28 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	if ((str = (char*)malloc(size + 1)))
	{
		i = 0;
		while (i < size)
			str[i++] = '\0';
		str[i] = '\0';
	}
	return (str);
}
