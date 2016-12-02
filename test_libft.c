/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:42:37 by jleblanc          #+#    #+#             */
/*   Updated: 2016/12/02 15:00:07 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_libft.h"
#include <string.h>
#include <stdlib.h>

#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>

#define DEBUG

#define SHOW_STRING(C,  T) ft_putstr(C #T "=\""); \
	ft_putstr(T); ft_putstr("\"\n");

#ifdef DONT_HAVE_STRLCPY

size_t	strlcat(char *dst, const char *src, size_t size);
char	*strnstr(const char *haystack, const char *needle, size_t len);

#endif


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
		ft_print_memory(d, n + k);
		ft_putendl("s :");
		ft_print_memory(s, n); 

		memmove(d, s, n);
		ft_memmove(dest, src, n);

		if(memcmp(d, dest, n) != 0)
		{
			ft_putendl("after  ft_memmove(dest, src, n)");
			ft_putendl("d :");
			ft_print_memory(d, n + k);
			ft_putendl("dest :");
			ft_print_memory(dest, n + k);
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
		if(o) { SHOW_STRING(" ", o); }
		ft_putstr(m?"m != NULL\n":"m == NULL\n");
		if(m) { SHOW_STRING(" ", m); }
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

int		test_ft_strnstr(const char *big, const char *little, size_t size)
{
	char	*o;
	char	*m;
	size_t	l;

	o = strnstr(big, little, size);
	m = ft_strnstr(big, little, size);
	l = strlen(little);
	TEST(((o==NULL) && (m==NULL)) 
			|| ((o!=NULL) && (m!=NULL) 
				&& strncmp(o, little, l) == 0 
				&& ft_strncmp(m, little, l) == 0));
	return (1);
}

int     test_ft_strcmp(char const *s1, char const *s2)
{
	{
		char *os1, *os2;

		os1 = ft_strdup(s1);
		os2 = ft_strdup(s2);

		ft_strcmp(s1, s2);
		TEST(strcmp(s1, os1) == 0);
		TEST(strcmp(s2, os2) == 0);
		ft_strdel(&os1); 
		ft_strdel(&os2);
	}
	if (strcmp(s1, s2) != ft_strcmp(s1, s2))
	{
		SHOW_STRING(" ", s1);
		SHOW_STRING(" ", s2);
		ft_putstr("strcmp(s1, s2) = "); ft_putnbr(strcmp(s1, s2)); ft_putstr("\n");
		ft_putstr("ft_strcmp(s1, s2) = "); ft_putnbr(ft_strcmp(s1, s2)); ft_putstr("\n");
	}
	TEST(strcmp(s1, s2) == ft_strcmp(s1, s2));
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
	if (strncmp(s1, s2, size) != ft_strncmp(s1, s2, size))
	{
		SHOW_STRING(" ", s1);
		SHOW_STRING(" ", s2);
		ft_putstr("strncmp(s1, s2, size) = "); ft_putnbr(strncmp(s1, s2, size)); ft_putstr("\n");
		ft_putstr("ft_strncmp(s1, s2, size) = "); ft_putnbr(ft_strncmp(s1, s2, size)); ft_putstr("\n");
	}
	TEST(strncmp(s1, s2, size) == ft_strncmp(s1, s2, size));
	return (1);
}

int     test_ft_atoi(char *str)
{
	TEST(atoi(str) == ft_atoi(str));
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
	void	*p;
	char	*t;
	size_t	i;

	o = ft_memalloc(size);
	if (o)
		free(o);
	p = malloc(size);
	TEST((p && o) || (!p && !o));
	if (p)
	{
		t = (char*)p;
		i = 0;
		while (i < size)
		{
			TEST(t[i] == 0);
			i++;
		}
		free(p);
	}
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


//#define DEBUG
#ifdef DEBUG
# define FAIL_IF_NOT(cond) ft_putstr("testons " STRINGIFY(cond) " .. \n"); FT_ASSERT(cond); ft_putstr("        " STRINGIFY(cond) " .. OK\n"); 
#else
# define FAIL_IF_NOT(cond) FT_ASSERT(cond); ft_putstr(STRINGIFY(cond) " .. OK\n"); 
#endif
#define BIG (1024*1024*1024)

//#define WARNING_IF_NOT(cond) ft_putstr("testons " STRINGIFY(cond) " .. \n"); FT_WARNING(cond); ft_putstr("        " STRINGIFY(cond) " .. OK\n"); 

#include <stdio.h>
void	lst_show_elt(t_list *l)
{
	char *	elt;

	elt = (char *)(l->content);
	printf("%p:[content:%p(\"%s\"), size:%zu, next:%p]\n", l, elt, elt, l->content_size, l->next);
}

void	lst_show_lst(t_list *l)
{
	while(l)
	{
		lst_show_elt(l);
		l = l->next;
	}
}
void lst_free_elt(void* data, size_t size)
{
	char *   elt;

	elt = (char *)data;
	size = 0 + size;
	printf("freeing elt %p(\"%s\")\n", elt, elt); 
	ft_memdel(&data);
}

t_list *func_for_ft_lstmap(t_list *elem)
{
	static char* buffer = NULL;
	static t_list	*tmp = NULL;
	char	*s;
	size_t	l;
	if(buffer==NULL)
	{
		buffer = ft_memalloc(13*sizeof(char));
		tmp = (t_list*)ft_memalloc(sizeof(t_list));
	}
	s = (char*)(elem->content);
	l = ft_strlen(s);//l = (ft_strlen(s) % 10);
	//if(l == 0)
	//	return (NULL);
	tmp->content_size = l+1;
	for (size_t i=0; i<l; i++)
		buffer[i] = s[l-1-i];
	buffer[l] = '\0';
	tmp->content = (void*)buffer;
	tmp->next = NULL;
	return (tmp); 
}

t_list  *lstmap_test_fn(t_list *list)
{ //copiryght moolitest
	t_list  *l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}

int main()
{
	char    *buffer;
	int		i;

	//ft_memalloc
	buffer = NULL;
	FAIL_IF_NOT((buffer = ft_memalloc(0)) != NULL);
	ft_strdel(&buffer);
	buffer = malloc(BIG);
	if(buffer)
	{
		ft_strdel(&buffer);
		buffer = ft_memalloc(BIG);
		FAIL_IF_NOT(buffer != NULL);
		for (i = 0; i < BIG; i++)
			buffer[i] = (char)(i+1);
	}
	ft_strdel(&buffer);
	buffer = ft_memalloc(255);
	FAIL_IF_NOT(buffer != NULL);
	for (i = 0; i < 255; i++)
		buffer[i] = (char)(i+1);

	//ft_memset
	FAIL_IF_NOT(test_ft_memset(buffer, 0, 61));
	FAIL_IF_NOT(test_ft_memset(buffer, 'Z', 40));
	FAIL_IF_NOT(test_ft_memset(buffer, 'Y', 20));
	FAIL_IF_NOT(test_ft_memset(buffer, 'X', 10));

	//ft_bzero
	FAIL_IF_NOT(test_ft_bzero(buffer+2, 20));

	//ft_memcpy
	{
		int i;
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
	}

	{//ft_memccpy
		int i;
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
	}

	//ft_memmove
	{
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
	}		

	{//memchr
		int i;

		ft_memset(buffer, 'X', 59);
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10+i] = 'a' + i;
		FAIL_IF_NOT(test_ft_memchr(buffer , 'X', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '0', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '8', 10));
		FAIL_IF_NOT(test_ft_memchr(buffer , '9', 10));
	}

	{// ft_memcmp
		char	*a = "12345\0""12345\0";
		char	*b = a+6;
		char	*c = "12346";
		FAIL_IF_NOT(test_ft_memcmp(a,a,6));
		FAIL_IF_NOT(test_ft_memcmp(a,b,6));
		FAIL_IF_NOT(test_ft_memcmp(a+1,b,6));
		FAIL_IF_NOT(test_ft_memcmp(a,c,6));
		FAIL_IF_NOT(test_ft_memcmp(c,a,6));
	}

	{ // ft_strdup
		char *text = "hello world!";
		FAIL_IF_NOT(test_ft_strdup(text));
		FAIL_IF_NOT(test_ft_strdup("&AFsd1''2\t3\n4+-{}5\0""67890"));
		FAIL_IF_NOT(test_ft_strdup(""));
	}

	{//ft_strlen
		char *a = "hello";
		char *b = "";
		char *c = "world!\n";
		FAIL_IF_NOT(test_ft_strlen(a));
		FAIL_IF_NOT(test_ft_strlen(b));
		FAIL_IF_NOT(test_ft_strlen(c));
		FAIL_IF_NOT(test_ft_strlen(buffer));
	}

	{//strcpy
		char *src = "1234567890";
		char dst[100];
		ft_bzero(dst,100);
		ft_strcpy(dst, src);
		FAIL_IF_NOT(ft_memcmp(src, dst, 11) == 0);
	}

	{//strncpy
		char *src = "1234567890";
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst, '.', 30);
		FAIL_IF_NOT(test_ft_strncpy(dst, src, 8));
		FAIL_IF_NOT(test_ft_strncpy(dst, src, 12));
	}

	{//strcat
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst+1, 'y', 29);
		FAIL_IF_NOT(test_ft_strcat(dst, ""));
		FAIL_IF_NOT(test_ft_strcat(dst, "12345"));
		FAIL_IF_NOT(test_ft_strcat(dst, "abcd"));
		FAIL_IF_NOT(test_ft_strcat(dst, ""));
		FAIL_IF_NOT(test_ft_strcat(dst, "X"));
		FAIL_IF_NOT(ft_strequ(dst, "12345abcdX"));
	}
	{//strncat
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
	}
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
	}

	{//strchr
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '6'));
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", 'X'));
		FAIL_IF_NOT(test_ft_strchr("", 'X'));
		FAIL_IF_NOT(test_ft_strchr("12345678\0""901234567890", '0'));
		FAIL_IF_NOT(test_ft_strchr("123456\t78901234567890", '\t'));
		/*failed !!	FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0')); */
		FAIL_IF_NOT(test_ft_strchr("12345678901234567890", '\0'));
	}
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
	}
	{//ft_strstr
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz","Bar"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Bar Baz","Bar"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz","Bat"));
		FAIL_IF_NOT(test_ft_strstr("Foo Bar Baz",""));
		FAIL_IF_NOT(test_ft_strstr("","Bat"));
		FAIL_IF_NOT(test_ft_strstr("",""));
	}

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
	}
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

	}
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
	}

	{//ft_atoi
		FAIL_IF_NOT(test_ft_atoi("0"));// == 0);
		FAIL_IF_NOT(test_ft_atoi("12"));//  == 12);
		FAIL_IF_NOT(test_ft_atoi(" 	12   "));//  == 12);
		FAIL_IF_NOT(test_ft_atoi("+12"));//   == 12);
		FAIL_IF_NOT(test_ft_atoi("+12,35"));//   == 12);
		FAIL_IF_NOT(test_ft_atoi("-83"));//   == -83);
		FAIL_IF_NOT(test_ft_atoi("-320,5"));//   == -320);
		FAIL_IF_NOT(test_ft_atoi(""));//   == 0));
		FAIL_IF_NOT(test_ft_atoi(" A"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("A12"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("12FS0"));//   == 12);
		FAIL_IF_NOT(test_ft_atoi(" - 4 2"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("0xFF"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("&x0A"));//   == 0);
		FAIL_IF_NOT(test_ft_atoi("2147483647"));//  == 2147483647);
		FAIL_IF_NOT(test_ft_atoi("2147483648"));//  == -2147483648);
		FAIL_IF_NOT(test_ft_atoi("2147483649"));//  == -2147483647);
		FAIL_IF_NOT(test_ft_atoi("-2147483647"));//  == -2147483647);
		FAIL_IF_NOT(test_ft_atoi("-2147483648"));//  == -2147483648);
		FAIL_IF_NOT(test_ft_atoi("-2147483649"));//  == 2147483647);
		FAIL_IF_NOT(test_ft_atoi("9223372036854775805"));//  == -3);
		FAIL_IF_NOT(test_ft_atoi("9223372036854775806"));//  == -2);
		FAIL_IF_NOT(test_ft_atoi("9223372036854775807"));//  == -1);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775805"));// == 3);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775806"));// == 2);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775807"));// == 1);
		FAIL_IF_NOT(test_ft_atoi("-9223372036854775808"));// == 0);
		/* uncomment for testing the same coportment than the real atoi :
		   FAIL_IF_NOT(test_ft_atoi("9223372036854775808"));//  == -1);
		   FAIL_IF_NOT(test_ft_atoi("9223372036854775809"));//  == -1);
		   FAIL_IF_NOT(test_ft_atoi("9223372036854775810"));//  == -1);
		   FAIL_IF_NOT(test_ft_atoi("1000000000000000000000000"));//   == -1);
		   FAIL_IF_NOT(test_ft_atoi("-9223372036854775809"));// == 0);
		   FAIL_IF_NOT(test_ft_atoi("-9223372036854775810"));// == 0);
		   FAIL_IF_NOT(test_ft_atoi("-1000000000000000000000000"));//  == 0);
		   */
	}

	{//isalpha
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
	}
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
	}

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
	}

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
	}

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
	}
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
	}

	{//ft_memalloc
		FAIL_IF_NOT(test_ft_memalloc(10));
		FAIL_IF_NOT(test_ft_memalloc(0));
		FAIL_IF_NOT(test_ft_memalloc(BIG));
	}

	{ //ft_memdel
		FAIL_IF_NOT(test_ft_memdel(1024));
		FAIL_IF_NOT(test_ft_memdel(0));
		FAIL_IF_NOT(test_ft_memdel(BIG));
	}	

	{// strdel
		FAIL_IF_NOT(test_ft_strdel(10));
		FAIL_IF_NOT(test_ft_strdel(1));
		FAIL_IF_NOT(test_ft_strdel(0));
	}

	{//strnew
		char	*char30 = ft_strnew(30);
		int	i;
		for (i=0; i<=30; i++)
		{ 
			FAIL_IF_NOT(char30[i] == '\0');
		}
		ft_strdel(&char30);

		char	*char0 = ft_strnew(0);
		for (i=0; i<=0; i++)
		{ 
			FAIL_IF_NOT(char0 == NULL || char0[i] == '\0');
		}
		ft_strdel(&char0);
	}

	{//ft_strclr
		char 	*ft_strclr_of_abcdef = ft_strdup("abcdef");
		ft_strclr(ft_strclr_of_abcdef);
		void	*null7 = ft_memalloc(7);
		FAIL_IF_NOT(ft_memcmp((void*)ft_strclr_of_abcdef, null7, 7) == 0);
		ft_memdel(&null7);
		ft_strdel(&ft_strclr_of_abcdef);
	}

	{//ft_striter
		char	*t = "txtaz123HAHZ";

		char	*ft_stirter_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirter_lower_txtaz123HAHZ = ft_strdup(t);

		SHOW_STRING("before ", ft_stirter_upper_txtaz123HAHZ);
		ft_striter(ft_stirter_upper_txtaz123HAHZ, &strtter_func_upper);
		SHOW_STRING("after  ", ft_stirter_upper_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strcmp(ft_stirter_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);

		SHOW_STRING("before ", ft_stirter_lower_txtaz123HAHZ);
		ft_striter(ft_stirter_lower_txtaz123HAHZ, &strtter_func_lower);
		SHOW_STRING("after  ", ft_stirter_lower_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strcmp(ft_stirter_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_stirter_upper_txtaz123HAHZ);
		ft_strdel(&ft_stirter_lower_txtaz123HAHZ);
	}

	{//ft_striteri
		char	*t = "txtaz123HAHZ";

		char	*ft_stirteri_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirteri_lower_txtaz123HAHZ = ft_strdup(t);

		SHOW_STRING("before ", ft_stirteri_upper_txtaz123HAHZ);
		ft_striteri(ft_stirteri_upper_txtaz123HAHZ, &strtteri_func_upper);
		SHOW_STRING("after  ", ft_stirteri_upper_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strcmp(ft_stirteri_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);

		SHOW_STRING("before ", ft_stirteri_lower_txtaz123HAHZ);
		ft_striteri(ft_stirteri_lower_txtaz123HAHZ, &strtteri_func_lower);
		SHOW_STRING("after  ", ft_stirteri_lower_txtaz123HAHZ);
		FAIL_IF_NOT(ft_strcmp(ft_stirteri_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_stirteri_upper_txtaz123HAHZ);
		ft_strdel(&ft_stirteri_lower_txtaz123HAHZ);
	}

	{//ft_strmap
		char	*ft_strmap_upper_txtaz123HAHZ;
		char	*ft_strmap_lower_txtaz123HAHZ;

		ft_strmap_upper_txtaz123HAHZ = ft_strmap("txtaz123HAHZ", &strmap_func_upper);
		SHOW_STRING("after  ", ft_strmap_upper_txtaz123HAHZ);
		ft_strmap_lower_txtaz123HAHZ = ft_strmap("txtaz123HAHZ", &strmap_func_lower);
		SHOW_STRING("after  ", ft_strmap_lower_txtaz123HAHZ);

		FAIL_IF_NOT(ft_strcmp(ft_strmap_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		FAIL_IF_NOT(ft_strcmp(ft_strmap_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_strmap_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmap_lower_txtaz123HAHZ);
	}

	{//ft_strmapi
		char	*ft_strmapi_upper_txtaz123HAHZ;
		char	*ft_strmapi_lower_txtaz123HAHZ;

		ft_strmapi_upper_txtaz123HAHZ = ft_strmapi("txtaz123HAHZ", &strmapi_func_upper);
		SHOW_STRING("after  ", ft_strmapi_upper_txtaz123HAHZ);
		ft_strmapi_lower_txtaz123HAHZ = ft_strmapi("txtaz123HAHZ", &strmapi_func_lower);
		SHOW_STRING("after  ", ft_strmapi_lower_txtaz123HAHZ);

		FAIL_IF_NOT(ft_strcmp(ft_strmapi_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		FAIL_IF_NOT(ft_strcmp(ft_strmapi_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_strmapi_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmapi_lower_txtaz123HAHZ);
	}

	{ // ftrsplit
		char	*__Ha_Ho_123______erf_ = "__Ha_Ho_123______erf_";
		char	**ftsplitresultof__Ha_Ho_123______erf_ =  ft_strsplit(__Ha_Ho_123______erf_, '_');
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[0], "Ha"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[1], "Ho"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[2], "123"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[3], "erf"));
		FAIL_IF_NOT(ftsplitresultof__Ha_Ho_123______erf_[4] == NULL);
		for (int i=0; i<4; i++)
			ft_strdel(&(ftsplitresultof__Ha_Ho_123______erf_[i]));
		ft_memdel((void**)ftsplitresultof__Ha_Ho_123______erf_);
	}

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
		t = ft_itoa((int)0x7FFFFFFFFFFFFFFF);
		ft_putendl(t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0x7FFFFFFF)),"2147483647"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa(0x80000000)),"-2147483648"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa((int)0x7FFFFFFFFFFFFFFF)),"-1"));
		ft_strdel(&t);
		FAIL_IF_NOT(ft_strequ((t = ft_itoa((int)0x8000000000000000)),"0"));
		ft_strdel(&t);
	}

	{ // ft_lstnew  ft_lstdelone ft_lstadd ft_lstdel
		{
			t_list	*tst[4];

			tst[0] = ft_lstnew("1", 2);
			tst[1] = ft_lstnew("12", 3);
			tst[2] = ft_lstnew("123", 4);
			tst[3] = ft_lstnew("1234", 5);


			lst_show_elt(tst[0]);
			lst_show_elt(tst[1]);
			lst_show_elt(tst[2]);
			lst_show_elt(tst[3]);

			ft_strdel((void*)(tst + 0));
			ft_strdel((void*)(tst + 1));
			ft_strdel((void*)(tst + 2));
			ft_strdel((void*)(tst + 3));
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
				ft_lstdelone(&elt, &lst_free_elt);
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
		ft_lstdel(&lst, &lst_free_elt);


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
		ft_lstdel(&elt0, &lst_free_elt);
	}


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
	} 


	{
		//strsub
		{
			char 	*abcde = "abcde";
			char	*r;
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
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 0)), ""));
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
						printf("\033[33mSegmentation Fault\033[0m\n");
					else if (WTERMSIG(status) == SIGEMT)
						printf("\033[33mBus Error\033[0m\n");
					else if (WTERMSIG(status) == SIGILL)
						printf("\033[33mIllegal Instruction\033[0m\n");
					else
						printf("\033[33mThe processus receive the signal %d\033[0m\n", WTERMSIG(status));
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
					else if (WTERMSIG(status) == SIGEMT)
						ft_putstr("\033[33mBus Error\033[0m\n");
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

		/*{  ***crash !! ***

		  char *str = "Un jour je serai, le meilleur codeur ! ^^";

		  char	* r = ft_strsub(str, 19, (size_t)-10);
		  if (r == NULL)
		  ft_putstr("ft_strsub(str, 19, (size_t)-10) == NULL)\n");
		  else
		  {
		  SHOW_STRING("ft_strsub(str, 19, (size_t)-10)", r);
		  }
		  FAIL_IF_NOT(r != NULL && ft_strcmp(r, str) == 0); // crash?
		  ft_strdel(&r);
		  }*/
		{
			char    *str = "i just want this part #############";
			char	* r = ft_strsub(str, 5, 10);
			//				      1234567890
			FAIL_IF_NOT(ft_strequ(r, "t want thi"));
		}
	}

	ft_strdel(&buffer);
	return (0);
}
