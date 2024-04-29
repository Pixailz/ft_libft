/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:01:50 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/29 06:02:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

ht_item *ft_ht_new_item(char *key, void *value)
{
	ht_item	*ptr;

	ptr = (ht_item *)ft_calloc(1, sizeof(ht_item));
	ptr->value = value;
	ptr->key = ft_strdup(key);
	return (ptr);
}

ht_item	*ft_ht_add_item(ht_item **item, char *key, void *value)
{
	ht_item	**ptr = item;

	while (*ptr)
		ptr = &((*ptr)->next);
	*ptr = ft_ht_new_item(key, value);
	return (*item);
}
