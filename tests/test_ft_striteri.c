#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static void strtteri_func_upper(unsigned int i, char *s)
{
	i = 0+i;
	*s = ft_toupper(*s);
}
static void strtteri_func_lower(unsigned int i, char *s)
{
	i = 0+i;
	*s = ft_tolower(*s);
}



int main_test_ft_striteri()
	{//ft_striteri
		char	*t = "txtaz123HAHZ";

		char	*ft_stirteri_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirteri_lower_txtaz123HAHZ = ft_strdup(t);

		INFO(SHOW_STRING("before ", ft_stirteri_upper_txtaz123HAHZ));
		ft_striteri(ft_stirteri_upper_txtaz123HAHZ, &strtteri_func_upper);
		INFO(SHOW_STRING("after  ", ft_stirteri_upper_txtaz123HAHZ));
		FAIL_IF_NOT(ft_strequ(ft_stirteri_upper_txtaz123HAHZ, "TXTAZ123HAHZ"));

		INFO(SHOW_STRING("before ", ft_stirteri_lower_txtaz123HAHZ));
		ft_striteri(ft_stirteri_lower_txtaz123HAHZ, &strtteri_func_lower);
		INFO(SHOW_STRING("after  ", ft_stirteri_lower_txtaz123HAHZ));
		FAIL_IF_NOT(ft_strequ(ft_stirteri_lower_txtaz123HAHZ, "txtaz123hahz"));

		ft_strdel(&ft_stirteri_upper_txtaz123HAHZ);
		ft_strdel(&ft_stirteri_lower_txtaz123HAHZ);

		return(SUCCESS);
	}
