/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:39:14 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 22:40:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_sort.h"

static int	ft_qsort_partition(
	void *arr,
	int low,
	int high,
	t_size size,
	t_sort_comp comp
)
{
	int	pivot_index;
	int i;
	int j;

	pivot_index = low + (high - low) / 2;
	if (pivot_index != high)
		ft_sort_swap(arr, pivot_index, high, size);
	pivot_index = high * size;
	i = low;
	j = low;
	while (j < high)
	{
		if (comp(arr + (j * size), arr + (high * size)) <= 0)
		{
			ft_sort_swap(arr, i, j, size);
			i++;
		}
		j++;
	}
	ft_sort_swap(arr, i, high, size);
	return (i);
}

static void ft_qsort_recursion(
	void *arr,
	int low,
	int high,
	t_size size,
	t_sort_comp comp
)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = ft_qsort_partition(arr, low, high, size, comp);
		ft_qsort_recursion(arr, low, pivot_index - 1, size, comp);
		ft_qsort_recursion(arr, pivot_index + 1, high, size, comp);
	}
}

void	ft_qsort(void *arr, t_size count, t_size size, t_sort_comp comp)
{
	ft_qsort_recursion(arr, 0, count - 1, size, comp);
}