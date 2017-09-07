#include "libft.h"
#include "test_libft.h"
#include "tests.h"



static int	test_ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if(s1 && s2)
	{	
		TEST((!s1 || !s2) 
			|| (ft_strnequ(s1, s2, n) == (ft_strncmp(s1, s2, n) == 0 ? 1 : 0)));
	}
	else
	{
		TEST((s1 && s2 ) 
			|| (ft_strnequ(s1, s2, n) == ((s1 == s2) ? 1 : 0)));
	}
	return(SUCCESS);
}


int main_test_ft_strnequ()
	{ // strnequ
		char *abcd = "abcd";
		int i = 6;
		while (i > -3)
		{
			FAIL_IF_NOT(test_ft_strnequ(abcd, abcd, i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, "abcd", i));
			FAIL_IF_NOT(test_ft_strnequ("abcd", "abcd", i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, "ab", i));
			FAIL_IF_NOT(test_ft_strnequ("ab", abcd, i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, "", i));
			FAIL_IF_NOT(test_ft_strnequ("", abcd, i));
			FAIL_IF_NOT(test_ft_strnequ("", "", i));
#ifdef PROTECTED_TEST
			FAIL_IF_NOT(test_ft_strnequ("", NULL, i));
			FAIL_IF_NOT(test_ft_strnequ(NULL, "", i));
			FAIL_IF_NOT(test_ft_strnequ(NULL, abcd, i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, NULL, i));
#endif
			i--;
		}
	
		return(SUCCESS);
	}

