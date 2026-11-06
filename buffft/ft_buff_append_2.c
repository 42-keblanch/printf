/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_append_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:16:25 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"

void	ft_buff_append_int(t_buff *self, const int n)
{
	char	*str;

	str = ft_itoa(n);
	ft_buff_append(self, str);
}

void	ft_buff_append_percent(t_buff *self)
{
	const char	*str = "%";

	ft_buff_append(self, str);
}

void	ft_buff_append_pointer(t_buff *self, const void *p)
{
	char	*str;

	str = ft_ptoh(p);
	ft_buff_append(self, str);
}

void	ft_buff_append_unsigned(t_buff *self, const unsigned int n)
{
	char	*str;

	str = ft_itoa(n);
	ft_buff_append(self, str);
}
