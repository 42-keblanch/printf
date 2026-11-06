/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:45:09 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stddef.h>

t_string	ft_buff_substr(t_string *self, size_t index, size_t len)
{
	t_string	ret;

	ret.str = ft_strdup(self->str + index);
	ret.max_size = ft_strlen(ret.str);
	if (len <= ret.max_size)
		ret.str[len] = '\0';
	return (ret);
}
