/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:25:10 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:25:15 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_matchlen(const char *str, const char *old)
{
	int		i;

	i = 0;
	while (str[i] && old[i] && str[i] == old[i])
		i++;
	return (i);
}

static int		ft_strocc(const char *s1, const char *s2)
{
	int		i;
	int		n;

	n = 0;
	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i])
			i++;
		if (s2[i] == '\0')
			n++;
		s1++;
	}
	return (n);
}

char			*ft_strreplace(char *str, const char *old, const char *new)
{
	char	*out;
	char	*tmp;
	int		i;
	int		n;

	n = ft_strocc(str, old);
	i = ft_strlen(str) - (n * ft_strlen(old)) + (n * ft_strlen(new)) + 1;
	if ((out = ft_strnew(i)) == NULL)
		return (NULL);
	tmp = out;
	while (*str)
	{
		i = ft_matchlen(str, old);
		if (old[i] == '\0')
		{
			n = -1;
			while (new[++n])
				*(out++) = new[n];
			str += i;
		}
		else
			*(out++) = *(str++);
	}
	return (tmp);
}
