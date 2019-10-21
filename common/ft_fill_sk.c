/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_sk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:01:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 14:37:29 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>
#include "libft.h"

/*
**	frees the two-dimensional array
*/

static void	ft_free(char ***arr)
{
	int	i;

	i = -1;
	while ((*arr)[++i] != NULL)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
	}
	free(*arr);
	*arr = NULL;
}

/*
**	fills stack from one or several arguments
*/

int			ft_fill_sk(t_stack **a, char **arg, int num)
{
	char	**arr;
	int		n;

	if (num == 1)
		arr = ft_strsplit(*arg, ' ');
	else
		arr = arg;
	if (*arr == NULL)
		ft_exception(a, NULL);
	n = ft_get_ints(a, arr);
	if (num == 1)
		ft_free(&arr);
	return (n);
}
