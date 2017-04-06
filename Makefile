# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 16:42:43 by jcentaur          #+#    #+#              #
#    Updated: 2017/04/06 05:50:00 by jcentaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = textures.c \
	  event.c \
	  wolf.c \
	  draw.c \
	  main.c \
	  map.c \

INCLUDE = 

OBJ = $(SRC:%.c=%.o)

FLAGO = -Wall -Werror -Wextra -Ofast

NAME = wolf3d

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(OBJ) -framework SDL2 $(INCLUDE) -L./libft -lft

%.o:%.c
	gcc -o $@ $(FLAGO) -c $<

clean:
	make fclean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
