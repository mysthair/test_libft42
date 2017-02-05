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
	return (1);
}


int main_test_ft_memccpy()
{//ft_memccpy
	int i;
	char buffer[256];
	char buffer2[255];
	ft_bzero(buffer2, 255);
	ft_memset(buffer, 'X', 59);
	for (i=0; i<10; i++)
		buffer[i] = '0' + i;
	for (i=0; i<26; i++)
		buffer[10+i] = 'a' + i;
	FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 6, '7', 10));
	FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 4, '7', 10));
	FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 2, '7', 10));
	FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 3, '7', 10));
	FAIL_IF_NOT(test_ft_memccpy(buffer + 20, buffer + 5, '7', 10));
	FAIL_IF_NOT(test_ft_memccpy(buffer + 20, buffer + 5, '7' , 10));

	return (1);
}

