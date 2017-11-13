/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:35:39 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 21:35:44 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char **tab, char *sep)
{
	char	*str;
	int		i;
	int		y;
	int		x;

	i = -1;
	x = 0;
	while (tab[++i])
	{
		y = -1;
		while (tab[i][++y])
			x++;
	}
	y = ft_strlen(sep);
	if ((str = (char*)malloc(((i - 1) * y + x + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		ft_strcat(str, tab[i]);
		if (tab[i + 1])
			ft_strcat(str, sep);
	}
	return (str);
}
