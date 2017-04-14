/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:54:57 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/20 21:04:12 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *content, size_t size))
{
	if (!*alst)
		return ;
	(*del)((*alst)->content, (*alst)->content_size);
	free(*alst);
	(*alst) = NULL;
}
