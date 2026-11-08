/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:49:51 by keblanch          #+#    #+#             */
/*   Updated: 2026/11/08 19:45:34 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft_bonus.h"
#include "libft.h"
#include <stdlib.h>

#define FORMAT_NUMBERS "0123456789"
#define FORMAT_SPECIFIERS "cspdiuxX%"
#define FORMAT_FLAGS "-0 +#"

t_fmtsp	ft_printf_parse_format(t_buff *out, size_t *cursor)
{
	t_fmtsp	spec;

	spec.flags = NULL;
	spec.width = 0;
	spec.precision = -1;
	spec.specifier = '\0';
	spec.fmtsp_len = 0;
	ft_printf_parse_flags(out, cursor, &spec);
	ft_printf_parse_width(out, cursor, &spec);
	if (out->data[*cursor + spec.fmtsp_len] == '.')
		ft_printf_parse_precision(out, cursor, &spec);
	ft_printf_parse_spec(out, cursor, &spec);
	if (*cursor < out->curr_size)
		spec.specifier = out->data[*cursor + 1];
	return (spec);
}

void	ft_printf_parse_flags(t_buff *out, size_t *cursor, t_fmtsp *spec)
{
	size_t	i;

	i = 0;
	while (ft_strchr(FORMAT_FLAGS, out->data[*cursor + 1 + i]))
		++i;
	if (i == 0)
		return ;
	spec->flags = ft_calloc(i + 1, sizeof(char));
	ft_memcpy(spec->flags, out->data + (*cursor + 1), i);
	spec->fmtsp_len += i;
}

void	ft_printf_parse_width(t_buff *out, size_t *cursor, t_fmtsp *spec)
{
	size_t	start;
	size_t	i;
	char *tmp;

	i = 0;
	start = 1 + spec->fmtsp_len;
	while (ft_isdigit(out->data[*cursor + start + i]))
		++i;
	if (i == 0)
		return ;
	tmp = ft_calloc(i + 1, sizeof(char));
	ft_memcpy(tmp, out->data + (*cursor + start), i);
	spec->width = ft_atoi(tmp);
	free(tmp);
	spec->fmtsp_len += i;
}

void	ft_printf_parse_precision(t_buff *out, size_t *cursor, t_fmtsp *spec)
{
	size_t	start;
	size_t	i;
	char *tmp;

	i = 0;
	spec->fmtsp_len += 1;
	start = 1 + spec->fmtsp_len;
	while (ft_isdigit(out->data[*cursor + start + i]))
		++i;
	if (i == 0)
		return ;
	tmp = ft_calloc(i + 1, sizeof(char));
	ft_memcpy(tmp, out->data + (*cursor + start), i);
	free(tmp);
	spec->fmtsp_len += i;
}

void	ft_printf_parse_spec(t_buff *out, size_t *cursor, t_fmtsp *spec)
{
	size_t	start;

	start = 1 + spec->fmtsp_len;
	if (!ft_strchr(FORMAT_SPECIFIERS, out->data[*cursor + start]))
		return ;
	spec->specifier = out->data[*cursor + start];
	spec->fmtsp_len += 1;
}
