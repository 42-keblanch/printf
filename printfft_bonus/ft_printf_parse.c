/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:15:03 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/07 22:38:55 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft_bonus.h"
#include "../libft.h"
#define NULL_STR "(null)"

static void	ft_printf_parse2(t_buff *out, size_t *cursor,
	va_list *args, t_fmtsp tmp)
{
	if (tmp.specifier == PRINT_INTEGER)
		ft_printf_parse_integer(out, cursor, args);
	else if (tmp.specifier == PRINT_UNSIGNED)
		ft_printf_parse_unsigned(out, cursor, args);
	else if (tmp.specifier == PRINT_UPHEX)
		ft_printf_parse_uphex(out, cursor, args);
	else if (tmp.specifier == PRINT_LOHEX)
		ft_printf_parse_lohex(out, cursor, args);
	else if (tmp.specifier == PRINT_PERCENT)
		ft_printf_parse_percent(out, cursor);
	else
		++*cursor;
}

void	ft_printf_parse(t_buff *out, size_t *cursor, va_list *args)
{
	char	*percent_pos;
	t_fmtsp	tmp;

	if (*cursor >= out->curr_size)
		return ;
	percent_pos = ft_memchr(out->data + *cursor, '%', out->curr_size - *cursor);
	if (!percent_pos)
		return ;
	*cursor = percent_pos - out->data;
	tmp = ft_printf_parse_spec(out, cursor);
	if (tmp.specifier == PRINT_CHAR)
		ft_printf_parse_char(out, cursor, args);
	else if (tmp.specifier == PRINT_BUFF)
		ft_printf_parse_string(out, cursor, args);
	else if (tmp.specifier == PRINT_POINTER)
		ft_printf_parse_pointer(out, cursor, args);
	else if (tmp.specifier == PRINT_DECIMAL)
		ft_printf_parse_integer(out, cursor, args);
	else
		ft_printf_parse2(out, cursor, args, tmp);
}

void	ft_printf_parse_char(t_buff *out, size_t *cursor, va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_char(out, *cursor, c);
}

void	ft_printf_parse_string(t_buff *out, size_t *cursor, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	ft_buff_erase(out, *cursor, 2);
	if (str)
		*cursor += ft_buff_insert_str(out, *cursor, str);
	else
		*cursor += ft_buff_insert_str(out, *cursor, NULL_STR);
}

void	ft_printf_parse_pointer(t_buff *out, size_t *cursor, va_list *args)
{
	void	*p;

	p = va_arg(*args, void *);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_ptr(out, *cursor, p);
}
