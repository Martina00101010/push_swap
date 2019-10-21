# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 02:55:16 by pberge            #+#    #+#              #
#    Updated: 2019/10/21 11:48:35 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SORT = push_swap
CHEC = checker
CMPLR = gcc
WFLAGS = -Wall -Wextra -Werror

SORT_SRC_ = main.c 				\
			push_swap.c			\
			ft_prepare.c		\
			ft_linksort.c		\
			ft_toss_eval.c		\

COMMON_SRC_ = ft_error.c		\
			  ft_get_ints.c		\
			  ft_fill_sk.c		\
  			  ft_stack.c		\
  			  ft_sknew.c		\
  			  ft_skadd.c		\
  			  ft_skfree.c		\
  			  ft_sklen.c		\
  			  ft_output.c		\
			  ft_issorted.c

CHEC_SRC_ = main.c				\
			ft_apply.c			\
			ft_answer.c

SORTF = src_push_swap/
COMMONF = common/
OBJFS = obj_ps/
OBJFC = obj_ch/
CHECF = src_checker/

SORT_SRC = $(addprefix $(SORTF), $(SORT_SRC_))
SORT_SRC += $(addprefix $(COMMONF), $(COMMON_SRC_))
CHEC_SRC = $(addprefix $(CHECF), $(CHEC_SRC_))
CHEC_SRC += $(addprefix $(COMMONF), $(COMMON_SRC_))

SORT_OBJ_ = $(SORT_SRC_:.c=.o)
COMMON_OBJ_ = $(COMMON_SRC_:.c=.o)
CHEC_OBJ_ = $(CHEC_SRC_:.c=.o)

SORT_OBJ = $(addprefix $(OBJFS), $(SORT_OBJ_))
SORT_OBJ += $(addprefix $(OBJFS), $(COMMON_OBJ_))
CHEC_OBJ = $(addprefix $(OBJFC), $(CHEC_OBJ_))
CHEC_OBJ += $(addprefix $(OBJFC), $(COMMON_OBJ_))

DEL = rm -rf

PFTF = ft_printf
LPFT = $(PFTF)/libftprintf.a

INC = -I inc -I ft_printf/libft -I ft_printf/inc
LIB = -L ft_printf/libft -lft -L ft_printf -lftprintf

all: $(CHEC) $(SORT)

$(SORT): $(OBJFS) $(SORT_OBJ) $(LPFT)
	$(CMPLR) $(WFLAGS) $(INC) $(LIB) $(SORT_OBJ) -o $(SORT)

$(CHEC): $(OBJFC) $(CHEC_OBJ) $(LPFT)
	$(CMPLR) $(WFLAGS) $(INC) $(LIB) $(CHEC_OBJ) -o $(CHEC)

$(OBJFC)%.o: $(CHECF)%.c
	$(CMPLR) $(INC) -c $< -o $@

$(OBJFS)%.o: $(SORTF)%.c
	$(CMPLR) $(INC) -c $< -o $@

$(OBJFS)%.o: $(COMMONF)%.c
	$(CMPLR) $(INC) -c $< -o $@

$(OBJFC)%.o: $(COMMONF)%.c
	$(CMPLR) $(INC) -c $< -o $@

$(OBJFS):
	@mkdir $(OBJFS)

$(OBJFC):
	@mkdir $(OBJFC)

$(LPFT):
	@make -C $(PFTF)

c:
	./push_swap "$(ruby -e 'puts (1..10).to_a.shuffle.join(" ")')"

clean:
	@$(DEL) $(SORT_OBJ) $(COMMON_OBJ)
	@$(DEL) $(CHEC_OBJ) $(COMMON_OBJ)
#	make clean -C libft
#	make clean -C $(PFTF) 

fclean:
	@$(DEL) $(SORT_OBJ) $(COMMON_OBJ)
	@$(DEL) $(SORT)
	@$(DEL) $(CHEC_OBJ) $(COMMON_OBJ)
	@$(DEL) $(CHEC)
#	make fclean -C libft
#	make fclean -C $(PFTF)

re:
	@make fclean all
