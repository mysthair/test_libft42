#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static void	lst_show_elt(t_list *l)
{
	char *	elt;

	elt = (char *)(l->content);
	//printf("%p:[content:%p(\"%s\"), size:%zu, next:%p]\n", l, elt, l->content_size ? (elt?elt:""):"(O-sized)", l->content_size, l->next);
	INFO(ft_putaddr(l);
	ft_putstr(":[content:");	ft_putaddr(elt);
	ft_putstr("(\"");			ft_putstr(l->content_size>0 ? elt : "");
	ft_putstr("\"), size:");	ft_putnbr(l->content_size);
	ft_putstr(", next:");		ft_putaddr(l->next);
	ft_putstr("]\n"));
}

static void	lst_show_lst(t_list *l)
{
	while(l)
	{
		lst_show_elt(l);
		l = l->next;
	}
}

static void func_del_for_ft_lstdel(void* data, size_t size)
{
	char *   elt;

	elt = (char *)data;
	if (!elt){
		//ft_putstr("func_del_for_ft_lstdel *NULL !\n");
	}else{
		/*ft_putstr("func_del_for_ft_lstdel ");
		ft_putaddr(elt);
		if (elt) {
			ft_putstr("(\""); ft_putstr(size > 0 ? elt : ""); ft_putstr("\")");
		}
		ft_putstr(", size ");	ft_putnbr(size);
		ft_putstr("\n");*/
    (void)size;
		ft_memdel(&data);
	}
}


int main_test_ft_lstdel()	{
		t_list	*lst = NULL;
		ft_lstadd(&lst, ft_lstnew(NULL, 1));
		ft_lstadd(&lst, ft_lstnew("#@!", 0));
#ifdef TEST_PROTECTED
		ft_lstadd(&lst, NULL);
#endif

		lst_show_lst(lst);
		ft_lstdel(&lst, &func_del_for_ft_lstdel);

  	FAIL_IF_NOT(lst == NULL);
		return(SUCCESS);
	}
