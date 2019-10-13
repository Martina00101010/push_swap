/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 04:09:57 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 04:47:08 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>
#include "libft.h"

/*
**	count number of integers
**	check if argument is valid
*/

static int	ft_validation(char *arg)
{
	int		len;

	len = 0;
	while (*arg)
	{
		if ((*arg <= '9' && *arg >= '0') ||
				*arg == '-' || *arg == '+' || *arg == ' ')
			arg++;
		else
			ft_error();
		len++;
	}
	return (len);
}

/*
**	fills stack with values
*/

static void	ft_fill(t_stack **a, char *arg)
{
	t_stack *tmp;
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(arg, ' ');
	while (arr[i] != NULL)
		i++;
	while (--i > -1)
	{
		ft_skadd(a, ft_sknew());
//		(*a)->el = ft_atoi(arr[i]);
//		ft_printf("cur %i\tprev %i\n", (*a)->el, (*a)->prev->el);
		free(arr[i]);
	}
	free(arr);
}

/*
**	allocates stacks and fills stack A
*/

void	ft_prepare(t_stack *a, t_stack *b, char *arg, int ***sk)
{
	ft_validation(arg);
	ft_fill(&a, arg);
	ft_skfree(&a);
//	ft_print_stack(a);
}
