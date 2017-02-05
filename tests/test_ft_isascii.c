#include "libft.h"
#include "test_libft.h"
#include "tests.h"
#include <ctype.h>

static int     test_ft_isascii(int c)
{
	TEST(!!isascii(c) == !!ft_isascii(c));
	return (1);
}

int main_test_ft_isascii()
{
	int i;
	int errors = 0;
	
	for (i =  -10; i< 520; i++)
	{
		errors += test_ft_isascii(i);
	}

	return (errors);
}

