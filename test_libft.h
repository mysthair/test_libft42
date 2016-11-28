#ifndef TEST_LIBFT_H
 #define TEST_LIBFT_H

#define _STRINGIFY(x) #x                                                        
#define STRINGIFY(x) _STRINGIFY(x)                                              

#define FT_ASSERT(cond) \
	ft_putstr("testons " #cond "\n"); \
	ft_assert(cond, __FILE__, STRINGIFY(__LINE__), #cond )  

#define TEST(cond) \
	if(!(cond)) { \
		ft_putstr(__FILE__ ":" STRINGIFY(__LINE__) ": (" #cond ") FAILED! :(    KO\n"); \
		return (0); \
	}

/*# ifndef NULL
#  define NULL 0
#  define TYPEDEF_SIZE_T typedef unsigned long size_t
TYPEDEF_SIZE_T;
# endif
*/
#include <string.h>

void   *ft_malloc(size_t n);
void   ft_free(void *p);
void   ft_exit(int n);
void   ft_print_memory(const void *addr, size_t size);
void   ft_assert(int cond, char *file, char *line, char *msg);

#ifdef DONT_HAVE_STRLCPY                                                        
size_t  strlcat(char *dst, const char *src, size_t size);
char *strnstr(const char *haystack, const char *needle, size_t len);
#endif

#endif
