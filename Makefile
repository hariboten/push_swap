# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/11 14:34:50 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src/
SRCNAMES = \
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)
INCLUDEDIR = ./include/

LIBFTDIR = ./libft/
LIBFT = libft.a
LIBDLISTDIR = ./libslist/
LIBDLIST = libdlist.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDEDIR)  -g -O0

all : $(OBJDIR) $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(LIBDLIST)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFTDIR) -L $(LIBDLISTDIR) -lft -ldlist

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT)
	make -C $(LIBFTDIR)

$(LIBDLIST)
	make -C $(LIBDLISTDIR)

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
