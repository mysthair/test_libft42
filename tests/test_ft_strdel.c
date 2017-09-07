#include "libft.h"
#include "test_libft.h"
#include "tests.h"



static int	test_ft_strdel(size_t size)
{
	char	*t = ft_memalloc(size);

	ft_strdel(&t);
	TEST(t == NULL);
	return(SUCCESS);
}



int main_test_ft_strdel()
	{// strdel
		FAIL_IF_NOT(test_ft_strdel(10));
		FAIL_IF_NOT(test_ft_strdel(1));
		FAIL_IF_NOT(test_ft_strdel(0));
	
		return(SUCCESS);
	}

