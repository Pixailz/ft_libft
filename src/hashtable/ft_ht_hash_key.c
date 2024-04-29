/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_hash_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/29 06:01:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

t_uint32	ft_ht_hash_key(const char *k)
{
	t_size		k_len = ft_strlen(k);
	t_uint32	hash = 1;
	t_size		index = 0;

	while (TRUE)
	{
		if (index + 4 >= k_len)
			break ;

		hash = (hash * (*((t_uint32 *)(k + index))));
		index += 4;
	}

	if (index != k_len)
	{
		unsigned char buff[4] = {0};

		for (int i = 0; i + index < k_len; i++)
			buff[i] = k[index + i];

		hash = (hash * (*((t_uint32 *)(buff))));
	}

	return (hash % HT_SIZE);
}
