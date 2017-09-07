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

		//FAIL_IF_NOT(test_ft_strcpy(s, s));
		FAIL_IF_NOT(test_ft_strcpy(buff100, s));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 1, s));
		FAIL_IF_NOT(test_ft_strcpy(buff100, buff100));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 2, abcdefghi));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 2, ""));
		FAIL_IF_NOT(test_ft_strcpy(buff100, abcdefghi));
		FAIL_IF_NOT(test_ft_strcpy(buff100, "lolmdr\n"));


		FAIL_IF_NOT(test_ft_strcpy(buff100, "000000000X"));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 1, "1111111"));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 2, "22222"));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 3, "333"));
		FAIL_IF_NOT(test_ft_strcpy(buff100 + 4, "4"));
		if(ft_memcmp(buff100, "01234\0\0\0\0X\0", 12)!=0)
		{
			ft_putendl("needed:");
			ft_print_memory("01234\0\0\0\0\0X\0",12);
			ft_putendl("result:");
			ft_print_memory(buff100,12);
		}
		FAIL_IF_NOT(ft_memcmp(buff100, "01234\0\0\0\0X\0", 12)==0);
		return(SUCCESS);
}
