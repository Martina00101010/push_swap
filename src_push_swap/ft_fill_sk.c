/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_sk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:01:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 05:36:09 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>
#include "libft.h"

/*
**	checks if stack already has d
*/

void	ft_duplicate(t_stack **a, int d, int i)
{
	t_stack *tmp;

	if (!*a)
		return ;
	tmp = *a;
	while (--i > -1)
	{
		if (tmp->el == d)
			ft_exception(a, NULL);
		tmp = tmp->prev;
	}
}

/*
**	check if argument is valid
*/

void	ft_validate(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	if (!*arg)
		ft_error();
	while (*arg)
	{
		if ((*arg <= '9' && *arg >= '0'))
			arg++;
		else
			ft_error();
	}
}

/*
**	frees the two-dimensional array
*/

static void	ft_free(char ***arr)
{
	int	i;

	i = -1;
	while ((*arr)[++i] != NULL)
		free((*arr)[i]);
	free(*arr);
}

/*
**	converts arguments from string to int
*/

static int	ft_get_ints(t_stack **a, char **arr)
{
	t_stack *new;
	int		i;
	int		ii;
	int		num;

	i = -1;
	while (arr[++i] != NULL)
		ft_validate(arr[i]);
	ii = i;
	while (--i > -1)
	{
		num = ft_atoi(arr[i]);
		if (ft_strlen(arr[i]) > 2 &&
				((*a)->el == -1 || (*a)->el == 0))
			ft_exception(a, NULL);
		ft_duplicate(a, num, ii - i);
		if (!(new = ft_sknew()))
			ft_exception(a, NULL);
		ft_skadd(a, new);
		(*a)->el = num;
	}
	return (ii);
}

/*
**	fills stack from one or several arguments
*/

int		ft_fill_sk(t_stack **a, char **arg, int num)
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
