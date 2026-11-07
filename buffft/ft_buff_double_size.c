/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_double_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:04:58 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stdlib.h>

size_t	ft_buff_double_size(t_buff *self)
{
	char	*temp;

	if (self->max_size == 0)
		self->max_size = 127;
	else
		self->max_size *= 2;
	temp = ft_calloc(self->max_size, 1);
	if (!temp)
	{
		free(self->data);
		self->data = NULL;
		return (0);
	}
	if (self->data)
		ft_memcpy(temp, self->data, self->curr_size);
	free(self->data);
	self->data = temp;
	return (self->max_size);
}
