/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:35:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/07 22:36:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_random.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_size	counter;
	t_size	max;

	if (ac != 2)
		return (1);
	max = atoi(av[1]);
	counter = 0;
	while (counter < max)
		printf("[%lu] \t%s\n", counter++, ft_tmpfile(0));
	return (0);
}
