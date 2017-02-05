#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int     test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n) == memcmp(s1,s2,n));
}


int main_test_ft_memcmp()	{// ft_memcmp
		char	*a = "12345\0""12345\0";
		char	*b = a+6;
		char	*c = "12346";
		FAIL_IF_NOT(test_ft_memcmp(a,a,6));
		FAIL_IF_NOT(test_ft_memcmp(a,b,6));
		FAIL_IF_NOT(test_ft_memcmp(a+1,b,6));
		FAIL_IF_NOT(test_ft_memcmp(a,c,6));
		FAIL_IF_NOT(test_ft_memcmp(c,a,6));
	
		return(1);
	}



