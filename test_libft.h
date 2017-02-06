#ifndef TEST_LIBFT_H
 #define TEST_LIBFT_H

#include <string.h>
#include "tests.h"

//void	ft_exit(int n);
void	ft_print_memory(const void *addr, size_t size);
void	ft_assert(int cond, char const *file, char const *line, char const *msg);
void	ft_putaddr(void const *ptr);
void	ft_putaddr_fd(void const *ptr, int fd);

#ifdef DONT_HAVE_STRLCPY                                                        
size_t  strlcat(char *dst, const char *src, size_t size);
char *strnstr(const char *haystack, const char *needle, size_t len);
#endif

#endif
