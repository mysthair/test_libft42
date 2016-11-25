/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:42:01 by jleblanc          #+#    #+#             */
/*   Updated: 2016/11/24 19:50:39 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strsub.c"

int main()
{
	char	*str = "Je suis le meeilleur :P";

	char	*res = ft_strsub(str, 0, (size_t)-10);

	if (res == NULL)
		ft_putendl("ft_strsub(str, 0, (size_t)-10) return NULL !!!");
	else
	{
		ft_putstr("ft_strsub(str, 0, (size_t)-10) return \"");
		ft_putstr(res);
		ft_putendl("\"");
	}
	return (0);
}
