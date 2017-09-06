
#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#define SUCCESS 1
#define FAILED 0

#ifdef DONT_HAVE_STRLCPY

char	*strnstr(const char *haystack, const char *needle, size_t len);

#endif



#include <stdio.h>
static int		test_ft_strnstr(const char *big, const char *little, size_t size)
{
	char	*o;
	char	*m;
	size_t	l;

	o = strnstr(big, little, size);
	m = ft_strnstr(big, little, size);
	l = strlen(little);
	if(!(((o==NULL) && (m==NULL))
		|| ((o!=NULL) && (m!=NULL)
			&& strncmp(o, little, l) == 0
			&& ft_strncmp(m, little, l) == 0)))
	{
		ft_putstr("error in test_ft_strnstr(big = \""); ft_putstr(big);
		ft_putstr("\", little=\""); ft_putstr(little);
		ft_putstr("\", size="); ft_putnbr(size);
		ft_putstr(")\n");

		ft_putstr("strnstr(big, little, size) = \""); ft_putstr(o);
		ft_putstr("\"\nft_strnstr(big, little, size) = \""); ft_putstr(m);
		ft_putstr("\"\n");
	}
	TEST((o==NULL && m==NULL) || (o!=NULL && m!=NULL));
	TEST((o==NULL && m==NULL)
		|| (o!=NULL && m!=NULL && strncmp(o, little, l) == 0  && ft_strncmp(m, little, l) == 0));
	return (SUCCESS);
}


int main_test_ft_strnstr()
	{//ft_strnstr
		int i;
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 7));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 8));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 30));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Bar Baz","Bar", 15));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", 8));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", 30));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 6));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","", 6));
		FAIL_IF_NOT(test_ft_strnstr("","Bar", 6));
		FAIL_IF_NOT(test_ft_strnstr("","", 6));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 0));

		for (i=-1; i< 30; i++)
		{
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Bar Baz","Bar", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","", i));
			FAIL_IF_NOT(test_ft_strnstr("","Bar", i));
			FAIL_IF_NOT(test_ft_strnstr("","", i));
			FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
		}

		return (SUCCESS);
	}
