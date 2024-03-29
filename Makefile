# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 19:22:56 by lmakynen          #+#    #+#              #
#    Updated: 2021/01/24 21:13:14 by lmakynen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE_DIR = source/

SOURCE_FILES = ft_printf.c conversion.c modifier.c char_conv.c str_conv.c \
	int_conv.c helper.c hexa_conv.c octal_conv.c pointer_conv.c length_mod.c \
	unsigned_conv.c percent_conv.c float_conv.c helper_float.c

SOURCE = $(addprefix $(SOURCE_DIR), $(SOURCE_FILES))

OFILES = $(subst .c,.o,$(SOURCE_FILES))

INCLUDES = -I ./includes/ -I ./libft/libft.h

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SOURCE)
	@ make compile_libft
	@ cp $(LIBFT) ./$(NAME)
	@ gcc $(FLAGS) $(INCLUDES) -c $(SOURCE)
	@ ar rc $(NAME) $(OFILES)
	@ ranlib $(NAME)

compile_libft:
	@ make -s fclean -C ./libft && make -s -C ./libft

clean:
	@ rm -f $(OFILES)
	@ make -s clean -C ./libft

fclean: clean
	@ rm -f $(NAME)
	@ make -s fclean -C ./libft

re: fclean all

fresh: re
	@ rm -f $(OFILES)
	@ make -s clean -C ./libft