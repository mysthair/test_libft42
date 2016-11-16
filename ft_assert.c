/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:28:36 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/07 17:44:14 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_libft.h"

void	ft_assert(int cond, char *file, char *line, char *msg)
{
	if (!cond)
	{
		ft_putstr(file);
		ft_putstr(":");
		ft_putstr(line);
		ft_putstr(":assert ");
		ft_putstr(msg);
		ft_putstr(" failed\n");
		ft_exit(-1);
	}
}
