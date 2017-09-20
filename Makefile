# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:27:19 by jleblanc          #+#    #+#              #
#    Updated: 2017/09/13 11:41:10 by jleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test_libft

DIRLIBFT=../libft

#DEBUG=-g3 -O0 -DDEBUG -DVERBOSE -DWITHOUT_FORK

ifdef DEBUG
	VERBOSE=-DVERBOSE
	V=
else
	V=@
endif

DIRH=./
DIRC=
DIRO=objs
DIRS=jllib
DIRTESTS=tests

LINKFT=link_libft
LIBFT=$(LINKFT)/libft.a
LIBS=-L$(LINKFT)-lft

LIBFTH=libft.h
#DIRFTH:= $(shell if [ -d $(LINKFT)/includes ]; then echo "$(LINKFT)/includes"; else echo "$(LINKFT)"; fi)
DIRFTH=$(LINKFT)
#DIRFTH=$(LINKFT)/includes
HEADERS=$(DIRFTH)/$(LIBFTH) test_libft.h tests.h
INC=-I. -I$(DIRFTH)

MISSFT:=$(MISSFT) $(shell if [ ! -f $(LINKFT)/ft_putaddr_fd.c ]; then echo putaddr_fd ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(LINKFT)/ft_putaddr.c ]; then echo putaddr ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(LINKFT)/ft_print_memory.c ]; then echo print_memory ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(LINKFT)/ft_exit.c ]; then echo exit ;fi)
MISSFT:=$(MISSFT) $(shell if [ ! -f $(LINKFT)/ft_assert.c ]; then echo assert ;fi)

OS:=$(shell uname)
CPU:=$(shell uname -m)
MISSING_O=$(addprefix $(DIRO)/ft_, $(addsuffix _$(OS)_$(CPU).o, $(MISSFT)))
ifeq ($(OS),Linux)
  HAVE_STRLCPY:=-DDONT_HAVE_STRLCPY
  DEBUG+=-DLinux
MISSING_O:=$(MISSING_O) $(DIRO)/strlcat_$(CPU).o $(DIRO)/strnstr_$(CPU).o
else
  HAVE_STRLCPY:=-DHAVE_STRLCPY
endif

#TITLE="[ $@ : $? ] ------------------------------------------------------ "
TITLE="[ $@ : $? ]"

CC=gcc
CFLAGS=-Wall -Wextra -Werror $(INC) $(HAVE_STRLCPY) $(DEBUG)

#pour tester une libft protegée, on peut ajouter ce flag
#CFLAGS+=-DTEST_PROTECTED

.PHONY:all clean fclean re testnorm verif memcheck link link1 link2 link3 link4 link5 debug_version verbose_version nofork_version
all: $(LINKFT) $(NAME) $(LIBFT)

$(LINKFT):
	@echo "$(TITLE)"
	if [ -d $(DIRLIBFT) -o -L $(DIRLIBFT) ]; then test -L $(LINKFT) || ln -s $(DIRLIBFT) $(LINKFT) ; \
	else echo "error $(DIRLIBFT) not exist/valid"; fi

