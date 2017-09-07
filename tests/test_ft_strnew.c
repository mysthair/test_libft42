#include "libft.h"
#include "test_libft.h"
#include "tests.h"




int main_test_ft_strnew()
	{//strnew
		char	*char256 = ft_strnew(256);
		int	i;
		for (i=0; i<=256; i++)
		{ 
			FAIL_IF_NOT(char256[i] == '\0');
		}
		ft_strdel(&char256);

	/*	{
			int X = 0x7FFFFFFF;
			
			ft_putstr("testons ft_strnew(0x7FFFFFFF) ..");
			
			char	*char7FFFFFFF = ft_strnew(X);
			int error_ft_strnew_7FFFFFFF = 0;
			int i;
			for (i=0; char7FFFFFFF && i<=X; i++)
			{ 
				if (char7FFFFFFF && char7FFFFFFF[i] != '\0')
					error_ft_strnew_7FFFFFFF++;
			}
			ft_strdel(&char7FFFFFFF);
			FAIL_IF_NOT(error_ft_strnew_7FFFFFFF == 0);

			ft_putendl("OK");
		}*/
	
		return(SUCCESS);
	}

