/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 20:22:23 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/20 20:41:59 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *content, size_t size))
{
	if (!(*alst))
		return ;
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	(*del)((*alst)->content, (*alst)->content_size);
	free(*alst);
	(*alst) = NULL;
}
