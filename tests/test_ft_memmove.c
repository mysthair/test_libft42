#include "libft.h"
#include "test_libft.h"
#include "tests.h"


static int	test_ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	char	*origin;

	origin = ft_memalloc(n);
	memcpy(origin, src, n);


	if(dest <= src && src <= dest + n)
	{
		INFO(ft_putendl("\ncas 1\n");)
		ft_memcpy(dest, src, n);
	}
	else if (src <= dest && dest < src + n)
	{
		size_t	k = dest - src;

		INFO(ft_putendl("\ncas 2\n");)
		s = ft_memalloc(n + k);
		ft_memcpy(s, src, n + k);
		d = s + k;
		TEST(ft_strnequ(s, src, n));

		INFO(ft_putendl("before ft_memmove(dest, src, n)");
		ft_putendl("d :");
		ft_print_memory(d, n);
		ft_putendl("s :");
		ft_print_memory(s, n);)

		memmove(d, s, n);
		ft_memmove(dest, src, n);

		if(memcmp(d, dest, n) != 0)
		{
			ft_putendl("\nft_memmove(dest, src, n)");
			ft_putendl("src :");
			ft_print_memory(src, n);
			ft_putendl("dest :");
			ft_print_memory(dest, n);
			ft_putstr("n="); ft_putnbr(n); ft_putendl("\n");



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
		INFO(ft_putendl("\ncas 3\n");)
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

	return (SUCCESS);
}

	//ft_memmove
int main_test_ft_memmove()	{
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

		return(SUCCESS);
	}
