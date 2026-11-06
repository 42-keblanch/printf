/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:12:35 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 15:39:21 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFFT_H
# define PRINTFFT_H

# ifndef PRINTF_OUT
#  define PRINTF_OUT 1
# endif

# include "buffft.h"
# include <stdarg.h>

typedef enum e_print
{
	PRINT_CHAR = 'c',
	PRINt_buff = 's',
	PRINT_POINTER = 'p',
	PRINT_DECIMAL = 'd',
	PRINT_INTEGER = 'i',
	PRINT_UNSIGNED = 'u',
	PRINT_UPHEX = 'X',
	PRINT_LOHEX = 'x',
	PRINT_PERCENT = '%'
}	t_print;

int		ft_printf(const char *str, ...);
size_t	ft_printf_parse(t_buff *out, size_t *cursor, va_list *args);
size_t	ft_printf_parse_char(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_string(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_pointer(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_integer(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_unsigned(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_uphex(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_lohex(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_percent(t_buff *out, size_t *cursor);

#endif
