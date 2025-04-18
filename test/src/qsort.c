/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:07:14 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 12:14:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isexec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:32:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 20:35:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_sort.h"
#include "libft_print.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

typedef struct s_test_qsort
{
	int		id;
	char	*name;
}	t_test_qsort;

int	__comp(const void *a, const void *b)
{
	return (((t_test_qsort *)a)->id > ((t_test_qsort *)b)->id);
}

int	ci_test(void)
{
	t_test_qsort arr[] = {
		{ .id = 9, .name = "Isabelle" },
		{ .id = 2, .name = "Barbara" },
		{ .id = 5, .name = "Emilie" },
		{ .id = 3, .name = "Corine" },
		{ .id = 1, .name = "Albert" },
		{ .id = 8, .name = "Homer" },
		{ .id = 4, .name = "Daniel" },
		{ .id = 7, .name = "George" },
		{ .id = 6, .name = "Fanny" },
	};
	int len = 9;

	ft_qsort(arr, len, sizeof(t_test_qsort), __comp);

	int last_value;
	last_value = 0;
	for (int i = 0; i < len; i++)
	{
		if (last_value > arr[i].id)
			return (1);
		last_value = arr[i].id;
		ft_printf("arr[%d]: (%d) %s\n", i, arr[i].id, arr[i].name);
	}
	return (0);
}

int	interactive(int ac, char **av)
{
	(void)ac;
	(void)av;
	return (0);
}

int	main(int ac, char **av)
{
	if (CI_TEST)
		return (ci_test());
	else
		return (interactive(ac, av));
	return (0);
}
