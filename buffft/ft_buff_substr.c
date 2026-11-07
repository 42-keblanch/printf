/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:45:09 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stddef.h>

t_buff	ft_buff_substr(t_buff *self, size_t index, size_t len)
{
	t_buff	ret;

	ret.data = ft_strdup(self->data + index);
	ret.max_size = ft_strlen(ret.data);
	if (len <= ret.max_size)
		ret.data[len] = '\0';
	return (ret);
}
