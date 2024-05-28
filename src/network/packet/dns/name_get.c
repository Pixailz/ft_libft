/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:40:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 21:16:03 by brda-sil         ###   ########.fr       */
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

int	ft_pkt_get_dnsr_name(
		unsigned char *data,
		char **name
	)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = FT_NULL;
	*name = FT_NULL;
	while (TRUE)
	{
		tmp = (char *)ft_calloc(data[i] + 2, sizeof(char));
		ft_memcpy(tmp, data + 1 + i, data[i]);
		i += data[i] + 1;
		if (data[i] == 0)
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
		*name = join_domain(name, tmp);
	else
		*name = tmp;
	if (tmp)
		free(tmp);
	return (i);
}
