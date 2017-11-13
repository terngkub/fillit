/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:22:32 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/13 10:17:57 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isvalid(char *map, char *piece, int pst, int size)
{
	int	row;
	int	col;
	int	i;

	row = pst / size;
	col = pst % size;
	i = 0;
	while (i <= 15)
	{
		if (piece[i] != '.')
		{
			if ((row + i / 4) >= size || col + i % 4 >= size)
				return (0);
			if (map[(size * (row + i / 4)) + (col + i % 4)] != '.')
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_mark(char *map, char *piece, int pst, int size)
{
	int	row;
	int	col;
	int	i;

	row = pst / size;
	col = pst % size;
	i = 0;
	while (i <= 15)
	{
		if (piece[i] != '.')
			map[(size * (row + i / 4)) + (col + i % 4)] = piece[i];
		i++;
	}
}

static void	ft_unmark(char *map, char *piece, int pst, int size)
{
	int	row;
	int	col;
	int	i;

	row = pst / size;
	col = pst % size;
	i = 0;
	while (i <= 15)
	{
		if (piece[i] != '.')
			map[(size * (row + i / 4)) + (col + i % 4)] = '.';
		i++;
	}
}

static int	ft_fillmap(char *map, t_list *lst, int pst, int size)
{
	if (lst == NULL)
		return (1);
	while (pst < size * size)
	{
		if (ft_isvalid(map, lst->content, pst, size))
		{
			ft_mark(map, lst->content, pst, size);
			if (ft_fillmap(map, lst->next, 0, size))
				return (1);
			ft_unmark(map, lst->content, pst, size);
		}
		pst++;
	}
	return (0);
}

int			ft_solver(t_list *lst)
{
	char	*old_map;
	char	*new_map;
	int		size;

	size = 24;
	while (size > 0)
	{
		if (!(new_map = ft_createmap(size)))
			return (0);
		if (ft_fillmap(new_map, lst, 0, size))
		{
			if (size-- != 24)
				free(old_map);
			old_map = ft_strdup(new_map);
		}
		else
		{
			ft_printsolution(old_map, size + 1);
			free(old_map);
			free(new_map);
			return (1);
		}
		free(new_map);
	}
	return (0);
}
