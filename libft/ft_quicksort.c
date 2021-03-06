/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:13:59 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/10 09:15:41 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_arrayswap(int **array, int a, int b)
{
	int		*c;

	c = array[a];
	array[a] = array[b];
	array[b] = c;
}

static int		ft_partition(int **array, int left, int right)
{
	int		pivot;

	pivot = *array[(left + right) / 2];
	while (left <= right)
	{
		while (*array[left] < pivot)
			left++;
		while (*array[right] > pivot)
			right--;
		if (left <= right)
		{
			ft_arrayswap(array, left, right);
			left++;
			right--;
		}
	}
	return (left);
}

void			ft_quicksort(int **array, int left, int right)
{
	int		index;

	if (left >= right || left < 0 || right < 0)
		return ;
	index = ft_partition(array, left, right);
	ft_quicksort(array, left, index - 1);
	ft_quicksort(array, index, right);
}
