/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:46 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 10:31:26 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GET_NEXT_LINE_H
# define LIBFT_GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 1
# define ERROR(x) if (!x) return (-1);
# define ERROR_RET_NULL(x) if (!x) return (NULL);

int		get_next_line(const int fd, char **line);

#endif
