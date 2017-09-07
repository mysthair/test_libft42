#include "tests.h"
#include "libft.h"
#include "test_libft.h"
#include "tests.h"
#include <stdlib.h>

int     test_ft_atoi(char *str)
{
	int o,m;

	o = atoi(str);
	m = ft_atoi(str);
	if(o != m)
	{
		ft_putstr("ft_atoi(\""); ft_putstr(str), ft_putstr("\" = ");
		ft_putnbr(m); ft_putstr("\n");
		ft_putstr("   atoi(\""); ft_putstr(str), ft_putstr("\" = ");
		ft_putnbr(o); ft_putstr("\n");
	}
	TEST(atoi(str) == ft_atoi(str));
	return (1);
}



int main_test_ft_atoi()
	{//ft_atoi
		FAIL_IF_NOT(test_ft_atoi("0"));// == 0);
		FAIL_IF_NOT(test_ft_atoi("12"));//  == 12);
		FAIL_IF_NOT(test_ft_atoi(" 	12   "));//  == 12);
		FAIL_IF_NOT(test_ft_atoi("+12"));//   == 12);
		FAIL_IF_NOT(test_ft_atoi("+12,35"));//   == 12);
		FAIL_IF_NOT(test_ft_atoi("-83"));//   == -83);
		FAIL_IF_NOT(test_ft_atoi("-320,5"));//   == -320);
		FAIL_IF_NOT(test_ft_atoi(""));//   == 0));
		FAIL_IF_NOT(test_ft_atoi(" A"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("A12"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("12FS0"));//   == 12);
		FAIL_IF_NOT(test_ft_atoi(" - 4 2"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("0xFF"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("&x0A"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("2147483647"));//  == 2147483647);
		FAIL_IF_NOT(test_ft_atoi("-2147483647"));//  == -2147483647);
		FAIL_IF_NOT(test_ft_atoi("-2147483648"));//  == -2147483648);
		FAIL_IF_NOT(test_ft_atoi("00000000000000000000000000000000"));// == 0);
#ifndef __armv6l__
		FAIL_IF_NOT(test_ft_atoi("2147483648"));//  == -2147483648);
		FAIL_IF_NOT(test_ft_atoi("2147483649"));//  == -2147483647);
		FAIL_IF_NOT(test_ft_atoi("-2147483649"));//  == 2147483647);
		FAIL_IF_NOT(test_ft_atoi("9223372036854775805"));//  == -3);
		FAIL_IF_NOT(test_ft_atoi("9223372036854775806"));//  == -2);
		FAIL_IF_NOT(test_ft_atoi("9223372036854775807"));//  == -1);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775805"));// == 3);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775806"));// == 2);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775807"));// == 1);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775808"));// == 0);
#endif
		/* uncomment this lines to compare with the real atoi !
		   FAIL_IF_NOT(test_ft_atoi("9223372036854775808"));//  == -1);
		   FAIL_IF_NOT(test_ft_atoi("9223372036854775809"));//  == -1);
		   FAIL_IF_NOT(test_ft_atoi("9223372036854775810"));//  == -1);
		   FAIL_IF_NOT(test_ft_atoi("1000000000000000000000000"));//   == -1);
		   FAIL_IF_NOT(test_ft_atoi("-9223372036854775809"));// == 0);
		   FAIL_IF_NOT(test_ft_atoi("-9223372036854775810"));// == 0);
		   FAIL_IF_NOT(test_ft_atoi("-1000000000000000000000000"));//  == 0);
		   */

		return(SUCCESS);
	}
