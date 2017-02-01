/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:42:37 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/01 12:51:19 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>

#include <unistd.h>

#ifdef DONT_HAVE_STRLCPY

size_t	strlcat(char *dst, const char *src, size_t size);
char	*strnstr(const char *haystack, const char *needle, size_t len);

#endif

void ft_perror(char *msg)
{
	ft_putendl_fd(msg, 2);
}

int		fork_test(int (*f)())
{
	pid_t pid = fork();
	if (pid == -1) {
		ft_perror("fork failed");
		_exit(EXIT_FAILURE);
	}else if (pid == 0){
       
        if ((*f)())
			_exit(EXIT_SUCCESS);
		else
			_exit(EXIT_SUCCESS);
	}else{
		int status;
		(void)waitpid(pid, &status, 0);
		if(status == -1){
			switch(errno){
			case ECHILD:
				ft_putendl("Fork : The calling process has no existing unwaited-for child processes");
				break;
			case EFAULT:
				ft_putendl("Fork : The status or rusage argument points to an illegal address (may not be detected before the exit of a child process).");
				break;
			case EINVAL:
				ft_putendl("Fork : Invalid or undefined flags are passed in the options argument.");
				break;
			case EINTR:
				ft_putendl("Fork : The call is interrupted by a caught signal or the signal does not have the SA_RESTART flag set.");
				break;
			default:
				ft_putendl("Fork : unknow status");
				break;
			}
			ft_putendl("\n   .. KO");
			return (0);
		}else{
			ft_putendl("\n  .. OK");
			return (1);
		}
	}	
}



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

int test_ft_bzero(void *buffer, size_t size)
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

int    test_ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s, *d;
	void 	*ret;

	s = ft_memalloc(n);
	memcpy(s, src, n);
	d = (char*)dest;
	ret = ft_memcpy(dest, src, n);
	if(ret != dest)
		ft_putstr("ret != dest");
	TEST(ret == dest);
	i = 0;
	while(i < n)
	{
		if(d[i] != s[i])
		{
			ft_putstr("d["); ft_putnbr(i); ft_putstr("] != s["); ft_putnbr(i);ft_putstr("]\n");
			ft_putstr("s:\n");
			ft_print_memory(s, n);
			ft_putstr("d:\n");
			ft_print_memory(d, n);
		}
		TEST(d[i] == s[i]);
		i++;
	}
	ft_strdel(&s);
	return (1);
}

int    test_ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;
	void	*r;

	s = ft_memalloc(n);
	ft_memcpy(s, src, n);
	r = ft_memccpy(dest, src, c, n);
	d = (char*)dest;
	i = 0;
	while(i < n)
	{
		if(d[i] != s[i])
		{
			ft_putstr("d["); ft_putnbr(i); ft_putstr("] != s["); ft_putnbr(i);ft_putstr("]\n");
			ft_putstr("s:\n");
			ft_print_memory(s, i);
			ft_putstr("d:\n");
			ft_print_memory(d, i);
		}
		TEST(d[i] == s[i]);
		if(s[i] == (char)c)
			break;
		i++;
	}
	TEST((size_t)(r - dest) == (i + 1));
	ft_strdel(&s);
	return (1);
}
int	test_ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	char	*origin;

	origin = ft_memalloc(n);
	memcpy(origin, src, n);

	ft_putendl("\nft_memmove(dest, src, n)");
	ft_putendl("src :");
	ft_print_memory(src, n);
	ft_putendl("dest :");
	ft_print_memory(dest, n);
	ft_putstr("n="); ft_putnbr(n); ft_putendl("\n");

	if(dest <= src && src <= dest + n)
	{
		ft_putendl("\ncas 1\n");
		ft_memcpy(dest, src, n);
	}
	else if (src <= dest && dest < src + n)
	{
		size_t	k = dest - src;

		ft_putendl("\ncas 2\n");
		s = ft_memalloc(n + k);
		ft_memcpy(s, src, n + k);
		d = s + k;
		TEST(ft_strnequ(s, src, n));

		ft_putendl("before ft_memmove(dest, src, n)");
		ft_putendl("d :");
		ft_print_memory(d, n);
		ft_putendl("s :");
		ft_print_memory(s, n); 

		memmove(d, s, n);
		ft_memmove(dest, src, n);

		if(memcmp(d, dest, n) != 0)
		{
			ft_putendl("after  ft_memmove(dest, src, n)");
			ft_putendl("d :");
			ft_print_memory(d, n);
			ft_putendl("dest :");
			ft_print_memory(dest, n);
		}	
		TEST(memcmp(d, dest, n) == 0);

		i = 0;
		while(i < n)
		{
			TEST(d[i] == origin[i]);
			i++;
		}

		ft_strdel(&s);
	}
	else 
	{
		ft_putendl("\ncas 3\n");
		d = ft_memalloc(n);
		s = ft_memalloc(n);
		ft_memcpy(s, src, n);
		ft_memcpy(d, dest, n);

		memmove(d, s, n);
		ft_memmove(dest, src, n);

		TEST(memcmp(d, dest, n) == 0);

		i = 0;
		while(i < n)
		{
			TEST(d[i] == s[i]);
			i++;
		}
		ft_strdel(&d);
		ft_strdel(&s);
	}		
	ft_strdel(&origin);

	return (1);
}
int	test_ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	void	*r;
	size_t	l;

	s = (char*)src;
	r = ft_memchr(src, c, n);
	if (r != NULL)
	{
		l = (r - src);
		i = 0;
		while(i < l)
		{
			TEST(s[i] != c);
			i++;
		}
		TEST(s[i] == c);
	}
	else
	{
		i = 0;
		while(i < n)
		{
			TEST(s[i] != c);
			i++;
		}
	}
	return (1);
}

int     test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n) == memcmp(s1,s2,n));
}

int	test_ft_strequ(const char *s1, const char *s2)
{
	if(!s1 || !s2)
	{	
		TEST(((s1 == s2) && ft_strequ(s1, s2)) || ((s1 != s2) && !ft_strequ(s1, s2)));
	}
	return (1);
}

int	test_ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if(!s1 || !s2)
	{	
		TEST(((s1 == s2) && ft_strnequ(s1, s2, n)) || ((s1 != s2) && !ft_strnequ(s1, s2, n)));
	}
	return (1);
}


int	test_ft_strdel(size_t size)
{
	char	*t = ft_memalloc(size);

	ft_strdel(&t);
	TEST(t == NULL);
	return (1);
}

int     test_ft_strlen(char *str)
{
	return (ft_strlen(str) == strlen(str));
}

int		test_ft_strdup(char *str)
{
	char 	*t;
	int 	r;

	t = ft_strdup(str);
	r = ft_strcmp(t, str);
	ft_strdel(&t);
	return (r==0);
}

int test_ft_strcpy(char *dest, char *src)
{
	char	*t;
	t = ft_strcpy(dest, src);
	TEST(t == dest);
	return (ft_strcmp(dest, src)==0);
}

int	test_ft_strncpy(char *dest, char *src, size_t n)
{
	char	*t;
	t = ft_strncpy(dest, src, n);

	TEST(t == dest);
	TEST(strncmp(dest, src, n) == ft_strncmp(dest, src, n));
	if (ft_strncmp(dest, src, n) != 0)
	{
		ft_putstr("src:\n");
		ft_print_memory(src, n);
		ft_putstr("dest:\n");
		ft_print_memory(dest, n);
	}
	return (ft_strncmp(dest, src, n)==0);
}

int		test_ft_strcat(char *dest, char *src)
{
	char	*buff;
	char	*ret;
	int		t;

	buff = ft_memalloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strcpy(buff, dest);
	ret = ft_strcat(dest, src);
	TEST(ret == dest);
	strcat(buff, src);
	t = ft_strcmp(buff, dest);
	ft_strdel(&buff);
	return (t == 0);
}

