#include "libft.h"
#include "test_libft.h"
#include "tests.h"

 #include <ctype.h>

static char strmap_func_upper(char c)
{
	return ((char)toupper((int)c));
}
static char strmap_func_lower(char c)
{
	return ((char)tolower((int)c));
}

int main_test_ft_strmap()
{
	{//ft_strmap
		char	*ft_strmap_upper_txtaz123HAHZ;
		char	*ft_strmap_lower_txtaz123HAHZ;

		ft_strmap_upper_txtaz123HAHZ = ft_strmap("txtaz123HAHZ", &strmap_func_upper);
		INFO(SHOW_STRING("before ", ft_strmap_upper_txtaz123HAHZ));
		ft_strmap_lower_txtaz123HAHZ = ft_strmap("txtaz123HAHZ", &strmap_func_lower);
		INFO(SHOW_STRING("after  ", ft_strmap_lower_txtaz123HAHZ));

		FAIL_IF_NOT(ft_strequ(ft_strmap_upper_txtaz123HAHZ, "TXTAZ123HAHZ"));
		FAIL_IF_NOT(ft_strequ(ft_strmap_lower_txtaz123HAHZ, "txtaz123hahz"));

		ft_strdel(&ft_strmap_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmap_lower_txtaz123HAHZ);

	}
	{
		char *ft_strmap_of_vide = ft_strmap("", &strmap_func_upper);
		FAIL_IF_NOT(ft_strequ(ft_strmap_of_vide, ""));
		ft_strdel(&ft_strmap_of_vide);
	}
	return(1);
}
