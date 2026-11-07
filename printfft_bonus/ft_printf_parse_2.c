/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:15:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/07 21:44:05 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft_bonus.h"

void	ft_printf_parse_integer(t_buff *out, size_t *cursor, va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_int(out, *cursor, n);
}

void	ft_printf_parse_unsigned(t_buff *out, size_t *cursor, va_list *args)
{
	t_uint	n;

	n = va_arg(*args, t_uint);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_uint(out, *cursor, n);
}

void	ft_printf_parse_uphex(t_buff *out, size_t *cursor, va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_hex_up(out, *cursor, n);
}

void	ft_printf_parse_lohex(t_buff *out, size_t *cursor, va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_hex_lo(out, *cursor, n);
}

void	ft_printf_parse_percent(t_buff *out, size_t *cursor)
{
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_char(out, *cursor, '%');
}