int		test_ft_strncat(char *dest, char *src, size_t n)
{
	char	*buff;
	char	*ret;
	int		t;

	buff = ft_memalloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strncpy(buff, dest, n);
	ret = ft_strncat(dest, src, n);
	TEST(ret == dest);
	strncat(buff, src, n);
	t = ft_strncmp(buff, dest, n);
	if (t !=0)
	{
		ft_putstr("ft_strncmp(buff, dest, n) = ");	ft_putnbr(t); 
		ft_putstr("\nn = ");	ft_putnbr(n); 
		ft_putendl("\nbuff:");
		ft_print_memory(buff, n);
		ft_putendl("\ndest:");
		ft_print_memory(dest, n);
	}
	ft_strdel(&buff);
	TEST(t==0);
	return (1);
}

int		test_ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t 	r1;
	size_t	r2;

	d = (char*)ft_memalloc(size+strlen(dst)+1);
	ft_bzero(d, size+strlen(dst)+1);
	ft_strcpy(d, dst);

	r1 = strlcat(d, src, size);
	r2 = ft_strlcat(dst, src, size);

	if (ft_strncmp(d, dst, size) != 0 || r1!= r2)
	{
		ft_putstr("ft_strncmp(d, dst, size) != 0\n");
		ft_putstr("size = \""); ft_putnbr(size); ft_putstr("\"\n");
		ft_putstr("src  = \""); ft_putstr((char*)src); ft_putstr("\"\n");
		ft_putstr("d    = \""); ft_putstr(d); ft_putstr("\"\n");
		ft_putstr("dst = \""); ft_putstr(dst); ft_putstr("\"\n");

		ft_putstr("strlcat(d, src, size) = "); ft_putnbr(r1); ft_putstr("\n");
		ft_putstr("ft_strlcat(d, src, size) = "); ft_putnbr(r2); ft_putstr("\n");
	}

	TEST(ft_strncmp(d, dst, size)==0);
	TEST(r1 == r2);

	ft_strdel(&d);
	return (1);
}

int		test_ft_strchr(const char *s, int c)
{
	char *o, *m;
	o = strchr(s,c);
	m = ft_strchr(s, c);
	TEST(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0));
	return (1);
}

int 	test_ft_strrchr(const char *s, int c)
{
	char	*o;
	char	*m;

	o = strrchr(s, c);
	m = ft_strrchr(s, c);
	if (!(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0)))
	{
		ft_putstr(o?"o != NULL\n":"o == NULL\n");
		if(o) { SHOW_STRING("trrchr(s, c) = ", o); }
		ft_putstr(m?"m != NULL\n":"m == NULL\n");
		if(m) { SHOW_STRING("ft_strrchr(s, c) = ", m); }
	}
	TEST(((o==NULL) && (m==NULL)) || ((o!=NULL) && (m!=NULL) && ft_strcmp(o, m) == 0));
	TEST(strrchr(s,c) == ft_strrchr(s, c)); //?
	return (1);
}

int		test_ft_strstr(const char *big, const char *little)
{
	char	*o;
	char	*m;
	size_t	l;

	o = strstr(big, little);
	m = ft_strstr(big, little);
	l = strlen(little);
	TEST(((o==NULL) && (m==NULL)) 
			|| ((o!=NULL) && (m!=NULL) 
				&& strncmp(o, little, l) == 0 
				&& ft_strncmp(m, little, l) == 0));
	return (1);
}
#include <stdio.h>
int		test_ft_strnstr(const char *big, const char *little, size_t size)
{
	char	*o;
	char	*m;
	size_t	l;

	o = strnstr(big, little, size);
	m = ft_strnstr(big, little, size);
	l = strlen(little);
	if(!(((o==NULL) && (m==NULL)) 
			|| ((o!=NULL) && (m!=NULL) 
				&& strncmp(o, little, l) == 0 
				&& ft_strncmp(m, little, l) == 0)))
	{
		ft_putstr("error in test_ft_strnstr(big = \""); ft_putstr(big);
		ft_putstr("\", little=\""); ft_putstr(little);
		ft_putstr("\", sise="); ft_putnbr(size);
		ft_putstr(")\n");
	
		ft_putstr("strnstr(big, little, size) = \""); ft_putstr(o);
		ft_putstr("\"\nft_strnstr(big, little, size) = \""); ft_putstr(m);
		ft_putstr("\"\n");
	}
	TEST(((o==NULL) && (m==NULL)) 
			|| ((o!=NULL) && (m!=NULL) 
				&& strncmp(o, little, l) == 0 
				&& ft_strncmp(m, little, l) == 0));
	return (1);
}

static int sign(int i)
{
	return (i > 0 ? 1 : (i == 0 ? 0 : -1));
}
int     test_ft_strcmp(char const *s1, char const *s2)
{
	if (sign(strcmp(s1, s2)) != sign(ft_strcmp(s1, s2)))
	{
		SHOW_STRING("", s1);
		SHOW_STRING("", s2);
		ft_putstr("strcmp(s1, s2) = "); ft_putnbr(strcmp(s1, s2)); ft_putstr("\n");
		ft_putstr("ft_strcmp(s1, s2) = "); ft_putnbr(ft_strcmp(s1, s2)); ft_putstr("\n");
	}
	TEST(sign(strcmp(s1, s2)) == sign(ft_strcmp(s1, s2)));
	return (1);
}

int     test_ft_strncmp(char *s1, char *s2, size_t size)
{
	{
		char *os1, *os2;

		os1 = ft_strdup(s1);
		os2 = ft_strdup(s2);

		ft_strncmp(s1, s2, size);
		TEST(ft_strncmp(s1, os1, size) == 0);
		TEST(ft_strncmp(s2, os2, size) == 0);
		ft_strdel(&os1); 
		ft_strdel(&os2);
	}
	if (sign(strncmp(s1, s2, size)) != sign(ft_strncmp(s1, s2, size)))
	{
		SHOW_STRING(" ", s1);
		SHOW_STRING(" ", s2);
		ft_putstr("strncmp(s1, s2, size) = "); ft_putnbr(strncmp(s1, s2, size)); ft_putstr("\n");
		ft_putstr("ft_strncmp(s1, s2, size) = "); ft_putnbr(ft_strncmp(s1, s2, size)); ft_putstr("\n");
	}
	TEST(sign(strncmp(s1, s2, size)) == sign(ft_strncmp(s1, s2, size)));
	return (1);
}


int     test_ft_isalpha(int c)
{
	TEST(!!isalpha(c) == !!ft_isalpha(c));
	return (1);
}

int     test_ft_isdigit(int c)
{
	TEST(!!isdigit(c) == !!ft_isdigit(c));
	return (1);
}

int     test_ft_isalnum(int c)
{
	TEST(!!isalnum(c) == !!ft_isalnum(c));
	return (1);
}

int     test_ft_isascii(int c)
{
	TEST(!!isascii(c) == !!ft_isascii(c));
	return (1);
}

int     test_ft_isprint(int c)
{
	TEST(!!isprint(c) == !!ft_isprint(c));
	return (1);
}

