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
DIRS=jllib/
DIRTESTS=tests/

LIBFT=libft.a
LIBFTH=libft.h
HEADERS=$(LIBFTH) test_libft.h

MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_putaddr_fd.c ]; then echo putaddr_fd ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_putaddr.c ]; then echo putaddr ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_print_memory.c ]; then echo print_memory ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_exit.c ]; then echo exit ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(DIRLIBFT)ft_assert.c ]; then echo assert ;fi)

OS:=$(shell uname)
CPU:=$(shell uname -m)
MISSING_O=$(addprefix $(DIRO)ft_, $(addsuffix _$(OS)_$(CPU).o, $(MISSFT)))
ifeq ($(OS),Linux)
  HAVE_STRLCPY:=-DDONT_HAVE_STRLCPY
MISSING_O:=$(MISSING_O) $(DIRO)strlcat_$(CPU).o $(DIRO)strnstr_$(CPU).o
else
  HAVE_STRLCPY:=-DHAVE_STRLCPY
endif

TITLE="[ $@ : $? ] ------------------------------------------------------ "

CC=gcc
CFLAGS=-g3 -O0 -Wall -Wextra -Werror -I$(DIRH) $(HAVE_STRLCPY)

#pour tester une libft protegée, on peut ajouter ce flag
#CFLAGS+=-DTEST_PROTECTED


all: $(NAME) $(LIBFT)

$(LIBFTH):$(DIRLIBFT)$(LIBFTH)
	cp $(DIRLIBFT)$(LIBFTH) $(LIBFTH)

$(LIBFT): $(DIRLIBFT) $(LIBFTH)
	@echo "$(TITLE)"
	make -j -C $(DIRLIBFT) && cp -v $(DIRLIBFT)$(LIBFT) $(LIBFT)

$(NAME) $(OBJS):$(HEADERS)

$(DIRO)%.o: $(DIRS)%.s
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

TESTS_FILES:=test_ft_memset.c test_ft_bzero.c test_ft_memcpy.c test_ft_memccpy.c  test_ft_memmove.c test_ft_memchr.c test_ft_memcmp.c test_ft_strlen.c test_ft_strdup.c  test_ft_strcpy.c test_ft_strncpy.c test_ft_strcat.c test_ft_strncat.c test_ft_strlcat.c  test_ft_strchr.c test_ft_strrchr.c test_ft_strstr.c test_ft_strnstr.c test_ft_strcmp.c test_ft_strncmp.c test_ft_atoi.c test_ft_isalpha.c test_ft_isdigit.c test_ft_isalnum.c test_ft_isascii.c test_ft_isprint.c test_ft_toupper.c test_ft_tolower.c test_ft_memalloc.c test_ft_memdel.c test_ft_strnew.c test_ft_strdel.c test_ft_strclr.c test_ft_striter.c test_ft_striteri.c test_ft_strmap.c test_ft_strmapi.c test_ft_strequ.c test_ft_strnequ.c test_ft_strsub.c test_ft_strjoin.c test_ft_strtrim.c test_ft_strsplit.c test_ft_itoa.c test_ft_putchar.c test_ft_putstr.c test_ft_putendl.c test_ft_putnbr.c test_ft_putchar_fd.c test_ft_putstr_fd.c test_ft_putendl_fd.c test_ft_putnbr_fd.c test_ft_lstnew.c test_ft_lstdelone.c test_ft_lstdel.c test_ft_lstadd.c test_ft_lstiter.c test_ft_lstmap.c

TESTS_OBJ:=$(addprefix $(DIRO), $(TESTS_FILES:.c=.o))

$(DIRO)%.o:$(DIRTESTS)/%.c
	@echo "$(TITLE)"
	@mkdir -p objs
	$(CC) $(CFLAGS) -o $@ -c $< 
	
verif:
	echo $(TESTS_OBJ)

$(NAME): test_libft.o $(LIBFT) $(OBJS) $(HEADERS) $(MISSING_O) $(TESTS_OBJ)
ifeq ($(OS), Linux)
	@echo "Linux OS detected :P"
endif
	$(CC) $(CFLAGS) $(HAVE_STRLCPY) -o test_libft test_libft.o $(MISSING_O) -D__$(OS)__ -D__$(CPU)__ $(OBJS) $(TESTS_OBJ) $(LIBFT)

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

truc:
	#for i in 1 2 3 4 5 6 7 8  9 ; do echo "$$i" ; done
	for f in $(LIBFILES) ; do touch test_$$f ; done
	ls test*.c
	
#listoffunc:=$(TESTS_FILES:.c=)
#lst_tests:
#	rm tests.h
#	for f in $(listoffunc) ; do echo "int $$f();" >> tests.h ; done
	
#####################################################################################
#####################################################################################
#####################################################################################

