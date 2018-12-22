/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:45:15 by vjacks            #+#    #+#             */
/*   Updated: 2018/12/12 21:53:26 by vjacks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *data, size_t size)
{
	if (data && size)
		free(data);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*item;

	if (!lst || !f)
		return (NULL);
	list = NULL;
	while (lst)
	{
		item = (*f)(lst);
		if (!item)
		{
			ft_lstdel(&list, &del);
			return (NULL);
		}
		list_pushback(&list, item);
		lst = lst->next;
	}
	return (list);
}
