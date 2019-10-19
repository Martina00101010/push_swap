/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:32:49 by pberge            #+#    #+#             */
/*   Updated: 2019/10/20 02:46:18 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		n;

	a = NULL;
	b = NULL;
	ft_fill_sk(&a, argv + 1, argc - 1);
	ft_print_stack(a);
	return (0);
}