int     test_ft_toupper(int c)
{
	int	 o, m;

	o = toupper(c);
	m = ft_toupper(c);
	if (o != m)
	{
		ft_putstr("   toupper("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(o); ft_putstr("'\n");
		ft_putstr("ft_toupper("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(m); ft_putstr("'\n");
	}
	TEST(o == m);
	return (1);
}

int     test_ft_tolower(int c)
{
	int o, m;
	o = tolower(c);
	m = ft_tolower(c);
	if (o != m)
	{
		ft_putstr("   tolower("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(o); ft_putstr("'\n");
		ft_putstr("ft_tolower("); ft_putnbr(c); ft_putstr(") = '"); ft_putchar(m); ft_putstr("'\n");
	}
	TEST(o == m);
	return (1);
}

int    test_ft_memalloc(size_t size)
{
	void	*o;
	void	*m;
	char	*t;
	size_t	i;

	m = ft_memalloc(size);
	if (m)
	{
		t = (char*)m;
		i = 0;
		while (i < size)
		{
			TEST(t[i] == 0);
			i++;
		}
		free(m);
	}
	o = malloc(size);
	free(o);
	TEST((m && o) || (!m && !o));
	return (1);
}

int		test_ft_memdel(size_t size)
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

void strtter_func_upper(char *c)
{
	*c = ft_toupper(*c);
}
void strtter_func_lower(char *c)
{
	*c = ft_tolower(*c);
}

void strtteri_func_upper(unsigned int i, char *s)
{
	i = 0+i;
	*s = ft_toupper(*s);
}
void strtteri_func_lower(unsigned int i, char *s)
{
	i = 0+i;
	*s = ft_tolower(*s);
}

char strmap_func_upper(char c)
{
	return ((char)toupper((int)c));
}
char strmap_func_lower(char c)
{
	return ((char)tolower((int)c));
}

char	strmapi_func_upper(unsigned i, char c)
{
	if (i < 512)
		return (ft_toupper(c));
	return (c);
}

char	strmapi_func_lower(unsigned i, char c)
{
	if (i < 512)
		return (ft_tolower(c));
	return (c);
}



#include <stdio.h>
void	lst_show_elt(t_list *l)
{
	char *	elt;

	elt = (char *)(l->content);
	//printf("%p:[content:%p(\"%s\"), size:%zu, next:%p]\n", l, elt, l->content_size ? (elt?elt:""):"(O-sized)", l->content_size, l->next);
	ft_putaddr(l); 
	ft_putstr(":[content:");	ft_putaddr(elt); 
	ft_putstr("(\"");			ft_putstr(l->content_size>0 ? elt : "");
	ft_putstr("\"), size:");	ft_putnbr(l->content_size);
	ft_putstr(", next:");		ft_putaddr(l->next);
	ft_putstr("]\n");
}

void	lst_show_lst(t_list *l)
{
	while(l)
	{
		lst_show_elt(l);
		l = l->next;
	}
}

void func_del_for_ft_lstmap(void* data, size_t size)
{
	char *   elt;

	elt = (char *)data;
	if (!elt)
		ft_putstr("func_del_for_ft_lstmap *NULL !\n");
	else	
	{ 
		ft_putstr("func_del_for_ft_lstmap ");
		ft_putaddr(elt); 
		if (elt) { 
			ft_putstr("(\""); ft_putstr(size > 0 ? elt : ""); ft_putstr("\")"); 
		} 
		ft_putstr(", size ");	ft_putnbr(size);
		ft_putstr("\n");

		ft_memdel(&data);
	}
}

static t_list *func_for_ft_lstmap(t_list *elem)
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

t_list* func2_for_lstmap(t_list *elt)
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

t_list  *lstmap_test_fn(t_list *list)
{ //copiryght moolitest
	t_list  *l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = ft_memalloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}


	//ft_memalloc
int test_00()
	{
		char    *buffer;
		int		i;

		buffer = NULL;
		FAIL_IF_NOT((buffer = ft_memalloc(0)) != NULL);
		ft_strdel(&buffer);
		/*buffer = malloc(BIG);
		if(buffer)
		{
			ft_strdel(&buffer);
			buffer = ft_memalloc(BIG);
			FAIL_IF_NOT(buffer != NULL);
			for (i = 0; i < BIG; i++)
				buffer[i] = (char)(i+1);
		}
		ft_strdel(&buffer);*/
		buffer = ft_memalloc(256);
		FAIL_IF_NOT(buffer != NULL);
		for (i = 0; i < 255; i++)
			buffer[i] = (char)(i+1);
		buffer[255] = '\0';

		//ft_memset
		FAIL_IF_NOT(test_ft_memset(buffer, 0, 61));
		FAIL_IF_NOT(test_ft_memset(buffer, 'Z', 40));
		FAIL_IF_NOT(test_ft_memset(buffer, 'Y', 20));
		FAIL_IF_NOT(test_ft_memset(buffer, 'X', 10));
	
		//ft_bzero
		FAIL_IF_NOT(test_ft_bzero(buffer+2, 20));

		ft_strdel(&buffer);
		return(1);
	}	
	//ft_memcpy
int test_01()
	{
		int i;
		char buffer[256];
		char buffer2[256];
		
		ft_memset(buffer, 'X', 255);
		buffer[255] = '\0';
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10 + i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memcpy(buffer2, buffer, 255));
		FAIL_IF_NOT(test_ft_memcpy(buffer + 5, buffer + 10, 10));
		FAIL_IF_NOT(test_ft_memcpy(buffer, buffer + 26, 10));
	
		return(1);
	}

int test_02()
	{//ft_memccpy
		int i;
		char buffer[256];
		char buffer2[255];
		ft_bzero(buffer2, 255);
		ft_memset(buffer, 'X', 59);
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10+i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 6, '7', 10));
		FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 4, '7', 10));
		FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 2, '7', 10));
		FAIL_IF_NOT(test_ft_memccpy(buffer2, buffer + 3, '7', 10));
		FAIL_IF_NOT(test_ft_memccpy(buffer + 20, buffer + 5, '7', 10));
		FAIL_IF_NOT(test_ft_memccpy(buffer + 20, buffer + 5, '7' , 10));
	
		return (1);
	}

	//ft_memmove
int test_03()	{
		int i;
		char	O123456789abcdefghijklmnopqrstuvwxyz[60];

		ft_memset(O123456789abcdefghijklmnopqrstuvwxyz, 'X', 59);
		O123456789abcdefghijklmnopqrstuvwxyz[59]='\0';
		for (i=0; i<10; i++)
			O123456789abcdefghijklmnopqrstuvwxyz[i] = '0' + i;
		for (i=0; i<26; i++)
			O123456789abcdefghijklmnopqrstuvwxyz[10+i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memmove(O123456789abcdefghijklmnopqrstuvwxyz + 10, O123456789abcdefghijklmnopqrstuvwxyz + 5, 10));

		ft_memset(O123456789abcdefghijklmnopqrstuvwxyz, 'X', 59);
		O123456789abcdefghijklmnopqrstuvwxyz[36]='\0';


		char	*abcdef___ = O123456789abcdefghijklmnopqrstuvwxyz;

		ft_strcpy(abcdef___, "abcdef\0\0\0");
		FAIL_IF_NOT(ft_memcmp(ft_memmove(abcdef___ + 2 , abcdef___, 6), "abcdef", 6)==0);
		FAIL_IF_NOT(ft_memcmp(abcdef___, "ababcdef", 8)==0);
		ft_strcpy(abcdef___, "abcdef\0\0\0");
		FAIL_IF_NOT(test_ft_memmove(abcdef___ + 2 , abcdef___, 6));
	
		return(1);
	}		

int test_04()	{//memchr
		int i;
		char	buffer[256];

		ft_memset(buffer, 'X', 59);
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10+i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memchr(buffer , 'X', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '0', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '8', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '9', 10));
	
		return(1);
	}

int test_05()	{// ft_memcmp
		char	*a = "12345\0""12345\0";
		char	*b = a+6;
		char	*c = "12346";
		FAIL_IF_NOT(test_ft_memcmp(a,a,6));
		FAIL_IF_NOT(test_ft_memcmp(a,b,6));
		FAIL_IF_NOT(test_ft_memcmp(a+1,b,6));
		FAIL_IF_NOT(test_ft_memcmp(a,c,6));
		FAIL_IF_NOT(test_ft_memcmp(c,a,6));
	
		return(1);
	}

int test_06()	{ // ft_strdup
		char *text = "hello world!";
		FAIL_IF_NOT(test_ft_strdup(text));
		FAIL_IF_NOT(test_ft_strdup("&AFsd1''2\t3\n4+-{}5\0""67890"));
		FAIL_IF_NOT(test_ft_strdup(""));
	
		return(1);
	}

int test_07()	{//ft_strlen
		char *a = "hello";
		char *b = "";
		char *c = "world!\n";
		FAIL_IF_NOT(test_ft_strlen(a));
		FAIL_IF_NOT(test_ft_strlen(b));
		FAIL_IF_NOT(test_ft_strlen(c));
	
		return(1);
	}
	