$(LIBFT): $(DIRFTH)/$(LIBFTH) $(DIRFTH)/*.c
	@echo "$(TITLE)"
ifdef DEBUG
	${V}make DEBUG="$(DEBUG)" VERBOSE="$(VERBOSE)" -s -C $(LINKFT)
else
	${V}make -s -C $(LINKFT)
endif


$(DIRO)/%.o: $(DIRS)/%.s
	@echo "$(TITLE)"
	@if [ ! -d objs ]; then mkdir -p objs ; fi
	${V}$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "$(TITLE)"
	${V}rm -rf $(OBJS) $(MISSING_O) $(DIRO)/test_libft.o
	${V}rm -rf $(DIRO)
	@if [ -L $(LINKFT) -o -d $(LINKFT) ]; then make -s -C $(LINKFT) clean  ; fi

fclean: clean
	@echo "$(TITLE)"
	${V}rm -f $(LIBFT)
	${V}rm -f *.e $(NAME)
	${V}rm -rf *.dSYM
	@if [ -L $(LINKFT) ]; then make -s -C $(LINKFT) fclean ; fi
re: fclean | all
#	@echo "$(TITLE)"
#	${V}make -s fclean && make -s -j all

TESTS_FILES:=test_ft_memset.c test_ft_bzero.c test_ft_memcpy.c \
	test_ft_memccpy.c test_ft_memmove.c test_ft_memchr.c test_ft_memcmp.c \
	test_ft_strlen.c test_ft_strdup.c  test_ft_strcpy.c test_ft_strncpy.c \
	test_ft_strcat.c test_ft_strncat.c test_ft_strlcat.c  test_ft_strchr.c \
	test_ft_strrchr.c test_ft_strstr.c test_ft_strnstr.c test_ft_strcmp.c \
	test_ft_strncmp.c test_ft_atoi.c test_ft_isalpha.c test_ft_isdigit.c \
	test_ft_isalnum.c test_ft_isascii.c test_ft_isprint.c test_ft_toupper.c \
	test_ft_tolower.c test_ft_memalloc.c test_ft_memdel.c test_ft_strnew.c \
	test_ft_strdel.c test_ft_strclr.c test_ft_striter.c test_ft_striteri.c \
	test_ft_strmap.c test_ft_strmapi.c test_ft_strequ.c test_ft_strnequ.c \
	test_ft_strsub.c test_ft_strjoin.c test_ft_strtrim.c test_ft_strsplit.c \
	test_ft_itoa.c test_ft_putchar.c test_ft_putstr.c test_ft_putendl.c \
	test_ft_putnbr.c test_ft_putchar_fd.c test_ft_putstr_fd.c \
	test_ft_putendl_fd.c test_ft_putnbr_fd.c test_ft_lstnew.c \
	test_ft_lstdelone.c test_ft_lstdel.c test_ft_lstadd.c test_ft_lstiter.c \
	test_ft_lstmap.c
#	test_ft_putaddr.c

TESTS_OBJ:=$(addprefix $(DIRO)/, $(TESTS_FILES:.c=.o))

$(NAME) $(OBJS) $(MISSING_O) $(TESTS_OBJ): $(HEADERS) Makefile

$(DIRO)/test_libft.o:test_libft.c $(LIBFT) $(HEADERS) Makefile
	@echo "$(TITLE)"
	@if [ ! -d objs ]; then mkdir -p objs ; fi
	${V}$(CC) $(CFLAGS) -o $@ -c $<
$(DIRO)/%.o:$(DIRTESTS)/%.c
	@echo "$(TITLE)"
	@if [ ! -d objs ]; then mkdir -p objs ; fi
	${V}$(CC) $(CFLAGS) -o $@ -c $<

verif:
	echo $(TESTS_OBJ)

$(NAME): $(DIRO)/test_libft.o $(LIBFT) $(OBJS) \
		$(HEADERS) $(MISSING_O) $(TESTS_OBJ)
#ifeq ($(OS), Linux)
#	@echo "Linux OS detected :P"
#endif
	@echo "$(TITLE)"
	${V}$(CC) $(CFLAGS) $(HAVE_STRLCPY) -o test_libft $(DIRO)/test_libft.o \
		$(MISSING_O) -D__$(OS)__ -D__$(CPU)__ $(OBJS) $(TESTS_OBJ) $(LIBFT)

test: test.log
	cat test.log

test.log: $(NAME)
	( ./$(NAME) && echo "OK"  || echo "KO" ) > test.log

testnorm:
	norminette $(LINKFT)
	norminette $(DIRC)ft_*.c $(DIRH)*.h

debug_version:
	make DEBUG="-DDEBUG" re
verbose_version:
	make DEBUG="-DDEBUG -DVERBOSE" re
nofork_version:
	make DEBUG="-DDEBUG -DVERBOSE -DWITHOUT_FORK" re

#####################################################################################
###   WIP
#####################################################################################

vg.log: test_libft
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-fd=1 ./test_libft> vg.log

memcheck: vg.log
	less vg.log

link:
	rm -f $(LINKFT)
	if [ -d ../libft -o -L ../libft ]; then ln -s ../libft $(LINKFT) ; fi

link1:
	rm -f $(LINKFT)
	if [ -d ../libft_a_tester1 -o -L ../libft_a_tester1 ]; \
		then ln -s ../libft_a_tester1 $(LINKFT) ; fi

link2:
	rm -f $(LINKFT)
	if [ -d ../libft_a_tester2 -o -L ../libft_a_tester2 ]; \
		then ln -s ../libft_a_tester2 $(LINKFT) ; fi

link3:
	rm -f $(LINKFT)
	if [ -d ../libft_a_tester3 -o -L ../libft_a_tester3 ]; \
		then ln -s ../libft_a_tester3 $(LINKFT) ; fi

link4:
	rm -f $(LINKFT)
	if [ -d ../libft_a_tester4 -o -L ../libft_a_tester4 ]; \
		then ln -s ../libft_a_tester4 $(LINKFT) ; fi

#truc:
#	#for i in 1 2 3 4 5 6 7 8  9 ; do echo "$$i" ; done
#	for f in $(LIBFILES) ; do touch test_$$f ; done
#	ls test*.c
#

link5:
	rm -f $(LINKFT)
	if [ -d ../libft_a_tester5 -o -L ../libft_a_tester5 ]; \
		then ln -s ../libft_a_tester5 $(LINKFT) ; fi

#lst_tests:
#	rm tests.h
#	for f in $(listoffunc) ; do echo "int $$f();" >> tests.h ; done

#replace_truc:
#	mkdir -p tmp
#	for f in tests/*.c; do sed -E 's/return\(0\)/return\(FAILED\)/' $f > $f.tmp; cat $f.tmp > $f && rm $f.tmp ; done
#	for f in tests/*.c; do sed -E 's/return\(1\)/return\(SUCCESS\)/' $f; done

#####################################################################################
#####################################################################################
#####################################################################################
