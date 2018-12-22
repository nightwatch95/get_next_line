/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:13:05 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/07 22:16:25 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	sub = NULL;
	if ((sub = (char *)malloc(len + 1)) && s)
	{
		i = 0;
		while (i < len)
		{
			sub[i] = s[i + start];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
