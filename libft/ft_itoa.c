/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:43:44 by keblanch          #+#    #+#             */
/*   Updated: 2026/11/07 22:42:51 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_nb_negative(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

static size_t	nb_len(int n)
{
	size_t	r;

	if (n == 0)
		return (1);
	r = 0;
	while (n > 0)
	{
		n /= 10;
		++r;
	}
	return (r);
}

static size_t	nb_len_uint(unsigned int n)
{
	size_t	r;

	if (n == 0)
		return (1);
	r = 0;
	while (n > 0)
	{
		n /= 10;
		++r;
	}
	return (r);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ret;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = nb_len_uint(n);
	ret = (char *)ft_calloc(i + 1, sizeof(char));
	while (n > 0)
	{
		--i;
		ret[i] = '0' + (n % 10);
		n /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*r;
	size_t	i;
	size_t	is_negative;

	if (n == -2147483648)
	{
		r = ft_strdup("-2147483648");
		return (r);
	}
	is_negative = is_nb_negative(n);
	if (is_negative)
		n *= -1;
	i = nb_len(n);
	r = (char *)ft_calloc(i + is_negative + 1, sizeof(char));
	if (!r)
		return (NULL);
	if (is_negative)
		r[0] = '-';
	while (i > 0)
	{
		--i;
		r[i + is_negative] = '0' + (n % 10);
		n /= 10;
	}
	return (r);
}
