/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:42:37 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/10 12:29:45 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

#define _STRING(x) #x
#define STRING(x) _STRING(x)
#define FT_ASSERT(cond) ft_assert(cond, __FILE__, STRING(__LINE__), #cond )

#define TEST(cond) if(!(cond)) return (0)

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
	d = dest;
	ret = ft_memcpy(dest, src, n);
	TEST(ret == dest);
	i = 0;
	while(i < n)
	{
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
	d = dest;
	i = 0;
	while(i < n)
	{
		TEST(d[i] == s[i]);
		if(s[i] == (char)c)
			break;
		i++;
	}
	TEST((size_t)(r - src) == (i));
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
	if (r == NULL)
	{
		l = (r - src) - 1;
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
	return (r);
}

int test_ft_strcpy(char *dest, char *src)
{
	char	*t;
	t = ft_strcpy(dest, src);
	TEST(t == dest);
	return (ft_strcmp(dest, src));
}

int	test_ft_strncpy(char *dest, char *src, size_t n)
{
	char	*t;
	t = ft_strncpy(dest, src, n);
	TEST(t == dest);
	return (ft_strncmp(dest, src, n));
}

int		test_ft_strcat(char *dest, char *src)
{
	char	*buff;
	char	*ret;
	int		t;

	buff = ft_malloc(ft_strlen(dest) + strlen(src) + 1);
	ft_strcpy(buff, src);
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
	ft_strncpy(buff, src, n);
	ret = ft_strncat(dest, src, n);
	TEST(ret == dest);
	strncat(buff, src, n);
	t = ft_strncmp(buff, dest, n);
	ft_free(buff);
	return (t == 0);

}

int	nest_ft_strlcat(char *dst, const char *src, size_t size)
{
	return (0);
}
size_t  test_ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	    return (0);
}
size_t  test_ft_strlcat(char *dst, const char *src, size_t size)
{
	    return (0);
}
char    *test_ft_strchr(const char *s, int c)
{
	    return (0);
}
char    *test_ft_strrchr(const char *s, int c)
{
	    return (0);
}
char    *test_ft_strstr(const char *big, const char *little)
{
	    return (0);
}
char    *test_ft_strnstr(const char *big, const char *little, size_t size)
{
	    return (0);
}
int     test_ft_strcmp(char *s1, char *s2)
{
	    return (0);
}
int     test_ft_strncmp(char *s1, char *s2, size_t size)
{
	    return (0);
}
int     test_ft_atoi(char *str)
{
	    return (0);
}
int     test_ft_isalpha(int c)
{
	    return (0);
}
int     test_ft_isdigit(int c)
{
	    return (0);
}
int     test_ft_isalnum(int c)
{
	    return (0);
}
int     test_ft_isascii(int c)
{
	    return (0);
}
int     test_ft_isprint(int c)
{
	    return (0);
}
int     test_ft_toupper(int c)
{
	    return (0);
}
int     test_ft_tolower(int c)
{
	    return (0);
}

