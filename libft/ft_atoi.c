/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:12:08 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/13 20:07:26 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_space(int *i, const char *str)
{
	while ((str[*i] == '\n') || (str[*i] == '\t') || (str[*i] == '\v') ||
		(str[*i] == ' ') || (str[*i] == '\f') || (str[*i] == '\r'))
		(*i)++;
}

int			ft_atoi(const char *str)
{
	unsigned long long	res;
	int					negative;
	int					i;

	i = 0;
	negative = 0;
	res = 0;
	is_space(&i, str);
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if ((9223372036854775807 <= res && negative == 0))
		return (-1);
	if ((9223372036854775807 < res && negative == 1))
		return (0);
	if (negative == 1)
		return (-res);
	return (res);
}
