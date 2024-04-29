/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/29 06:03:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

ht	*ft_ht_new()
{
	ht *table;

	table = (ht *)ft_calloc(1, sizeof(ht));
	table->item = (ht_item **)ft_calloc(HT_SIZE, sizeof(ht_item *));
	return table;
}
