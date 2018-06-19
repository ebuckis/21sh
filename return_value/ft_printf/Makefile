# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/21 14:37:00 by bpajot       #+#   ##    ##    #+#        #
#    Updated: 2018/03/21 10:56:28 by bpajot      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

TEST = test
NAME = libftprintf.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LFT_FLAGS = -L ../libft/ -lft
LIBS = ../libft/libft.a
PATH_SRCS = ./
PATH_OBJS = ./
PATH_LIBFT = ../libft/
PATH_INCS = ./
FILES = ft_printf.c ft_printf_type.c ft_printf_c.c ft_printf_d1.c  \
		ft_printf_d2.c ft_printf_e.c ft_printf_f.c ft_printf_g.c \
		ft_printf_n1.c ft_printf_n2.c ft_printf_o1.c ft_printf_o2.c \
		ft_printf_p.c ft_printf_s.c ft_printf_percent.c ft_printf_u1.c \
		ft_printf_u2.c ft_printf_x1.c ft_printf_x2.c ft_putwchar.c \
		ft_putstr_size.c ft_putchar_size.c ft_putwstr.c ft_wstrlen.c \
		ft_putnbr_size.c ft_putnbr_double.c ft_nbr_size.c ft_nbr_size_base.c \
		ft_putnbr_base.c parse.c parse2.c parse3.c ft_two_pow.c ft_two_pow2.c \
		ft_sum.c ft_sum2.c ft_round.c ft_putnbr_longdouble.c \
		ft_putnbr_double_sci.c ft_putnbr_double_sci2.c \
		ft_putnbr_longdouble_sci.c ft_putnbr_double_denormalized.c
FILES_LIBFT = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_swap.c ft_sort_integer_table.c ft_strrev.c \
		ft_is_prime.c ft_sqrt.c ft_concat_params.c get_next_line.c \
		ft_atoi_base.c ft_count_nb_words.c
SRCS = $(addprefix $(PATH_SRCS), $(FILES))
OBJS = $(addprefix $(PATH_OBJS), $(FILES:.c=.o))
OBJS_LIBFT = $(addprefix $(PATH_LIBFT), $(FILES_LIBFT:.c=.o))
INCS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	@make -C ../libft
	@echo "CREATION DE LA LIBFTPRINTF.A "
	ar rcs $@ $^

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INCS)
	$(CC) $(CC_FLAGS) -o $@ -c $<

clean:
	@make -C ../libft clean
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(OBJS_TEST)

fclean: clean
	@make -C ../libft fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)

re: fclean all
