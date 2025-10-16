# Output Name:
NAME:=		libft.a

# Folders
BUILD:=		./build
SOURCE:=	./src

# Other variables:
COMPILER:=	cc
COMPFLAGS:=	-Wall -Werror -Wextra -g -c

# Source Files:
SRCFILES =	mem/ft_calloc.c \
		mem/ft_free_2dstr.c \
		mem/ft_bzero.c \
		mem/ft_memset.c \
		mem/ft_memcpy.c \
		mem/ft_memccpy.c \
		mem/ft_memmove.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_char_rep.c \
		mem/memory.c \
		string/ft_realloc.c \
		\
		env/setup_env.c \
		env/debug_env.c \
		env/env_utils.c \
		\
		check/ft_isalpha.c \
		check/ft_isdigit.c \
		check/ft_isalnum.c \
		check/ft_isascii.c \
		check/ft_isprint.c \
		check/ft_isnumeric.c \
		check/ft_isdouble.c \
		check/ft_2d_array_size.c \
		\
		convert/ft_atof.c \
		convert/ft_atoi.c \
		convert/ft_atoi_base.c \
		convert/ft_itoa.c \
		convert/ft_toupper.c \
		convert/ft_tolower.c \
		convert/ft_split.c \
		convert/ft_limit.c \
		\
		string/ft_formatSpaces.c \
		string/ft_str_sed.c \
		string/ft_strlen.c \
		string/ft_strlcpy.c \
		string/ft_strlcat.c \
		string/ft_strchr.c \
		string/ft_strrchr.c \
		string/ft_strnstr.c \
		string/ft_strncmp.c \
		string/ft_strdup.c \
		string/ft_substr.c \
		string/ft_strjoin.c \
		string/ft_strtrim.c \
		string/ft_str_not_trim.c \
		string/ft_strmapi.c \
		string/ft_striteri.c \
		\
		print/ft_color.c \
		print/ft_color_basics.c \
		print/ft_printfile.c \
		print/ft_putchar_fd.c \
		print/ft_putstr_fd.c \
		print/ft_putendl_fd.c \
		print/ft_putnbr_fd.c \
		print/ft_putnbr_base.c \
		\
		print/ft_printf/flag_handling.c \
		print/ft_printf/flag_reading.c \
		print/ft_printf/handlers_1.c \
		print/ft_printf/handlers_2.c \
		print/ft_printf/handlers_3.c \
		print/ft_printf/padding.c \
		print/ft_printf/print_utils.c \
		print/ft_printf/storage.c \
		print/ft_printf/debug.c \
		print/ft_printf.c \
		\
		lst/ft_lstnew.c \
		lst/ft_lstadd_front.c \
		lst/ft_lstsize.c \
		lst/ft_lstlast.c \
		lst/ft_lstfirst.c \
		lst/ft_lstadd_back.c \
		lst/ft_lstdelone.c \
		lst/ft_lstclear.c \
		lst/ft_lstiter.c \
		lst/ft_lstmap.c \
		\
		gnl/get_next_line.c \
		\
		graph/ft_graph.c \
		graph/ft_link.c \
		\
		vector/addition.c \
		vector/angle.c \
		vector/cross_product.c \
		vector/dot_product.c \
		vector/ft_vector.h \
		vector/multiplication.c \
		vector/new_vec.c \
		vector/normalise.c \
		vector/resize.c \
		vector/rotate.c \
		vector/subtraction.c \
		vector/veclen.c \


# Process Variables
CC:=		$(COMPILER)
CFLAGS:=	$(COMPFLAGS)
SRCS:=		$(addprefix $(SOURCE)/,$(SRCFILES))
OBJS:=		$(SRCS:$(SOURCE)/%.c=$(BUILD)/%.o)
NAME:=		./$(NAME)
OS:=		$(shell uname -s)

.PHONY: all clean fclean re

all:
	make -j $(nproc) $(NAME)

$(OBJS): $(BUILD)%.o : $(SOURCE)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 

clean:
	$(RM) -r $(BUILD)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

bonus: all
