/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfft_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:24:07 by keblanch          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFFT_BONUS_H
# define PRINTFFT_BONUS_H

# ifndef PRINTF_OUT
#  define PRINTF_OUT 1
# endif

# include "buffft.h"
# include <stdarg.h>

typedef enum e_print
{
	PRINT_CHAR = 'c',
	PRINT_STRING = 's',
	PRINT_POINTER = 'p',
	PRINT_DECIMAL = 'd',
	PRINT_INTEGER = 'i',
	PRINT_UNSIGNED = 'u',
	PRINT_UPHEX = 'X',
	PRINT_LOHEX = 'x',
	PRINT_PERCENT = '%'
}	t_print;

struct s_format_specifier
{
	char	*flags;
	int		width;
	int		precision;
	int		fmtsp_len;
	char	specifier;
};
typedef struct s_format_specifier	t_fmtsp;

int		ft_printf(const char *str, ...);
size_t	ft_printf_parse(t_string *out, size_t *cursor, va_list *args);
size_t	ft_printf_parse_char(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_string(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_pointer(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_integer(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_unsigned(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_uphex(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_lohex(t_string *out, size_t *cursor, va_list *args);
void	ft_printf_parse_percent(t_string *out, size_t *cursor);
t_fmtsp	ft_printf_parse_spec(t_string *out, size_t *cursor);

#endif