int test_08()	{//strcpy
		char *src = "1234567890";
		char dst[100];
		ft_bzero(dst,100);
		ft_strcpy(dst, src);
		FAIL_IF_NOT(ft_memcmp(src, dst, 11) == 0);
		
		return(1);
}

int test_09()	{//strncpy
		char *src = "1234567890";
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst, '.', 30);
		FAIL_IF_NOT(test_ft_strncpy(dst, src, 8));
		FAIL_IF_NOT(test_ft_strncpy(dst, src, 12));
	
		return(1);
	}

int test_10()	{//strcat
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst+1, 'y', 29);
		FAIL_IF_NOT(test_ft_strcat(dst, ""));
		FAIL_IF_NOT(test_ft_strcat(dst, "12345"));
		FAIL_IF_NOT(test_ft_strcat(dst, "abcd"));
		FAIL_IF_NOT(test_ft_strcat(dst, ""));
		FAIL_IF_NOT(test_ft_strcat(dst, "X"));
		FAIL_IF_NOT(ft_strequ(dst, "12345abcdX"));
	
		return(1);
	}
int test_11()	{//strncat
		char dst[31];
		ft_bzero(dst, 31);
		FAIL_IF_NOT(test_ft_strncat(dst, "xxx", 0));
		FAIL_IF_NOT(ft_strequ(dst, ""));
		FAIL_IF_NOT(test_ft_strncat(dst, "1xx", 1));
		FAIL_IF_NOT(ft_strequ(dst, "1"));
		FAIL_IF_NOT(test_ft_strncat(dst, "23x", 2));
		FAIL_IF_NOT(ft_strequ(dst, "123"));
		FAIL_IF_NOT(test_ft_strncat(dst, "456", 3));
		FAIL_IF_NOT(ft_strequ(dst, "123456"));
		FAIL_IF_NOT(test_ft_strncat(dst, "789", 4));
		FAIL_IF_NOT(ft_strequ(dst, "123456789"));
		FAIL_IF_NOT(test_ft_strncat(dst, "abc", 5));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abc"));
		FAIL_IF_NOT(test_ft_strncat(dst, "", 	0));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abc"));
		FAIL_IF_NOT(test_ft_strncat(dst, "",	5));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abc"));
		FAIL_IF_NOT(test_ft_strncat(dst, "X", 1));
		FAIL_IF_NOT(ft_strequ(dst, "123456789abcX"));
	
		return(1);
	}
int test_12()
	{
		char *s = NULL;
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("  test1   ")), "test1"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" \n \t bidule \n \t ")), "bidule"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" \t\f\r\n ")), ""));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("  \t \n   ")), ""));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" a ")), "a"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("\n")), ""));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim("\t")), ""));
		ft_strdel(&s);
#ifdef PROTECTED_TEST		
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(NULL)), NULL));
		ft_strdel(&s);
#endif
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(" \176			 ")), "\176"));
		ft_strdel(&s);
		char a_strange_char[] = { '-', '>', 0xF0, 0x9D, 0x84, 0x9E, '<', '-', '\0' };
		FAIL_IF_NOT(ft_strequ((s=ft_strtrim(a_strange_char)), a_strange_char));
		ft_strdel(&s);
	
		return(1);
	}
int test_13()
	{//strtrim
		char *txt = " Ceci, est   le texte à\tdécouper...     ";
		char **tab = ft_strsplit(txt, ' ');
		int i;
		FAIL_IF_NOT(tab && *tab && **tab);
		FAIL_IF_NOT(ft_strequ(tab[0], "Ceci,"));
		FAIL_IF_NOT(ft_strequ(tab[1], "est"));
		FAIL_IF_NOT(ft_strequ(tab[2], "le"));
		FAIL_IF_NOT(ft_strequ(tab[3], "texte"));
		FAIL_IF_NOT(ft_strequ(tab[4], "à\tdécouper..."));
		FAIL_IF_NOT(tab[5] == NULL);
		for (i=0; i<5; i++)
			ft_memdel((void**)(tab + i));
		ft_memdel((void*)&tab);
	
		return(1);
	}
int test_14()
	{//strlcat
		char vide31[31];
		char abcde31[31];
		//		ft_bzero(vide31, 31);  
		//		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 1));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 2));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 3));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 4));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 5));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 6));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 7));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 8));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 9));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 11));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 12));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 0));

		/*ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		  FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", -1));


		  ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		  FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", -10));
		  */

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 0));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 1));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 2));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 4));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 5));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 6));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "12345", 7));

		ft_bzero(vide31, 31); 
		FAIL_IF_NOT(test_ft_strlcat(vide31, "", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "1", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "123", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "1234", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "12345", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "123456", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "1234567890", 10));

		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		FAIL_IF_NOT(test_ft_strlcat(abcde31, "123456789012", 10));
	
		return(1);
	}
int test_15()
	{//strchr
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '6'));
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", 'X'));
		FAIL_IF_NOT(test_ft_strchr("", 'X'));
		FAIL_IF_NOT(test_ft_strchr("12345678\0""901234567890", '0'));
		FAIL_IF_NOT(test_ft_strchr("123456\t78901234567890", '\t'));
		/*failed !!	FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0')); */
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0'));
	
		return(1);
	}
int test_16()
	{//strrchr
		FAIL_IF_NOT(test_ft_strrchr("12345678901234567890", '6'));
		FAIL_IF_NOT(test_ft_strrchr("12345678901234567890", 'X'));
		FAIL_IF_NOT(test_ft_strrchr("", 'X'));
		FAIL_IF_NOT(test_ft_strrchr("12345678\0""901234567890", '0'));
		FAIL_IF_NOT(test_ft_strrchr("12345678\0""901234567890", '\0'));
		FAIL_IF_NOT(test_ft_strrchr("123456\t78901234567890", '\t'));
		char *abcd = "abcd";
		FAIL_IF_NOT(ft_strrchr(abcd, 'a') == abcd);
		FAIL_IF_NOT(ft_strrchr(abcd, 'b') == abcd + 1);
		FAIL_IF_NOT(ft_strrchr(abcd, 'X') == NULL);
		FAIL_IF_NOT(ft_strrchr(abcd, '\0') == abcd + 4);
	
		return(1);
	}
int test_17()
	{//ft_strstr
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz","Bar"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Bar Baz","Bar"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz","Bat"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz",""));
		FAIL_IF_NOT(test_ft_strstr("","Bat"));
		FAIL_IF_NOT(test_ft_strstr("",""));
	
		return(1);
	}

int test_18()
	{//ft_strnstr
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 7));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 8));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 30));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Bar Baz","Bar", 15));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", 8));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", 30));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 6));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","", 6));
		FAIL_IF_NOT(test_ft_strnstr("","Bar", 6));
		FAIL_IF_NOT(test_ft_strnstr("","", 6));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", 0));
		for (int i=-1; i< 30; i++)
		{
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Bar Baz","Bar", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bat", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","", i));
		FAIL_IF_NOT(test_ft_strnstr("","Bar", i));
		FAIL_IF_NOT(test_ft_strnstr("","", i));
		FAIL_IF_NOT(test_ft_strnstr("Foo Bar Baz","Bar", i));
		}
	
		return(1);
	}
int test_19()
	{//ft_strcmp

		FAIL_IF_NOT(test_ft_strcmp("1234", "1234"));
		FAIL_IF_NOT(test_ft_strcmp("12345", "12335"));
		FAIL_IF_NOT(test_ft_strcmp("12345", "12355"));
		FAIL_IF_NOT(test_ft_strcmp("12345", "1234"));
		FAIL_IF_NOT(test_ft_strcmp("1234", "12345"));
		FAIL_IF_NOT(test_ft_strcmp("1234", ""));
		FAIL_IF_NOT(test_ft_strcmp("", "12345"));
		FAIL_IF_NOT(test_ft_strcmp("", ""));

		FAIL_IF_NOT(test_ft_strcmp("\200", "\0"));
		FAIL_IF_NOT(test_ft_strcmp("0", "\200"));
		FAIL_IF_NOT(test_ft_strcmp("\200", "\177"));
		FAIL_IF_NOT(test_ft_strcmp("\177", "\200"));
		FAIL_IF_NOT(test_ft_strcmp("\x7F", "\x80"));
		FAIL_IF_NOT(test_ft_strcmp("\x80", "\x7F"));

	
		return(1);
	}
