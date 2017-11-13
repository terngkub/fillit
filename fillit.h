/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:03:57 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/13 11:27:01 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 21

int		ft_error(int retval);
int		ft_checkparams(int argc);
void	ft_printsolution(char *map, int size);
char	*ft_parsepattern(char *piece, int nb_tetri);
int		ft_solver(t_list *lst);
char	*ft_createmap(int size);

#endif
