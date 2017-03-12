#include "test_libft.h"
#include "libft.h"
#include "tests.h"

static int test_ft_strsplit1()
	{ // ftrsplit
		char	*__Ha_Ho_123______erf_ = "__Ha_Ho_123______erf_";
		char	**ftsplitresultof__Ha_Ho_123______erf_ =  ft_strsplit(__Ha_Ho_123______erf_, '_');
		int i;

		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[0], "Ha"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[1], "Ho"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[2], "123"));
		FAIL_IF_NOT(ft_strequ(ftsplitresultof__Ha_Ho_123______erf_[3], "erf"));
		if(ftsplitresultof__Ha_Ho_123______erf_[4]!=NULL)
		{
			ft_putstr("ftsplitresultof__Ha_Ho_123______erf_[4] = \"");
			ft_putstr(ftsplitresultof__Ha_Ho_123______erf_[4]);
			ft_putstr("\"\n");
		}
		FAIL_IF_NOT(ftsplitresultof__Ha_Ho_123______erf_[4] == NULL);
		for (i=0; i < 4; i++)
			ft_strdel(ftsplitresultof__Ha_Ho_123______erf_ + i);
		ft_memdel((void**)&ftsplitresultof__Ha_Ho_123______erf_);
	
		return(1);
	}
static int test_ft_strsplit2()
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
	
static int test_ft_strsplit_null(void)
{
	char ** ft_strsplit_null = ft_strsplit(NULL, ' ');
	FAIL_IF_NOT(ft_strsplit_null == NULL || ft_strlen(ft_strsplit_null[0]) == 0);
	return (1);
}
int main_test_ft_strsplit()
{
	return (test_ft_strsplit1() 
	&& test_ft_strsplit2()
	&& test_ft_strsplit_null()
	);
}

