/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_hash_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 15:11:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

static		void	compute(t_uint32 *hash, char *ptr)
{
	// *hash ^= *((t_uint32 *)ptr);
	*hash *= *((t_uint32 *)ptr);
}

t_uint32	ft_ht_hash_key(const char *k)
{
	t_size		k_len = ft_strlen(k);
	t_uint32	hash = 1;
	t_size		index = 0;

	while (TRUE)
	{
		if (index + 4 >= k_len)
			break ;
		compute(&hash, (char *)k + index);
		index += 4;
	}

	if (index != k_len)
	{
		char buff[4] = {0};

		for (int i = 0; i + index < k_len; i++)
			buff[i] = k[index + i];

		compute(&hash, buff);
	}
	return (hash % HT_SIZE);
}
