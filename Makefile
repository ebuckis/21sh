# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/06 14:53:11 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/07/25 17:22:38 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = 21sh

WFLAGS = -Wall -Wextra -Werror -g

SRC_PATH	=	./
INC_PATH	=	./includes/
OBJ_PATH	=	./obj/
LIB_PATH	=	./libft/
EDIT_PATH	=	./edition/
PARSE_PATH	=	./parser/
EXEC_PATH	=	./exec/

SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC =		-I $(LIB_PATH)		\
			-I $(EDIT_PATH)		\
			-I $(PARSE_PATH)	\
			-I $(EXEC_PATH)

OBJ_NAME = $(N_SRCS:.c=.o)

N_SRCS =	main.c

LIB_A =		-L $(LIB_PATH) -lft			\
			-L $(PARSE_PATH) -lparser	\
			-L $(EDIT_PATH) -ledition	\
			-L $(EXEC_PATH) -lexec		\
			-ltermcap

all : $(NAME)

$(NAME):	$(OBJ)
			@make -C $(PARSE_PATH)
			@make -C $(EDIT_PATH)
			@make -C $(EXEC_PATH)
			@gcc $(WFLAGS) $(OBJ) $(INC) $(LIB_A) -o $(NAME)
			#@make -C $(LIB_PATH)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH)
			@gcc -c $(FLAGS) $(INC) -o $@ $<
	
clean :
			@make -C $(PARSE_PATH) clean
			@make -C $(EDIT_PATH) clean
			@make -C $(EXEC_PATH) clean
			@rm -rf $(OBJ_PATH)
			#@make -C $(LIB_PATH) clean

fclean : 	clean
			@make -C $(PARSE_PATH) fclean
			@make -C $(EDIT_PATH) fclean
			@make -C $(EXEC_PATH) fclean
			@rm -rf $(NAME)
			#@make -C $(LIB_PATH) fclean

re : fclean clean all
