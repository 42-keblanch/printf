/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:43:04 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"

#include <stdlib.h>

t_buff	*ft_buff_init(t_buff *self)
{
	self->max_size = 0;
	self->curr_size = 0;
	self->data = NULL;
	return (self);
}

t_buff	*ft_buff_init_str(t_buff *self, const char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	self->data = ft_calloc(str_len, sizeof(char));
	if (!self->data)
		return (NULL);
	self->max_size = str_len;
	self->curr_size = str_len;
	ft_memcpy(self->data, str, str_len);
	return (self);
}
