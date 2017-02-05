#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int		test_ft_strncat(char *dest, char *src, size_t n)
{
	char	*buff;
	char	*ret;
	int		t;

	buff = ft_memalloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strncpy(buff, dest, n);
	ret = ft_strncat(dest, src, n);
	TEST(ret == dest);
	strncat(buff, src, n);
	t = ft_strncmp(buff, dest, n);
	if (t !=0)
	{
		ft_putstr("ft_strncmp(buff, dest, n) = ");	ft_putnbr(t); 
		ft_putstr("\nn = ");	ft_putnbr(n); 
		ft_putendl("\nbuff:");
		ft_print_memory(buff, n);
		ft_putendl("\ndest:");
		ft_print_memory(dest, n);
	}
	ft_strdel(&buff);
	TEST(t==0);
	return (1);
}

int main_test_ft_strncat()	{//strncat
		char dst[31];
		ft_bzero(dst, 31);
		FAIL_IF_NOT(test_ft_strncat(dst, "xxx", 0));
		FAIL_IF_NOT(ft_strequ(dst, ""));
		FAIL_IF_NOT(test_ft_strncat(dst, "1xx", 1));
		FAIL_IF_NOT(ft_strequ(dst, "1"));
		FAIL_IF_NOT(test_ft_strncat(dst, "23x", 2));
		FAIL_IF_NOT(ft_strequ(dst, "123"));
		FAIL_IF_NOT(test_ft_strncat(dst, "456", 3));
		FAIL_IF_NOT(ft_strequ(dst, "123456"));
		FAIL_IF_NOT(test_ft_strncat(dst, "789", 4));
		FAIL_IF_NOT(ft_strequ(dst, "123456789"));
		FAIL_IF_NOT(test_ft_strncat(dst, "abc", 5));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abc"));
		FAIL_IF_NOT(test_ft_strncat(dst, "", 	0));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abc"));
		FAIL_IF_NOT(test_ft_strncat(dst, "",	5));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abc"));
		FAIL_IF_NOT(test_ft_strncat(dst, "X", 1));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abcX"));
	
		return(1);
	}

