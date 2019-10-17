/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:47:02 by pberge            #+#    #+#             */
/*   Updated: 2019/10/17 01:47:47 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_ps	*ps;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc != 2)
		ft_error();
	ps = ft_prepare(&a, &b, argv[1]);
	push_swap(&a, &b, ps);
	ft_end(&a, &b, &ps);
	return (0);
}
