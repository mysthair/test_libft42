#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <ctype.h>


static int     test_ft_toupper(int c)
{
	int	 o, m;

	o = toupper(c);
	m = ft_toupper(c);
	if (o != m)
	{
		ft_putstr("   toupper("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(o); ft_putstr("'\n");
		ft_putstr("ft_toupper("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(m); ft_putstr("'\n");
	}
	TEST(o == m);
	return(SUCCESS);
}

int main_test_ft_toupper()
	{//toupper
		FAIL_IF_NOT(test_ft_toupper('a'));
		FAIL_IF_NOT(test_ft_toupper('j'));
		FAIL_IF_NOT(test_ft_toupper('z'));
		FAIL_IF_NOT(test_ft_toupper('A'));
		FAIL_IF_NOT(test_ft_toupper('E'));
		FAIL_IF_NOT(test_ft_toupper('Z'));
		FAIL_IF_NOT(test_ft_toupper('0'));
		FAIL_IF_NOT(test_ft_toupper('\t'));
		FAIL_IF_NOT(test_ft_toupper('\n'));
		FAIL_IF_NOT(test_ft_toupper('\0'));

#ifdef DEBUG
		for(int c=-256; c<=512; c++)
		{
			FAIL_IF_NOT(test_ft_toupper(c));
		}	
#endif
	
		return(SUCCESS);
	}


