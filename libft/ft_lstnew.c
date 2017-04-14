/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:29:05 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/20 22:06:19 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if ((res = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	res->content = (void *)malloc(content_size);
	if (!res->content || !content_size || !content)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
		return (res);
	}
	ft_memcpy(res->content, content, content_size);
	res->content_size = content_size;
	res->next = NULL;
	return (res);
}
