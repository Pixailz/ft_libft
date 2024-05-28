/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getip_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 14:54:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

static	t_size	set_part(char *ptr, t_int4 n, t_size i)
{
	char	*tmp_n;
	t_size	len_tmp_n;

	tmp_n = ft_itoa(ft_int4_dcomp(n, i));
	len_tmp_n = ft_strlen(tmp_n);
	ft_memcpy(ptr, tmp_n, len_tmp_n);
	if (i)
	{
		ptr[len_tmp_n] = '.';
		len_tmp_n++;
	}
	free(tmp_n);
	return (len_tmp_n);
}

char	*ft_getip_str(t_int4 n)
{
	char	*ptr;
	t_size	index;

	ptr = (char *)ft_calloc(16, sizeof(char));

	index = set_part(ptr, n, 3);
	index += set_part(ptr + index, n, 2);
	index += set_part(ptr + index, n, 1);
	index += set_part(ptr + index, n, 0);

	return ptr;
}
