# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/06 14:53:11 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/06/15 11:44:59 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libparser.a

WFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LIB_PATH = ../libft/


SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = -I $(INC_PATH) -I $(LIB_PATH)

OBJ_NAME = $(N_SRCS:.c=.o)

N_SRCS =	ft_parser.c				\
			ft_antislash.c			\
			ft_init_parse.c			\
			ft_separator.c			\
			ft_is_separator.c		\
			ft_is_white.c			\
			ft_parse_dquote.c		\
			ft_parse_quote.c		\
			ft_parse_suite.c		\
			ft_save_struct.c		\
			ft_close_parse.c

all : $(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIB_PATH)
			@ar rc $(NAME) $(OBJ) 

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@gcc -c $(FLAGS) $(INC) -o $@ $<
	
clean :
		@make -C $(LIB_PATH) clean
		@rm -rf $(OBJ_PATH)

fclean : 	clean
			@make -C $(LIB_PATH) fclean
			@rm -rf $(NAME)

re : fclean clean all
