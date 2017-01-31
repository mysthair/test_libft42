# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:27:19 by jleblanc          #+#    #+#              #
#    Updated: 2017/01/31 15:28:12 by jleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test_libft

DIRH=./
DIRC=
DIRLIBFT=libft_a_tester/
DIRO=objs/

LIBFT=libft.a
LIBFTH=libft.h
HEADERS=$(LIBFTH) test_libft.h

CC=gcc
CFLAGS=-Wall -Wextra -Werror -I$(DIRH)

#pour tester une libft protegée, on peut ajouter ce flag
#CFLAGS+=-DTEST_PROTECTED

MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_putaddr_fd.c ]; then echo putaddr_fd ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_putaddr.c ]; then echo putaddr ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_print_memory.c ]; then echo print_memory ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_exit.c ]; then echo exit ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_assert.c ]; then echo assert ;fi)
#LOCALFUNCS:=$(MISSFT)
LOCALFUNCS=

#OBJS=$(addprefix $(DIRO)ft_, $(addsuffix .o, $(LOCALFUNCS)))

OS:=$(shell uname)
CPU:=$(shell uname -m)
MISSING_O=$(addprefix $(DIRO)ft_, $(addsuffix _$(OS)_$(CPU).o, $(MISSFT)))
ifeq ($(OS),Linux)
  HAVE_STRLCPY:=-DDONT_HAVE_STRLCPY
MISSING_O:=$(MISSING_O) strlcat_$(CPU).o strnstr_$(CPU).o
else
  HAVE_STRLCPY:=-DHAVE_STRLCPY
endif

TITLE="[ $@ : $? ] ------------------------------------------------------ "

all: $(NAME) $(LIBFT)

$(LIBFTH):$(DIRLIBFT)$(LIBFTH)
	cp $(DIRLIBFT)$(LIBFTH) $(LIBFTH)

$(LIBFT): $(DIRLIBFT) $(LIBFTH)
	@echo "$(TITLE)"
	make -C $(DIRLIBFT) && cp -v $(DIRLIBFT)$(LIBFT) $(LIBFT)

$(NAME) $(OBJS):$(HEADERS)

$(DIRO)%.o: %.s
	@echo "$(TITLE)"
	@mkdir -p objs
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@echo "$(TITLE)"
	rm -rf $(DIRO) $(MISSING_O)
	make -C $(DIRLIBFT) clean 

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
	make

$(NAME): test_libft.c $(LIBFT) $(OBJS) $(HEADERS) $(MISSING_O)
ifeq ($(OS), Linux)
	@echo "Linux OS detected :P"
endif
	$(CC) $(CFLAGS) $(HAVE_STRLCPY) -o test_libft test_libft.c $(MISSING_O) -D__$(OS)__ -D__$(CPU)__ $(LIBFT) $(OBJS) 

test: $(NAME)
	./$(NAME)	

testnorm:
	norminette $(DIRLIBFT)
	norminette $(DIRC)ft_*.c $(DIRH)*.h

vg.log: test_libft
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-fd=1 ./test_libft> vg.log

memcheck: vg.log
	less vg.log

link:
	rm -f libft_a_tester
	ln -s ../libft libft_a_tester

link1:
	rm -f libft_a_tester
	ln -s ~/libft_a_tester

link2:
	rm -f libft_a_tester
	ln -s ~/tmp/libft_a_tester libft_a_tester
