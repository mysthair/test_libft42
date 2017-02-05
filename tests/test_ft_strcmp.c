#include "libft.h"
#include "test_libft.h"
#include "tests.h"


static int sign(int i)
{
	return (i > 0 ? 1 : (i == 0 ? 0 : -1));
}

static int     test_ft_strcmp(char const *s1, char const *s2)
{
	if (sign(strcmp(s1, s2)) != sign(ft_strcmp(s1, s2)))
	{
		SHOW_STRING("", s1);
		SHOW_STRING("", s2);
		ft_putstr("strcmp(s1, s2) = "); ft_putnbr(strcmp(s1, s2)); ft_putstr("\n");
		ft_putstr("ft_strcmp(s1, s2) = "); ft_putnbr(ft_strcmp(s1, s2)); ft_putstr("\n");
	}
	TEST(sign(strcmp(s1, s2)) == sign(ft_strcmp(s1, s2)));
	return (1);
}

int main_test_ft_strcmp()
	{//ft_strcmp

		FAIL_IF_NOT(test_ft_strcmp("1234", "1234"));
		FAIL_IF_NOT(test_ft_strcmp("12345", "12335"));
		FAIL_IF_NOT(test_ft_strcmp("12345", "12355"));
		FAIL_IF_NOT(test_ft_strcmp("12345", "1234"));
		FAIL_IF_NOT(test_ft_strcmp("1234", "12345"));
		FAIL_IF_NOT(test_ft_strcmp("1234", ""));
		FAIL_IF_NOT(test_ft_strcmp("", "12345"));
		FAIL_IF_NOT(test_ft_strcmp("", ""));

		FAIL_IF_NOT(test_ft_strcmp("\200", "\0"));
		FAIL_IF_NOT(test_ft_strcmp("0", "\200"));
		FAIL_IF_NOT(test_ft_strcmp("\200", "\177"));
		FAIL_IF_NOT(test_ft_strcmp("\177", "\200"));
		FAIL_IF_NOT(test_ft_strcmp("\x7F", "\x80"));
		FAIL_IF_NOT(test_ft_strcmp("\x80", "\x7F"));

	
		return(1);
	}

