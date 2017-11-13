/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknbd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:22:12 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/13 11:30:19 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_checknbd(char *piece)
{
	int		block;
	int		dot;
	int		i;

	block = 0;
	dot = 0;
	i = 0;
	while (i <= 20)
	{
		if ((i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
				&& piece[i] == '\n')
			;
		else if (piece[i] == '#')
			block++;
		else if (piece[i] == '.')
			dot++;
		else
			return (0);
		i++;
	}
	if (block != 4 || dot != 12)
		return (0);
	return (1);
}

static int	ft_checkpattern(char *piece)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (i <= 15)
	{
		if (piece[i] == '#')
		{
			if (i / 4 != 0 && piece[4 * (i / 4 - 1) + (i % 4)] == '#')
				link++;
			if (i / 4 != 3 && piece[4 * (i / 4 + 1) + (i % 4)] == '#')
				link++;
			if (i % 4 != 0 && piece[4 * (i / 4) + (i % 4 - 1)] == '#')
				link++;
			if (i % 4 != 3 && piece[4 * (i / 4) + (i % 4 + 1)] == '#')
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

static char	*ft_getpattern(char *piece, int type, int beg, char letter)
{
	char	copy[17];
	int		i;

	ft_strcpy(copy, piece);
	copy[16] = '\n';
	i = 0;
	while (i < 16)
	{
		if (i + beg - type < 16)
			piece[i] = copy[i + beg - type];
		else
			piece[i] = copy[i + beg - type - 16];
		if (piece[i] == '#')
			piece[i] = letter;
		i++;
	}
	return (piece);
}

static char	*ft_editpattern(char *piece, char letter)
{
	int		i;
	int		type;
	char	*pattern;

	i = 0;
	while (piece[i] && piece[i] != '#')
		i++;
	if (ft_strncmp(piece + i, "####", 4) == 0)
		type = 0;
	else if (piece[i + 2] == '#' && piece[i + 3] == '#')
		type = 2;
	else if (piece[i + 3] == '#')
		type = 1;
	else if (piece[i + 3] == '.' && piece[i + 7] == '#')
		type = 1;
	else
		type = 0;
	pattern = ft_getpattern(piece, type, i, letter);
	return (pattern);
}

char		*ft_parsepattern(char *piece, int nb_tetri)
{
	char	*no_newline;
	int		i;

	if (ft_strlen(piece) == 20)
		piece[20] = '\n';
	if (!ft_checknbd(piece))
		return (NULL);
	if (!(no_newline = ft_strnew(16)))
		return (NULL);
	i = 0;
	while (*piece)
	{
		if (*piece != '\n')
			no_newline[i++] = *piece++;
		else
			piece++;
	}
	if (!ft_checkpattern(no_newline))
		return (NULL);
	no_newline = ft_editpattern(no_newline, 'A' + nb_tetri);
	return (no_newline);
}
