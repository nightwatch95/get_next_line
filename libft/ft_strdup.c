/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:38:23 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/02 13:59:49 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*copy;

	len = ft_strlen(s1);
	i = 0;
	if ((copy = (char*)malloc(len + 1)))
	{
		return (ft_strcpy(copy, s1));
	}
	errno = ENOMEM;
	return (NULL);
}
