#include "libft.h"
#include "tests.h"
#include "test_libft.h"

int test_ft_memset(void* buffer, int value, size_t size)
{
	size_t	i;
	char 	*data;

	ft_memset(buffer, value, size);
	data = (char*)buffer;
	i = 0;
	while(i < size)
	{	
		TEST(data[i] == (char)value);
		i++;
	}
	return (1);
}

int main_test_ft_memset()
{

	char	*buffer;
	int		i;
	
	buffer = ft_memalloc(256);
	FAIL_IF_NOT(buffer != NULL);
	for (i = 0; i < 255; i++)
		buffer[i] = (char)('0' + (i%10));
	buffer[255] = '\0';

	//ft_memset
	FAIL_IF_NOT(test_ft_memset(buffer, '\n', 61));
	FAIL_IF_NOT(test_ft_memset(buffer, 'Z', 40));
	FAIL_IF_NOT(test_ft_memset(buffer, 'Y', 20));
	FAIL_IF_NOT(test_ft_memset(buffer, 'X', 10));

	ft_strdel(&buffer);

	return(1);
}