int test_20()
	{//ft_strncmp
		FAIL_IF_NOT(test_ft_strncmp("1234", "1234", 10));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12335", 10));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12355", 10));
		FAIL_IF_NOT(test_ft_strncmp("12345", "1234", 10));
		FAIL_IF_NOT(test_ft_strncmp("1234", "12345", 10));
		FAIL_IF_NOT(test_ft_strncmp("1234", "", 10));
		FAIL_IF_NOT(test_ft_strncmp("", "12345", 10));
		FAIL_IF_NOT(test_ft_strncmp("", "", 10));
		FAIL_IF_NOT(test_ft_strncmp("1234", "1234", 2));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12335",2));
		FAIL_IF_NOT(test_ft_strncmp("12345", "12355", 2));
		FAIL_IF_NOT(test_ft_strncmp("12345", "1234", 2));
		FAIL_IF_NOT(test_ft_strncmp("1234", "12345", 2));
		FAIL_IF_NOT(test_ft_strncmp("1234", "", 2));
		FAIL_IF_NOT(test_ft_strncmp("", "12345", 2));
		FAIL_IF_NOT(test_ft_strncmp("", "", 2));

		FAIL_IF_NOT(test_ft_strncmp("\200", "\0", 1));
		FAIL_IF_NOT(test_ft_strncmp("\200", "\0", 2));
		FAIL_IF_NOT(test_ft_strncmp("0", "\200", 3));
		FAIL_IF_NOT(test_ft_strncmp("\200", "\177", 4));
		FAIL_IF_NOT(test_ft_strncmp("\177", "\200", 5));
		FAIL_IF_NOT(test_ft_strncmp("\x7F", "\x80", 6));
		FAIL_IF_NOT(test_ft_strncmp("\x80", "\x7F", 7));
		int i;
		for (i = -2; i < 10; i++)
		{
			FAIL_IF_NOT(test_ft_strncmp("1234", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12335", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12355", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "", i));
			FAIL_IF_NOT(test_ft_strncmp("", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("", "", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12335",i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "12355", i));
			FAIL_IF_NOT(test_ft_strncmp("12345", "1234", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("1234", "", i));
			FAIL_IF_NOT(test_ft_strncmp("", "12345", i));
			FAIL_IF_NOT(test_ft_strncmp("", "", i));
	
			FAIL_IF_NOT(test_ft_strncmp("\200", "\0", i));
			FAIL_IF_NOT(test_ft_strncmp("\200", "\0", i));
			FAIL_IF_NOT(test_ft_strncmp("0", "\200", i));
			FAIL_IF_NOT(test_ft_strncmp("\200", "\177", i));
			FAIL_IF_NOT(test_ft_strncmp("\177", "\200", i));
			FAIL_IF_NOT(test_ft_strncmp("\x7F", "\x80", i));
			FAIL_IF_NOT(test_ft_strncmp("\x80", "\x7F", i));
		}
	
		return(1);
	}



int test_22()	{//isalpha
		FAIL_IF_NOT(test_ft_isalpha('a'));
		FAIL_IF_NOT(test_ft_isalpha('b'));
		FAIL_IF_NOT(test_ft_isalpha('z'));
		FAIL_IF_NOT(test_ft_isalpha('A'));
		FAIL_IF_NOT(test_ft_isalpha('F'));
		FAIL_IF_NOT(test_ft_isalpha('Z'));
		FAIL_IF_NOT(test_ft_isalpha(';'));
		FAIL_IF_NOT(test_ft_isalpha('0'));
		FAIL_IF_NOT(test_ft_isalpha('9'));
		FAIL_IF_NOT(test_ft_isalpha('&'));
		FAIL_IF_NOT(test_ft_isalpha('\n'));
		FAIL_IF_NOT(test_ft_isalpha('\0'));
	
		return(1);
	}
int test_23()
	{//ft_isdigit
		FAIL_IF_NOT(test_ft_isdigit('a'));
		FAIL_IF_NOT(test_ft_isdigit('A'));
		FAIL_IF_NOT(test_ft_isdigit('Z'));
		FAIL_IF_NOT(test_ft_isdigit('&'));
		FAIL_IF_NOT(test_ft_isdigit('\0'));
		FAIL_IF_NOT(test_ft_isdigit('\n'));
		FAIL_IF_NOT(test_ft_isdigit('0'));
		FAIL_IF_NOT(test_ft_isdigit('3'));
		FAIL_IF_NOT(test_ft_isdigit('9'));
	
		return(1);
	}

int test_24()
	{
		FAIL_IF_NOT(test_ft_isalnum('0'));
		FAIL_IF_NOT(test_ft_isalnum('9'));
		FAIL_IF_NOT(test_ft_isalnum('a'));
		FAIL_IF_NOT(test_ft_isalnum('z'));
		FAIL_IF_NOT(test_ft_isalnum('A'));
		FAIL_IF_NOT(test_ft_isalnum('Z'));
		FAIL_IF_NOT(test_ft_isalnum('f'));
		FAIL_IF_NOT(test_ft_isalnum('F'));
		FAIL_IF_NOT(test_ft_isalnum('%'));
		FAIL_IF_NOT(test_ft_isalnum('!'));
		FAIL_IF_NOT(test_ft_isalnum('{'));
		FAIL_IF_NOT(test_ft_isalnum('\n'));
		FAIL_IF_NOT(test_ft_isalnum('\t'));
		FAIL_IF_NOT(test_ft_isalnum('\0'));
	
		return(1);
	}

int test_25()
	{//isprint
		/*		char i;
				printf("tab = { ");
				int n=0;
				for (i=0; i<127; i++)
				if(isprint(i))
				{
				printf("'%c', ", i);
				n++;
				}
				printf("}; n=%i\n", n);*/

		FAIL_IF_NOT(test_ft_isprint('0'));
		FAIL_IF_NOT(test_ft_isprint('5'));
		FAIL_IF_NOT(test_ft_isprint(0));
		FAIL_IF_NOT(test_ft_isprint(127));
		FAIL_IF_NOT(test_ft_isprint(-1));
		FAIL_IF_NOT(test_ft_isprint('a'));
		FAIL_IF_NOT(test_ft_isprint('w'));
		FAIL_IF_NOT(test_ft_isprint('z'));
		FAIL_IF_NOT(test_ft_isprint('A'));
		FAIL_IF_NOT(test_ft_isprint('W'));
		FAIL_IF_NOT(test_ft_isprint('Z'));
		FAIL_IF_NOT(test_ft_isprint('%'));
		FAIL_IF_NOT(test_ft_isprint('\n'));
		FAIL_IF_NOT(test_ft_isprint('\t'));
		FAIL_IF_NOT(test_ft_isprint('\r'));
		FAIL_IF_NOT(test_ft_isprint('^'));
		FAIL_IF_NOT(test_ft_isprint(128));
		FAIL_IF_NOT(test_ft_isprint(129));
		FAIL_IF_NOT(test_ft_isprint(130));
		FAIL_IF_NOT(test_ft_isprint(131));
		FAIL_IF_NOT(test_ft_isprint(255));
		FAIL_IF_NOT(test_ft_isprint(-1));
		FAIL_IF_NOT(test_ft_isprint(-255));
		FAIL_IF_NOT(test_ft_isprint(256));
		FAIL_IF_NOT(test_ft_isprint(512));
#ifdef DEBUG
		for(int c=-256; c<=512; c++)
		{
			FAIL_IF_NOT(test_ft_isprint(c));
		}
#endif
	
		return(1);
	}

int test_26()
	{//toupper
		FAIL_IF_NOT(test_ft_toupper('a'));
		FAIL_IF_NOT(test_ft_toupper('j'));
		FAIL_IF_NOT(test_ft_toupper('z'));
		FAIL_IF_NOT(test_ft_toupper('A'));
		FAIL_IF_NOT(test_ft_toupper('E'));
		FAIL_IF_NOT(test_ft_toupper('Z'));
		FAIL_IF_NOT(test_ft_toupper('0'));
		FAIL_IF_NOT(test_ft_toupper('\t'));
		FAIL_IF_NOT(test_ft_toupper('\n'));
		FAIL_IF_NOT(test_ft_toupper('\0'));

#ifdef DEBUG
		for(int c=-256; c<=512; c++)
		{
			FAIL_IF_NOT(test_ft_toupper(c));
		}	
#endif
	
		return(1);
	}

int test_27()
	{//tolower
		FAIL_IF_NOT(test_ft_tolower('a'));
		FAIL_IF_NOT(test_ft_tolower('j'));
		FAIL_IF_NOT(test_ft_tolower('z'));
		FAIL_IF_NOT(test_ft_tolower('A'));
		FAIL_IF_NOT(test_ft_tolower('E'));
		FAIL_IF_NOT(test_ft_tolower('Z'));
		FAIL_IF_NOT(test_ft_tolower('0'));
		FAIL_IF_NOT(test_ft_tolower('\t'));
		FAIL_IF_NOT(test_ft_tolower('\n'));
		FAIL_IF_NOT(test_ft_tolower('\0'));
		FAIL_IF_NOT(test_ft_tolower('a' + 0x100 ));
#ifdef DEBUG
		for(int c=-1256; c<1512; c++)
		{
			FAIL_IF_NOT(test_ft_tolower(c));
		}
#endif
	
		return(1);
	}

int test_28()
	{//ft_memalloc
		FAIL_IF_NOT(test_ft_memalloc(10));
		FAIL_IF_NOT(test_ft_memalloc(0));
		//FAIL_IF_NOT(test_ft_memalloc(BIG));
	
		return(1);
	}

int test_29()
	{ //ft_memdel
		FAIL_IF_NOT(test_ft_memdel(1024));
		FAIL_IF_NOT(test_ft_memdel(0));
	//n	FAIL_IF_NOT(test_ft_memdel(BIG));
	
		return(1);
	}	


int test_30()
	{// strdel
		FAIL_IF_NOT(test_ft_strdel(10));
		FAIL_IF_NOT(test_ft_strdel(1));
		FAIL_IF_NOT(test_ft_strdel(0));
	
		return(1);
	}

int test_31()
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
	
		return(1);
	}

int test_32()
	{//ft_strclr
		char 	*ft_strclr_of_abcdef = ft_strdup("abcdef");
		ft_strclr(ft_strclr_of_abcdef);
		void	*null7 = ft_memalloc(7);
		FAIL_IF_NOT(ft_memcmp((void*)ft_strclr_of_abcdef, null7, 7) == 0);
		ft_memdel(&null7);
		ft_strdel(&ft_strclr_of_abcdef);
	
		return(1);
	}

int test_33()
	{//ft_strclr
		char 	*ft_strclr_of_vide = ft_strdup("");
		ft_strclr(ft_strclr_of_vide);
		void	*null1 = ft_memalloc(1);
		FAIL_IF_NOT(ft_memcmp((void*)ft_strclr_of_vide, null1, 1) == 0);
		ft_memdel(&null1);
		ft_strdel(&ft_strclr_of_vide);
	
		return(1);
	}

int test_34()
	{//ft_striter
		char	*t = "txtaz123HAHZ";

		char	*ft_stirter_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirter_lower_txtaz123HAHZ = ft_strdup(t);

		SHOW_STRING("before ", ft_stirter_upper_txtaz123HAHZ);
		ft_striter(ft_stirter_upper_txtaz123HAHZ, &strtter_func_upper);
		SHOW_STRING("after  ", ft_stirter_upper_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strequ(ft_stirter_upper_txtaz123HAHZ, "TXTAZ123HAHZ"));

		SHOW_STRING("before ", ft_stirter_lower_txtaz123HAHZ);
		ft_striter(ft_stirter_lower_txtaz123HAHZ, &strtter_func_lower);
		SHOW_STRING("after  ", ft_stirter_lower_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strequ(ft_stirter_lower_txtaz123HAHZ, "txtaz123hahz"));

		ft_strdel(&ft_stirter_upper_txtaz123HAHZ);
		ft_strdel(&ft_stirter_lower_txtaz123HAHZ);
	
		return(1);
	}

int test_35()
	{//ft_striteri
		char	*t = "txtaz123HAHZ";

		char	*ft_stirteri_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirteri_lower_txtaz123HAHZ = ft_strdup(t);

		SHOW_STRING("before ", ft_stirteri_upper_txtaz123HAHZ);
		ft_striteri(ft_stirteri_upper_txtaz123HAHZ, &strtteri_func_upper);
		SHOW_STRING("after  ", ft_stirteri_upper_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strequ(ft_stirteri_upper_txtaz123HAHZ, "TXTAZ123HAHZ"));

		SHOW_STRING("before ", ft_stirteri_lower_txtaz123HAHZ);
		ft_striteri(ft_stirteri_lower_txtaz123HAHZ, &strtteri_func_lower);
		SHOW_STRING("after  ", ft_stirteri_lower_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strequ(ft_stirteri_lower_txtaz123HAHZ, "txtaz123hahz"));

		ft_strdel(&ft_stirteri_upper_txtaz123HAHZ);
		ft_strdel(&ft_stirteri_lower_txtaz123HAHZ);
	
		return(1);
	}

int test_36()
{
	{//ft_strmap
		char	*ft_strmap_upper_txtaz123HAHZ;
		char	*ft_strmap_lower_txtaz123HAHZ;

		ft_strmap_upper_txtaz123HAHZ = ft_strmap("txtaz123HAHZ", &strmap_func_upper);
		SHOW_STRING("before ", ft_strmap_upper_txtaz123HAHZ);
		ft_strmap_lower_txtaz123HAHZ = ft_strmap("txtaz123HAHZ", &strmap_func_lower);
		SHOW_STRING("after  ", ft_strmap_lower_txtaz123HAHZ);

		FAIL_IF_NOT(ft_strequ(ft_strmap_upper_txtaz123HAHZ, "TXTAZ123HAHZ"));
		FAIL_IF_NOT(ft_strequ(ft_strmap_lower_txtaz123HAHZ, "txtaz123hahz"));

		ft_strdel(&ft_strmap_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmap_lower_txtaz123HAHZ);
	
	}
	{
		char *ft_strmap_of_vide = ft_strmap("", &strmap_func_upper);
		FAIL_IF_NOT(ft_strequ(ft_strmap_of_vide, ""));
		ft_strdel(&ft_strmap_of_vide);
	}
	return(1);
}

int test_37()
	{//ft_strmapi
		char	*ft_strmapi_upper_txtaz123HAHZ;
		char	*ft_strmapi_lower_txtaz123HAHZ;

		ft_strmapi_upper_txtaz123HAHZ = ft_strmapi("txtaz123HAHZ", &strmapi_func_upper);
		SHOW_STRING("before ", ft_strmapi_upper_txtaz123HAHZ);
		ft_strmapi_lower_txtaz123HAHZ = ft_strmapi("txtaz123HAHZ", &strmapi_func_lower);
		SHOW_STRING("after  ", ft_strmapi_lower_txtaz123HAHZ);

		FAIL_IF_NOT(ft_strcmp(ft_strmapi_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		FAIL_IF_NOT(ft_strcmp(ft_strmapi_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_strmapi_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmapi_lower_txtaz123HAHZ);
	
		return(1);
	}


int test_38()
	{ // strequ
		char *abcd = "abcd";
		FAIL_IF_NOT(test_ft_strequ(abcd, abcd));
		FAIL_IF_NOT(test_ft_strequ(abcd, "abcd"));
		FAIL_IF_NOT(test_ft_strequ("abcd", "abcd"));
		FAIL_IF_NOT(test_ft_strequ(abcd, "ab"));
		FAIL_IF_NOT(test_ft_strequ("ab", abcd));
		FAIL_IF_NOT(test_ft_strequ(abcd, ""));
		FAIL_IF_NOT(test_ft_strequ("", abcd));
		FAIL_IF_NOT(test_ft_strequ("", ""));
#ifdef PROTECTED_TEST
		FAIL_IF_NOT(test_ft_strequ("", NULL));
		FAIL_IF_NOT(test_ft_strequ(NULL, ""));
		FAIL_IF_NOT(test_ft_strequ(NULL, abcd));
		FAIL_IF_NOT(test_ft_strequ(abcd, NULL));
#endif
	
		return(1);
	}

int test_39()
	{ // strnequ
		char *abcd = "abcd";
		int i = 6;
		while (i > -3)
		{
			FAIL_IF_NOT(test_ft_strnequ(abcd, abcd, i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, "abcd", i));
			FAIL_IF_NOT(test_ft_strnequ("abcd", "abcd", i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, "ab", i));
			FAIL_IF_NOT(test_ft_strnequ("ab", abcd, i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, "", i));
			FAIL_IF_NOT(test_ft_strnequ("", abcd, i));
			FAIL_IF_NOT(test_ft_strnequ("", "", i));
#ifdef PROTECTED_TEST
			FAIL_IF_NOT(test_ft_strnequ("", NULL, i));
			FAIL_IF_NOT(test_ft_strnequ(NULL, "", i));
			FAIL_IF_NOT(test_ft_strnequ(NULL, abcd, i));
			FAIL_IF_NOT(test_ft_strnequ(abcd, NULL, i));
#endif
			i--;
		}
	
		return(1);
	}

int test_40()
	{	char *abcde = "abcde";
		char *xyz = "xyz";
		char *s;
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(abcde, xyz)), "abcdexyz"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(abcde, "")),"abcde"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin("", xyz)), "xyz"));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin("", "")),""));
		ft_strdel(&s);
