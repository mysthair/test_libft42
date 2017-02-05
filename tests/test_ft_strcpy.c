#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <string.h>

static int test_ft_strcpy(char *dest, char *src)
{
	char	*t;
	t = ft_strcpy(dest, src);
	FAIL_IF_NOT(t == dest);
	FAIL_IF_NOT(ft_strequ(dest, src));
	return (t == dest && ft_strequ(dest, src));
}


int main_test_ft_strcpy()	
{//strcpy
		char *abcdefgh = "abcdefgh";
		char buff100[100];
		
		ft_bzero(buff100, 100);
		ft_strcpy(buff100+1, abcdefgh);
		FAIL_IF_NOT(ft_memcmp(abcdefgh, buff100+1, 11) == 0);
		
		test_ft_strcpy(buff100, abcdefgh);
		
		return(1);
}


