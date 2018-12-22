/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:15:01 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/08 21:15:38 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_itoa(char *res, int n)
{
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		*res++ = '-';
	}
	if (n > 9)
	{
		res = fill_itoa(res, n / 10);
		*res = n % 10 + '0';
		return (res + 1);
	}
	else
	{
		*res = n + '0';
		return (res + 1);
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*res;

	size = get_num_categories(n);
	res = NULL;
	if ((res = ft_strnew(size)))
	{
		fill_itoa(res, n);
	}
	return (res);
}
