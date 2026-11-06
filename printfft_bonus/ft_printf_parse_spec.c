/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:49:51 by keblanch          #+#    #+#             */
/*   Updated: 2026/11/04 21:09:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft_bonus.h"

#define FORTMAT_SPECIFIERS "-0 +#123456789."

t_fmtsp	ft_printf_parse_spec(t_string *out, size_t *cursor)
{
	t_fmtsp	spec;
	size_t	i;

	i = 0;
	while (out->str[*cursor + 1 + i] == '-' || out->str[*cursor + 1 + i] == '0')
		++i;

	spec.flags = NULL;
	spec.width = 0;
	spec.precision = -1;
	spec.fmtsp_len = 0;
	spec.specifier = out->str[*cursor + 1];
	return (spec);
}
