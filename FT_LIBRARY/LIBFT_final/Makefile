# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 18:19:48 by zzaludov          #+#    #+#              #
#    Updated: 2023/02/09 22:13:57 by zzaludov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c \
	ft_atoi.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
	ft_bzero.c ft_isprint.c ft_memset.c ft_strlen.c	ft_toupper.c \
	ft_isalnum.c ft_memchr.c ft_strncmp.c ft_isalpha.c \
	ft_memcmp.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_itoa.c ft_strtrim.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_split.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

CC = cc
RM = rm -f
AR = ar rc
HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ${HEADER}
	@${CC} ${CFLAGS} -c ${SRCS} ${BSRCS}

$(NAME): $(OBJS)
	@${AR} ${NAME} ${OBJS}
	
bonus: $(NAME)
	@${AR} ${NAME} ${BOBJS}
	
clean:
	@${RM} ${OBJS} ${BOBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all


.PHONY: all bonus clean fclean re
