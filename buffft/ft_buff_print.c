/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:59:17 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"

void	ft_buff_print(const t_buff *self, int fd)
{
	t_buff	out;

	ft_buff_init(&out);
	ft_buff_assign(&out, "string: [");
	if (self->str)
		ft_buff_append(&out, self->str);
	else
		ft_buff_append(&out, "(null)");
	ft_buff_append(&out, "]\nsize: ");
	ft_buff_append_int(&out, self->max_size);
	ft_buff_append(&out, "\n");
	ft_putstr_fd(out.str, fd);
	ft_buff_destroy(&out);
}
