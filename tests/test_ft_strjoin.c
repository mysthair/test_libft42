#include "libft.h"
#include "test_libft.h"
#include "tests.h"





int main_test_ft_strjoin()
	{	char *abcde = "abcde";
		char *xyz = "xyz";
		char *s;
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(abcde, xyz)), "abcdexyz"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(abcde, "")),"abcde"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin("", xyz)), "xyz"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin("", "")),""));
		ft_strdel(&s);
#ifdef PROTECTED_TEST
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(abcde, NULL)),"abcde") 
				|| (s == NULL));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(NULL, xyz)),"xyz")
				|| (s == NULL));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(NULL, NULL)), "")
				|| (s == NULL));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(NULL, "")), "")
			   	|| (s == NULL));
		ft_strdel(&s);
#endif
	
		return(1);
	}

