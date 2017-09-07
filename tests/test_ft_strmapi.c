#include "libft.h"
#include "test_libft.h"
#include "tests.h"





static char	strmapi_func_upper(unsigned i, char c)
{
	if (i < 512)
		return (ft_toupper(c));
	return (c);
}

static char	strmapi_func_lower(unsigned i, char c)
{
	if (i < 512)
		return (ft_tolower(c));
	return (c);
}


int main_test_ft_strmapi()
	{//ft_strmapi
		char	*ft_strmapi_upper_txtaz123HAHZ;
		char	*ft_strmapi_lower_txtaz123HAHZ;

		ft_strmapi_upper_txtaz123HAHZ = ft_strmapi("txtaz123HAHZ", &strmapi_func_upper);
		INFO(SHOW_STRING("before ", ft_strmapi_upper_txtaz123HAHZ));
		ft_strmapi_lower_txtaz123HAHZ = ft_strmapi("txtaz123HAHZ", &strmapi_func_lower);
		INFO(SHOW_STRING("after  ", ft_strmapi_lower_txtaz123HAHZ));

		FAIL_IF_NOT(ft_strcmp(ft_strmapi_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		FAIL_IF_NOT(ft_strcmp(ft_strmapi_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_strmapi_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmapi_lower_txtaz123HAHZ);

		return(1);
	}
