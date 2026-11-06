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

t_string	*ft_buff_init(t_string *self)
{
	self->max_size = 0;
	self->str = NULL;
	return (self);
}

t_string	*ft_buff_init_str(t_string *self, const char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	self->max_size = str_len;
	self->str = ft_calloc(str_len + 1, sizeof(char));
	ft_strlcpy(self->str, str, str_len + 1);
	return (self);
}
