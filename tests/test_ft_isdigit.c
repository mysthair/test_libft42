#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <ctype.h>


int     test_ft_isdigit(int c)
{
	TEST(!!isdigit(c) == !!ft_isdigit(c));
	return (1);
}




int main_test_ft_isdigit()
	{//ft_isdigit
		int c;

		FAIL_IF_NOT(test_ft_isdigit('a'));
		FAIL_IF_NOT(test_ft_isdigit('A'));
		FAIL_IF_NOT(test_ft_isdigit('Z'));
		FAIL_IF_NOT(test_ft_isdigit('&'));
		FAIL_IF_NOT(test_ft_isdigit('\0'));
		FAIL_IF_NOT(test_ft_isdigit('\n'));
		FAIL_IF_NOT(test_ft_isdigit('0'));
		FAIL_IF_NOT(test_ft_isdigit('3'));
		FAIL_IF_NOT(test_ft_isdigit('9'));

		c = 0;
		while (c < 0xFF)
			FAIL_IF_NOT(test_ft_isdigit(c++));

		return(1);
	}
