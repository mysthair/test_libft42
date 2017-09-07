#include "libft.h"
#include "test_libft.h"
#include "tests.h"
#include <ctype.h>

static int     test_ft_isascii(int c)
{
	TEST(!!isascii(c) == !!ft_isascii(c));
	return(SUCCESS);
}

int main_test_ft_isascii()
{
	int i;
	for (i =  -10; i< 520; i++)
	{
		FAIL_IF_NOT( test_ft_isascii(i));
	}

	return(SUCCESS);
}

