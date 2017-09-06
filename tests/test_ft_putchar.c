#include "libft.h"
#include "tests.h"
int main_test_ft_putchar()
{
  //ce test fonctionne
  ft_putstr("Ø ça va être dur pour les élèves... Да, меня зовут Джимми..");

  /* mais celui-ci qui suit n'est pas compilable 
  ft_putchar('Ø');
  ft_putchar('[');
  ft_putchar('ç');
  ft_putchar('é');
  ft_putchar('œ');
  ft_putchar('é');
  ft_putchar(']');
  */
  return SUCCESS;
}
