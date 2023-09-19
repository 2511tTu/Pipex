# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 14:49:13 by zzaludov          #+#    #+#              #
#    Updated: 2023/07/25 14:49:17 by zzaludov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CFLAGS	:= -Wextra -Wall -Werror

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	@make -C FT_LIBRARY --no-print-directory
	@$(CC) $(OBJS) ft_library.a -o $(NAME)
	@echo "$(NAME) built successfully"

clean:
	@rm -f $(OBJS)
	@cd FT_LIBRARY && $(MAKE) clean --no-print-directory

fclean: clean
	@rm -f $(NAME) ft_library.a
	@cd FT_LIBRARY && $(MAKE) fclean --no-print-directory
	
re: clean all

.PHONY: all, clean, fclean, re
