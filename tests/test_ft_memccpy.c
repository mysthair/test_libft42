#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int    test_ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;
	void	*r;

	s = ft_memalloc(n);
	ft_memcpy(s, src, n);
	r = ft_memccpy(dest, src, c, n);
	d = (char*)dest;
	i = 0;
	while(i < n)
	{
		if(d[i] != s[i])
		{
			ft_putstr("d["); ft_putnbr(i); ft_putstr("] != s["); ft_putnbr(i);ft_putstr("]\n");
			ft_putstr("s:\n");
			ft_print_memory(s, i);
			ft_putstr("d:\n");
			ft_print_memory(d, i);
		}
		TEST(d[i] == s[i]);
		if(s[i] == (char)c)
			break;
		i++;
	}
	TEST((size_t)(r - dest) == (i + 1));
	ft_strdel(&s);
	return(SUCCESS);
}

static int main_test_ft_memccpy_test1()
{
	int i;
	char buffer[256];
	char buffer2[255];
	ft_bzero(buffer2, 255);
	ft_memset(buffer, 'X', 59);
	for (i=0; i<10; i++)
		buffer[i] = '0' + i;
	for (i=0; i<26; i++)
		buffer[10+i] = 'a' + i;
	TEST(test_ft_memccpy(buffer2, buffer + 6, '7', 10));
	TEST(test_ft_memccpy(buffer2, buffer + 4, '7', 10));
	TEST(test_ft_memccpy(buffer2, buffer + 2, '7', 10));
	TEST(test_ft_memccpy(buffer2, buffer + 3, '7', 10));
	TEST(test_ft_memccpy(buffer + 20, buffer + 5, '7', 10));
	TEST(test_ft_memccpy(buffer + 20, buffer + 5, '7' , 10));

	return (SUCCESS);
}

static int main_test_ft_memccpy_test2()
{
			char buffer[1024];
			char *txt = "Ceci est un texte pour le test memccpy...";

			for (size_t i=0; i<strlen(txt); i++){
				FAIL_IF_NOT(memccpy(buffer, txt, ' ', i) == ft_memccpy(buffer, txt, ' ', i));
			}
			FAIL_IF_NOT(memccpy(buffer, txt, ' ', 0) == ft_memccpy(buffer, txt, ' ', 0));
//			int t = memccpy(0, txt, ' ', 0) == ft_memccpy(NULL, txt, ' ', 0);
/*[ objs/test_ft_memccpy.o : tests/test_ft_memccpy.c ] ------------------------------------------------------
gcc -Wall -Wextra -Werror -I. -Ilink_libft -DDONT_HAVE_STRLCPY  -o objs/test_ft_memccpy.o -c tests/test_ft_memccpy.c
tests/test_ft_memccpy.c: In function ‘main_test_ft_memccpy_test2’:
tests/test_ft_memccpy.c:67:12: error: null argument where non-null required (argument 1) [-Werror=nonnull]
    int t = memccpy(0, txt, ' ', 0) == ft_memccpy(NULL, txt, ' ', 0);
            ^~~~~~~
cc1: all warnings being treated as errors
Makefile:127 : la recette pour la cible « objs/test_ft_memccpy.o » a échouée
make: *** [objs/test_ft_memccpy.o] Erreur 1
*/
      //FAIL_IF_NOT(t);
      //FAIL_IF_NOT(memccpy(NULL, txt, ' ', 0) == ft_memccpy(NULL, txt, ' ', 0));
			FAIL_IF_NOT(memccpy(buffer, buffer, ' ', 0) == ft_memccpy(buffer, buffer, ' ', 0));
			return SUCCESS;
}

int main_test_ft_memccpy()
{//ft_memccpy
		return ( main_test_ft_memccpy_test1() == SUCCESS
			&& main_test_ft_memccpy_test2() == SUCCESS
			? SUCCESS
			: FAILED );
}
