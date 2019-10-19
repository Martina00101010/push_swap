/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:47:02 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 05:53:22 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_ps	*ps;
	t_stack	*a;
	t_stack	*b;
	int		n;

	a = NULL;
	b = NULL;
	ps = NULL;
	if (argc < 2)
		ft_error();
	n = ft_fill_sk(&a, argv + 1, argc - 1);
	if (ft_issorted(&a))
	{
		ft_skfree(&a);
		return (0);
	}
	ps = ft_prepare(n);
	push_swap(&a, &b, ps);
	ft_end(&a, &b, &ps);
	return (0);
}
