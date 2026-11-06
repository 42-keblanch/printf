/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:49 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:19:11 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include "../libft.h"
#include <stdarg.h>
#include <stddef.h>

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_string	out;
	int			ret;
	size_t		cursor;
	size_t		nb_null_char;

	if (!str)
		return (-1);
	nb_null_char = 0;
	va_start(args, str);
	cursor = 0;
	ft_buff_init_str(&out, str);
	while (ft_strfind(out.str + cursor, "%") != -1)
		nb_null_char += ft_printf_parse(&out, &cursor, &args);
	ft_putstr_fd(out.str, PRINTF_OUT);
	ret = ft_strlen(out.str) + nb_null_char;
	ft_buff_destroy(&out);
	va_end(args);
	return (ret);
}
