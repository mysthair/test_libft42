#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <stdlib.h>

#define BIG 0xc0000000

static int    test_ft_memalloc(size_t size)
{
	void	*o;
	void	*m;
	char	*t;
	size_t	i;

	m = ft_memalloc(size);
	if (m)
	{
		t = (char*)m;
		i = 0;
		while (i < size)
		{
			TEST(t[i] == 0);
			i++;
		}
		free(m);
	}
	o = malloc(size);
	free(o);
	TEST(size == 0 || (m && o) || (!m && !o));
	return(SUCCESS);
}



static int main_test_ft_memalloc1()
{//ft_memalloc
	FAIL_IF_NOT(test_ft_memalloc(1));
	FAIL_IF_NOT(test_ft_memalloc(10));
	FAIL_IF_NOT(test_ft_memalloc(1234));
	FAIL_IF_NOT(test_ft_memalloc(16*1024));

	FAIL_IF_NOT(test_ft_memalloc(0));
	FAIL_IF_NOT(test_ft_memalloc(-1));

#ifdef DEBUG
	FAIL_IF_NOT(test_ft_memalloc(BIG));
#endif
	return(SUCCESS);
}

static int main_test_ft_memalloc2()
{	//ft_memalloc
	char    *buffer;
	int		i;

	buffer = NULL;
	FAIL_IF_NOT((buffer = ft_memalloc(0)) != NULL);
	ft_strdel(&buffer);

	buffer = ft_memalloc(256);
	FAIL_IF_NOT(buffer != NULL);
	for (i = 0; i < 255; i++)
		buffer[i] = (char)('0' + (i%10));
	buffer[255] = '\0';

	ft_strdel(&buffer);
	return(SUCCESS);
}

int main_test_ft_memalloc()
{
	return (main_test_ft_memalloc1()
		&& main_test_ft_memalloc2());
}
