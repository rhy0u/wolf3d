/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:11:05 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/21 11:18:41 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color(t_color col)
{
	if (col == red)
		ft_putstr(RED);
	if (col == blue)
		ft_putstr(BLU);
	if (col == green)
		ft_putstr(GRN);
	if (col == yellow)
		ft_putstr(YEL);
	if (col == magenta)
		ft_putstr(MAG);
	if (col == cyan)
		ft_putstr(CYN);
	if (col == reset)
		ft_putstr(RST);
}
