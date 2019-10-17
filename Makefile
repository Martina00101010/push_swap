# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 02:55:16 by pberge            #+#    #+#              #
#    Updated: 2019/10/17 06:12:22 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SORT = push_swap
CMPLR = gcc
WFLAGS = -Wall -Wextra -Werror

SORT_SRC_ = main.c 				\
			push_swap.c			\
			ft_prepare.c		\
			ft_print_stack.c	\
			ft_stack.c			\
			ft_sknew.c			\
			ft_skadd.c			\
			ft_skfree.c			\
			ft_sort.c			\
			ft_sklen.c			\
			ft_output.c			\
			ft_linksort.c

COMMON_SRC_ = ft_error.c

SORTF = src_push_swap/
COMMONF = common/
OBJF = obj/

SORT_SRC = $(addprefix $(SORTF), $(SORT_SRC_))
SORT_SRC += $(addprefix $(COMMONF), $(COMMON_SRC_))

SORT_OBJ_ = $(SORT_SRC_:.c=.o)
COMMON_OBJ_ = $(COMMON_SRC_:.c=.o)

SORT_OBJ = $(addprefix $(OBJF), $(SORT_OBJ_))
SORT_OBJ += $(addprefix $(OBJF), $(COMMON_OBJ_))

DEL = rm -rf

PFTF = ft_printf
LPFT = $(PFTF)/libftprintf.a

INC = -I inc -I libft -I ft_printf/inc
LIB = -L libft -lft -L ft_printf -lftprintf

all: $(SORT)

$(SORT): $(OBJF) $(SORT_OBJ) $(LPFT)
	$(CMPLR) $(INC) $(LIB) $(SORT_OBJ) -o $(SORT)

$(OBJF)%.o: $(SORTF)%.c
	$(CMPLR) $(INC) -c $< -o $@

$(OBJF)%.o: $(COMMONF)%.c
	$(CMPLR) $(INC) -c $< -o $@

$(OBJF):
	mkdir $(OBJF)

$(LPFT):
	make -C $(PFTF)

c:
	./push_swap "$(ruby -e 'puts (1..10).to_a.shuffle.join(" ")')"

clean:
	$(DEL) $(SORT_OBJ) $(COMMON_OBJ)
#	make clean -C libft
#	make clean -C $(PFTF) 

fclean:
	$(DEL) $(SORT_OBJ) $(COMMON_OBJ)
	$(DEL) $(SORT)
#	make fclean -C libft
#	make fclean -C $(PFTF)

re:
	make fclean all
