/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 22:57:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

t_ht	*ft_ht_new()
{
	t_ht *table;

	table = (t_ht *)ft_calloc(1, sizeof(t_ht));
	table->item = (t_ht_item **)ft_calloc(HT_SIZE, sizeof(t_ht_item *));
	return table;
}
