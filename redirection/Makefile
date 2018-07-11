# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/29 11:17:43 by bpajot       #+#   ##    ##    #+#        #
#    Updated: 2018/07/11 16:48:43 by bpajot      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = redirec
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LFT_FLAGS = -L ../libft/ -lft
PATH_SRCS = ./
PATH_OBJS = ./
PATH_INCS = ./
FILES = redirec.c manage_redir.c execve.c
SRCS = $(addprefix $(PATH_SRCS), $(FILES))
OBJS = $(addprefix $(PATH_OBJS), $(FILES:.c=.o))
INCS = redirec.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../libft
	@echo "CREATION DE L'EXECUTABLE MINISHELL"
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ $(LFT_FLAGS)

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INCS)
	$(CC) $(CC_FLAGS) -o $@ -c $<

clean:
	@make -C ../libft clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C ../libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
