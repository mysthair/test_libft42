#include "libft.h"
#include "test_libft.h"
#include "tests.h"
#include <ctype.h>

static int     test_ft_isprint(int c)
{
	TEST(!!isprint(c) == !!ft_isprint(c));
	return (1);
}

int main_test_ft_isprint()
	{//isprint
		/*		char i;
				printf("tab = { ");
				int n=0;
				for (i=0; i<127; i++)
				if(isprint(i))
				{
				printf("'%c', ", i);
				n++;
				}
				printf("}; n=%i\n", n);*/

		FAIL_IF_NOT(test_ft_isprint('0'));
		FAIL_IF_NOT(test_ft_isprint('5'));
		FAIL_IF_NOT(test_ft_isprint(0));
		FAIL_IF_NOT(test_ft_isprint(127));
		FAIL_IF_NOT(test_ft_isprint(-1));
		FAIL_IF_NOT(test_ft_isprint('a'));
		FAIL_IF_NOT(test_ft_isprint('w'));
		FAIL_IF_NOT(test_ft_isprint('z'));
		FAIL_IF_NOT(test_ft_isprint('A'));
		FAIL_IF_NOT(test_ft_isprint('W'));
		FAIL_IF_NOT(test_ft_isprint('Z'));
		FAIL_IF_NOT(test_ft_isprint('%'));
		FAIL_IF_NOT(test_ft_isprint('\n'));
		FAIL_IF_NOT(test_ft_isprint('\t'));
		FAIL_IF_NOT(test_ft_isprint('\r'));
		FAIL_IF_NOT(test_ft_isprint('^'));
		FAIL_IF_NOT(test_ft_isprint(128));
		FAIL_IF_NOT(test_ft_isprint(129));
		FAIL_IF_NOT(test_ft_isprint(130));
		FAIL_IF_NOT(test_ft_isprint(131));
		FAIL_IF_NOT(test_ft_isprint(255));
		FAIL_IF_NOT(test_ft_isprint(-1));
		FAIL_IF_NOT(test_ft_isprint(-255));
		FAIL_IF_NOT(test_ft_isprint(256));
		FAIL_IF_NOT(test_ft_isprint(512));
		for(int c=0; c<=0xFF; c++)
		{
			FAIL_IF_NOT(test_ft_isprint(c));
		}
#ifdef DEBUG
		for(int c=-256; c<=512; c++)
		{
			FAIL_IF_NOT(test_ft_isprint(c));
		}
#endif

		return(1);
	}
