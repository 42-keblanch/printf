/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 08:26:19 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 15:05:37 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strfind(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;
	int		r;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len > haystack_len)
		return (-1);
	while (i + needle_len <= haystack_len)
	{
		if (haystack[i] == needle[0])
		{
			r = ft_strncmp(haystack + i, needle, needle_len);
			if (r == 0)
				return (i);
		}
		++i;
	}
	return (-1);
}
