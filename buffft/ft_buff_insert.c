/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 07:12:56 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../buffft.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_buff_insert(t_buff *self, size_t index,
	const char *data, size_t size)
{
	if (!data)
		return (0);
	if (self->curr_size < index)
		return (0);
	while (size >= self->max_size - self->curr_size)
		ft_buff_double_size(self);
	ft_memmove(self->data + index + size, self->data + index,
		self->curr_size - index);
	ft_memcpy(self->data + index, data, size);
	self->curr_size += size;
	return (size);
}

size_t	ft_buff_insert_str(t_buff *self, size_t index, const char *str)
{
	size_t	ret;
	size_t	str_len;

	str_len = ft_strlen(str);
	ret = ft_buff_insert(self, index, str, str_len);
	return (ret);
}

size_t	ft_buff_insert_char(t_buff *self, size_t index, const char c)
{
	size_t	ret;

	ret = ft_buff_insert(self, index, &c, 1);
	return (ret);
}

size_t	ft_buff_insert_hex_lo(t_buff *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoh(n);
	ft_strtolower(str);
	ret = ft_buff_insert_str(self, index, str);
	free(str);
	return (ret);
}

size_t	ft_buff_insert_hex_up(t_buff *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoh(n);
	ft_strtoupper(str);
	ret = ft_buff_insert_str(self, index, str);
	free(str);
	return (ret);
}
