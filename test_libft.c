/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:42:37 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/15 18:16:12 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

#include <ctype.h>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)
#define FT_ASSERT(cond) ft_assert(cond, __FILE__, STRINGIFY(__LINE__), #cond )

#define TEST(cond) if(!(cond)) { ft_putstr(__FILE__ ":" STRINGIFY(__LINE__) ": test (" #cond ") failed :(\n"); return (0); }

#ifdef DONT_HAVE_STRLCPY
size_t	strlcat(char *dest, char *src, size_t size)
{
  size_t    i;  
  size_t    dest_len;

  i = 0;
  dest_len = strlen(dest);
  if (size == 0)
    return dest_len;
  while (dest_len < size)
  {
    dest[dest_len] = src[i];
    dest_len++;
    i++;
  }
  dest[dest_len] = '\0';
  return (strlen(dest));
}

char *strnstr(const char *haystack, const char *needle, size_t len)
{
        int i;
        size_t needle_len;

        /* segfault here if needle is not NULL terminated */
        if (0 == (needle_len = strlen(needle)))
                return (char *)haystack;

        for (i=0; i<=(int)(len-needle_len); i++)
        {
                if ((haystack[0] == needle[0]) &&
                        (0 == strncmp(haystack, needle, needle_len)))
                        return (char *)haystack;

                haystack++;
        }
        return NULL;
}
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

	s = ft_malloc(n);
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
	ft_free(s);
	return (1);
}

int    test_ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;
	void	*r;

	s = ft_malloc(n);
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
	ft_free(s);
	return (1);
}
int	test_ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;
	
	s = ft_malloc(n);
	ft_memcpy(s, src, n);
	d = dest;
	TEST(ft_memmove(dest, src, n) == dest);;
	i = 0;
	while(i < n)
	{
		TEST(d[i] == s[i]);
		i++;
	}
	ft_free(s);
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
	ft_free(t);
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

	buff = ft_malloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strcpy(buff, dest);
	ret = ft_strcat(dest, src);
	TEST(ret == dest);
	strcat(buff, src);
	t = ft_strcmp(buff, dest);
	ft_free(buff);
	return (t == 0);
}

int		test_ft_strncat(char *dest, char *src, size_t n)
{
	char	*buff;
	char	*ret;
	int		t;

	buff = ft_malloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strncpy(buff, dest, n);
	ret = ft_strncat(dest, src, n);
	TEST(ret == dest);
	strncat(buff, src, n);
	t = ft_strncmp(buff, dest, n);
	ft_free(buff);
	return (t == 0);
}

int		test_ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t 	r1;
	size_t	r2;

	d = (char*)ft_malloc(size+1);
	ft_bzero(d, size+1);
	ft_strcpy(d, dst);

	r1 = strlcat(d, src, size);
	r2 = ft_strlcat(dst, src, size);

	if (ft_strncmp(d, dst, size) != 0 || r1!= r2)
	{
		ft_putstr("ft_strncmp(d, dst, size) != 0\n");
		ft_putstr("size = \""); ft_putnbr(size); ft_putstr("\"\n");
		ft_putstr("src  = \""); ft_putstr((char*)src); ft_putstr("\"\n");
		ft_putstr("d    = \""); ft_putstr(d); ft_putstr("\"\n");
		ft_putstr("dest = \""); ft_putstr(dst); ft_putstr("\"\n");
		
		ft_putstr("r1 = \""); ft_putnbr(r1); ft_putstr("\"\n");
		ft_putstr("r2 = \""); ft_putnbr(r2); ft_putstr("\"\n");
	}

	TEST(ft_strncmp(d, dst, size)==0);
	TEST(r1 == r2);

	ft_free(d);
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

int     test_ft_strcmp(char *s1, char *s2)
{
	TEST(strcmp(s1, s2) == ft_strcmp(s1, s2));
	return (1);
}

int     test_ft_strncmp(char *s1, char *s2, size_t size)
{
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
	TEST(isalpha(c) == ft_isalpha(c));
	return (1);
}

