/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:15:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 05:53:01 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

void	ft_skfree(t_stack **sk)
{
	t_stack	*end;
	t_stack	*tmp;

	if (sk == NULL || *sk == NULL)
		return ;
	end = (*sk)->next;
	while (*sk != end)
	{
		tmp = (*sk)->prev;
		free(*sk);
		*sk = tmp;
	}
	free(end);
}
