
#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int	test_ft_strncpy(char *dest, char *src, size_t n)
{
	char	*t;
	t = ft_strncpy(dest, src, n);

	TEST(t == dest);
	TEST(strncmp(dest, src, n) == ft_strncmp(dest, src, n));
	if (ft_strncmp(dest, src, n) != 0)
	{
		ft_putstr("src:\n");
		ft_print_memory(src, n);
		ft_putstr("dest:\n");
		ft_print_memory(dest, n);
	}
	return (ft_strncmp(dest, src, n)==0);
}

int main_test_ft_strncpy()	{//strncpy
		char *src = "1234567890";
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst, '.', 30);
		FAIL_IF_NOT(test_ft_strncpy(dst, src, 8));
		FAIL_IF_NOT(test_ft_strncpy(dst, src, 12));
	
		return(SUCCESS);
	}



