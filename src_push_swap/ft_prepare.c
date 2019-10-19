/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 04:09:57 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 03:00:49 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>
#include "libft.h"

/*
**	allocates main structure
*/

t_ps		*ft_prepare(int n)
{
	t_ps	*ps;

	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		ft_error();
	ft_bzero(ps, sizeof(t_ps));
	ft_bzero(&ps->out, sizeof(t_out));
	ft_bzero(&ps->out.buff, BUFF_SIZE + 1);
	ps->bsize = n;
	return (ps);
}