#ifdef PROTECTED_TEST
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(abcde, NULL)),"abcde") 
				|| (s == NULL));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(NULL, xyz)),"xyz")
				|| (s == NULL));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(NULL, NULL)), "")
				|| (s == NULL));
		ft_strdel(&s);
		FAIL_IF_NOT(ft_strequ((s=ft_strjoin(NULL, "")), "")
			   	|| (s == NULL));
		ft_strdel(&s);
#endif
	
		return(1);
	}

/*	{ ici
		FAIL_IF_NOT(0);
	}

	{
		FAIL_IF_NOT(0);
	}*/


int test_41()
	{ // ftrsplit
		char	*__Ha_Ho_123______erf_ = "__Ha_Ho_123______erf_";
		char	**ftsplitresultof__Ha_Ho_123______erf_ =  ft_strsplit(__Ha_Ho_123______erf_, '_');
		int i;

		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[0], "Ha"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[1], "Ho"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[2], "123"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[3], "erf"));
		FAIL_IF_NOT(ftsplitresultof__Ha_Ho_123______erf_[4] == NULL);
		for (i=0; i < 4; i++)
			ft_strdel(ftsplitresultof__Ha_Ho_123______erf_ + i);
		ft_memdel((void**)&ftsplitresultof__Ha_Ho_123______erf_);
	
		return(1);
	}

