/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pushback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:42:57 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/12 21:41:20 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_pushback(t_list **list, t_list *item)
{
	t_list *cur;

	if (!list)
		return ;
	if (!(*list))
	{
		*list = item;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = item;
}
