# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/29 11:17:43 by bpajot       #+#   ##    ##    #+#        #
#    Updated: 2018/06/19 09:43:28 by bpajot      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = return_value
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LFT_FLAGS = -L ../libft/ -lft -L ./ft_printf/ -lftprintf
PATH_SRCS = ./
PATH_OBJS = ./
PATH_INCS = ./
FILES = return_value.c fork.c execve.c
SRCS = $(addprefix $(PATH_SRCS), $(FILES))
OBJS = $(addprefix $(PATH_OBJS), $(FILES:.c=.o))
INCS = return_value.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./ft_printf
	@echo "CREATION DE L'EXECUTABLE MINISHELL"
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ $(LFT_FLAGS)

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INCS)
	$(CC) $(CC_FLAGS) -o $@ -c $<

clean:
	@make -C ./libft clean
	@make -C ./ft_printf clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./ft_printf fclean
	@/bin/rm -f $(NAME)

re: fclean all
