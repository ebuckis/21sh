# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/21 14:37:00 by bpajot       #+#   ##    ##    #+#        #
#    Updated: 2018/01/24 08:13:04 by bpajot      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_SRCS = ./
PATH_OBJS = ./
PATH_INCS = ./
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
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
INCS = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	@echo "CREATION DE LA LIBFT "
	@ar rcs $@ $^
	@echo "👍  COMPILATION REUSSIE 👍\ "

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INCS)
	@echo "CREATION $@ "
	@$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "👍  COMPILATION REUSSIE 👍\ "

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
