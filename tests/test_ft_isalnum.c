#include "libft.h"
#include "test_libft.h"
#include "tests.h"
#include <ctype.h>

static int     test_ft_isalnum(int c)
{
	if(!!isalnum(c) != !!ft_isalnum(c))
	{
		ft_putstr("ft_isalnum("); ft_putnbr(c); ft_putstr(") = ") ; ft_putnbr(ft_isalnum(c));
		ft_putstr("\nisalnum("); ft_putnbr(c); ft_putstr(") = ") ; ft_putnbr(isalnum(c));
		ft_putstr("\n");
	}

	TEST((!!isalnum(c)) == (!!ft_isalnum(c)));
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
	
		int i;
		for (i = -128; i<1024; i++)
			FAIL_IF_NOT(test_ft_isalnum(i));
	
		return(1);
	}

