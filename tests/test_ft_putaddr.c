#include "libft.h"
#include "tests.h"

int test_ft_putaddr(char *name, void *p)
{
      ft_putstr("ft_putaddr(");
      ft_putstr(name);
      ft_putstr("): ");
      ft_putnbr((int)p);
      ft_putstr("  ");
      ft_putaddr(p);
      ft_putstr("  ");
      //ft_putstr((char*)p);
      ft_putstr("\n");
      return (SUCCESS);
}

int main_test_ft_putaddr(void)
{
  void *t = 0;
  char *txt = "Ceci est un texte bidon";
  char *txt2 = ft_strdup(txt);
  int len = ft_strlen(txt);

  ft_putendl("voyons intmax et intmin\n");
  test_ft_putaddr("intmax", (void*)0x7FFFFFFF);
  test_ft_putaddr("intmin", (void*)0x80000000);
  ft_putchar('\n');
  test_ft_putaddr("0", 0);
  test_ft_putaddr("0x12345678", (void*)0x12345678);
  test_ft_putaddr("0xFEDCBA98", (void*)0xFEDCBA98);
  test_ft_putaddr("test", (void*)0xEADAAAAA);
  test_ft_putaddr("test", (void*)0xA0000000);
  test_ft_putaddr("void *t = 0", t);
  test_ft_putaddr("&len", &len);
  test_ft_putaddr("char *txt2 = ft_strdup(txt)", txt2);
  ft_strdel(&txt2);

  for (int i=0; i<len +1; i++)
    test_ft_putaddr("txt + i", txt + i);

  return (SUCCESS);
}
