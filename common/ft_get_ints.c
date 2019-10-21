/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 05:50:06 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 14:25:14 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/*
**	checks if stack already has d
*/

static void	ft_duplicate(t_stack **a, int d, int i)
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

static void	ft_validate(char *arg, t_stack **a)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	if (!*arg)
		ft_exception(a, NULL);
	while (*arg)
	{
		if ((*arg <= '9' && *arg >= '0'))
			arg++;
		else
			ft_exception(a, NULL);
	}
}

static int	ft_atoi_ps(const char *str)
{
	int		neg;
	int		num;
	char	*s;

	s = (char *)str;
	num = 0;
	neg = 1;
	while (*s == ' ' || *s == '\f' || *s == '\v'
			|| *s == '\n' || *s == '\r' || *s == '\t')
		s++;
	if (*s == '-')
		neg = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		if (num * 10 / 10 != num)
			return (neg > 0 ? -1 : 0);
		num *= 10;
		if (num + *s - '0' < num)
			return (neg > 0 ? -1 : 0);
		num += (*s - '0');
		s++;
	}
	return (num * neg);
}

static int	ft_maxint(int num, char *arri)
{
	if (ft_strlen(arri) > 2 && (num == -1 || num == 0))
		return (1);
	return (0);
}

/*
**	converts arguments from string to int
*/

int			ft_get_ints(t_stack **a, char **arr)
{
	t_stack *new;
	int		i;
	int		ii;
	int		num;

	i = -1;
	while (arr[++i] != NULL)
		ft_validate(arr[i], a);
	ii = i;
	while (--i > -1)
	{
		if (ft_strcmp(arr[i], "-2147483648") == 0)
			num = -21483648;
		else
			num = ft_atoi_ps(arr[i]);
		if (ft_maxint(num, arr[i]))
			ft_exception(a, NULL);
		ft_duplicate(a, num, ii - i);
		if (!(new = ft_sknew()))
			ft_exception(a, NULL);
		ft_skadd(a, new);
		(*a)->el = num;
	}
	return (ii);
}
