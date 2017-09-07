#include "libft.h"
#include "test_libft.h"
#include "tests.h"


#include <ctype.h>


static int     test_ft_tolower(int c)
{
	int o, m;
	o = tolower(c);
	m = ft_tolower(c);
	if (o != m)
	{
		ft_putstr("   tolower("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(o); ft_putstr("'\n");
		ft_putstr("ft_tolower("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(m); ft_putstr("'\n");
	}
	TEST(o == m);
	return(SUCCESS);
}

int main_test_ft_tolower()
	{//tolower
		FAIL_IF_NOT(test_ft_tolower('a'));
		FAIL_IF_NOT(test_ft_tolower('j'));
		FAIL_IF_NOT(test_ft_tolower('z'));
		FAIL_IF_NOT(test_ft_tolower('A'));
		FAIL_IF_NOT(test_ft_tolower('E'));
		FAIL_IF_NOT(test_ft_tolower('Z'));
		FAIL_IF_NOT(test_ft_tolower('0'));
		FAIL_IF_NOT(test_ft_tolower('\t'));
		FAIL_IF_NOT(test_ft_tolower('\n'));
		FAIL_IF_NOT(test_ft_tolower('\0'));
		FAIL_IF_NOT(test_ft_tolower('a' + 0x100 ));
#ifdef DEBUG
		for(int c=-1256; c<1512; c++)
		{
			FAIL_IF_NOT(test_ft_tolower(c));
		}
#endif
	
		return(SUCCESS);
	}


