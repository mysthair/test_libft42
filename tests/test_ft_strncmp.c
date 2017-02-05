#include "libft.h"
#include "test_libft.h"
#include "tests.h"


static int sign(int i)
{
	return (i > 0 ? 1 : (i == 0 ? 0 : -1));
}

static int     test_ft_strncmp(char *s1, char *s2, size_t size)
{
	{
		char *os1, *os2;

		os1 = ft_strdup(s1);
		os2 = ft_strdup(s2);

		ft_strncmp(s1, s2, size);
		TEST(ft_strncmp(s1, os1, size) == 0);
		TEST(ft_strncmp(s2, os2, size) == 0);
		ft_strdel(&os1); 
		ft_strdel(&os2);
	}
	if (sign(strncmp(s1, s2, size)) != sign(ft_strncmp(s1, s2, size)))
	{
		SHOW_STRING(" ", s1);
		SHOW_STRING(" ", s2);
		ft_putstr("strncmp(s1, s2, size) = "); ft_putnbr(strncmp(s1, s2, size)); ft_putstr("\n");
		ft_putstr("ft_strncmp(s1, s2, size) = "); ft_putnbr(ft_strncmp(s1, s2, size)); ft_putstr("\n");
	}
	TEST(sign(strncmp(s1, s2, size)) == sign(ft_strncmp(s1, s2, size)));
	return (1);
}

int main_test_ft_strncmp()
	{//ft_strncmp
		FAIL_IF_NOT(test_ft_strncmp("1234", "1234", 10));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12335", 10));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12355", 10));
		FAIL_IF_NOT(test_ft_strncmp("12345", "1234", 10));
		FAIL_IF_NOT(test_ft_strncmp("1234", "12345", 10));
		FAIL_IF_NOT(test_ft_strncmp("1234", "", 10));
		FAIL_IF_NOT(test_ft_strncmp("", "12345", 10));
		FAIL_IF_NOT(test_ft_strncmp("", "", 10));
		FAIL_IF_NOT(test_ft_strncmp("1234", "1234", 2));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12335",2));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12355", 2));
		FAIL_IF_NOT(test_ft_strncmp("12345", "1234", 2));
		FAIL_IF_NOT(test_ft_strncmp("1234", "12345", 2));
		FAIL_IF_NOT(test_ft_strncmp("1234", "", 2));
		FAIL_IF_NOT(test_ft_strncmp("", "12345", 2));
		FAIL_IF_NOT(test_ft_strncmp("", "", 2));

		FAIL_IF_NOT(test_ft_strncmp("\200", "\0", 1));
		FAIL_IF_NOT(test_ft_strncmp("\200", "\0", 2));
		FAIL_IF_NOT(test_ft_strncmp("0", "\200", 3));
		FAIL_IF_NOT(test_ft_strncmp("\200", "\177", 4));
		FAIL_IF_NOT(test_ft_strncmp("\177", "\200", 5));
		FAIL_IF_NOT(test_ft_strncmp("\x7F", "\x80", 6));
		FAIL_IF_NOT(test_ft_strncmp("\x80", "\x7F", 7));
		int i;
		for (i = -2; i < 10; i++)
		{
			FAIL_IF_NOT(test_ft_strncmp("1234", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12335", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12355", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "", i));
			FAIL_IF_NOT(test_ft_strncmp("", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("", "", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12335",i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12355", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "", i));
			FAIL_IF_NOT(test_ft_strncmp("", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("", "", i));
	
			FAIL_IF_NOT(test_ft_strncmp("\200", "\0", i));
			FAIL_IF_NOT(test_ft_strncmp("\200", "\0", i));
			FAIL_IF_NOT(test_ft_strncmp("0", "\200", i));
			FAIL_IF_NOT(test_ft_strncmp("\200", "\177", i));
			FAIL_IF_NOT(test_ft_strncmp("\177", "\200", i));
			FAIL_IF_NOT(test_ft_strncmp("\x7F", "\x80", i));
			FAIL_IF_NOT(test_ft_strncmp("\x80", "\x7F", i));
		}
	
		return(1);
	}

