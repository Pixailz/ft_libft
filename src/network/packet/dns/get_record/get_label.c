/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:40:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 15:52:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"


static	char	*join_domain(char **src, char *dst)
{
	char	*ret;
	t_size	len_src;
	t_size	len_dst;

	len_src = ft_strlen(*src);
	len_dst = ft_strlen(dst);
	ret = (char *)ft_calloc(len_src + len_dst + 2, sizeof(char));
	ft_memcpy(ret, *src, len_src);
	ret[len_src] = '.';
	ft_memcpy(ret + len_src + 1, dst, len_dst);
	free(*src);
	return (ret);
}

int	ft_dns_getlabel_ptr(
		unsigned char *data,
		t_uint32 offset,
		char **name,
		t_uint32 max_len
	)
{
	t_uint32	i;
	char		*tmp;
	t_uint32	lab_len;

	i = 0;
	tmp = FT_NULL;
	*name = FT_NULL;
	while (TRUE)
	{
		lab_len = data[i + offset];
		if (lab_len & 0xc0)
		{
			ft_dns_getlabel_ptr(data, data[i + offset + 1], &tmp, max_len);
			i += 2;
		}
		else
		{
			tmp = (char *)ft_calloc(lab_len + 2, sizeof(char));
			ft_memcpy(tmp, data + 1 + i + offset, lab_len);
			i += lab_len + 1;
		}
		if (data[i + offset] == 0 || (max_len && i >= max_len))
			break ;
		if (*name)
		{
			*name = join_domain(name, tmp);
			free(tmp);
		}
		else
			*name = tmp;
	}
	if (*name)
	{
		*name = join_domain(name, tmp);
		free(tmp);
	}
	else
		*name = tmp;
	return (i);
}

int	ft_dns_getlabel_a(
		unsigned char *data,
		t_uint32 offset,
		char **name
	)
{
	t_int4	ip;

	ip = ft_int4_comp(
		data[offset],
		data[offset + 1],
		data[offset + 2],
		data[offset + 3]
	);
	*name = ft_utoa(ip);
	return (4);
}
