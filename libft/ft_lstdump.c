/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:53:28 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 21:53:34 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdump(t_list **list)
{
	t_list		*l;

	l = *list;
	if (l == NULL)
		return ;
	while ((*list)->next)
	{
		ft_putstr((char*)(*list)->content);
		ft_putstr(" -> ");
		*list = (*list)->next;
	}
	ft_putstr((char*)(*list)->content);
	ft_putstr(" -> NULL\n");
	*list = l;
}
