/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:14:48 by pberge            #+#    #+#             */
/*   Updated: 2019/10/20 06:27:03 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"
#include <unistd.h>
#include "libft.h"

void	ft_output(t_out *out, char *op)
{
	int		len;

	len = ft_strlen(op);
	if (LINE_SIZE - out->i < len)
	{
		write(1, out->buff, out->i);
		ft_bzero(out->buff, LINE_SIZE + 1);
		out->i = 0;
	}
	ft_strcat(out->buff, op);
	out->i += len;
}
