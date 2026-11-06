/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:37:03 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/25 01:42:42 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef buffft_H
# define buffft_H

# include <stddef.h>

typedef unsigned int	t_uint;
typedef struct s_ft_buff
{
	char	*str;
	size_t	max_size;
}	t_string;

void		ft_buff_append(t_string *self, const char *str);
void		ft_buff_append_char(t_string *self, const char c);
void		ft_buff_append_float(t_string *self, const double n);
void		ft_buff_append_hex_lo(t_string *self, const int n);
void		ft_buff_append_hex_up(t_string *self, const int n);
void		ft_buff_append_int(t_string *self, const int n);
void		ft_buff_append_percent(t_string *self);
void		ft_buff_append_pointer(t_string *self, const void *p);
void		ft_buff_append_unsigned(t_string *self, const unsigned int n);
void		ft_buff_assign(t_string *self, const char *str);
void		ft_buff_destroy(t_string *self);
size_t		ft_buff_double_size(t_string *self);
void		ft_buff_erase(t_string *self, size_t index, size_t len);
t_string	*ft_buff_init(t_string *self);
t_string	*ft_buff_init_str(t_string *self, const char *str);
size_t		ft_buff_insert(t_string *self, size_t index, const char *str);
size_t		ft_buff_insert_char(t_string *self, size_t index, const char c);
size_t		ft_buff_insert_hex_lo(t_string *self, size_t index, const int n);
size_t		ft_buff_insert_hex_up(t_string *self, size_t index, const int n);
size_t		ft_buff_insert_int(t_string *self, size_t index, const int n);
size_t		ft_buff_insert_percent(t_string *self, size_t index);
size_t		ft_buff_insert_ptr(t_string *self, size_t index, const void *p);
size_t		ft_buff_insert_uint(t_string *self, size_t index, const t_uint n);
void		ft_buff_print(const t_string *self, int fd);
t_string	ft_buff_substr(t_string *self, size_t index, size_t len);

#endif
