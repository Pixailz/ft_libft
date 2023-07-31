/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:53:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 20:36:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_random.h"

#include <stdio.h>
#include <string.h>

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

int	ci_test(void)
{
	// TODO: add more stuff
	return (0);
}

int	interactive(int ac, char **av)
{
	int	counter;
	int	max;

	if (ac != 2)
		return (1);
	max = atoi(av[1]);
	counter = 0;
	while (counter < max)
	{
		printf("[0, 100] -> [%lld]\n", ft_randint(0, 100));
		counter++;
	}
	counter = 0;
	while (counter < max)
	{
		printf("[-10, 10] -> [%lld]\n", ft_randint(-10, 10));
		counter++;
	}
	counter = 0;
	while (counter < max)
	{
		printf("[0, 100000] -> [%lld]\n", ft_randint(0, 100000));
		counter++;
	}
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
