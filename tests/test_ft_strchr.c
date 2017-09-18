#include "libft.h"
#include "test_libft.h"
#include "tests.h"




static int		test_ft_strchr(const char *s, int c)
{
	char *o, *m;
	o = strchr(s,c);
	m = ft_strchr(s, c);
	if(!(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0)))
	{
		ft_putstr("strchr(\"");
		ft_putstr(s);
		ft_putstr("\",");
		ft_putnbr(c);
		ft_putstr(")=");
		ft_putstr(o);
		ft_putstr("; ft_strchr(\"");
		ft_putstr(s);
		ft_putstr("\",");
		ft_putnbr(c);
		ft_putstr(")=");
		ft_putstr(m);
		ft_putstr("...\n");
	}
	TEST(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0));
	return(SUCCESS);
}

int main_test_ft_strchr()
	{//strchr
		char txt[] = "\0\0";
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '6'));
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", 'X'));
		FAIL_IF_NOT(test_ft_strchr("", 'X'));
		FAIL_IF_NOT(test_ft_strchr("12345678\0""901234567890", '0'));
		FAIL_IF_NOT(test_ft_strchr("123456\t78901234567890", '\t'));
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0'));

		int errors = 0;
		for (int i=0; i<=0x7F; i++)
		{
			if (!test_ft_strchr(txt, i))
				errors++;
			txt[0] = i;
			if (!test_ft_strchr(txt, i))
				errors++;
			/*if (!test_ft_strchr("12345678901234567890ABCDefghéçèûüœ", i))
			{
				ft_putstr("error fo i=");
				ft_putnbr(i);
				ft_putstr("\n");
				FAIL_IF_NOT(test_ft_strchr("12345678901234567890ABCDefghéçèûüœ", i));
			}*/
		}
		// FAIL_IF_NOT(test_ft_strchr(NULL, '6')); // segfault
		// FAIL_IF_NOT(test_ft_strchr("héhé", 'é')); // error: character too large for enclosing character literal type

		return(errors == 0 ? SUCCESS : FAILED);
	}
