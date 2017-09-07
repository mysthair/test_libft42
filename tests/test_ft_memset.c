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
	  if (!(data[i] == (char)value))
	  {
	    ft_putstr("in test_ft_memset(void* buffer, int value=");
	    ft_putnbr(value);
	    ft_putstr(", size_t size=");
	    ft_putnbr(size);
	    ft_putchar('\n');
	    ft_putstr("erf data[");
	    ft_putnbr(i);
	    ft_putstr("] = ");
	    ft_putnbr(data[i]);
	    ft_putstr(", not ");
	    ft_putnbr(value);
	    ft_putchar('\n');
      ft_print_memory(buffer, size);
	  }
		TEST(data[i] == (char)value);
		i++;
	}
	return (SUCCESS);
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
	FAIL_IF_NOT(test_ft_memset(buffer, 'a', 0));
	FAIL_IF_NOT(test_ft_memset(buffer, 'b', 1));
	FAIL_IF_NOT(test_ft_memset(buffer, 'c', 2));
	FAIL_IF_NOT(test_ft_memset(buffer, 'd', 3));
	FAIL_IF_NOT(test_ft_memset(buffer, 'e', 4));
	FAIL_IF_NOT(test_ft_memset(buffer, 'f', 5));
	FAIL_IF_NOT(test_ft_memset(buffer, 'g', 6));
	FAIL_IF_NOT(test_ft_memset(buffer, 'h', 7));
	FAIL_IF_NOT(test_ft_memset(buffer, 'i', 8));
	FAIL_IF_NOT(test_ft_memset(buffer, '_', 64));
	FAIL_IF_NOT(test_ft_memset(buffer, 'j', 9));
	FAIL_IF_NOT(test_ft_memset(buffer, 'k', 10));
	FAIL_IF_NOT(test_ft_memset(buffer, 'l', 11));
	FAIL_IF_NOT(test_ft_memset(buffer, 'm', 12));
	FAIL_IF_NOT(test_ft_memset(buffer, 'n', 13));
	FAIL_IF_NOT(test_ft_memset(buffer, 'o', 14));
	FAIL_IF_NOT(test_ft_memset(buffer, 'p', 15));
	FAIL_IF_NOT(test_ft_memset(buffer, 'q', 16));
	FAIL_IF_NOT(test_ft_memset(buffer, 'r', 17));
	FAIL_IF_NOT(test_ft_memset(buffer, 's', 18));
	FAIL_IF_NOT(test_ft_memset(buffer, 't', 18));
	FAIL_IF_NOT(test_ft_memset(buffer, 'u', 19));
	FAIL_IF_NOT(test_ft_memset(buffer, '\n', 61));
	FAIL_IF_NOT(test_ft_memset(buffer, 'Z', 40));
	FAIL_IF_NOT(test_ft_memset(buffer, 'Y', 20));
	FAIL_IF_NOT(test_ft_memset(buffer, 'X', 10));

	ft_strdel(&buffer);

	return(SUCCESS);
}
