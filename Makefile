# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 16:22:31 by agirona           #+#    #+#              #
#    Updated: 2021/11/23 16:23:03 by agirona          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_memcmp.c ft_putendl_fd.c ft_strchr.c ft_strmapi.c ft_substr.c \
		  ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_tolower.c \
		  ft_calloc.c ft_isprint.c ft_memmove.c ft_putnbr_fd.c ft_strjoin.c \
		  ft_toupper.c ft_isalnum.c ft_itoa.c ft_memset.c ft_strlcat.c ft_strnstr.c \
		  ft_isalpha.c ft_memccpy.c ft_putstr_fd.c ft_strlcpy.c ft_strrchr.c \
		  ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_split.c ft_strlen.c ft_strtrim.c \
		  ft_abs.c ft_longlen.c ft_ischar.c ft_strnew.c ft_putchar.c ft_putstr.c \
		  ft_putnbr.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c  ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		  ft_sort_int_tab.c ft_swap.c ft_putstr_non_printable.c ft_putnbr_base.c \
		  ft_strncpy.c get_next_line.c get_next_line_utils.c ft_strcmp.c new_malloc.c \
		  new_ternaire.c ft_long_atoi.c ft_atoi_check.c ft_iswhitespace.c

OBJS	= $(SRCS:.c=.o)

INC		= .

CFLAGS	= -Wall -Wextra -Werror -I $(INC)

%.o: %.c $(INC)/libft.h
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) :	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
