/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:43:14 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 15:16:12 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_arg(va_list ap, char length)
{
	return (NULL);
}

int		ft_size(char length)
{
	if (length & BIGL)
		size = sizeof(long double);
	else if (length & LLMOD || length & LMOD)
		size = sizeof(long long);
	else if (length & HMOD)
		size = sizeof(short);
	else if (length & HHMOD)
		size = sizeof(char);
	else
		size = sizeof(int);
	return (size);
}

void	ft_b(t_vaio *v, t_flags *flg)
{
	unsigned char	*b;
	int				size;
	int				i;
	unsigned char	*bits;

	
	size = ft_size(char length);
	while (--size > -1)
	{
		i = 8;
		while (--i > -1)
			b |= b[size] & 1 << (8 * size + i);
	}
}
