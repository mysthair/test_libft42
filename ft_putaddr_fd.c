/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 13:01:01 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/21 16:06:17 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_libft.h"

static void aff_hexa(unsigned char h, int fd)
{                                                                               
	char c;

	if (h > 9)
		c = 'a' + (h - 10);
	else
		c = '0' + h;
	ft_putchar_fd(c, fd);
}                                                                               
                                                                                
static void show_byte(char *mem, size_t offset, int fd)
{
	unsigned char   b;

	b = mem[offset];
	aff_hexa((b >> 4) & 0xF, fd);
	aff_hexa(b & 0xF, fd);
}                                                                               

void	ft_putaddr_fd(void const *a, int fd)
{
	char	*mem;
	size_t	i;
	if (a == NULL)
		ft_putstr_fd("NULL", fd);
	else
	{ 
		mem = (char*)&a;
		ft_putstr_fd("0x", fd);
		i = sizeof(mem)/2;
		while(i-->0)
		 	show_byte(mem, i, fd);
	}
}
