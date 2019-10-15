/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:15:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/15 12:28:50 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

void	ft_skfree(t_stack **sk)
{
	t_stack	*head;

	if (*sk == NULL)
		return ;
	head = *sk;
	(*sk) = (*sk)->prev;
	while (*sk != head)
	{
//		printf("hi %i\n", (*sk)->el);
		free(*sk);
		*sk = (*sk)->prev;
	}
//	printf("hi %i\n", head->el);
	free(head);
}
