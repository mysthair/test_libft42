#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <ctype.h>

static int     test_ft_isalpha(int c)
{
	TEST(!!isalpha(c) == !!ft_isalpha(c));
	return (1);
}


int main_test_ft_isalpha()	{//isalpha
		FAIL_IF_NOT(test_ft_isalpha('a'));
		FAIL_IF_NOT(test_ft_isalpha('b'));
		FAIL_IF_NOT(test_ft_isalpha('z'));
		FAIL_IF_NOT(test_ft_isalpha('A'));
		FAIL_IF_NOT(test_ft_isalpha('F'));
		FAIL_IF_NOT(test_ft_isalpha('Z'));
		FAIL_IF_NOT(test_ft_isalpha(';'));
		FAIL_IF_NOT(test_ft_isalpha('0'));
		FAIL_IF_NOT(test_ft_isalpha('9'));
		FAIL_IF_NOT(test_ft_isalpha('&'));
		FAIL_IF_NOT(test_ft_isalpha('\n'));
		FAIL_IF_NOT(test_ft_isalpha('\0'));

		return(SUCCESS);
	}