int test_42()
	{
		char *t;

		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0)),"0"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(123)),"123"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(-10)),"-10"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(12345)),"12345"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0x7FFFFFFF)),"2147483647"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0x80000000)),"-2147483648"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa((int)0x7FFFFFFFFFFFFFFF)),"-1"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa((int)0x8000000000000000)),"0"));
		ft_strdel(&t);
	
		return(1);
	}

int test_43()
	{ // ft_lstnew  ft_lstdelone ft_lstadd ft_lstdel
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

			ft_lstdel(tst + 0, &func_del_for_ft_lstmap);
			ft_lstdel(tst + 1, &func_del_for_ft_lstmap);
			ft_lstdel(tst + 2, &func_del_for_ft_lstmap);
			ft_lstdel(tst + 3, &func_del_for_ft_lstmap);
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
				ft_lstdelone(&elt, &func_del_for_ft_lstmap);
				FAIL_IF_NOT(elt == NULL); */

		{
			size_t  l;

			l = ft_strlen(z1);
			lst = ft_lstnew(z1, l + 1);
			ft_putendl("contenu de la liste z1:");
			lst_show_lst(lst);
			ft_print_memory(lst, sizeof(t_list));
		}
		{
			size_t  l;

			l = ft_strlen(z2);
			elt = ft_lstnew(z2, l + 1);
			ft_putstr("z2:");
			lst_show_elt(elt);
			ft_print_memory(elt, sizeof(t_list));
			ft_lstadd(&lst, elt);//ft_lstnew(z2, ft_strlen(z2)+1));
			ft_putendl("contenu de la liste z1,z2:");
			lst_show_lst(lst);
		}
		elt = ft_lstnew(z3, ft_strlen(z3)+1);
		ft_putstr("z3:");
		lst_show_elt(elt);
		ft_lstadd(&lst, elt);//ft_lstnew(z3, ft_strlen(z3)+1));
		ft_putendl("contenu de la liste z1-z3:");
		lst_show_lst(lst);

		elt = ft_lstnew(z4, ft_strlen(z4)+1);
		lst_show_elt(elt);
		ft_putstr("z4:");
		ft_lstadd(&lst, elt);//ft_lstnew(z4, ft_strlen(z4)+1));
		ft_putendl("contenu de la liste z1-z4:");
		lst_show_lst(lst);

		ft_putendl("ft_lstiter(l, &lst_show_elt);");
		ft_lstiter(lst, &lst_show_elt);

		ft_putendl("m0 = ft_lstmap(&l, &f)");
		t_list	*elt0 = ft_lstmap(lst, &func_for_ft_lstmap);
		lst_show_lst(elt0); 

		ft_putendl("ft_lstdel(&l, ..");
		ft_lstdel(&lst, &func_del_for_ft_lstmap);


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

		ft_putendl("ft_lstdel(&m, ..");
		ft_lstdel(&elt0, &func_del_for_ft_lstmap);
	
		return(1);
	}


int test_44()
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

