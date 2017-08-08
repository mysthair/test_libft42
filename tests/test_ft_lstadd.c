#include "libft.h"
#include "test_libft.h"
#include "tests.h"



int main_test_ft_lstadd()
	{
    char    *str1 = "this is", *str2 = "a test";
    t_list  a = (t_list){ .content= str1, .content_size= sizeof(char*), .next= NULL };
    t_list  b = (t_list){ .content= str2, .content_size= sizeof(char*), .next= NULL };

    t_list *lst = NULL;

    ft_lstadd(&lst, &a);

		FAIL_IF_NOT(lst == &a && lst->content == str1 && lst->next == NULL);

    ft_lstadd(&lst, &b);

		FAIL_IF_NOT(lst == &b && lst->content == str2 && lst->next == &a);
		FAIL_IF_NOT(lst->next == &a && lst->next->content == str1 && lst->next->next == NULL);

		return(1);
	}
