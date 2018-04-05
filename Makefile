# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/05 18:21:25 by mberedda          #+#    #+#              #
#    Updated: 2016/05/12 13:30:11 by mberedda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC  = ft_printf.c \
	  ./sources/ft_percent.c ./sources/istype_c.c ./sources/ft_whichflags.c \
	  ./sources/init_flags.c ./sources/ft_conv_unicode.c \
	  ./sources/ft_print_c.c ./sources/ft_print_char_c.c \
	  ./sources/ft_conv_hexa.c ./sources/ft_conv_octal.c \
	  ./sources/ft_cs.c ./sources/ft_print_char_s.c \
	  ./sources/ft_print_o_unsigned_number.c ./sources/ft_print_s.c \
	  ./sources/ft_print_signed_number.c ./sources/ft_putnbr_ll.c \
	  ./sources/ft_print_unsigned_number.c ./sources/ft_putstr_n.c \
	  ./sources/ft_size_arg_null.c ./sources/ft_size_arg_null_s.c \
	  ./sources/ft_ulltoa.c ./sources/ft_wchar_len.c \
	  ./sources/ft_whichflags.c ./sources/init_flags.c ./sources/intlen.c \
	  ./sources/istype_c.c ./sources/istype_d.c ./sources/istype_d_jz.c \
	  ./sources/istype_o.c ./sources/istype_o_jz.c ./sources/istype_s.c \
	  ./sources/istype_u.c ./sources/istype_x.c ./sources/uintlen.c \
	  ./sources/ft_strjoin_c.c ./sources/ft_size_sn.c ./sources/ft_conv.c \
	  ./sources/init_tab.c ./sources/ft_print_o_unsigned_number_bis.c \
	  ./sources/libft/ft_isdigit.c ./sources/libft/ft_putchar.c \
	  ./sources/libft/ft_putstr.c ./sources/libft/ft_strcat.c \
	  ./sources/libft/ft_strcmp.c ./sources/libft/ft_strdup.c \
	  ./sources/libft/ft_strjoin.c ./sources/libft/ft_strlen.c \
	  ./sources/libft/ft_strnew.c ./sources/libft/ft_strsub.c \
	  ./sources/libft/ft_strcpy.c

NOM  = $(basename $(SRC))

OBJ  = $(addsuffix .o, $(NOM))

CC   = gcc

FLAGS= -Wall -Wextra -Werror -I includes/ -I ./libft/includes

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./sources/libft/
	@ar rc $(NAME) $^
	@echo "SUCCESS"

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	@make -C ./sources/libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./sources/libft/ fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