int test_45()
	{
		//strsub
		{
			char 	*abcde = "abcde";
			char	*r;
			if (!ft_strequ((r = ft_strsub(abcde, 2, 1)), "c"))
			{
				ft_putstr("ft_strsub(abcde, 2, 1) = \"");
				ft_putstr(r);
				ft_putstr("\"\n");
			}
			ft_strdel(&r);
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 1)), "c"));
			ft_strdel(&r);
		}
		{
			char 	*abcde = "abcde";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 3)), "cde"));
			ft_strdel(&r);
		}
		{
			char 	*abcde = "abcde";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 10)), "cde"));
			ft_strdel(&r);
		}

		{
			char 	*abcde = "abcde";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r = ft_strsub(abcde, 2, 0)), ""));
			ft_strdel(&r);
		}

		{
			char 	*abcde = "abcde";
			char	*ft_strsub_abcde_10_10;
			ft_strsub_abcde_10_10 = ft_strsub(abcde, 10, 10);
			if(!(ft_strsub_abcde_10_10 == NULL || ft_strequ(ft_strsub_abcde_10_10, "")))
			{
				ft_putstr("WARNING : ft_strsub(abcde, 10, 10) = ");
				ft_putendl(ft_strsub_abcde_10_10 ? ft_strsub_abcde_10_10 : "NULL");
			}
			//WARNING_IF_NOT(ft_strsub_abcde_10_10 == NULL || ft_strequ(ft_strsub_abcde_10_10, ""));
			ft_strdel(&ft_strsub_abcde_10_10);
		}
		{
			char 	*vide = "";
			char	*ft_strsub_vide_10_10;
			ft_strsub_vide_10_10 = ft_strsub(vide, 10, 10);
			if(!(ft_strsub_vide_10_10 == NULL || ft_strequ(ft_strsub_vide_10_10, "")))
			{
				ft_putstr("WARNING : ft_strsub(vide, 10, 10) = ");
				ft_putendl(ft_strsub_vide_10_10 ? ft_strsub_vide_10_10 : "NULL");
			}
			//FAIL_IF_NOT(ft_strsub_vide_10_10 == NULL || ft_strequ(ft_strsub_vide_10_10, ""));
			ft_strdel(&ft_strsub_vide_10_10);
		}

		{
			char 	*vide = "";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(vide, 0, 0)), ""));
			ft_strdel(&r);
		}

		pid_t pid = fork();
		if (pid == -1) 
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) 
		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 10, 2)), ""));
			ft_strdel(&r);
			_exit(EXIT_SUCCESS);
		}
		else 
		{
			int status;
			(void)waitpid(pid, &status, 0);
			if(status == -1)
			{
				switch(errno)
				{
					case ECHILD:
						ft_putendl("Fork : The calling process has no existing unwaited-for child processes");
						break;
					case EFAULT:
						ft_putendl("Fork : The status or rusage argument points to an illegal address (may not be detected before the exit of a child process).");
						break;
					case EINVAL:
						ft_putendl("Fork : Invalid or undefined flags are passed in the options argument.");
						break;
					case EINTR:
						ft_putendl("Fork : The call is interrupted by a caught signal or the signal does not have the SA_RESTART flag set.");
						break;
					default:
						ft_putendl("Fork : unknow status");
						break;
				}
				ft_putendl("\n   .. KO");
			}
			else
			{
				ft_putendl("\n  .. OK");
			}
		}


		pid = fork();
		if (pid == -1) 
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) 
		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 2, 10)), ""));
			ft_strdel(&r);
		}
		else 
		{
			int status;
			int ret = waitpid(pid, &status, 0);
			if (ret == 0)
				ft_putendl("\n  .. OK");
			else if (ret != -1)
			{
				if (WIFSIGNALED(status))
				{
					if (WTERMSIG(status) == SIGSEGV)
						ft_putstr("\033[33mSegmentation Fault\033[0m\n");
					/*else if (WTERMSIG(status) == SIGEMT)
						printf("\033[33mBus Error\033[0m\n");*/
					else if (WTERMSIG(status) == SIGILL)
						ft_putstr("\033[33mIllegal Instruction\033[0m\n");
					else
					{
						ft_putstr("\033[33mThe processus receive the signal ");
						ft_putnbr(WTERMSIG(status));
						ft_putstr("\033[0m\n");
					}
				}
			}
			else
				perror("fork error Waitpid");
		}

		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 2, 0)), ""));
			ft_strdel(&r);
		}
		
		pid = fork();
		if (pid == -1) 
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) 
		{
			char	*ft_strsub_NULL_0_2 = ft_strsub(NULL, 0, 2);
			FAIL_IF_NOT(ft_strsub_NULL_0_2 == NULL || ft_strequ(ft_strsub_NULL_0_2, ""));
			ft_strdel(&ft_strsub_NULL_0_2);
		}
		else 
		{
			int status;
			int ret = waitpid(pid, &status, 0);
			if (ret == 0)
				ft_putendl("\n  .. OK");
			else if (ret != -1)
			{
				if (WIFSIGNALED(status))
				{
					if (WTERMSIG(status) == SIGSEGV)
						ft_putstr("\033[33mSegmentation Fault\033[0m\n");
					/*else if (WTERMSIG(status) == SIGEMT)
						ft_putstr("\033[33mBus Error\033[0m\n");*/
					else if (WTERMSIG(status) == SIGILL)
						ft_putstr("\033[33mIllegal Instruction\033[0m\n");
					else
					{	ft_putstr("\033[33mThe processus receive the signal ");
						ft_putnbr(WTERMSIG(status));
						ft_putstr("\033[0m\n");
					}
				}
			}
			else
				perror("Waitpid");
		}
		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 0, 0)), ""));
			ft_strdel(&r);
		}

		{
			char *str = "Un jour je serai, le meilleur codeur ! ^^";

			char	* r1 = ft_strsub(str, 0, (size_t)-10);
			//			char	* r2 = ft_strsub2(str, 0, (size_t)-10);
			if (r1 == NULL)
				ft_putstr("ft_strsub(str, 0, (size_t)-10) == NULL)\n");
			else
			{
				SHOW_STRING("ft_strsub(str, 0, (size_t)-10) : ", r1);
			}
			FAIL_IF_NOT(r1 ==NULL);
			//			FAIL_IF_NOT(r2 != NULL && ft_strequ(r2, str));
			ft_strdel(&r1);
			//			ft_strdel(&r2);
		}
		{
			char 	*str = "Un jour je serai, le meilleur codeur ! ^^";

			char	*result = ft_strsub(str, 0, 0);
			if (result == NULL)
				ft_putstr("ft_strsub(str, 0, 0) == NULL)\n");
			else
			{
				SHOW_STRING("ft_strsub(str, 0, 0) : ", result);
			}
			FAIL_IF_NOT(result != NULL && ft_strequ(result, ""));
			ft_strdel(&result);
		}

		{

		  char *str = "Un jour je serai, le meilleur codeur ! ^^";

		  char	* r = ft_strsub(str, 19, (size_t)-10);
		  if (r == NULL)
		 	 ft_putstr("ft_strsub(str, 19, (size_t)-10) == NULL)\n");
		  else
		  {
		  	SHOW_STRING("ft_strsub(str, 19, (size_t)-10)", r);
		  }
		  FAIL_IF_NOT(r == NULL || ft_strcmp(r, str) == 0);
		  ft_strdel(&r);
		}
		{
			char    *str = "i just want this part #############";
			char	* r = ft_strsub(str, 5, 10);
			//				      1234567890
			FAIL_IF_NOT(ft_strequ(r, "t want thi"));
			ft_strdel(&r);
		}
		
		return(1);
	}


int test_46()
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
		lst_show_lst(lst);

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
		
		return(1);
}
int test_47()	{
		t_list	*lst = NULL;
		ft_lstadd(&lst, ft_lstnew(NULL, 1));
		ft_lstadd(&lst, ft_lstnew("#@!", 0));
#ifdef TEST_PROTECTED
		ft_lstadd(&lst, NULL);
#endif

		lst_show_lst(lst);
		ft_lstdel(&lst, &func_del_for_ft_lstmap);
	
		return(1);
	}

int main()
{
	FORK_TEST(test_00);
	FORK_TEST(test_01);
	FORK_TEST(test_02);
	FORK_TEST(test_03);
	FORK_TEST(test_04);
	FORK_TEST(test_05);
	FORK_TEST(test_06);
	FORK_TEST(test_07);
	FORK_TEST(test_08);
	FORK_TEST(test_09);
	FORK_TEST(test_10);
	FORK_TEST(test_11);
	FORK_TEST(test_12);
	FORK_TEST(test_13);
	FORK_TEST(test_14);
	FORK_TEST(test_15);
	FORK_TEST(test_16);
	FORK_TEST(test_17);
	FORK_TEST(test_18);
	FORK_TEST(test_19);
	FORK_TEST(test_20);
	FORK_TEST(test_21);
	FORK_TEST(test_22);
	FORK_TEST(test_23);
	FORK_TEST(test_24);
	FORK_TEST(test_25);
	FORK_TEST(test_26);
	FORK_TEST(test_27);
	FORK_TEST(test_28);
	FORK_TEST(test_29);
	FORK_TEST(test_30);
	FORK_TEST(test_31);
	FORK_TEST(test_32);
	FORK_TEST(test_33);
	FORK_TEST(test_34);
	FORK_TEST(test_35);
	FORK_TEST(test_36);
	FORK_TEST(test_37);
	FORK_TEST(test_38);
	FORK_TEST(test_39);
	FORK_TEST(test_40);
	FORK_TEST(test_41);
	FORK_TEST(test_42);
	FORK_TEST(test_43);
	FORK_TEST(test_44);
	FORK_TEST(test_45);
	FORK_TEST(test_46);
	FORK_TEST(test_47);

	ft_putendl("#############################################################");
	ft_putendl("##############     ALL TESTS ARE OK       ###################");
	ft_putendl("#############################################################");
	return (0);
}
