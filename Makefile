# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krutten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 00:43:56 by krutten           #+#    #+#              #
#    Updated: 2019/05/14 01:15:40 by krutten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

SRCS=event_handling.c compute.c initialise.c main.c\
	palettes.c window_finish_palettes.c window_finish.c

OBJS=${SRCS:.c=.o} 

HEADERS=fractal.h

FLAGS= -Wall -Wextra -Werror -Ofast

LIBRARIES=-L minilibx_macos -lmlx -L libft -lft

FRAMEWORKS=-framework OpenGl -framework Appkit

all: $(NAME)

$(NAME):
	#Compiling
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(FLAGS) -c $(SRCS) -I $(HEADERS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBRARIES) $(FRAMEWORKS)

clean:
	#Cleaning
	@/bin/rm -f $(OBJS)
	@make clean -C libft/
	@make clean -C minilibx_macos/

fclean: clean
	#Fcleaning
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

PHONY : fclean clean all re
