/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:49:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/11 04:03:46 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/*
**	in case of:
**		invalid number of arguments
*/

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_alloc(int *alloc, int n, int ***sk)
{
	if (alloc == NULL)
	{
		while (n > -1)
			free((*sk)[n--]);
		free(*sk);
		ft_error();
	}
	else
		(*sk)[n] = alloc;
}
