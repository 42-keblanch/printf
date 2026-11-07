/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:49:51 by keblanch          #+#    #+#             */
/*   Updated: 2026/11/07 22:59:29 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft_bonus.h"

#define FORTMAT_SPECIFIERS "-0 +#123456789."

t_fmtsp	ft_printf_parse_spec(t_buff *out, size_t *cursor)
{
	t_fmtsp	spec;
	size_t	i;

	i = 0;
	while (out->data[*cursor + 1 + i] == '-' || out->data[*cursor + 1 + i] == '0')
		++i;
	spec.flags = NULL;
	spec.width = 0;
	spec.precision = -1;
	spec.fmtsp_len = 0;
	spec.specifier = '\0';
	if (*cursor < out->curr_size)
		spec.specifier = out->data[*cursor + 1];
	return (spec);
}
