#include "libft.h"
#include "test_libft.h"
#include "tests.h"






int main_test_ft_strtrim()
	{
		char *s = NULL;
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("  test1   ")), "test1"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" \n \t bidule \n \t ")), "bidule"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" \t\f\r\n ")), "") || ft_strequ((s=ft_strtrim(" \t\f\r\n ")), "\f\r"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("  \t \n   ")), ""));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" a ")), "a"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("\n")), ""));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("\t")), ""));
		ft_strdel(&s);
#ifdef PROTECTED_TEST		
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(NULL)), NULL));
		ft_strdel(&s);
#endif
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" \176			 ")), "\176"));
		ft_strdel(&s);
		char strange[] = { '-', '>', 0xF0, 0x9D, 0x84, 0x9E, '<', '-', '\0' };
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(strange)), strange));
		ft_strdel(&s);
	
		return(SUCCESS);
	}

