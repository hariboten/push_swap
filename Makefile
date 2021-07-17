# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/17 17:33:42 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src/
SRCNAMES = main.c\
		   push_swap.c\
		   ps_init.c\
		   coordinate_compression.c\
		   print_debug.c
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)
INCLUDEDIR = ./include/

LIBFTDIR = ./libft/
LIBFT = libft.a
LIBDLISTDIR = ./libdlist/
LIBDLIST = libdlist.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDEDIR)  -g -O0

all : $(OBJDIR) $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBDLISTDIR)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFTDIR) -lft -L $(LIBDLISTDIR) -ldlist

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(LIBDLISTDIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(LIBDLISTDIR)

re : fclean all

.phony: all fclean clean re
