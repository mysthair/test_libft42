/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:42:56 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/10 16:48:11 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "libft.h"

static void	aff_hexa(unsigned char h)
{
	char c;

	if (h > 9)
		c = 'a' + (h - 10);
	else
		c = '0' + h;
	ft_putchar(c);
}

static void	show_byte(char *mem, size_t offset, int out)
{
	unsigned char	b;

	if (offset > 0 && !(offset & 1))
		ft_putchar(' ');
	if (out)
	{
		b = mem[offset];
		aff_hexa((b >> 4) & 0xF);
		aff_hexa(b & 0xF);
	}
	else
	{
		ft_putstr("  ");
	}
}

static void	show_text(char *mem, size_t offset)
{
	char b;

	b = mem[offset];
	if (b >= ' ' && b < '~')
		ft_putchar(b);
	else
		ft_putchar('.');
}

void		ft_print_memory(const void *addr, size_t size)
{
	char	*mem;
	size_t	pos;
	size_t	i;

	mem = (char*)addr;
	pos = 0;
	while (pos < size)
	{
		i = 0;
		while (i < 16)
		{
			show_byte(mem + pos, i, (pos + i) < size);
			i++;
		}
		i = 0;
		ft_putchar(' ');
		while (i < 16)
		{
			if ((pos + i) < size)
				show_text(mem + pos, i);
			i++;
		}
		ft_putchar('\n');
		pos += 16;
	}
}
