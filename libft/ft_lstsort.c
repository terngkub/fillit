/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:02:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:03:08 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		**ft_lstalloc2(size_t size)
{
	t_list	**t;
	int		i;

	i = 0;
	if (size < 1)
		return (NULL);
	if ((t = (t_list**)malloc(size * sizeof(t_list*))) == NULL)
		return (NULL);
	ft_lstpushback(t, " ");
	while (i++ < (int)size)
		ft_lstpushback(t, " ");
	return (t);
}

static void			ft_merge(t_list **list, t_list **tmp, int left, int right)
{
	int		i;
	int		j;
	int		k;
	int		mid;

	mid = (right + left) / 2;
	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
		if (ft_strcmp(ft_lstat(*list, i)->content,
					ft_lstat(*list, j)->content) <= 0)
			ft_lstat(*tmp, k++)->content = ft_lstat(*list, i++)->content;
		else
			ft_lstat(*tmp, k++)->content = ft_lstat(*list, j++)->content;
	while (i <= mid)
		ft_lstat(*tmp, k++)->content = ft_lstat(*list, i++)->content;
	while (j <= right)
		ft_lstat(*tmp, k++)->content = ft_lstat(*list, j++)->content;
	while (--k >= 0)
		ft_lstat(*list, left + k)->content = ft_lstat(*tmp, k)->content;
}

static void			ft_sort(t_list **list, t_list **tmp, int left, int right)
{
	int		mid;

	if (left >= right)
		return ;
	mid = (right + left) / 2;
	ft_sort(list, tmp, left, mid);
	ft_sort(list, tmp, mid + 1, right);
	ft_merge(list, tmp, left, right);
}

void				ft_lstsort(t_list **list)
{
	t_list		**tmp;

	tmp = ft_lstalloc2(ft_lstsize(*list));
	ft_sort(list, tmp, 0, ft_lstsize(*list) - 1);
	free(tmp);
}
