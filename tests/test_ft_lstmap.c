#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <stdlib.h>


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


//utilisée autre part mais où?
t_list *func_for_ft_lstmap(t_list *elem)
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

static t_list* func2_for_lstmap(t_list *elt)
{
	char	*txt;
	size_t 	size;
	t_list	*new;

	new = NULL;
	if (elt)
	{
		txt = ft_strjoin(elt->content, elt->content);
		size = ft_strlen(txt);
		new = ft_lstnew(txt, 1 + size);
		ft_strdel(&txt);
	}
	return (new);
};


static void func_del_for_ft_lstmap(void* data, size_t size)
{
	char *   elt;

	elt = (char *)data;
	if (!elt)
		ft_putstr("func_del_for_ft_lstmap *NULL !\n");
	else
	{
		TRACE(ft_putstr("func_del_for_ft_lstmap ");
		ft_putaddr(elt));
		TRACE(if (elt) {
			ft_putstr("(\""); ft_putstr(size > 0 ? elt : ""); ft_putstr("\")");
		}
		ft_putstr(", size ");	ft_putnbr(size);
		ft_putstr("\n");)

		ft_memdel(&data);
	}
}


static t_list  *lstmap_test_fn(t_list *list)
{ //copiryght moolitest
	t_list  *l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = ft_memalloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}


static int test_44()
	{ // copiright moulytest :P
		t_list  *list;
		t_list  *map;

		bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
		bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
		list->content_size = 21;
		list->content = strdup("abc");
		list->next->content_size = 100;
		list->next->content = strdup("abc");
		map = ft_lstmap(list, lstmap_test_fn);
		FAIL_IF_NOT(list->content_size == 21);
		FAIL_IF_NOT(list->next->content_size == 100);
		FAIL_IF_NOT(!!map);
		FAIL_IF_NOT(map->content_size == 42);
		FAIL_IF_NOT(!!map);
		FAIL_IF_NOT(map->next->content_size == 200);
		ft_lstdel(&list, &func_del_for_ft_lstmap);
		ft_lstdel(&map, &func_del_for_ft_lstmap);

		return(1);
	}

int main_test_ft_lstmap()
	{
		//another test for ft_lstmap
		char* tab[] = { "Un", "Deux", "Trois", "...",
						"A very long phrase... more than 20 Characters... "
						"A very long phrase... more than 20 Characters... "
						"A very long phrase... more than 20 Characters... "
						"A very long phrase... more than 20 Characters... "
						"A very long phrase... more than 20 Characters... "
						"repeted five times :P",
						"Six", "Sept", "Huit", "Neuf", "Dix"
			};
		t_list *lst = NULL;
		int i;

		for (i=0; i < 10; i++)
			ft_lstadd(&lst, ft_lstnew(tab[9 - i], 1 + ft_strlen(tab[9 - i])));
		TRACE(lst_show_lst(lst));

		t_list *lst2;
		lst2 = ft_lstmap(lst, &func2_for_lstmap);
		FAIL_IF_NOT(lst2 != NULL);
		ft_lstdel(&lst, &func_del_for_ft_lstmap);

		ft_lstiter(lst2, &lst_show_elt);

		t_list	*l = lst2;

		FAIL_IF_NOT(ft_strequ(l->content, "UnUn") && l->content_size == 5);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "DeuxDeux") && l->content_size == 9);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "TroisTrois") && l->content_size == 11);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "......") && l->content_size == 7);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... repeted five times :PA very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... A very long phrase... more than 20 Characters... repeted five times :P"));
//	ft_putnbr(lst2->content_size);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "SixSix") && l->content_size == 7);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "SeptSept") && l->content_size == 9);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "HuitHuit") && l->content_size == 9);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "NeufNeuf") && l->content_size == 9);
		l = l->next;
		FAIL_IF_NOT(ft_strequ(l->content, "DixDix") && l->content_size == 7);
		l = l->next;
		FAIL_IF_NOT(l == NULL);

		ft_lstdel(&lst2, &func_del_for_ft_lstmap);
		FAIL_IF_NOT(lst2 == NULL);

		return(test_44());
}
