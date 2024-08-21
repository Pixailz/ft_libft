/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 22:56:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

void	*ft_ht_get(t_ht *table, char *key)
{
	t_uint32	key_hash = ft_ht_hash_key(key);
	t_ht_item		*ptr = table->item[key_hash];
	t_size		len_str = ft_strlen(key);

	while (ptr && ft_strncmp(ptr->key, key, len_str))
		ptr = ptr->next;
	if (ptr)
		return ptr->value;
	return (FT_NULL);
}
