#include "libft.h"
#include "test_libft.h"
#include "tests.h"





static void strtter_func_upper(char *c)
{
	*c = ft_toupper(*c);
}
static void strtter_func_lower(char *c)
{
	*c = ft_tolower(*c);
}



int main_test_ft_striter()
	{//ft_striter
		char	*t = "txtaz123HAHZ";

		char	*ft_stirter_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirter_lower_txtaz123HAHZ = ft_strdup(t);

		TRACE(SHOW_STRING("before ", ft_stirter_upper_txtaz123HAHZ));
		ft_striter(ft_stirter_upper_txtaz123HAHZ, &strtter_func_upper);
		TRACE(SHOW_STRING("after  ", ft_stirter_upper_txtaz123HAHZ));
		FAIL_IF_NOT(ft_strequ(ft_stirter_upper_txtaz123HAHZ, "TXTAZ123HAHZ"));

		TRACE(SHOW_STRING("before ", ft_stirter_lower_txtaz123HAHZ));
		ft_striter(ft_stirter_lower_txtaz123HAHZ, &strtter_func_lower);
		TRACE(SHOW_STRING("after  ", ft_stirter_lower_txtaz123HAHZ));
		FAIL_IF_NOT(ft_strequ(ft_stirter_lower_txtaz123HAHZ, "txtaz123hahz"));

		ft_strdel(&ft_stirter_upper_txtaz123HAHZ);
		ft_strdel(&ft_stirter_lower_txtaz123HAHZ);

		return(1);
	}
