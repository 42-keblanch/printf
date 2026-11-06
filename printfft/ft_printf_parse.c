/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:15:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 15:39:22 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include "../libft.h"
#define NULL_STR "(null)"

static void	ft_printf_parse2(t_buff *out, size_t *cursor,
	va_list *args, char tmp)
{
	if (tmp == PRINT_INTEGER)
		ft_printf_parse_integer(out, cursor, args);
	else if (tmp == PRINT_UNSIGNED)
		ft_printf_parse_unsigned(out, cursor, args);
	else if (tmp == PRINT_UPHEX)
		ft_printf_parse_uphex(out, cursor, args);
	else if (tmp == PRINT_LOHEX)
		ft_printf_parse_lohex(out, cursor, args);
	else if (tmp == PRINT_PERCENT)
		ft_printf_parse_percent(out, cursor);
	else
		++*cursor;
}

size_t	ft_printf_parse(t_buff *out, size_t *cursor, va_list *args)
{
	char	tmp;
	size_t	nb_null_char;

	*cursor += ft_strfind(out->str + *cursor, "%");
	tmp = out->str[*cursor + 1];
	nb_null_char = 0;
	if (tmp == PRINT_CHAR)
		nb_null_char += ft_printf_parse_char(out, cursor, args);
	else if (tmp == PRINt_buff)
		ft_printf_parse_string(out, cursor, args);
	else if (tmp == PRINT_POINTER)
		ft_printf_parse_pointer(out, cursor, args);
	else if (tmp == PRINT_DECIMAL)
		ft_printf_parse_integer(out, cursor, args);
	else
		ft_printf_parse2(out, cursor, args, tmp);
	return (nb_null_char);
}

size_t	ft_printf_parse_char(t_buff *out, size_t *cursor, va_list *args)
{
	char	c;
	size_t	is_null_char;

	c = va_arg(*args, int);
	is_null_char = 0;
	if (c == '\0')
		is_null_char = 1;
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_char(out, *cursor, c);
	return (is_null_char);
}

void	ft_printf_parse_string(t_buff *out, size_t *cursor, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	ft_buff_erase(out, *cursor, 2);
	if (str)
		*cursor += ft_buff_insert(out, *cursor, str);
	else
		*cursor += ft_buff_insert(out, *cursor, NULL_STR);
}

void	ft_printf_parse_pointer(t_buff *out, size_t *cursor, va_list *args)
{
	void	*p;

	p = va_arg(*args, void *);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_ptr(out, *cursor, p);
}