#define TESTONS(cond) FT_ASSERT(cond); ft_putstr(STRING(cond) " .. OK\n"); 

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
		char buffer2[255];
		ft_memset(buffer, 'X', 59);
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
		char dst[31];
		ft_bzero(dst, 31);
		TESTONS(test_ft_strlcat(dst, "12345", 10));
		TESTONS(test_ft_strlcat(dst, "", 10));
		TESTONS(test_ft_strlcat(dst, "abcdef", 10));
	}

	{//strchr
		char* text = "12345678901234567890";

		TESTONS(ft_strcmp(ft_strchr(text, '6'), "678901234567890")==0);
		char *tmp = ft_strchr(text, '6');
		ft_putstr("ft_strchr(\"12345678901234567890\", '6') = \"");
		ft_putstr(tmp);ft_putstr("\"  OK\n");

		TESTONS(ft_strchr("12345678901234567890", 'X') == NULL);
		ft_putstr("ft_strchr(\"12345678901234567890\", 'X') == NULL   OK\n\n");
	}
	{//strrchr
		char* text = "123456789012345678901234567890";

		char *tmp = ft_strrchr(text, '6');
		ft_putstr("ft_strrchr(\"1234567890\", '6') = \"");
		ft_putstr(tmp);ft_putstr("\"\n");
		TESTONS(ft_strcmp(ft_strrchr(text, '6'), "67890")==0);
		ft_putstr("..  OK\n");

		TESTONS(ft_strchr("1234567890", 'X') == NULL);
		ft_putstr("ft_strchr(\"1234567890\", 'X') == NULL   OK\n\n");
	}

	{//ft_strstr
		char *l = "Foo Bar Baz";
		char *s = "Bar";
		//ptr = strstr(largestring, smallstring);
		TESTONS(ft_strstr("Foo Bar Baz","Bar")!=NULL);
		TESTONS(ft_memcmp(ft_strstr("Foo Bar Baz","Bar"), "Bar", 3)==0);
		TESTONS(ft_strstr("Foo Bar Baz","Bat")==NULL);
		TESTONS(ft_strcmp(ft_strstr(l, ""), l) == 0);
		TESTONS(ft_strstr("", s) == NULL);
	}

	{//ft_strnstr
		char *l = "Foo Bar Baz";
		char *s = "Bar";
		//ptr = strstr(largestring, smallstring);
		TESTONS(ft_strnstr("Foo Bar Baz","Bar", 7)==NULL);
		TESTONS(ft_strnstr("Foo Bar Baz","Bar", 8)!=NULL);
		TESTONS(ft_memcmp(ft_strnstr("Foo Bar Baz","Bar",8), "Bar", 3)==0);
		TESTONS(ft_strnstr("Foo Bar Baz","Bat",8)==NULL);
		TESTONS(ft_strnstr("Foo Bar Baz","Bar", 6)==NULL);
		TESTONS(ft_strcmp(ft_strnstr(l, "", 6), l) == 0);
		TESTONS(ft_strnstr("", s, 6) == NULL);
	}
	{//ft_strcmp

		TESTONS(ft_strcmp("1234", "1234") == 0);
		TESTONS(ft_strcmp("12345", "12335") > 0);
		TESTONS(ft_strcmp("12345", "12355") < 0);
		TESTONS(ft_strcmp("12345", "1234") > 0);
		TESTONS(ft_strcmp("1234", "12345") < 0);
		TESTONS(ft_strcmp("1234", "") > 0);
		TESTONS(ft_strcmp("", "12345") < 0);
		TESTONS(ft_strcmp("", "") == 0);
	}
	{//ft_strncmp
		TESTONS(ft_strncmp("1234", "1234", 10) == 0);
		TESTONS(ft_strncmp("12345", "12335", 10) > 0);
		TESTONS(ft_strncmp("12345", "12355", 10) < 0);
		TESTONS(ft_strncmp("12345", "1234", 10) > 0);
		TESTONS(ft_strncmp("1234", "12345", 10) < 0);
		TESTONS(ft_strncmp("1234", "", 10) > 0);
		TESTONS(ft_strncmp("", "12345", 10) < 0);
		TESTONS(ft_strncmp("", "", 10) == 0);
		TESTONS(ft_strncmp("1234", "1234", 2) == 0);
		TESTONS(ft_strncmp("12345", "12335",2) == 0);
		TESTONS(ft_strncmp("12345", "12355", 2) == 0);
		TESTONS(ft_strncmp("12345", "1234", 2) == 0);
		TESTONS(ft_strncmp("1234", "12345", 2) == 0);
		TESTONS(ft_strncmp("1234", "", 2) > 0);
		TESTONS(ft_strncmp("", "12345", 2) < 0);
		TESTONS(ft_strncmp("", "", 2) == 0);
	}
	
	{//ft_atoi
		TESTONS(ft_atoi("0") == 0);
		TESTONS(ft_atoi("12") == 12);
		TESTONS(ft_atoi(" 	12   ") == 12);
		TESTONS(ft_atoi("+12") == 12);
		TESTONS(ft_atoi("+12,35") == 12);
		TESTONS(ft_atoi("-83") == -83);
		TESTONS(ft_atoi("-320,5") == -320);
		TESTONS(ft_atoi("") == 0);
		TESTONS(ft_atoi(" A") == 0);
		TESTONS(ft_atoi("A12") == 0);
		TESTONS(ft_atoi("12FS0") == 12);
		TESTONS(ft_atoi(" - 4 2") == 0);
		TESTONS(ft_atoi("0xFF") == 0);
		TESTONS(ft_atoi("&x0A") == 0);
		TESTONS(ft_atoi("2147483647") == 2147483647);
		TESTONS(ft_atoi("2147483648") == -2147483648);
		TESTONS(ft_atoi("2147483649") == -2147483647);
		TESTONS(ft_atoi("-2147483647") == -2147483647);
		TESTONS(ft_atoi("-2147483648") == -2147483648);
		TESTONS(ft_atoi("-2147483649") == 2147483647);
		TESTONS(ft_atoi("9223372036854775805") == -3);
		TESTONS(ft_atoi("9223372036854775806") == -2);
		TESTONS(ft_atoi("9223372036854775807") == -1);
		TESTONS(ft_atoi("9223372036854775808") == -1);
		TESTONS(ft_atoi("9223372036854775809") == -1);
		TESTONS(ft_atoi("9223372036854775810") == -1);
		TESTONS(ft_atoi("1000000000000000000000000") == -1);
		TESTONS(ft_atoi("-9223372036854775805") == 3);
		TESTONS(ft_atoi("-9223372036854775806") == 2);
		TESTONS(ft_atoi("-9223372036854775807") == 1);
		TESTONS(ft_atoi("-9223372036854775808") == 0);
		TESTONS(ft_atoi("-9223372036854775809") == 0);
		TESTONS(ft_atoi("-9223372036854775810") == 0);
		TESTONS(ft_atoi("-1000000000000000000000000") == 0);
		TESTONS(ft_atoi("") == 0);
	}

	{//isalpha
		TESTONS(ft_isalpha('a'));
		TESTONS(ft_isalpha('b'));
		TESTONS(ft_isalpha('z'));
		TESTONS(ft_isalpha('A'));
		TESTONS(ft_isalpha('F'));
		TESTONS(ft_isalpha('Z'));
		TESTONS(!ft_isalpha(';'));
		TESTONS(!ft_isalpha('0'));
		TESTONS(!ft_isalpha('9'));
		TESTONS(!ft_isalpha('&'));
		TESTONS(!ft_isalpha('\n'));
		TESTONS(!ft_isalpha('\0'));
	}
	{//ft_isdigit
		TESTONS(!ft_isdigit('a'));
		TESTONS(!ft_isdigit('A'));
		TESTONS(!ft_isdigit('Z'));
		TESTONS(!ft_isdigit('&'));
		TESTONS(!ft_isdigit('\0'));
		TESTONS(!ft_isdigit('\n'));
		TESTONS(ft_isdigit('0'));
		TESTONS(ft_isdigit('3'));
		TESTONS(ft_isdigit('9'));
	}

	{
		TESTONS(ft_isalnum('0'));
		TESTONS(ft_isalnum('9'));
		TESTONS(ft_isalnum('a'));
		TESTONS(ft_isalnum('z'));
		TESTONS(ft_isalnum('A'));
		TESTONS(ft_isalnum('Z'));
		TESTONS(ft_isalnum('f'));
		TESTONS(ft_isalnum('F'));
		TESTONS(!ft_isalnum('%'));
		TESTONS(!ft_isalnum('!'));
		TESTONS(!ft_isalnum('{'));
		TESTONS(!ft_isalnum('\n'));
		TESTONS(!ft_isalnum('\t'));
		TESTONS(!ft_isalnum('\0'));
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

		TESTONS(ft_isprint('0'));
		TESTONS(ft_isprint('5'));
		TESTONS(!ft_isprint(0));
		TESTONS(ft_isprint(127));
		TESTONS(!ft_isprint(-1));
		TESTONS(ft_isprint('a'));
		TESTONS(ft_isprint('w'));
		TESTONS(ft_isprint('z'));
		TESTONS(ft_isprint('A'));
		TESTONS(ft_isprint('W'));
		TESTONS(ft_isprint('Z'));
		TESTONS(ft_isprint('%'));
		TESTONS(ft_isprint('\n'));
		TESTONS(ft_isprint('\t'));
		TESTONS(ft_isprint('\r'));
		TESTONS(ft_isprint('^'));
		TESTONS(!ft_isprint(128));
	}

	{//toupper
		TESTONS(ft_toupper('a')=='A');
		TESTONS(ft_toupper('j')=='J');
		TESTONS(ft_toupper('z')=='Z');
		TESTONS(ft_toupper('A')=='A');
		TESTONS(ft_toupper('E')=='E');
		TESTONS(ft_toupper('Z')=='Z');
		TESTONS(ft_toupper('0')=='0');
		TESTONS(ft_toupper('\t')=='\t');
		TESTONS(ft_toupper('\n')=='\n');
		TESTONS(ft_toupper('\0')=='\0');
	}

	ft_free(buffer);
	return (0);
}
