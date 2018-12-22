/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:16:05 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/13 20:24:29 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;

	new = NULL;
	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (len > 0 && is_space(s[len - 1]))
		len--;
	while (i < len && is_space(s[i]))
	{
		i++;
		len--;
	}
	if ((new = (char *)malloc(len + 1)))
	{
		s += i;
		i = -1;
		while (++i < len)
			new[i] = *s++;
		new[i] = '\0';
	}
	return (new);
}
