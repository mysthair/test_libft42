#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int    test_ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s, *d;
	void 	*ret;

	s = ft_memalloc(n);
	memcpy(s, src, n);
	d = (char*)dest;
	ret = ft_memcpy(dest, src, n);
	if(ret != dest)
		ft_putstr("ret != dest");
	TEST(ret == dest);
	i = 0;
	while(i < n)
	{
		if(d[i] != s[i])
		{
			ft_putstr("d["); ft_putnbr(i); ft_putstr("] != s["); ft_putnbr(i);ft_putstr("]\n");
			ft_putstr("s:\n");
			ft_print_memory(s, n);
			ft_putstr("d:\n");
			ft_print_memory(d, n);
		}
		TEST(d[i] == s[i]);
		i++;
	}
	ft_strdel(&s);
	return (1);
}

	//ft_memcpy
int main_test_ft_memcpy()
	{
		int i;
		char buffer[256];
		char buffer2[256];

		ft_memset(buffer, 'X', 255);
		buffer[255] = '\0';
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10 + i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memcpy(buffer2, buffer, 255));
		FAIL_IF_NOT(test_ft_memcpy(buffer + 5, buffer + 10, 10));

		FAIL_IF_NOT(test_ft_memcpy(buffer, buffer, 256));
		FAIL_IF_NOT(test_ft_memcpy(buffer, buffer, 0));
		FAIL_IF_NOT(test_ft_memcpy(buffer, NULL, 0));
		FAIL_IF_NOT(test_ft_memcpy(NULL, buffer, 0));
		FAIL_IF_NOT(test_ft_memcpy(NULL, NULL, 0));

		return(1);
	}
