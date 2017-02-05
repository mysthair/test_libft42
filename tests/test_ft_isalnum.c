#include "libft.h"
#include "test_libft.h"
#include "tests.h"
#include <ctype.h>

static int     test_ft_isalnum(int c)
{
	TEST(!!isalnum(c) == !!ft_isalnum(c));
	return (1);
}

int main_test_ft_isalnum()
	{
		FAIL_IF_NOT(test_ft_isalnum('0'));
		FAIL_IF_NOT(test_ft_isalnum('9'));
		FAIL_IF_NOT(test_ft_isalnum('a'));
		FAIL_IF_NOT(test_ft_isalnum('z'));
		FAIL_IF_NOT(test_ft_isalnum('A'));
		FAIL_IF_NOT(test_ft_isalnum('Z'));
		FAIL_IF_NOT(test_ft_isalnum('f'));
		FAIL_IF_NOT(test_ft_isalnum('F'));
		FAIL_IF_NOT(test_ft_isalnum('%'));
		FAIL_IF_NOT(test_ft_isalnum('!'));
		FAIL_IF_NOT(test_ft_isalnum('{'));
		FAIL_IF_NOT(test_ft_isalnum('\n'));
		FAIL_IF_NOT(test_ft_isalnum('\t'));
		FAIL_IF_NOT(test_ft_isalnum('\0'));
	
		return(1);
	}

