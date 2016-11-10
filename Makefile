# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:27:19 by jleblanc          #+#    #+#              #
#    Updated: 2016/11/08 16:07:30 by jleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRH=./
DIRC=
DIRLIBFT=../libft/
DIRO=objs/

LIB=libft.a
LIBHEADER=$(DIRH)libft.h

GWW=gcc -O0 -g -Wall -Wextra -Werror -I$(DIRH)

LOCALFUNCS = malloc free exit assert putchar putstr
FUNCS = memset bzero memcpy memccpy memmove memchr memcmp \
strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr \
strnstr strcmp strncmp atoi isalpha isdigit \
isalnum isascii isprint toupper tolower
#FUNCS+=memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
#bonus s_list

LOCALFILES=$(addprefix ft_, $(addsuffix .c, $(LOCALFUNCS)))
LIBFILES=$(addprefix $(DIRC)ft_, $(addsuffix .c, $(FUNCS)))
LIBOBJ=$(addprefix $(DIRO)ft_, $(addsuffix .o, $(FUNCS) $(LOCALFUNCS)))

TITLE="[ $@ : $? ] ------------------------------------------------------ "

all: $(LIB)
	@echo "$(TITLE)"
	@echo "################################################################################"
	@echo "##                          $(LIB)                                            ##"
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

test_libft: test_libft.c $(LIB)
	$(GWW) -o test_libft test_libft.c $(LIB)

test: test_libft
	./test_libft	

testnorm:
	norminette $(DIRC)*.c $(DIRH)*.h
