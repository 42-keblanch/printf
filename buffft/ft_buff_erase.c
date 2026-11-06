/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_erase.c                                  :+:      :+:    :+:   */
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

void	ft_buff_erase(t_buff *self, size_t index, size_t len)
{
	ft_strlcpy(self->str + index,
		self->str + index + len,
		ft_strlen(self->str + index + len) + 1
		);
}
