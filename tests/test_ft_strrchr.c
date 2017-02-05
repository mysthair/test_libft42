#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int 	test_ft_strrchr(const char *s, int c)
{
	char	*o;
	char	*m;

	o = strrchr(s, c);
	m = ft_strrchr(s, c);
	if (!(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0)))
	{
		ft_putstr(o?"o != NULL\n":"o == NULL\n");
		if(o) { SHOW_STRING("trrchr(s, c) = ", o); }
		ft_putstr(m?"m != NULL\n":"m == NULL\n");
		if(m) { SHOW_STRING("ft_strrchr(s, c) = ", m); }
	}
	TEST(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0));
	TEST(strrchr(s,c) == ft_strrchr(s, c)); //?
	return (1);
}

int main_test_ft_strrchr()
	{//strrchr
		FAIL_IF_NOT(test_ft_strrchr("12345678901234567890", '6'));
		FAIL_IF_NOT(test_ft_strrchr("12345678901234567890", 'X'));
		FAIL_IF_NOT(test_ft_strrchr("", 'X'));
		FAIL_IF_NOT(test_ft_strrchr("12345678\0""901234567890", '0'));
		FAIL_IF_NOT(test_ft_strrchr("12345678\0""901234567890", '\0'));
		FAIL_IF_NOT(test_ft_strrchr("123456\t78901234567890", '\t'));
		char *abcd = "abcd";
		FAIL_IF_NOT(ft_strrchr(abcd, 'a') == abcd);
		FAIL_IF_NOT(ft_strrchr(abcd, 'b') == abcd + 1);
		FAIL_IF_NOT(ft_strrchr(abcd, 'X') == NULL);
		FAIL_IF_NOT(ft_strrchr(abcd, '\0') == abcd + 4);
	
		return(1);
	}

