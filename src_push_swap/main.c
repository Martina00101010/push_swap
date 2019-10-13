/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:47:02 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 09:18:32 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		**sk;

	a = NULL;
	b = NULL;
	if (argc != 2)
		ft_error();
	ft_prepare(&a, &b, argv[1], &sk);
	push_swap(&a, &b);
	ft_skfree(&a);
	ft_skfree(&b);
	return (0);
}
