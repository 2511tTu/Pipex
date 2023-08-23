# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 22:31:02 by zzaludov          #+#    #+#              #
#    Updated: 2023/04/24 23:25:01 by zzaludov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = LIBFT_final
PRINTF = PRINTF_final
GNL = GET_NEXT_LINE_final
NAME = ft_library.a
.PHONY: all clean

all: get_next_line.a libftprintf.a libft.a $(NAME)

$(NAME): get_next_line.a libftprintf.a libft.a
	ar rcs $(NAME) objects/*.o
	mv $(NAME) ./..

libft.a: ${LIBFT}/Makefile
	cd ${LIBFT} && $(MAKE)
	mkdir -p objects
	cd ${LIBFT} && mv *.o ../objects
	echo "libft.a rule applied"

libftprintf.a: ${PRINTF}/Makefile
	cd ${PRINTF} && $(MAKE)
	mkdir -p objects
	cd ${PRINTF} && mv *.o ../objects
	echo "libftprintf.a rule applied"


get_next_line.a: ${GNL}/Makefile
	cd ${GNL} && $(MAKE)
	mkdir -p objects
	cd ${GNL} && mv *.o ../objects
	echo "gnl.a rule applied"


clean:
	 rm -rf objects

fclean: clean
	cd ${LIBFT} && $(MAKE) fclean
	cd ${PRINTF} && $(MAKE) fclean
	cd ${GNL} && $(MAKE) fclean

.PHONY: all announce clean fclean re libft.a libftprintf.a get_next_line.a




