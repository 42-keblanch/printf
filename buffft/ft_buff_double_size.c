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

size_t	ft_buff_double_size(t_string *self)
{
	char	*temp;

	if (self->max_size == 0)
		self->max_size = 127;
	else
		self->max_size *= 2;
	temp = ft_calloc(self->max_size, 1);
	if (!temp)
	{
		free(self->str);
		self->str = NULL;
		return (0);
	}
	if (self->str)
		ft_memcpy(temp, self->str, ft_strlen(self->str));
	free(self->str);
	self->str = temp;
	return (self->max_size);
}
