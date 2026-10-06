# Output Name:
NAME:=		libft.a

# Folders
BUILD:=		./build
TESTS:=		./test
SOURCE:=	./src

# Other variables:
COMPILER:=	cc
COMPFLAGS:=	-Wall -Werror -Wextra -g -c

# Source Files:
SRCFILES =	\
			check/ft_2d_array_size.c \
			check/ft_isalnum.c \
			check/ft_isalpha.c \
			check/ft_isascii.c \
			check/ft_isdigit.c \
			check/ft_isdouble.c \
			check/ft_isnumeric.c \
			check/ft_isprint.c \
 \
			convert/ft_atof.c \
			convert/ft_atoi.c \
			convert/ft_atoi_base.c \
			convert/ft_atol.c \
			convert/ft_itoa.c \
			convert/ft_limit.c \
			convert/ft_split.c \
			convert/ft_tolower.c \
			convert/ft_toupper.c \
 \
			env/debug_env.c \
			env/env_utils.c \
			env/setup_env.c \
 \
			list/changing/ft_lstadd_back.c \
			list/changing/ft_lstadd_front.c \
			list/changing/ft_lstclear.c \
			list/changing/ft_lstdelone.c \
			list/changing/ft_lstnew.c \
			list/changing/ft_unique_insert.c \
 \
			list/function/ft_lstiter.c \
			list/function/ft_lstmap.c \
 \
			list/information/ft_lst_cmp.c \
			list/information/ft_lstextract.c \
			list/information/ft_lstfind.c \
			list/information/ft_lstfirst.c \
			list/information/ft_lstlast.c \
			list/information/ft_lstsize.c \
 \
			memory/manipulation/ft_bzero.c \
			memory/manipulation/ft_char_rep.c \
			memory/manipulation/ft_free_2dstr.c \
			memory/manipulation/ft_memccpy.c \
			memory/manipulation/ft_memchr.c \
			memory/manipulation/ft_memcmp.c \
			memory/manipulation/ft_memcpy.c \
			memory/manipulation/ft_memmove.c \
			memory/manipulation/ft_memset.c \
 \
			memory/persistent/ft_calloc.c \
			memory/persistent/ft_malloc.c \
			memory/persistent/ft_memory_pool.c \
			memory/persistent/ft_realloc.c \
			memory/persistent/memory_anchors.c \
			memory/persistent/memory_cleanup.c \
 \
			print/ft_printf/debug.c \
			print/ft_printf/flag_handling.c \
			print/ft_printf/flag_reading.c \
			print/ft_printf/handlers_1.c \
			print/ft_printf/handlers_2.c \
			print/ft_printf/handlers_3.c \
			print/ft_printf/padding.c \
			print/ft_printf/print_utils.c \
			print/ft_printf/storage.c \
 \
			print/ft_color.c \
			print/ft_color_basics.c \
			print/ft_printf.c \
			print/ft_printfile.c \
			print/ft_putchar_fd.c \
			print/ft_putendl_fd.c \
			print/ft_putnbr_base.c \
			print/ft_putnbr_fd.c \
			print/ft_putstr_fd.c \
 \
			reading/get_next_line.c \
			reading/read_file.c \
 \
			string/ft_formatSpaces.c \
			string/ft_str_not_trim.c \
			string/ft_str_sed.c \
			string/ft_strchr.c \
			string/ft_strdup.c \
			string/ft_striteri.c \
			string/ft_strjoin.c \
			string/ft_strlcat.c \
			string/ft_strlcpy.c \
			string/ft_strlen.c \
			string/ft_strmapi.c \
			string/ft_strmerge.c \
			string/ft_strncmp.c \
			string/ft_strnstr.c \
			string/ft_strrchr.c \
			string/ft_strtrim.c \
			string/ft_substr.c \
 \
			vector/addition.c \
			vector/angle.c \
			vector/comparison.c \
			vector/cross_product.c \
			vector/dot_product.c \
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
TEST:=		$(SRCS:$(SOURCE)/%.c=$(TESTS)/%.out)
LOGS:=		$(TEST:$(TESTS)/%.out=$(TESTS)/%.log)
NAME:=		./$(NAME)
OS:=		$(shell uname -s)

.PHONY: all clean fclean re

all:
	make -j $(shell nproc) $(NAME)

$(TEST): $(TESTS)/%.out : $(SOURCE)/%.c
	@if grep -q "#ifdef TEST" $<; then \
		mkdir -p $(dir $@); \
		$(CC) $(NAME) -D TEST=1 $< -o $@; \
	fi

$(LOGS): $(TESTS)/%.log : $(TESTS)/%.out
	@if [ -f $< ]; then \
		./$< > $@ 2>&1; \
	fi

$(OBJS): $(BUILD)%.o : $(SOURCE)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 

clean:
	$(RM) -r $(BUILD)
	$(RM) -r $(TESTS)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

test: re
	make -j $(shell nproc) $(TEST)
	make -j $(shell nproc) $(LOGS)
