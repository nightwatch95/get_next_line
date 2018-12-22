# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 21:22:33 by vjacks            #+#    #+#              #
#    Updated: 2018/11/24 18:17:05 by vjacks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HEADERS = libft.h
FUNC_1 = 	ft_memset.c 	ft_bzero.c 		ft_memcpy.c 	\
			ft_memccpy.c 	ft_memmove.c 	ft_memchr.c 	\
			ft_memcmp.c 	ft_strcmp.c 	ft_strncmp.c 	\
			ft_strlen.c 	ft_strdup.c 	ft_strcpy.c 	\
			ft_strncpy.c 	ft_toupper.c 	ft_tolower.c 	\
			ft_isdigit.c 	ft_atoi.c 		ft_isalpha.c 	\
			ft_isalnum.c 	ft_isascii.c 	ft_isprint.c 	\
			ft_strcat.c 	ft_strncat.c 	ft_strstr.c 	\
			ft_strnstr.c 	ft_strchr.c 	ft_strrchr.c 	\
			ft_strlcat.c 	

FUNC_2 = 	ft_memalloc.c 		ft_memdel.c 	ft_strnew.c 	\
		 	ft_strdel.c 		ft_strclr.c 	ft_striter.c 	\
		 	ft_striteri.c 		ft_strmap.c 	ft_strmapi.c 	\
		 	ft_strequ.c 		ft_strnequ.c 	ft_strsub.c 	\
		 	ft_strjoin.c 		ft_strsplit.c 	ft_itoa.c 		\
		 	ft_putchar.c 		ft_putstr.c 	ft_putendl.c 	\
		 	ft_putnbr.c 		ft_putchar_fd.c ft_putstr_fd.c	\
		 	ft_putendl_fd.c 	ft_putnbr_fd.c 	ft_strtrim.c

FUNC_BONUS = ft_lstnew.c 		ft_lstdelone.c 	ft_lstdel.c 	\
			 ft_lstadd.c 		ft_lstiter.c 	ft_lstmap.c

FUNC_ADD = 	get_num_categories.c 	ft_count_if.c 	list_pushback.c \
			is_whitespace.c 		ft_foreach.c

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) -I $(HEADERS) $(FUNC_1) $(FUNC_2) $(FUNC_BONUS) $(FUNC_ADD)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f *.a

re:	fclean all
