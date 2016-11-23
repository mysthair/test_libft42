/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:19:27 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/23 19:08:26 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_libft.h"
#include <stdlib.h>

void	*ft_malloc(size_t n)
{
	ft_putstr("ft_malloc(n = ");
	ft_putnbr(n);
	ft_putendl(")");
	return (malloc(n));
}
