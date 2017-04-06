# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhy0u <jsn.centaure@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 20:30:33 by rhy0u             #+#    #+#              #
#    Updated: 2017/02/13 20:12:16 by jcentaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CFLAGS	=	-Wall -Werror -Wextra -I. -c
SRC		=	ft_memset.c ft_bzero.c ft_tolower.c ft_toupper.c ft_isprint.c \
			ft_isascii.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
			ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_strchr.c ft_strdup.c ft_strrchr.c ft_strcpy.c ft_strcat.c \
			ft_strncat.c ft_strncpy.c ft_strtrim.c ft_strsub.c ft_strnew.c \
			ft_strnequ.c ft_strmapi.c ft_strmap.c ft_strlcat.c ft_strjoin.c \
			ft_striteri.c ft_striter.c ft_strequ.c ft_strdel.c ft_memdel.c \
			ft_strclr.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar.c \
			ft_memalloc.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_itoa.c ft_strrev.c ft_strsplit.c ft_lstnew.c \
			ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_lstadd.c \
			ft_swap.c ft_putstrcol.c ft_color.c ft_strcount.c ft_strjoinf.c \
			ft_strsubf.c ft_strmem.c get_next_line.c \

OBJ = $(SRC:%.c=%.o)

RST = \x1B[0m
RED = \x1B[31m
GRN = \x1B[32m
YEL = \x1B[33m
BLU = \x1B[34m
MAG = \x1B[35m
CYN = \x1B[36m
WHT = \x1B[37m

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): test $(OBJ)
	@echo "$(RED)   -Compilation de la libft$(RST)\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GRN)DONE !$(RST)"

test:
	@echo "$(RED)   -Compilation des fonctions...$(RST)\n"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<
clean:
	@echo "$(RED)   -Clean$(RST)\n"
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "$(RED)   -Fclean$(RST)\n"
	@/bin/rm -f $(NAME)

re: fclean all


