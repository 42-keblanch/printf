/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:49 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/07 23:00:15 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include "../libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_buff		out;
	int			ret;
	size_t		cursor;

	if (!str)
		return (-1);
	va_start(args, str);
	cursor = 0;
	ft_buff_init_str(&out, str);
	while (cursor < out.curr_size
		&& ft_memchr(out.data + cursor, '%', out.curr_size - cursor))
		ft_printf_parse(&out, &cursor, &args);
	write(PRINTF_OUT, out.data, out.curr_size);
	ret = out.curr_size;
	ft_buff_destroy(&out);
	va_end(args);
	return (ret);
}
