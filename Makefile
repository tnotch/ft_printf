# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 17:58:15 by kirilltruha       #+#    #+#              #
#    Updated: 2021/01/17 23:17:07 by kirilltruha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = ft_printf.c \
	ft_output_d.c \
	ft_output_c.c \
	ft_output_p.c \
	ft_output_perc.c \
	ft_output_s.c \
	ft_output_u.c \
	ft_output_x.c \
	ft_parse_string.c

gcc = gcc -c -Wall -Werror -Wextra

obj = ${src:.c=.o}

name = libftprintf.a

rm = rm -f

.c.o:
	${gcc} $< -o ${<:.c=.o}

all: ${name}

${name}: ${obj}
		make -C libft
		cp	libft/libft.a ${name}
		ar -rcs ${name} ${obj}
		
clean: 
	make clean -C libft
	$(RM) $(obj)

fclean: clean
	$(RM) ${name}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re