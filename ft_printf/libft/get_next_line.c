/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <pberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:07:48 by pberge            #+#    #+#             */
/*   Updated: 2019/03/16 23:23:27 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static t_list	*get_node(int fd, t_list **l)
{
	t_list	*node;

	if (!*l)
	{
		ERROR_RET_NULL((*l = ft_lstnew(NULL, 0)));
		(*l)->content_size = fd;
	}
	node = *l;
	while (node)
	{
		if ((int)node->content_size == fd)
			break ;
		node = node->next;
	}
	if (node == NULL)
	{
		ERROR_RET_NULL((node = ft_lstnew(NULL, 0)));
		node->content = ft_strnew(0);
		ft_memset(node->content, '\0', 1);
		node->content_size = fd;
		ft_lstadd(l, node);
	}
	return (node);
}

static void		*read_file(t_list *node)
{
	char	*buff;
	void	*tmp;
	int		rd;

	ERROR_RET_NULL((buff = (char *)malloc(BUFF_SIZE + 1)));
	while ((rd = read(node->content_size, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (node->content == NULL)
		{
			ERROR_RET_NULL((node->content = ft_strnew(rd)));
			ft_strcpy(node->content, buff);
		}
		else
		{
			tmp = node->content;
			ERROR_RET_NULL((node->content = ft_strjoin(tmp, buff)));
			free(tmp);
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (node->content);
}

static int		retrieve_line(t_list *node, char **line)
{
	char	*feed_line;
	size_t	line_len;
	size_t	cnt_len;
	char	*tmp;

	ERROR(node->content);
	if (!(cnt_len = ft_strlen(node->content)))
		return (0);
	line_len = cnt_len;
	if ((feed_line = ft_strchr(node->content, 0x0a)))
		line_len = feed_line - (char *)node->content;
	ERROR((*line = ft_strnew(line_len)));
	ft_strncpy(*line, node->content, line_len);
	if (line_len + 1 < cnt_len)
	{
		tmp = ft_strnew(cnt_len - line_len);
		ft_strcpy(tmp, feed_line + 1);
		free(node->content);
		node->content = NULL;
		ERROR((node->content = ft_strdup(tmp)));
		free(tmp);
	}
	else
		ft_strclr(node->content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*l;
	t_list			*node;
	char			buff[1];

	ERROR((fd >= 0 && line && read(fd, buff, 0) >= 0));
	ERROR((node = get_node(fd, &l)));
	ERROR(read_file(node));
	return (retrieve_line(node, line));
}
