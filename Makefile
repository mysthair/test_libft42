# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:27:19 by jleblanc          #+#    #+#              #
#    Updated: 2016/11/30 16:39:18 by jleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test_libft

DIRH=./
DIRC=
DIRLIBFT=../libft/
DIRO=objs/

LIBFT=libft.a
LIBFTH=libft.h
HEADERS=$(LIBFTH) test_libft.h

CC=gcc
CFLAGS=-g -O0 -std=gnu11 -Wall -Wextra -Werror -I$(DIRH)

INCMD:=$(INCMD) $(shell if [ ! -f $(DIRLIBFT)ft_exit.c ]; then echo exit ;fi)
INCMD:=$(INCMD) $(shell if [ ! -f $(DIRLIBFT)ft_assert.c ]; then echo assert ;fi)
INCMD:=$(INCMD) $(shell if [ ! -f $(DIRLIBFT)ft_print_memory.c ]; then echo print_memory ;fi)
LOCALFUNCS:=$(INCMD)

#LOCALFUNCS = malloc free exit assert print_memory
#LOCALFILES=$(addprefix ft_, $(addsuffix .c, $(LOCALFUNCS)))
OBJS=$(addprefix $(DIRO)ft_, $(addsuffix .o, $(LOCALFUNCS)))

#testlocfunc:
#	echo "LOCALFUNCS=$(LOCALFUNCS)"
#	echo "OBJS=$(OBJS)"

TITLE="[ $@ : $? ] ------------------------------------------------------ "

all: test $(LIBFT)
	@echo "$(TITLE)"
	@echo "################################################################################"
	@echo "##                          $(LIBFT) testeur                                    ##"
	@echo "################################################################################"

$(LIBFTH):$(DIRLIBFT)$(LIBFTH)
	cp $(DIRLIBFT)$(LIBFTH) $(LIBFTH)

$(LIBFT): $(DIRLIBFT) $(LIBFTH)
	@echo "$(TITLE)"
	make -C $(DIRLIBFT) && cp -v $(DIRLIBFT)$(LIBFT) $(LIBFT)

#$(NAME) $(OBJS):$(HEADERS)

$(DIRO)%.o: %.c
	@echo "$(TITLE)"
	@mkdir -p objs
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@echo "$(TITLE)"
	rm -rf $(DIRO)

fclean: clean
	@echo "$(TITLE)"
	rm -f $(LIBFT) $(LIBFTH)
	rm -f *.e $(NAME)
	@rm -rf *.dSYM
	make -C $(DIRLIBFT) fclean 
re:
	@echo "$(TITLE)"
	make fclean
	make all
	make test
OS:=$(shell uname)
CPU:=$(shell uname -m)
ifeq ($(OS),Linux)
  HAVE_STRLCPY:=-DDONT_HAVE_STRLCPY
  MISSING_O=strlcat_$(CPU).o strnstr_$(CPU).o
else
  HAVE_STRLCPY:=-DHAVE_STRLCPY
  MISSING_O=
endif

$(NAME): test_libft.c $(LIBFT) $(OBJS) $(HEADERS)  $(MISSING_O)
ifeq ($(OS), Linux)
	@echo "Linux OS detected :P"
endif
	$(CC) $(CFLAGS) $(HAVE_STRLCPY) -o test_libft test_libft.c $(MISSING_O) $(LIBFT) $(OBJS) 

test: $(NAME)
	./$(NAME)	

testnorm:
	norminette $(DIRLIBFT)
	norminette $(DIRC)ft_*.c $(DIRH)*.h


