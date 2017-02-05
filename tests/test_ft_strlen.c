#include "libft.h"
#include "test_libft.h"
#include "tests.h"



#include <string.h>

int     test_ft_strlen(char *str)
{
	return (ft_strlen(str) == strlen(str));
}



int main_test_ft_strlen()	{//ft_strlen
		char *a = "hello";
		char *b = "";
		char *c = "world!\n";
		FAIL_IF_NOT(test_ft_strlen(a));
		FAIL_IF_NOT(test_ft_strlen(b));
		FAIL_IF_NOT(test_ft_strlen(c));
	
		return(1);
	}
	

