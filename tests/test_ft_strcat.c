#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int		test_ft_strcat(char *dest, char *src)
{
	char	*buff;
	char	*ret;
	int		t;

	buff = ft_memalloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strcpy(buff, dest);
	ret = ft_strcat(dest, src);
	TEST(ret == dest);
	strcat(buff, src);
	t = ft_strcmp(buff, dest);
	ft_strdel(&buff);
	return (t == 0);
}


int main_test_ft_strcat()	{//strcat
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst+1, 'y', 29);
		FAIL_IF_NOT(test_ft_strcat(dst, ""));
		FAIL_IF_NOT(test_ft_strcat(dst, "12345"));
		FAIL_IF_NOT(test_ft_strcat(dst, "abcd"));
		FAIL_IF_NOT(test_ft_strcat(dst, ""));
		FAIL_IF_NOT(test_ft_strcat(dst, "X"));
		FAIL_IF_NOT(ft_strequ(dst, "12345abcdX"));
	
		return(SUCCESS);
	}

