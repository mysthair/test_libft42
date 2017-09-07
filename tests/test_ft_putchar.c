#include "libft.h"
#include "tests.h"
int main_test_ft_putchar()
{
  //ce test fonctionne
  char * txt = "[héhé Ø ça va être dur pour les élèves... Да, меня зовут Джимми] ..";
  int l = ft_strlen(txt);
  int i=0;
  while (i<l)
    ft_putchar(txt[i++]);

  // mais celui-ci qui suit n'est pas compilable
#if 0
  ft_putchar('Ø');
  ft_putchar('[');
  ft_putchar('ç');
  ft_putchar('é');
  ft_putchar('œ');
  ft_putchar('é');
  ft_putchar(']');
#endif

  return SUCCESS;
}
