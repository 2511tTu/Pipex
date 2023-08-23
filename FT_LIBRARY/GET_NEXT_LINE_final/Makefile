# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 23:00:51 by zzaludov          #+#    #+#              #
#    Updated: 2023/04/24 23:02:23 by zzaludov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
AR = ar rc
HEADER = get_next_line.h

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
