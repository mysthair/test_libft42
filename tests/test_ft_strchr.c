#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int		test_ft_strchr(const char *s, int c)
{
	char *o, *m;
	o = strchr(s,c);
	m = ft_strchr(s, c);
	TEST(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0));
	return(SUCCESS);
}

int main_test_ft_strchr()
	{//strchr
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '6'));
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", 'X'));
		FAIL_IF_NOT(test_ft_strchr("", 'X'));
		FAIL_IF_NOT(test_ft_strchr("12345678\0""901234567890", '0'));
		FAIL_IF_NOT(test_ft_strchr("123456\t78901234567890", '\t'));
		/*failed !!	FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0')); */
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0'));
	
		return(SUCCESS);
	}

