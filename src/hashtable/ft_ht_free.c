/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 22:56:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

void	ft_ht_free(t_ht *table)
{
	t_ht_item		*ptr;
	t_ht_item		*tmp;

	for (unsigned long int i = 0; i < HT_SIZE; i++)
	{
		ptr = table->item[i];
		while (ptr)
		{
			tmp = ptr->next;
			free(ptr->key);
			free(ptr);
			ptr = tmp;
		}
	}
	free(table->item);
	free(table);
}
