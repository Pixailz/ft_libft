/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 22:57:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

t_bool	ft_ht_set(t_ht *table, char *key, void *value)
{
	t_uint32	key_hash = ft_ht_hash_key(key);

	if (!table->item[key_hash])
		table->item[key_hash] = ft_ht_new_item(key, value);
	else
		table->item[key_hash] = ft_ht_add_item(&table->item[key_hash], key, value);
	return TRUE;
}
