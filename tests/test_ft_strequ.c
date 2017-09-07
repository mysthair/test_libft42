#include "libft.h"
#include "test_libft.h"
#include "tests.h"


static int	test_ft_strequ(const char *s1, const char *s2)
{
	if(!s1 && !s2)
	{	
		TEST((!s1 || !s2) 
			|| (ft_strequ(s1, s2) == ((ft_strcmp(s1, s2) == 0 ? 1 : 0))));
	}
	else
	{
		TEST((s1 && s2) 
			|| (ft_strequ(s1, s2) == ((s1 == s2) ? 1 : 0)));
	}
	return(SUCCESS);
}


int main_test_ft_strequ()
	{ // strequ
		char *abcd = "abcd";
		FAIL_IF_NOT(test_ft_strequ(abcd, abcd));
		FAIL_IF_NOT(test_ft_strequ(abcd, "abcd"));
		FAIL_IF_NOT(test_ft_strequ("abcd", "abcd"));
		FAIL_IF_NOT(test_ft_strequ(abcd, "ab"));
		FAIL_IF_NOT(test_ft_strequ("ab", abcd));
		FAIL_IF_NOT(test_ft_strequ(abcd, ""));
		FAIL_IF_NOT(test_ft_strequ("", abcd));
		FAIL_IF_NOT(test_ft_strequ("", ""));
#ifdef PROTECTED_TEST
		FAIL_IF_NOT(test_ft_strequ("", NULL));
		FAIL_IF_NOT(test_ft_strequ(NULL, ""));
		FAIL_IF_NOT(test_ft_strequ(NULL, abcd));
		FAIL_IF_NOT(test_ft_strequ(abcd, NULL));
#endif
	
		return(SUCCESS);
	}

