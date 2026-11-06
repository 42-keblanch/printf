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

size_t	ft_buff_insert(t_string *self, size_t index, const char *str)
{
	size_t	str_len;
	size_t	self_len;
	char	*tmp;

	if (!str)
		return (0);
	self_len = ft_strlen(self->str);
	if (self_len < index)
		return (0);
	str_len = ft_strlen(str);
	while (str_len >= self->max_size - self_len)
		ft_buff_double_size(self);
	tmp = ft_strdup(self->str);
	self->str[index] = '\0';
	ft_buff_append(self, str);
	ft_buff_append(self, tmp + index);
	free(tmp);
	return (str_len);
}

size_t	ft_buff_insert_char(t_string *self, size_t index, const char c)
{
	char	str[2];
	size_t	ret;

	str[0] = c;
	str[1] = '\0';
	ret = ft_buff_insert(self, index, str);
	return (ret);
}

size_t	ft_buff_insert_hex_lo(t_string *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoh(n);
	ft_strtolower(str);
	ret = ft_buff_insert(self, index, str);
	free(str);
	return (ret);
}

size_t	ft_buff_insert_hex_up(t_string *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoh(n);
	ft_strtoupper(str);
	ret = ft_buff_insert(self, index, str);
	free(str);
	return (ret);
}
