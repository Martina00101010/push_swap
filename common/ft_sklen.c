/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sklen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:22:52 by pberge            #+#    #+#             */
/*   Updated: 2019/10/20 02:13:09 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"
#include <stdlib.h>

/*
**	counting size of stack
*/

int		ft_sklen(t_stack *sk)
{
	t_stack	*end;
	int		len;

	len = 0;
	if (sk == NULL)
		return (len);
	end = sk->next;
	while (1)
	{
		len++;
		if (len > 3 || sk == end)
			break ;
		sk = sk->prev;
	}
	return (len);
}
