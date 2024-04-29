/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:00:45 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/29 06:11:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"

t_size ft_ht_len(ht table)
{
	t_size	len = 0;
	ht_item	*ptr;

	for (unsigned long int i = 0; i < HT_SIZE; i++)
	{
		ptr = table.item[i];

		while (ptr)
		{
			if (ptr->value)
				len++;
			ptr = ptr->next;
		}
	}
	return (len);
}
