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

void	ft_buff_assign(t_buff *self, const char *str)
{
	size_t	str_len;

	if (!str)
	{
		free(self->data);
		self->data = NULL;
		return ;
	}
	str_len = ft_strlen(str);
	while (self->max_size <= str_len)
		ft_buff_double_size(self);
	ft_strlcpy(self->data, str, str_len + 1);
}
