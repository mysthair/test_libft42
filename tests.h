#ifndef TESTS_H
#define TESTS_H


#define _STRINGIFY(x) #x                                                        
#define STRINGIFY(x) _STRINGIFY(x)                                              

//#define PROTECTED_TEST


/*#define FT_ASSERT(cond) { \
	ft_putstr("testons " #cond "\n"); \
	ft_assert(cond, __FILE__, STRINGIFY(__LINE__), #cond ); \
}*/


#define TEST(cond) \
	if(!(cond)) { \
		ft_putstr(__FILE__ ":" STRINGIFY(__LINE__) ": (" #cond \
	")   FAILED! :(  KO\n"); \
		return (0); \
	}

#define FT_ASSERT(cond) TEST(cond)
# define FAIL_IF_NOT(cond) FT_ASSERT(cond)
// ft_putstr(STRINGIFY(cond) " .. OK\n"); 


/*# ifndef NULL
#  define NULL 0
#  define TYPEDEF_SIZE_T typedef unsigned long size_t
TYPEDEF_SIZE_T;
# endif
*/


#define SHOW_STRING(msg, v) { ft_putstr(msg); ft_putstr(": " #v " = \""); ft_putstr(v); ft_putendl("\""); }


#define FORK_TEST(t) {\
	ft_putstr(#t " .. \n");\
	if(fork_test(&t)) {\
		ft_putendl(#t " .. OK");\
	}else{\
		ft_putendl(" .. KO");\
		_exit(-1);\
	}\
}



int main_test_ft_memset();
int main_test_ft_bzero();
int main_test_ft_memcpy();
int main_test_ft_memccpy();
int main_test_ft_memmove();
int main_test_ft_memchr();
int main_test_ft_memcmp();
int main_test_ft_strlen();
int main_test_ft_strdup();
int main_test_ft_strcpy();
int main_test_ft_strncpy();
int main_test_ft_strcat();
int main_test_ft_strncat();
int main_test_ft_strlcat();
int main_test_ft_strchr();
int main_test_ft_strrchr();
int main_test_ft_strstr();
int main_test_ft_strnstr();
int main_test_ft_strcmp();
int main_test_ft_strncmp();
int main_test_ft_atoi();
int main_test_ft_isalpha();
int main_test_ft_isdigit();
int main_test_ft_isalnum();
int main_test_ft_isascii();
int main_test_ft_isprint();
int main_test_ft_toupper();
int main_test_ft_tolower();
int main_test_ft_memalloc();
int main_test_ft_memdel();
int main_test_ft_strnew();
int main_test_ft_strdel();
int main_test_ft_strclr();
int main_test_ft_striter();
int main_test_ft_striteri();
int main_test_ft_strmap();
int main_test_ft_strmapi();
int main_test_ft_strequ();
int main_test_ft_strnequ();
int main_test_ft_strsub();
int main_test_ft_strjoin();
int main_test_ft_strtrim();
int main_test_ft_strsplit();
int main_test_ft_itoa();
int main_test_ft_putchar();
int main_test_ft_putstr();
int main_test_ft_putendl();
int main_test_ft_putnbr();
int main_test_ft_putchar_fd();
int main_test_ft_putstr_fd();
int main_test_ft_putendl_fd();
int main_test_ft_putnbr_fd();
int main_test_ft_lstnew();
int main_test_ft_lstdelone();
int main_test_ft_lstdel();
int main_test_ft_lstadd();
int main_test_ft_lstiter();
int main_test_ft_lstmap();

#endif
