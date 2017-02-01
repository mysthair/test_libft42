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



#####################################################################################
###   WIP
#####################################################################################
TESTS_FILES:=ft_strsub2.c ft_strnlen.c ft_exit.c ft_assert.c ft_print_memory.c \
 ft_split.c ft_isspace.c \
 ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
 ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
 ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
 ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
 ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
 ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
 ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
 ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
 ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
 ft_lstiter.c ft_lstmap.c

LIBOBJ:=$(TESTS_FILES:.c=.o)

truc:
	#for i in 1 2 3 4 5 6 7 8  9 ; do echo "$$i" ; done
	for f in $(LIBFILES) ; do touch test_$$f ; done
	ls test*.c
#####################################################################################
#####################################################################################
#####################################################################################