int     test_ft_isdigit(int c)
{
	TEST(isdigit(c) == ft_isdigit(c));
	return (1);
}

int     test_ft_isalnum(int c)
{
	TEST(isalnum(c) == ft_isalnum(c));
    return (1);
}

int     test_ft_isascii(int c)
{
	TEST(isascii(c) == ft_isascii(c));
	return (1);
}

int     test_ft_isprint(int c)
{
	TEST(isprint(c) == ft_isprint(c));
    return (1);
}

int     test_ft_toupper(int c)
{
	char o, m;
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
	char o, m;
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

	o = ft_malloc(size);
	if (o)
		ft_free(o);
	p = ft_memalloc(size);
	//TEST(sizeof(p) == size);
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

//int		test_ft_striter(char *s, void (*f)(char *))
//{
void strtter_func_upper(char *c)
{
	*c = ft_toupper(*c);
}
void strtter_func_lower(char *c)
{
	*c = ft_tolower(*c);
}
//}

//int		test_ft_striteri(char *s, void (*f)(unsigned int, char *))
//{
void strtteri_func_upper(unsigned int i, char *s)
{
	s[i] = ft_toupper(s[i]);
}
void strtteri_func_lower(unsigned int i, char *s)
{
	s[i] = ft_tolower(s[i]);
}
//}

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
# define TESTONS(cond) ft_putstr("testons " STRINGIFY(cond) "\n"); FT_ASSERT(cond); ft_putstr(STRINGIFY(cond) " .. OK\n"); 
#else
# define TESTONS(cond) FT_ASSERT(cond); ft_putstr(STRINGIFY(cond) " .. OK\n"); 
#endif
#define BIG (1024*1024*1024)

int main()
{
        char    *buffer;
		int		i;

        //ft_malloc
		buffer = NULL;
		TESTONS((buffer = ft_malloc(0)) != NULL);
		ft_free(buffer);
        buffer = ft_malloc(BIG);
        TESTONS(buffer != NULL);
		for (i = 0; i < BIG; i++)
			buffer[i] = (char)(i+1);
		ft_free(buffer);
		buffer = ft_malloc(255);
        TESTONS(buffer != NULL);
		for (i = 0; i < 255; i++)
			buffer[i] = (char)(i+1);

	//ft_memset
	TESTONS(test_ft_memset(buffer, 0, 61));
   	TESTONS(test_ft_memset(buffer, 'Z', 40));
	TESTONS(test_ft_memset(buffer, 'Y', 20));
	TESTONS(test_ft_memset(buffer, 'X', 10));

	//ft_bzero
	TESTONS(test_ft_bzero(buffer+2, 20));

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
		TESTONS(test_ft_memcpy(buffer2, buffer, 255));
		TESTONS(test_ft_memcpy(buffer + 5, buffer + 10, 10));
		TESTONS(test_ft_memcpy(buffer, buffer + 26, 10));
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
		TESTONS(test_ft_memccpy(buffer2, buffer + 6, '7', 10));
		TESTONS(test_ft_memccpy(buffer2, buffer + 4, '7', 10));
		TESTONS(test_ft_memccpy(buffer2, buffer + 2, '7', 10));
		TESTONS(test_ft_memccpy(buffer2, buffer + 3, '7', 10));
		TESTONS(test_ft_memccpy(buffer + 20, buffer + 5, '7', 10));
		TESTONS(test_ft_memccpy(buffer + 20, buffer + 5, '7' , 10));
	}

	//ft_memmove
	{
		int i;

		ft_memset(buffer, 'X', 59);
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10+i] = 'a' + i;
		TESTONS(test_ft_memmove(buffer + 10, buffer + 5, 10));
	}		

	{//memchr
		int i;

		ft_memset(buffer, 'X', 59);
		for (i=0; i<10; i++)
			buffer[i] = '0' + i;
		for (i=0; i<26; i++)
			buffer[10+i] = 'a' + i;
		TESTONS(test_ft_memchr(buffer , 'X', 10));
		TESTONS(test_ft_memchr(buffer , '0', 10));
		TESTONS(test_ft_memchr(buffer , '8', 10));
		TESTONS(test_ft_memchr(buffer , '9', 10));
	}

	{// ft_memcmp
		char	*a = "12345\0""12345\0";
		char	*b = a+6;
		char	*c = "12346";
		TESTONS(test_ft_memcmp(a,a,6));
		TESTONS(test_ft_memcmp(a,b,6));
		TESTONS(test_ft_memcmp(a+1,b,6));
		TESTONS(test_ft_memcmp(a,c,6));
		TESTONS(test_ft_memcmp(c,a,6));
	}

	{ // ft_strdup
		char *text = "hello world!";
		TESTONS(test_ft_strdup(text));
		TESTONS(test_ft_strdup("&AFsd1''2\t3\n4+-{}5\0""67890"));
		TESTONS(test_ft_strdup(""));
	}

	{//ft_strlen
		char *a = "hello";
		char *b = "";
		char *c = "world!\n";
		TESTONS(test_ft_strlen(a));
		TESTONS(test_ft_strlen(b));
		TESTONS(test_ft_strlen(c));
		TESTONS(test_ft_strlen(buffer));
	}

	{//strcpy
		char *src = "1234567890";
		char dst[100];
		ft_bzero(dst,100);
		ft_strcpy(dst, src);
		TESTONS(ft_memcmp(src, dst, 11) == 0);
	}

	{//strncpy
		char *src = "1234567890";
		char dst[31];
		ft_bzero(dst, 31);
		ft_memset(dst, '.', 30);
		TESTONS(test_ft_strncpy(dst, src, 8));
		TESTONS(test_ft_strncpy(dst, src, 12));
	}

	{//strcat
		char dst[31];
		ft_bzero(dst, 31);
		TESTONS(test_ft_strcat(dst, "12345"));
		TESTONS(test_ft_strcat(dst, "abcd"));
		TESTONS(test_ft_strcat(dst, ""));
		TESTONS(test_ft_strcat(dst, "X"));
	}
	{//strlcat
		char vide31[31];
		char abcde31[31];
		ft_bzero(vide31, 31); 
		TESTONS(test_ft_strlcat(vide31, "12345", 10));
		
		ft_bzero(vide31, 31); 
		TESTONS(test_ft_strlcat(vide31, "", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "1", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "12", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "123", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "1234", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "12345", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "123456", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "1234567890", 10));
		
		ft_bzero(abcde31, 31); strcpy(abcde31, "abcde");
		TESTONS(test_ft_strlcat(abcde31, "123456789012", 10));
	}

	{//strchr
		TESTONS(test_ft_strchr("12345678901234567890", '6'));
		TESTONS(test_ft_strchr("12345678901234567890", 'X'));
		TESTONS(test_ft_strchr("", 'X'));
		TESTONS(test_ft_strchr("12345678\0""901234567890", '0'));
		TESTONS(test_ft_strchr("123456\t78901234567890", '\t'));
/*failed !!	TESTONS(test_ft_strchr("12345678901234567890", '\0')); */
		TESTONS(test_ft_strchr("12345678901234567890", '\0'));
	}
	{//strrchr
		TESTONS(test_ft_strrchr("12345678901234567890", '6'));
		TESTONS(test_ft_strrchr("12345678901234567890", 'X'));
		TESTONS(test_ft_strrchr("", 'X'));
		TESTONS(test_ft_strrchr("12345678\0""901234567890", '0'));
		TESTONS(test_ft_strrchr("123456\t78901234567890", '\t'));
	}
	{//ft_strstr
		TESTONS(test_ft_strstr("Foo Bar Baz","Bar"));
		TESTONS(test_ft_strstr("Foo Bar Bar Baz","Bar"));
		TESTONS(test_ft_strstr("Foo Bar Baz","Bat"));
		TESTONS(test_ft_strstr("Foo Bar Baz",""));
		TESTONS(test_ft_strstr("","Bat"));
		TESTONS(test_ft_strstr("",""));
	}

	{//ft_strnstr
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bar", 7));
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bar", 8));
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bar", 30));
		TESTONS(test_ft_strnstr("Foo Bar Bar Baz","Bar", 15));
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bat", 8));
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bat", 30));
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bar", 6));
		TESTONS(test_ft_strnstr("Foo Bar Baz","", 6));
		TESTONS(test_ft_strnstr("","Bar", 6));
		TESTONS(test_ft_strnstr("","", 6));
		TESTONS(test_ft_strnstr("Foo Bar Baz","Bar", 0));
	}
	{//ft_strcmp

		TESTONS(test_ft_strcmp("1234", "1234"));
		TESTONS(test_ft_strcmp("12345", "12335"));
		TESTONS(test_ft_strcmp("12345", "12355"));
		TESTONS(test_ft_strcmp("12345", "1234"));
		TESTONS(test_ft_strcmp("1234", "12345"));
		TESTONS(test_ft_strcmp("1234", ""));
		TESTONS(test_ft_strcmp("", "12345"));
		TESTONS(test_ft_strcmp("", ""));
	}
	{//ft_strncmp
		TESTONS(test_ft_strncmp("1234", "1234", 10));
		TESTONS(test_ft_strncmp("12345", "12335", 10));
		TESTONS(test_ft_strncmp("12345", "12355", 10));
		TESTONS(test_ft_strncmp("12345", "1234", 10));
		TESTONS(test_ft_strncmp("1234", "12345", 10));
		TESTONS(test_ft_strncmp("1234", "", 10));
		TESTONS(test_ft_strncmp("", "12345", 10));
		TESTONS(test_ft_strncmp("", "", 10));
		TESTONS(test_ft_strncmp("1234", "1234", 2));
		TESTONS(test_ft_strncmp("12345", "12335",2));
		TESTONS(test_ft_strncmp("12345", "12355", 2));
		TESTONS(test_ft_strncmp("12345", "1234", 2));
		TESTONS(test_ft_strncmp("1234", "12345", 2));
		TESTONS(test_ft_strncmp("1234", "", 2));
		TESTONS(test_ft_strncmp("", "12345", 2));
		TESTONS(test_ft_strncmp("", "", 2));
	}
	
	{//ft_atoi
		TESTONS(test_ft_atoi("0"));// == 0);
		TESTONS(test_ft_atoi("12"));//  == 12);
		TESTONS(test_ft_atoi(" 	12   "));//  == 12);
		TESTONS(test_ft_atoi("+12"));//   == 12);
		TESTONS(test_ft_atoi("+12,35"));//   == 12);
		TESTONS(test_ft_atoi("-83"));//   == -83);
		TESTONS(test_ft_atoi("-320,5"));//   == -320);
		TESTONS(test_ft_atoi(""));//   == 0));
		TESTONS(test_ft_atoi(" A"));//   == 0);
		TESTONS(test_ft_atoi("A12"));//   == 0);
		TESTONS(test_ft_atoi("12FS0"));//   == 12);
		TESTONS(test_ft_atoi(" - 4 2"));//   == 0);
		TESTONS(test_ft_atoi("0xFF"));//   == 0);
		TESTONS(test_ft_atoi("&x0A"));//   == 0);
		TESTONS(test_ft_atoi("2147483647"));//  == 2147483647);
		TESTONS(test_ft_atoi("2147483648"));//  == -2147483648);
		TESTONS(test_ft_atoi("2147483649"));//  == -2147483647);
		TESTONS(test_ft_atoi("-2147483647"));//  == -2147483647);
		TESTONS(test_ft_atoi("-2147483648"));//  == -2147483648);
		TESTONS(test_ft_atoi("-2147483649"));//  == 2147483647);
		TESTONS(test_ft_atoi("9223372036854775805"));//  == -3);
		TESTONS(test_ft_atoi("9223372036854775806"));//  == -2);
		TESTONS(test_ft_atoi("9223372036854775807"));//  == -1);
		TESTONS(test_ft_atoi("9223372036854775808"));//  == -1);
		TESTONS(test_ft_atoi("9223372036854775809"));//  == -1);
		TESTONS(test_ft_atoi("9223372036854775810"));//  == -1);
		TESTONS(test_ft_atoi("1000000000000000000000000"));//   == -1);
		TESTONS(test_ft_atoi("-9223372036854775805"));// == 3);
		TESTONS(test_ft_atoi("-9223372036854775806"));// == 2);
		TESTONS(test_ft_atoi("-9223372036854775807"));// == 1);
		TESTONS(test_ft_atoi("-9223372036854775808"));// == 0);
		TESTONS(test_ft_atoi("-9223372036854775809"));// == 0);
		TESTONS(test_ft_atoi("-9223372036854775810"));// == 0);
		TESTONS(test_ft_atoi("-1000000000000000000000000"));//  == 0);
		TESTONS(test_ft_atoi(""));//  == 0);
	}

	{//isalpha
		TESTONS(test_ft_isalpha('a'));
		TESTONS(test_ft_isalpha('b'));
		TESTONS(test_ft_isalpha('z'));
		TESTONS(test_ft_isalpha('A'));
		TESTONS(test_ft_isalpha('F'));
		TESTONS(test_ft_isalpha('Z'));
		TESTONS(test_ft_isalpha(';'));
		TESTONS(test_ft_isalpha('0'));
		TESTONS(test_ft_isalpha('9'));
		TESTONS(test_ft_isalpha('&'));
		TESTONS(test_ft_isalpha('\n'));
		TESTONS(test_ft_isalpha('\0'));
	}
	{//ft_isdigit
		TESTONS(test_ft_isdigit('a'));
		TESTONS(test_ft_isdigit('A'));
		TESTONS(test_ft_isdigit('Z'));
		TESTONS(test_ft_isdigit('&'));
		TESTONS(test_ft_isdigit('\0'));
		TESTONS(test_ft_isdigit('\n'));
		TESTONS(test_ft_isdigit('0'));
		TESTONS(test_ft_isdigit('3'));
		TESTONS(test_ft_isdigit('9'));
	}

	{
		TESTONS(test_ft_isalnum('0'));
		TESTONS(test_ft_isalnum('9'));
		TESTONS(test_ft_isalnum('a'));
		TESTONS(test_ft_isalnum('z'));
		TESTONS(test_ft_isalnum('A'));
		TESTONS(test_ft_isalnum('Z'));
		TESTONS(test_ft_isalnum('f'));
		TESTONS(test_ft_isalnum('F'));
		TESTONS(test_ft_isalnum('%'));
		TESTONS(test_ft_isalnum('!'));
		TESTONS(test_ft_isalnum('{'));
		TESTONS(test_ft_isalnum('\n'));
		TESTONS(test_ft_isalnum('\t'));
		TESTONS(test_ft_isalnum('\0'));
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

		TESTONS(test_ft_isprint('0'));
		TESTONS(test_ft_isprint('5'));
		TESTONS(test_ft_isprint(0));
		TESTONS(test_ft_isprint(127));
		TESTONS(test_ft_isprint(-1));
		TESTONS(test_ft_isprint('a'));
		TESTONS(test_ft_isprint('w'));
		TESTONS(test_ft_isprint('z'));
		TESTONS(test_ft_isprint('A'));
		TESTONS(test_ft_isprint('W'));
		TESTONS(test_ft_isprint('Z'));
		TESTONS(test_ft_isprint('%'));
		TESTONS(test_ft_isprint('\n'));
		TESTONS(test_ft_isprint('\t'));
		TESTONS(test_ft_isprint('\r'));
		TESTONS(test_ft_isprint('^'));
		TESTONS(test_ft_isprint(128));
		TESTONS(test_ft_isprint(129));
		TESTONS(test_ft_isprint(130));
		TESTONS(test_ft_isprint(131));
		TESTONS(test_ft_isprint(255));
		TESTONS(test_ft_isprint(-1));
		TESTONS(test_ft_isprint(-255));
		TESTONS(test_ft_isprint(256));
		TESTONS(test_ft_isprint(512));
#ifdef DEBUG
		for(int c=-256; c<=512; c++)
		{
			TESTONS(test_ft_isprint(c));
		}
#endif
	}

	{//toupper
		TESTONS(test_ft_toupper('a'));
		TESTONS(test_ft_toupper('j'));
		TESTONS(test_ft_toupper('z'));
		TESTONS(test_ft_toupper('A'));
		TESTONS(test_ft_toupper('E'));
		TESTONS(test_ft_toupper('Z'));
		TESTONS(test_ft_toupper('0'));
		TESTONS(test_ft_toupper('\t'));
		TESTONS(test_ft_toupper('\n'));
		TESTONS(test_ft_toupper('\0'));
#ifdef DEBUG
		for(int c=-256; c<=512; c++)
		{
			TESTONS(test_ft_toupper(c));
		}	
#endif
	}
	{//tolower
		TESTONS(test_ft_tolower('a'));
		TESTONS(test_ft_tolower('j'));
		TESTONS(test_ft_tolower('z'));
		TESTONS(test_ft_tolower('A'));
		TESTONS(test_ft_tolower('E'));
		TESTONS(test_ft_tolower('Z'));
		TESTONS(test_ft_tolower('0'));
		TESTONS(test_ft_tolower('\t'));
		TESTONS(test_ft_tolower('\n'));
		TESTONS(test_ft_tolower('\0'));
#ifdef DEBUG
		for(int c=-256; c<512; c++)
		{
			TESTONS(test_ft_tolower(c));
		}
#endif
	}

	{//ft_memalloc
		TESTONS(test_ft_memalloc(10));
		TESTONS(test_ft_memalloc(0));
		TESTONS(test_ft_memalloc(1024 * BIG));
	}
	
	{ //ft_memdel
		TESTONS(test_ft_memdel(1024));
		TESTONS(test_ft_memdel(0));
	}	
	
