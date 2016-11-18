# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:27:19 by jleblanc          #+#    #+#              #
#    Updated: 2016/11/18 14:49:36 by jleblanc         ###   ########.fr        #
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

GWW=gcc -std=gnu11 -O0 -g -Wall -Wextra -Werror -I$(DIRH)
#GWW=gcc -O0 -g -Wall -Wextra -Werror -I$(DIRH)

LOCALFUNCS = malloc free exit assert print_memory

LOCALFILES=$(addprefix ft_, $(addsuffix .c, $(LOCALFUNCS)))
OBJS=$(addprefix $(DIRO)ft_, $(addsuffix .o, $(LOCALFUNCS)))

TITLE="[ $@ : $? ] ------------------------------------------------------ "

all: test $(LIBFT)
	@echo "$(TITLE)"
	@echo "################################################################################"
	@echo "##                          $(LIBFT) testeur                                    ##"
	@echo "################################################################################"

#$(LIBFT): $(OBJS) $(HEADERS)
$(LIBFTH):$(DIRLIBFT)$(LIBFTH)
	cp $(DIRLIBFT)$(LIBFTH) $(LIBFTH)

$(LIBFT): $(DIRLIBFT) $(LIBFTH)
	@echo "$(TITLE)"
	make -C $(DIRLIBFT) && cp $(DIRLIBFT)$(LIBFT) $(LIBFT)

$(OBJS): $(HEADERS)

$(DIRO)%.o: %.c
	@echo "$(TITLE)"
	@mkdir -p objs
	$(GWW) -o $@ -c $< 

clean:
	@echo "$(TITLE)"
	rm -rf $(DIRO)

fclean: clean
	@echo "$(TITLE)"
	rm -f $(LIBFT) $(LIBFTH)
	rm -f *.e $(NAME)
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
$(NAME): test_libft.c $(LIBFT) $(OBJS) $(HEADERS)
ifeq ($(OS), Linux)
	@echo "Linux OS detected :P"
endif
	$(GWW) $(HAVE_STRLCPY) -o test_libft test_libft.c $(LIBFT) $(OBJS) 

test: $(NAME)
	./$(NAME)	

testnorm:
	norminette $(DIRLIBFT)
	norminette $(DIRC)ft_*.c $(DIRH)*.h



