# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/18 16:22:51 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src/
SRCNAMES = main.c \
		   push_swap.c \
		   dfs_sort.c \
		   ps_init.c \
		   coordinate_compression.c \
		   qsorti.c \
		   list_util.c \
		   op_func_swap.c \
		   op_func_push.c \
		   op_func_rotate.c \
		   op_func_rev_rotate.c \
		   print_debug.c \
		   ps_operate.c \
		   ps_divaconq.c

SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)
INCLUDEDIR = ./include/

LIBFTDIR = ./libft/
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDEDIR)  -g -O0

all : $(OBJDIR) $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFTDIR) -lft

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re : fclean all

.phony: all fclean clean re
