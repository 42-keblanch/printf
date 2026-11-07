/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:03:07 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stddef.h>

void	ft_buff_append(t_buff *self, const char *data, size_t size)
{
	if (!data)
		return ;
	if (!self->data)
	{
		ft_buff_init_str(self, data);
		return ;
	}
	while (self->curr_size > self->max_size - size)
		ft_buff_double_size(self);
	ft_memcpy(self->data + self->curr_size, data, size);
	self->curr_size += size;
}

void	ft_buff_append_char(t_buff *self, const char c)
{
	ft_buff_append(self, &c, 1);
}

void	ft_buff_append_hex_lo(t_buff *self, const int n)
{
	char	*str;
	size_t	len;

	str = ft_itoh(n);
	ft_strtolower(str);
	len = ft_strlen(str);
	ft_buff_append(self, str, len);
}

void	ft_buff_append_hex_up(t_buff *self, const int n)
{
	char	*str;
	size_t	len;

	str = ft_itoh(n);
	ft_strtoupper(str);
	len = ft_strlen(str);
	ft_buff_append(self, str, len);
}
