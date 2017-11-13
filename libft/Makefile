# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:49:24 by fbabin            #+#    #+#              #
#    Updated: 2017/11/10 09:13:14 by fbabin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
SRCS			= .

_OBJS			=	ft_memset.o \
					ft_bzero.o \
					ft_memcpy.o \
					ft_memccpy.o \
					ft_memmove.o \
					ft_memchr.o \
					ft_memcmp.o \
					ft_strlen.o \
					ft_strdup.o \
					ft_strcpy.o \
					ft_strncpy.o \
					ft_strcat.o \
					ft_strncat.o \
					ft_strlcat.o \
					ft_strchr.o \
					ft_strrchr.o \
					ft_strstr.o \
					ft_strnstr.o \
					ft_strcmp.o \
					ft_strncmp.o \
					ft_atoi.o \
					ft_itoa.o \
					ft_isalpha.o \
					ft_isdigit.o \
					ft_isalnum.o \
					ft_isascii.o \
					ft_isprint.o \
					ft_toupper.o \
					ft_tolower.o \
					ft_memalloc.o \
					ft_memdel.o \
					ft_strnew.o \
					ft_strdel.o \
					ft_strclr.o \
					ft_putstr.o \
					ft_striter.o \
					ft_striteri.o \
					ft_strmap.o \
					ft_strmapi.o \
					ft_strequ.o \
					ft_strnequ.o \
					ft_strsub.o \
					ft_strjoin.o \
					ft_strtrim.o \
					ft_strsplit.o \
					ft_putchar.o \
					ft_putstr.o \
					ft_putendl.o \
					ft_putnbr.o \
					ft_putchar_fd.o \
					ft_putstr_fd.o \
					ft_putendl_fd.o \
					ft_putnbr_fd.o \
					ft_lstnew.o \
					ft_lstdelone.o \
					ft_lstdel.o \
					ft_lstadd.o \
					ft_lstiter.o \
					ft_lstmap.o \
					ft_isspace.o \
					ft_lstcreate.o \
					ft_lstpushback.o \
					ft_lstpushfront.o \
					ft_lstsize.o \
					ft_lstlast.o \
					ft_lstclear.o \
					ft_lstat.o \
					ft_lstreverse.o \
					ft_lstfind.o \
					ft_lstremoveif.o \
					ft_lstmerge.o \
					ft_lstdump.o \
					ft_lstsort.o \
					ft_abs.o \
					ft_isspace.o \
					ft_memalloc2.o \
					ft_ftoa.o \
					ft_ltoa.o \
					ft_lltoa.o \
					ft_memdup.o \
					ft_realloc.o \
					ft_strreplace.o \
					ft_split.o \
					ft_join.o \
					ft_quicksort.o \
					ft_strquicksort.o \
					ft_mergesort.o \
					ft_strmergesort.o \
					ft_char2dump.o \
					ft_int2dump.o \

OBJS			= $(patsubst %,$(SRCS)/%,$(_OBJS))
RM				= /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) 
	ar rc $(NAME) $^
	ranlib $(NAME)

$(SRCS)/%.o: %.c \
		$(CC) $(CFLAGS) -c $<

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
