/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:45:25 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/05 16:52:34 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t s1_len;
	size_t s2_len;
	size_t j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	j = 0;
	if (s1_len > size)
		return (size + ft_strlen(s2));
	while (s2[j] != '\0' && s1_len + j < size - 1)
	{
		s1[s1_len + j] = s2[j];
		j++;
	}
	s1[s1_len + j] = '\0';
	return (s1_len + s2_len);
}