#define SHOW_STRING(C,  T) ft_putstr(C #T "=\""); \
	ft_putstr(T); ft_putstr("\"\n");
	
	{//ft_striter
		char	*t = "txtaz123HAHZ";

		char	*ft_stirter_upper_txtaz123HAHZ = ft_strdup(t);
		char	*ft_stirter_lower_txtaz123HAHZ = ft_strdup(t);

		SHOW_STRING("before ", ft_stirter_upper_txtaz123HAHZ);
		ft_striter(ft_stirter_upper_txtaz123HAHZ, &strtter_func_upper);
		SHOW_STRING("after  ", ft_stirter_upper_txtaz123HAHZ);
		TESTONS(ft_strcmp(ft_stirter_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		
		SHOW_STRING("before ", ft_stirter_lower_txtaz123HAHZ);
		ft_striter(ft_stirter_lower_txtaz123HAHZ, &strtter_func_lower);
		SHOW_STRING("after  ", ft_stirter_lower_txtaz123HAHZ);
		TESTONS(ft_strcmp(ft_stirter_lower_txtaz123HAHZ, "txtaz123hahz") == 0);
		
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
		TESTONS(ft_strcmp(ft_stirteri_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		
		SHOW_STRING("before ", ft_stirteri_lower_txtaz123HAHZ);
		ft_striteri(ft_stirteri_lower_txtaz123HAHZ, &strtteri_func_lower);
		SHOW_STRING("after  ", ft_stirteri_lower_txtaz123HAHZ);
		TESTONS(ft_strcmp(ft_stirteri_lower_txtaz123HAHZ, "txtaz123hahz") == 0);
		
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

		TESTONS(ft_strcmp(ft_strmap_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		TESTONS(ft_strcmp(ft_strmap_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

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

		TESTONS(ft_strcmp(ft_strmapi_upper_txtaz123HAHZ, "TXTAZ123HAHZ") == 0);
		TESTONS(ft_strcmp(ft_strmapi_lower_txtaz123HAHZ, "txtaz123hahz") == 0);

		ft_strdel(&ft_strmapi_upper_txtaz123HAHZ);
		ft_strdel(&ft_strmapi_lower_txtaz123HAHZ);
	}

	ft_free(buffer);
	return (0);
}
