/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:21:56 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/09 16:35:38 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define _STRING(x) #x
# define STRING(x) _STRING(x)
# define FT_ASSERT(cond) ft_assert(cond, __FILE__, STRING(__LINE__), #cond )
#define NULL 0
typedef unsigned long size_t;

void	*ft_malloc(size_t n);
void	ft_free(void *p);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_exit(int n);
void	ft_assert(int cond, char *file, char *line, char *msg);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char    *ft_strstr(const char *big, const char *little);
char    *ft_strnstr(const char *big, const char *little, size_t size);
int		ft_strcmp(char *s1, char *s2);
int     ft_strncmp(char *s1, char *s2, size_t size);
int		ft_atoi(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
