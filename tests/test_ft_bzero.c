#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int test_ft_bzero(void *buffer, size_t size)
{
	size_t	i;
	char 	*data;

	ft_bzero(buffer, size);
	data = (char*)buffer;
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
	
	errors += test_ft_bzero(buffer, 0);
	errors += test_ft_bzero(buffer, 1024);
	errors += test_ft_bzero(buffer, 0);

	return errors;
}
