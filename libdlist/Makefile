# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/09 11:32:03 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libdlist.a
SRCDIR = ./src/
SRCNAMES = \
		   dlist.c \
		   ref.c \
		   push.c \
		   pop.c \
		   operate.c
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
INCLUDEDIR =  ./include/
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0

AR = ar
ARFLAGS = -rc

all : $(OBJDIR) $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -I $(INCLUDEDIR) -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.phony: all fclean clean re
