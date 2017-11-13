/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:57:18 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/09 16:28:29 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list		*t;

	t = *begin_list1;
	if (*begin_list1 == NULL && begin_list2 != NULL)
		*begin_list1 = begin_list2;
	else if (begin_list2 != NULL)
	{
		while (t->next)
			t = t->next;
		t->next = begin_list2;
	}
}
