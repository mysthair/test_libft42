#include "libft.h"
#include "test_libft.h"
#include "tests.h"



int main_test_ft_itoa()
	{
		char *t;

		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0)),"0"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(123)),"123"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(-10)),"-10"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(12345)),"12345"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0x7FFFFFFF)),"2147483647"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0x80000000)),"-2147483648"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa((int)0x7FFFFFFFFFFFFFFF)),"-1"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa((int)0x8000000000000000)),"0"));
		ft_strdel(&t);
	
		return(1);
	}

