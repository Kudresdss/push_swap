# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 13:49:23 by ymirna            #+#    #+#              #
#    Updated: 2022/03/25 17:04:53 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

PATH_M		=	mandatory/

PATH_B		=	bonus/

PATH_H		=	headers/

SRC_M		=	main.c push_swap.c functs.c functs_list.c split.c \
				sorting_1.c sorting_2.c sorting_op_1.c sorting_op_2.c \
				sort_int.c

SRC_B		= 	checker_bonus.c functs_bonus.c functs_list_bonus.c get_next_line_bonus.c \
				get_next_line_utils_bonus.c push_swap_bonus.c sort_int_bonus.c \
				sorting_1_bonus.c sorting_2_bonus.c sorting_op_1_bonus.c sorting_op_2_bonus.c split_bonus.c

HEADER		=	push_header.h push_header_bonus.h

SRC_M_P		=	$(addprefix $(PATH_M), $(SRC_M))

SRC_B_P		=	$(addprefix $(PATH_B), $(SRC_B))

HEADER_P	=	$(addprefix $(PATH_H), $(HEADER))

OBJS_M		=	$(SRC_M_P:%.c=%.o)

OBJS_B		=	$(SRC_B_P:%.c=%.o)

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

.PHONY:		all bonus re clean fclean

%.o : %.c	$(HEADER_P)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS_M) Makefile
			$(CC) $(FLAGS) $(OBJS_M) -o $(NAME)

bonus:		
			@make OBJS_M="$(OBJS_B)" NAME="checker" all

clean:		
			rm -f $(OBJS_M)
			rm -f $(OBJS_B)

fclean:		clean
			rm -f $(NAME)
			rm -f checker

re:			fclean all