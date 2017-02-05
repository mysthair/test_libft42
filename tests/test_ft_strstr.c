#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int		test_ft_strstr(const char *big, const char *little)
{
	char	*o;
	char	*m;
	size_t	l;

	o = strstr(big, little);
	m = ft_strstr(big, little);
	l = strlen(little);
	TEST(((o==NULL) && (m==NULL)) 
			|| ((o!=NULL) && (m!=NULL) 
				&& strncmp(o, little, l) == 0 
				&& ft_strncmp(m, little, l) == 0));
	return (1);
}


int main_test_ft_strstr()
	{//ft_strstr
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz","Bar"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Bar Baz","Bar"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz","Bat"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz",""));
		FAIL_IF_NOT(test_ft_strstr("","Bat"));
		FAIL_IF_NOT(test_ft_strstr("",""));
	
		return(1);
	}


