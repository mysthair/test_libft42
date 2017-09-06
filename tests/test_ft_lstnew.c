#include "libft.h"
#include "test_libft.h"
#include "tests.h"

static void	lst_show_elt(t_list *l)
{
	char *	elt;

	elt = (char *)(l->content);
	//printf("%p:[content:%p(\"%s\"), size:%zu, next:%p]\n", l, elt, l->content_size ? (elt?elt:""):"(O-sized)", l->content_size, l->next);
	TRACE(ft_putaddr(l);
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

static t_list *func_for_ft_lstnew(t_list *elem)
{
	char* 			buffer = NULL;
	static t_list	*tmp = NULL;
	char			*s;
	size_t			l = elem->content_size;
	size_t 			i;

	buffer = ft_strnew(l);
	tmp = (t_list*)ft_memalloc(sizeof(t_list));
	s = (char*)(elem->content);
	tmp->content_size = l;
	for (i = 0; i < l - 1; i++)
		buffer[i] = s[l - 2 - i];
	tmp->content = (void*)buffer;
	tmp->next = NULL;
	return (tmp);
}


static void func_del_for_ft_lstnew(void* data, size_t size)
{
	char *   elt;

	elt = (char *)data;
	if (!elt)
		ft_putstr("func_del_for_ft_lstnew *NULL !\n");
	else
	{
		TRACE(ft_putstr("func_del_for_ft_lstnew ");
		ft_putaddr(elt);
		if (elt) {
			ft_putstr("(\""); ft_putstr(size > 0 ? elt : ""); ft_putstr("\")");
		}
		ft_putstr(", size ");	ft_putnbr(size);
		ft_putstr("\n"));

		ft_memdel(&data);
	}
}

static int main_test_ft_lstnew_stdelone_lstadd_lstdel_lstmap()
	{ // ft_lstnew  ft_lstdelone ft_lstadd ft_lstdel lstmap
		{
			t_list	*tst[4];

			tst[0] = ft_lstnew("1", 2);
			tst[1] = ft_lstnew(NULL, 3);
			tst[2] = ft_lstnew("123", 0);
			tst[3] = ft_lstnew(NULL, 0);


			lst_show_elt(tst[0]);
			lst_show_elt(tst[1]);
			lst_show_elt(tst[2]);
			lst_show_elt(tst[3]);

			ft_lstdel(tst + 0, &func_del_for_ft_lstnew);
			ft_lstdel(tst + 1, &func_del_for_ft_lstnew);
			ft_lstdel(tst + 2, &func_del_for_ft_lstnew);
			ft_lstdel(tst + 3, &func_del_for_ft_lstnew);
		}

		const char *z1 = "hello";
		const char *z2 = "beautiful!";
		const char *z3 = "wonderfully super";
		const char *z4 = "world !";

		t_list	*lst;
		t_list	*elt;
		/*		{
				size_t 	l;

				l = ft_strlen(z1);
				elt = ft_lstnew(z1, l + 1);
				ft_putendl("elt = ft_lstnew(z1, ft_strlen(z1)+1);");
				lst_show_elt(elt);
				ft_print_memory(elt, sizeof(t_list));
				}

				ft_putendl("ft_lstdelone");
				ft_lstdelone(&elt, &func_del_for_ft_lstnew);
				FAIL_IF_NOT(elt == NULL); */

		{
			size_t  l;

			l = ft_strlen(z1);
			lst = ft_lstnew(z1, l + 1);
			TRACE(ft_putendl("contenu de la liste z1:");
			lst_show_lst(lst);
			ft_print_memory(lst, sizeof(t_list)));
		}
		{
			size_t  l;

			l = ft_strlen(z2);
			elt = ft_lstnew(z2, l + 1);
			TRACE(ft_putstr("z2:");
			lst_show_elt(elt);
			ft_print_memory(elt, sizeof(t_list)));
			ft_lstadd(&lst, elt);//ft_lstnew(z2, ft_strlen(z2)+1));
			TRACE(ft_putendl("contenu de la liste z1,z2:");
			lst_show_lst(lst));
		}
		elt = ft_lstnew(z3, ft_strlen(z3)+1);
		TRACE(ft_putstr("z3:");
		lst_show_elt(elt));
		ft_lstadd(&lst, elt);//ft_lstnew(z3, ft_strlen(z3)+1));
		TRACE(ft_putendl("contenu de la liste z1-z3:");
		lst_show_lst(lst));

		elt = ft_lstnew(z4, ft_strlen(z4)+1);
		TRACE(lst_show_elt(elt);
		ft_putstr("z4:"));
		ft_lstadd(&lst, elt);//ft_lstnew(z4, ft_strlen(z4)+1));
		TRACE(ft_putendl("contenu de la liste z1-z4:");
		lst_show_lst(lst));

		TRACE(ft_putendl("ft_lstiter(l, &lst_show_elt);"));
		ft_lstiter(lst, &lst_show_elt);

		TRACE(ft_putendl("m0 = ft_lstmap(&l, &f)"));
		t_list	*elt0 = ft_lstmap(lst, &func_for_ft_lstnew);
		TRACE(lst_show_lst(elt0));

		TRACE(ft_putendl("ft_lstdel(&l, .."));
		ft_lstdel(&lst, &func_del_for_ft_lstnew);


		t_list	*elt1 = (elt0 ? elt0->next : NULL);
		t_list	*elt2 = (elt1 ? elt1->next : NULL);
		t_list	*elt3 = (elt2 ? elt2->next : NULL);
		t_list	*elt4 = (elt3 ? elt3->next : NULL);

		if(elt0 && ft_memcmp(elt0->content, "! dlrow", 7) != 0)
		{
			ft_putendl("elt0->content \"! dlrow\" ?");
			ft_print_memory(elt0->content, 7);
			ft_print_memory("! dlrow", 7);
		}
		FAIL_IF_NOT(elt0 && ft_memcmp(elt0->content, "! dlrow", 7)==0);

		if(elt1 && ft_memcmp(elt1->content, "repus y", 7) != 0)
		{
			ft_putendl("elt1->content \"repus y\" ?");
			ft_print_memory(elt1->content, 7);
			ft_print_memory("repus y", 7);
		}
		FAIL_IF_NOT(elt1 && ft_memcmp(elt1->content, "repus y", 7)==0);

		if(elt2 && ft_memcmp(elt2->content, "!lufitu", 7) != 0)
		{
			ft_putendl("elt2->content \"!lufitu\" ?");
			ft_print_memory(elt2->content, 7);
			ft_print_memory("!lufitu", 7);
		}
		FAIL_IF_NOT(elt2 && ft_memcmp(elt2->content, "!lufitu", 7)==0);

		if(elt3 && ft_memcmp(elt3->content, "olleh", 5) != 0)
		{
			ft_putendl("elt3->content \"olleh\" ?");
			ft_print_memory(elt3->content, 5);
			ft_print_memory("olleh", 5);
			ft_putstr("ft_memcmp(elt3->content, \"olleh\", 5) = ");
			ft_putnbr(ft_memcmp(elt3->content, "olleh", 5));
			ft_putendl("");
		}
		FAIL_IF_NOT(ft_memcmp(elt3->content, "olleh", 5)==0);

		FAIL_IF_NOT(elt4 == NULL);

		TRACE(ft_putendl("ft_lstdel(&m, .."));
		ft_lstdel(&elt0, &func_del_for_ft_lstnew);

		return(1);
	}




int main_test_ft_lstnew(){
	return (main_test_ft_lstnew_stdelone_lstadd_lstdel_lstmap());
}
