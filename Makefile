# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 18:08:57 by fbabin            #+#    #+#              #
#    Updated: 2017/11/12 18:52:06 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fillit
_LIBFT			= libft.a

CC				= gcc
CFLAGS			= -g -Wall -Werror -Wextra
SRCS			= .
LIBFT_DIR		= libft

_OBJS			=	parser.o \
					checker.o \
					utils.o \
					solver.o \

OBJS			= $(patsubst %,$(SRCS)/%,$(_OBJS))
LIBFT			= $(patsubst %,$(LIBFT_DIR)/%,$(_LIBFT))
RM				= /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
		make -C $(LIBFT_DIR)

$(SRCS)/%.o: %.c \
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) -f $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
