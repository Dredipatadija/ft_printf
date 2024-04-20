# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 19:52:09 by arenilla          #+#    #+#              #
#    Updated: 2024/04/20 21:56:59 by arenilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = Mandatory

SRC_FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c\
			ft_putptr.c ft_check.c ft_putunbr.c

SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJECTS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
