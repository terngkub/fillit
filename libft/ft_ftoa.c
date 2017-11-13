/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:28:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 21:30:15 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(double nb, int prec)
{
	int		i;
	int		tmp;
	char	*str;
	double	dec;
	int		y;

	i = (nb < 0) ? 2 : 1;
	tmp = (nb < 0) ? -nb : nb;
	while (tmp >= 10 && (tmp /= 10) && i++)
		;
	if ((str = (char*)malloc((i + prec + 2) * sizeof(char))) == NULL)
		return (0);
	tmp = (nb < 0) ? -1 : 1;
	nb *= tmp;
	str[i + prec + 1] = '\0';
	dec = nb - ((int)nb);
	y = -1;
	while (++y < prec && (dec -= (int)dec) && (dec *= 10))
		str[i + y + 1] = ((int)dec) + 48;
	str[i] = '.';
	while (i-- && (str[i] = ((int)nb % 10) + 48))
		nb /= 10;
	if (tmp < 0)
		str[0] = '-';
	return (str);
}
