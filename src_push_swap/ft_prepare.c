/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 04:09:57 by pberge            #+#    #+#             */
/*   Updated: 2019/10/15 12:58:50 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>
#include "libft.h"

static void	ft_sortfuncs(t_sort *s)
{
	(*s)[0] = ft_divide;
	(*s)[2] = ft_two;
	(*s)[1] = ft_btoa;
	(*s)[3] = ft_three;
	(*s)[4] = ft_staircase;
}

/*
**	count number of integers
**	check if argument is valid
*/

static void	ft_validation(char *arg)
{
	int		fl;

	fl = 0;
	while (*arg)
	{
		if ((*arg <= '9' && *arg >= '0') ||
				*arg == '-' || *arg == '+' || *arg == ' ')
		{
			fl = 1;
			arg++;
		}
		else
			ft_error();
	}
	if (fl == 0)
		ft_error();
}

/*
**	fills stack with values
*/

static void	ft_fill(t_stack **a, char *arg, t_ps *ps)
{
	t_stack *new;
	char	**arr;
	int		i;

	i = 0;
	if (!(arr = ft_strsplit(arg, ' ')))
			ft_exception(a, &ps);
	while (arr[i] != NULL)
		i++;
	while (--i > -1)
	{
		if (!(new = ft_sknew()))
				ft_exception(a, &ps);
		ft_skadd(a, new);
		(*a)->el = ft_atoi(arr[i]);
		free(arr[i]);
	}
	free(arr);
}

/*
**	allocates stacks and fills stack A
*/

t_ps		*ft_prepare(t_stack **a, t_stack **b, char *arg)
{
	t_ps	*ps;

	ft_validation(arg);
	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		ft_error();
	ft_fill(a, arg, ps);
	ft_sortfuncs(&ps->sort);
	return (ps);
}
