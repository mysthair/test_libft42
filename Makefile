# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:27:19 by jleblanc          #+#    #+#              #
#    Updated: 2016/11/15 12:27:47 by jleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRH=./
DIRC=
DIRLIBFT=../libft/
DIRO=objs/

LIB=libft.a
LIBHEADER=$(DIRH)libft.h

GWW=gcc -O0 -g -Wall -Wextra -Werror -I$(DIRH)

LOCALFUNCS = malloc free exit assert putchar putstr putnbr print_memory
FUNCS = memset bzero memcpy memccpy memmove memchr memcmp \
strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr \
strnstr strcmp strncmp atoi isalpha isdigit \
isalnum isascii isprint toupper tolower \
memalloc memdel strnew strdel strclr striter striteri strmap strmapi \
# strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
#bonus s_list

LOCALFILES=$(addprefix ft_, $(addsuffix .c, $(LOCALFUNCS)))
LIBFILES=$(addprefix $(DIRLIBFT)ft_, $(addsuffix .c, $(FUNCS)))
LIBOBJ=$(addprefix $(DIRO)ft_, $(addsuffix .o, $(FUNCS) $(LOCALFUNCS)))

TITLE="[ $@ : $? ] ------------------------------------------------------ "

all: test $(LIB)
	@echo "$(TITLE)"
	@echo "################################################################################"
	@echo "##                          $(LIB) testeur                                    ##"
	@echo "$(LIBFILES)"
	@echo "################################################################################"

$(LIB): $(LIBOBJ) $(LIBHEADER)
	@echo "$(TITLE)"
	ar rc $(LIB) $(LIBOBJ)
	ranlib $(LIB)

$(LIBOBJ): $(LIBHEADER)

$(DIRO)%.o: %.c
	@echo "$(TITLE)"
	@mkdir -p objs
	$(GWW) -o $@ -c $< 
$(DIRO)%.o: $(DIRLIBFT)%.c
	@echo "$(TITLE)"
	@mkdir -p objs
	$(GWW) -o $@ -c $< 

clean:
	@echo "$(TITLE)"
	rm -rf $(DIRO)

fclean: clean
	@echo "$(TITLE)"
	rm -f $(LIB)
	rm -f *.e test_libft
	@rm -rf *.dSYM

re:
	@echo "$(TITLE)"
	make fclean
	make all
	make test
OS:=$(shell uname)
ifeq ($(OS),Linux)
  HAVE_STRLCPY:=-DDONT_HAVE_STRLCPY
else
  HAVE_STRLCPY:=-DHAVE_STRLCPY
endif
testos:
	echo "$(OS) -> GWW $(HAVE_STRLCPY)"
test_libft: test_libft.c $(LIB)
ifeq ($(OS), Linux)
	@echo "Linux OS detected :P"
endif
	$(GWW) $(HAVE_STRLCPY) -o test_libft test_libft.c $(LIB)

test: test_libft
	./test_libft	

testnorm:
	norminette $(DIRC)*.c $(DIRH)*.h



