#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static int		test_ft_memdel(size_t size)
{
	void *ft_memdel_parameter_after_call;

	ft_memdel_parameter_after_call = ft_memalloc(size);
	if (ft_memdel_parameter_after_call)
	{
		ft_memdel(&ft_memdel_parameter_after_call);
		TEST(ft_memdel_parameter_after_call == NULL);
	}
	return (1);
}


int main_test_ft_memdel()
	{ //ft_memdel
		FAIL_IF_NOT(test_ft_memdel(1024));
		FAIL_IF_NOT(test_ft_memdel(0));
	//n	FAIL_IF_NOT(test_ft_memdel(BIG));
	
		return(1);
	}	

