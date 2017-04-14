/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 20:50:47 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/20 21:05:09 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*iter;

	if (!lst)
		return (NULL);
	res = (*f)(lst);
	iter = res;
	lst = lst->next;
	while (lst)
	{
		iter->next = (*f)(lst);
		iter = iter->next;
		lst = lst->next;
	}
	return (res);
}
