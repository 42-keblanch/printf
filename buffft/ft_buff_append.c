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

void	ft_buff_append(t_buff *self, const char *str)
{
	size_t	self_len;
	size_t	str_len;

	if (!str)
		return ;
	if (!self->str)
	{
		ft_buff_init_str(self, str);
		return ;
	}
	self_len = ft_strlen(self->str);
	str_len = ft_strlen(str);
	while (self_len > self->max_size - str_len)
		ft_buff_double_size(self);
	ft_strlcpy(self->str + self_len, str, str_len + 1);
}

void	ft_buff_append_char(t_buff *self, const char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	ft_buff_append(self, str);
}

void	ft_buff_append_hex_lo(t_buff *self, const int n)
{
	char	*str;

	str = ft_itoh(n);
	ft_strtolower(str);
	ft_buff_append(self, str);
}

void	ft_buff_append_hex_up(t_buff *self, const int n)
{
	char	*str;

	str = ft_itoh(n);
	ft_strtoupper(str);
	ft_buff_append(self, str);
}
