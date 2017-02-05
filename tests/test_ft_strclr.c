#include "libft.h"
#include "test_libft.h"
#include "tests.h"



int main_test_ft_strclr()
{
	{//ft_strclr
		char 	*ft_strclr_of_abcdef = ft_strdup("abcdef");
		ft_strclr(ft_strclr_of_abcdef);
		void	*null7 = ft_memalloc(7);
		FAIL_IF_NOT(ft_memcmp((void*)ft_strclr_of_abcdef, null7, 7) == 0);
		ft_memdel(&null7);
		ft_strdel(&ft_strclr_of_abcdef);
	
		return(1);
	}

	{//ft_strclr
		char 	*ft_strclr_of_vide = ft_strdup("");
		ft_strclr(ft_strclr_of_vide);
		void	*null1 = ft_memalloc(1);
		FAIL_IF_NOT(ft_memcmp((void*)ft_strclr_of_vide, null1, 1) == 0);
		ft_memdel(&null1);
		ft_strdel(&ft_strclr_of_vide);
	
		return(1);
	}
}

