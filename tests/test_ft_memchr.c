#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int	test_ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	void	*r;
	size_t	l;

	s = (char*)src;
	r = ft_memchr(src, c, n);
	if (r != NULL)
	{
		l = (r - src);
		i = 0;
		while(i < l)
		{
			TEST(s[i] != c);
			i++;
		}
		TEST(s[i] == c);
	}
	else
	{
		i = 0;
		while(i < n)
		{
			TEST(s[i] != c);
			i++;
		}
	}
	return (1);
}

int main_test_ft_memchr()	{//memchr
		int i;
		char	buffer[256];

		ft_memset(buffer, 'X', 59);
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10+i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memchr(buffer , 'X', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '0', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '8', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '9', 10));
	
		return(1);
	}

