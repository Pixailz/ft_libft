/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:16:08 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 12:17:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_sort.h"

void ft_sort_swap(void *arr, t_size ia, t_size ib, t_size size)
{
	unsigned char	*sa;
	unsigned char	*sb;
	unsigned char	tmp;
	t_size			i;

	i = 0;
	sa = (unsigned char *)(arr + (ia * size));
	sb = (unsigned char *)(arr + (ib * size));
	while (i < size)
	{
		tmp = sa[i];
		sa[i] = sb[i];
		sb[i] = tmp;
		i++;
	}
}