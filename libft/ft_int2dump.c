/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:30:41 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 21:30:46 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int2dump(int **array, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		ft_putstr("[");
		ft_putnbr(*array[i]);
		ft_putstr("] ");
	}
	ft_putstr("[");
	ft_putnbr(*array[i]);
	ft_putstr("]\n");
}
