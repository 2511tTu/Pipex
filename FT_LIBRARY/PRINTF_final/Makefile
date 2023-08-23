# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 15:59:53 by zzaludov          #+#    #+#              #
#    Updated: 2023/04/04 16:28:22 by zzaludov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_char.c ft_string.c ft_integer.c ft_unsig_int.c ft_itoa.c \
	ft_uitoa.c ft_hexa.c ft_ptr.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
AR = ar rc
HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c ${SRCS}

$(NAME): $(OBJS)
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
