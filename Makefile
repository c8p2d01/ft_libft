# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 11:15:21 by clems             #+#    #+#              #
#    Updated: 2021/08/31 00:16:52 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ_FILES = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
			ft_isdigit.o ft_isprint.o ft_memccpy.o ft_memcpy.o ft_memmove.o\
			ft_memset.o ft_memcmp.o ft_strchr.o ft_strlcat.o ft_strlcpy.o \
			ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_tolower.o \
			ft_toupper.o ft_calloc.o ft_memchr.o ft_strdup.o \
			\
			ft_itoa.o ft_putchar_fd.o ft_putnbr_fd.o ft_putendl_fd.o \
			ft_putstr_fd.o  ft_substr.o ft_strjoin.o ft_strtrim.o\
			ft_split.o ft_strmapi.o\
			\
			ft_log.o ft_c_e_set_bonus.o \
			ft_strncpy_bonus.o ft_lstprev_bonus.o ft_lstdup_bonus.o\
			ft_randnbr.o
#SRC = 		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
#			ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memcpy.c ft_memmove.c\
#			ft_memset.c ft_memcmp.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
#			ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
#			ft_toupper.c ft_calloc.c ft_memchr.c ft_strdup.c \
#			\
#			ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
#			ft_putstr_fd.c  ft_substr.c ft_strjoin.c ft_strtrim.c\
#			ft_split.c ft_strmapi.c\
#			\
#			ft_ndigit_bonus.c ft_c_e_set_bonus.c \
#			ft_strncpy_bonus.c ft_lstprev_bonus.c ft_lstdup_bonus.c
BONUS_FILES =	ft_lstadd_back.o ft_lstadd_front.o ft_lstlast.o ft_lstnew.o\
				ft_lstsize.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o\
				ft_lstmap.o
HEADER_FILES = libft.h
CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) -c -Wall -Werror -Wextra -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(BONUS_FILES)

fclean: clean
	rm -f $(Name)

re: fclean all

bonus: $(OBJ_FILES) $(BONUS_FILES)
	ar rcs $(NAME) $(OBJ_FILES) $(BONUS_FILES)

.PHONY: all clean fclean re bonus

#so:
#	$(CC) -nostartfiles -fPIC -Wall -Werror -Wextra $(SRC)
#	gcc -nostartfiles -shared -o libft.so $(OBJ_FILES)
