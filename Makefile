# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 15:21:48 by jrichard          #+#    #+#              #
#    Updated: 2017/04/14 22:51:09 by jrichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = libft/libft.a

SRC = ft_printf.c parse_str.c checks.c flags.c conversion.c length_modifier.c \
	  convert_s.c convert_s2.c convert_d_i.c convert_DOU.c convert_c.c \
	  convert_u.c convert_x.c convert_x2.c convert_o.c convert_p.c \
	  convert_c2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all : $(LIBFT) $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) :
	gcc -c $(SRC) $(CFLAGS) -I$(LIBFT_DIR) -L$(LIBFT)
	ar rc $@ $(OBJ)
	ranlib $@
	libtool -static -o $(NAME) $(LIBFT) $(NAME)

clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : $(LIBFT)
