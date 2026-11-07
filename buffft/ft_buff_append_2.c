/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_append_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:16:25 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 14:18:33 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"

void	ft_buff_append_int(t_buff *self, const int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_buff_append(self, str, len);
}

void	ft_buff_append_pointer(t_buff *self, const void *p)
{
	char	*str;
	size_t	len;

	str = ft_ptoh(p);
	len = ft_strlen(str);
	ft_buff_append(self, str, len);
}

void	ft_buff_append_unsigned(t_buff *self, const t_uint n)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_buff_append(self, str, len);
}
