/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:16:18 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/13 19:05:32 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int retval)
{
	ft_putstr("error\n");
	return (retval);
}

int		ft_checkparams(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit Tetriminos_file\n");
		return (1);
	}
	return (0);
}

void	ft_printsolution(char *map, int size)
{
	int		i;

	i = 0;
	while (i < size * size)
	{
		if ((i % size) == 0 && i > 0)
			ft_putchar('\n');
		ft_putchar(map[i]);
		i++;
	}
	ft_putchar('\n');
}

char	*ft_createmap(int size)
{
	char	*map;

	map = ft_strnew(size * size);
	if (!map)
		return (NULL);
	map = ft_memset(map, '.', size * size);
	return (map);
}
