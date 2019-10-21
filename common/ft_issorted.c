/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:05:47 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 13:41:51 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ft_issorted(t_stack **sk)
{
	t_stack *tmp;

	if (sk == NULL || *sk == NULL)
		return (0);
	tmp = (*sk)->prev;
	while (tmp->el != (*sk)->el)
	{
		if (tmp->next->el > tmp->el)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}
