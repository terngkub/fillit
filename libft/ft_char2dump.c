/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:28:30 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/09 15:28:41 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char2dump(char **array)
{
	int		i;

	i = 0;
	while (array[++i])
	{
		ft_putstr("[");
		ft_putstr(array[i - 1]);
		ft_putstr("] ");
	}
	ft_putstr("[");
	ft_putstr(array[i - 1]);
	ft_putstr("]\n");
}
