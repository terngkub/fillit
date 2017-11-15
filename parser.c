/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:32:53 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/15 16:03:57 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_elemdel(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
	content = NULL;
}

int		ft_read(int fd, int warning, int ret, int nb_tetri)
{
	char		buffer[BUFF_SIZE + 1];
	t_list		*maps;
	char		*tmp;

	maps = NULL;
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) != 0)
	{
		warning = 0;
		if (buffer[20] == '\n')
			warning++;
		if (++nb_tetri > 26)
			return (0);
		if (!(tmp = ft_parsepattern(buffer, nb_tetri - 1)))
			return (0);
		ft_lstpushback(&maps, tmp);
		ft_bzero(buffer, BUFF_SIZE);
	}
	if (((!nb_tetri && !ret)) || warning || !ft_solver(maps))
		return (0);
	ft_lstdel(&maps, ft_elemdel);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		warning;
	int		ret;
	int		nb_tetri;

	nb_tetri = 0;
	warning = 0;
	ret = 0;
	if (ft_checkparams(argc))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(1));
	if (!ft_read(fd, warning, ret, nb_tetri))
		return (ft_error(1));
	if (close(fd) == -1)
		return (ft_error(1));
	return (0);
}
