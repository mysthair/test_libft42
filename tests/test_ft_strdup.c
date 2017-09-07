
#include "libft.h"
#include "test_libft.h"
#include "tests.h"














int		test_ft_strdup(char *str)
{
	char 	*t;
	int 	r;

	t = ft_strdup(str);
	r = ft_strcmp(t, str);
	ft_strdel(&t);
	return (r==0);
}

int main_test_ft_strdup()	{ // ft_strdup
		char *text = "hello world!";
		FAIL_IF_NOT(test_ft_strdup(text));
		FAIL_IF_NOT(test_ft_strdup("&AFsd1''2\t3\n4+-{}5\0""67890"));
		FAIL_IF_NOT(test_ft_strdup(""));
	
		return(SUCCESS);
	}


