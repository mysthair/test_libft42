#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <string.h>

static int test_ft_strcpy(char *dest, char const *src)
{
	char	*t;
	t = ft_strcpy(dest, src);
	TEST(t == dest);
	TEST(ft_strequ(dest, src));
	return (t == dest && ft_strequ(dest, src));
}


int main_test_ft_strcpy()	
{//strcpy
		char *s = "s";	
		char *abcdefghi = "abcdefghi";
		char buff100[100];
		
		ft_bzero(buff100, 100);
		
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 1, s));
		FAIL_IF_NOT(test_ft_strcpy(s, s));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 2, abcdefghi));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 2, ""));
		FAIL_IF_NOT(test_ft_strcpy(buff100, abcdefghi));
		FAIL_IF_NOT(test_ft_strcpy(abcdefghi, "lolmdr\n"));
		
		return(1);
}


