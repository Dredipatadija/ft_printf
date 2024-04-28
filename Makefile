# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 19:52:09 by arenilla          #+#    #+#              #
#    Updated: 2024/04/28 13:29:17 by arenilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAMEB = libftprintf_bonus.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = Mandatory

SRCB_DIR = Bonus

SRC_FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c\
			ft_putptr.c ft_check.c ft_putunbr.c

SRCB_FILES = ft_printf_bonus.c ft_print_unbr_bonus.c ft_print_str_bonus.c\
			 ft_print_ptr_bonus.c ft_print_char_bonus.c ft_print_hex_bonus.c\
			 ft_print_nbr_bonus.c ft_padwidth_bonus.c ft_errorstr_bonus.c\
			 ft_check_bonus.c ft_padprecis_bonus.c ft_precision.c

SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

SOURCESB = $(addprefix $(SRCB_DIR)/, $(SRCB_FILES))\
		   $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSB = $(SOURCESB:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJECTS)

bonus: $(NAMEB)

$(NAMEB): $(OBJECTSB)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAMEB)
	ar -crs $(NAMEB) $(OBJECTSB)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS) $(OBJECTSB)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus
