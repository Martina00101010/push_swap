/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:15:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 04:46:28 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

void	ft_skfree(t_stack **sk)
{
	t_stack	*head;

	head = *sk;
	(*sk) = (*sk)->next;
	while (*sk != head)
	{
		free(*sk);
		*sk = (*sk)->next;
	}
	free(head);
}
