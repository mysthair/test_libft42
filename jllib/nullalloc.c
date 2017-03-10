/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:00:33 by jleblanc          #+#    #+#             */
/*   Updated: 2016/12/02 16:23:22 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**  void	*ft_malloc(size_t n)
** {
**  ft_putstr("ft_memmalloc(n = ");
** 	ft_putnbr(n);
** 	ft_putendl(")");
**	tmp = malloc(size);
**	if (tmp)
**		ft_bzero(tmp, size);
**	return (tmp);
** }
*/

void	*nullalloc(size_t unused)
{
	(void)unused;
	return (NULL);
}
