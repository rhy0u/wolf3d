/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:09:06 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/03 08:58:46 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_save	*search_fd(int fd, t_save **save)
{
	if (!*save)
	{
		if (!(*save = (t_save*)malloc(sizeof(t_save))))
			return (NULL);
		(*save)->fd = fd;
		(*save)->buf = NULL;
		(*save)->next = NULL;
	}
	if ((*save)->fd == fd)
		return (*save);
	return (search_fd(fd, &((*save)->next)));
}

int		get_line(char *s)
{
	int i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n' && s[i] != '\r')
		i++;
	return (s[i]) ? i : -1;
}

void	del_save(t_save **alst)
{
	t_save	*tmp;

	tmp = (*alst)->next;
	ft_strdel(&(*alst)->buf);
	free(*alst);
	*alst = tmp;
}

void	ft_cheat(char **line, t_save *tmp)
{
	int		r;

	r = get_line(tmp->buf);
	if (r != -1)
	{
		*line = ft_strsub(tmp->buf, 0, r);
		tmp->buf = ft_strsubf(&tmp->buf, r + 1,
			ft_strlen(tmp->buf) - (r + 1));
	}
	else
	{
		*line = ft_strdup(tmp->buf);
		ft_strdel(&tmp->buf);
	}
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_save			*tmp;
	static t_save	*save = NULL;

	if (!line || fd < 0)
		return (-1);
	tmp = search_fd(fd, &save);
	ret = 1;
	while (ret && get_line(tmp->buf) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp->buf = ft_strjoinf(tmp->buf, buf);
	}
	ft_cheat(line, tmp);
	if (!ret && !**line && !tmp->buf)
	{
		ft_strdel(&tmp->buf);
		return (0);
	}
	return (1);
}
