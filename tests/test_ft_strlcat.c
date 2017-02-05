#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#ifdef DONT_HAVE_STRLCPY

size_t	strlcat(char *dst, const char *src, size_t size);

#endif


static int		test_ft_strlcat(char *dst, const char *src, size_t size)
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

int main_test_ft_strlcat()
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

