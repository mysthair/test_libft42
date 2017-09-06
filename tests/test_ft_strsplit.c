#include "test_libft.h"
#include "libft.h"
#include "tests.h"

#define SUCCESS 1
#define FAILED 0


static int test_ft_strsplit1(void)
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

		return (SUCCESS);
	}
static int test_ft_strsplit2(void)
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

		return (SUCCESS);
	}

static int test_ft_strsplit_null(void)
{
	char ** ft_strsplit_null = ft_strsplit(NULL, ' ');
	FAIL_IF_NOT(ft_strsplit_null == NULL || ft_strlen(ft_strsplit_null[0]) == 0);
	return (SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
static int uf_free_tab(void** tab)
{
	int i = 0;
	while(tab[i])
	{
		//ft_memdel(&tab[i]);
		free((void*)tab[i]);
		i++;
	}
	//ft_memdel((void **)&tab);
	free((void*)tab);
	return 1;
}
static int test_strsplit_bidule42Filechecker(void)
{
	char **tab;
	tab = ft_strsplit("g*hel*lo*f", '*');
	if (tab[4] != NULL && strcmp(tab[0], "g") != 0 && strcmp(tab[1], "hel") != 0 &&
	strcmp(tab[2], "lo") != 0 && strcmp(tab[3], "f") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"g*hel*lo*f\", '*').\nExpected tab[0] = \"g\", tab[1] = \"hel\", tab[2] = \"lo\", tab[3] = \"f\" and tab[4] = NULL \
				 but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\", tab[3] = \"%s\" and tab[4] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, tab[0], tab[1], tab[2], tab[3], tab[4]);
		uf_free_tab((void **)tab);
		return (FAILED);
	}


	/*int					uf_test_strsplit(void)*/
		char			**ret;

		ft_strsplit(NULL, 0);
		ft_strsplit(NULL, 'a');
		ret = ft_strsplit("", '*');
		if (ret == NULL || ret[0] != NULL)
		{
			printf("Error Line %d, Funct %s : \
				   \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
			uf_free_tab((void **)ret);
			return (0);
		}
		uf_free_tab((void **)ret);
		ret = ft_strsplit("*********", '*');
		if (ret == NULL || ret[0] != NULL)
		{
			printf("Error Line %d, Funct %s : \
				   \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \nUnable to free your tab in first test\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("hello", '*');
		if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
				   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in second test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("*hello", '*');
		if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
				   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("*hello*", '*');
		if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello*\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
				   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("*hel*lo*", '*');
		if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
				   but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fourth test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("*hel*lo*f", '*');
		if (ret[3] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0 &&
			strcmp(ret[2], "f") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*f\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\", tab[2] = \"f\" and tab[3] = NULL \
				   but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\" and tab[3] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fifth test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("g*hel*lo*f", '*');
		if (ret[4] != NULL && strcmp(ret[0], "g") != 0 && strcmp(ret[1], "hel") != 0 &&
			strcmp(ret[2], "lo") != 0 && strcmp(ret[3], "f") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"g*hel*lo*f\", '*').\nExpected tab[0] = \"g\", tab[1] = \"hel\", tab[2] = \"lo\", tab[3] = \"f\" and tab[4] = NULL \
				   but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\", tab[3] = \"%s\" and tab[4] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3], ret[4]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in sixth test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
		ret = ft_strsplit("***hel****lo**", '*');
		if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel****lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
				   but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
			uf_free_tab((void **)ret);
			return (0);
		}
		if (uf_free_tab((void **)ret) == 0)
		{
			printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in seventh test\033[0m\n", __LINE__ - 2, __func__);
			return (0);
		}
	return (SUCCESS);
}

int main_test_ft_strsplit(void)
{
	return (test_ft_strsplit1()
	&& test_ft_strsplit2()
	&& test_ft_strsplit_null()
	&& test_strsplit_bidule42Filechecker()
	);
}
