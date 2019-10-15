/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sknew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:12:58 by pberge            #+#    #+#             */
/*   Updated: 2019/10/15 12:35:45 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

t_stack		*ft_sknew(void)
{
	t_stack	*ret;

	if (!(ret = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	ft_bzero(ret, sizeof(t_stack));
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}
