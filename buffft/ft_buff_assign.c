/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_assign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:11:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stdlib.h>

void	ft_buff_assign(t_buff *self, const char *data, size_t size)
{
	if (!data)
	{
		free(self->data);
		self->data = NULL;
		return ;
	}
	while (self->max_size <= size)
		ft_buff_double_size(self);
	ft_memcpy(self->data, data, size);
}
