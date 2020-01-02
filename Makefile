# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 13:40:06 by aazeroua          #+#    #+#              #
#    Updated: 2019/11/24 03:31:42 by iel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC  = main.c  open.c fdf.c  \
		get_next_line.c center.c error.c 
C       = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C libft
		@$(C) $(CFLAGS) libft/libft.a $(OBJ) -o $(NAME) \
		-L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

%.o	: %.c
		$(C) $(CFLAGS)  -o $@ -c $<

clean	:
		@make clean -C libft
		@rm -rf $(OBJ)

fclean	: clean
		@make fclean -C libft
		@rm -f $(NAME)

re	: fclean all