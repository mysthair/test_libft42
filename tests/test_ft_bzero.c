#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int test_ft_bzero(void *buffer, size_t size)
{
	size_t	i;
	char 	*data;

	data = (char*)buffer;

	i = 0;
	while(buffer && i < size)
	{
		data[i] = (char) i;
		i++;
	}

	ft_bzero(buffer, size);

	i = 0;
	while(i < size)
	{
		TEST(data[i] == 0);
		i++;
	}
	return (1);
}


int	main_test_ft_bzero()
{
	char	buffer[1024];
	int errors = 0;

	errors += (test_ft_bzero(buffer, 1) ? 0 :1);
	errors += (test_ft_bzero(buffer+1, 1) ? 0 :1);
	errors += (test_ft_bzero(buffer+2, 1) ? 0 :1);
	errors += (test_ft_bzero(buffer+3, 1) ? 0 :1);
	errors += (test_ft_bzero(buffer, 1024) ? 0 :1);
	errors += (test_ft_bzero(buffer, 0) ? 0 :1);
	errors += (test_ft_bzero(NULL, 0) ? 0 :1);
	//errors += (test_ft_bzero(NULL, 1) ? 0 :1);  // --> signal 11
	//errors += (test_ft_bzero(NULL, -1) ? 0 :1);  // --> signal 11

	return (errors == 0 ? 1 : 0);
}
