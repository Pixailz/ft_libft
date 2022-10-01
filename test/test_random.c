/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:53:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 03:03:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_random.h"

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	counter;
	int	max;

	if (argc != 2)
		return (1);
	max = atoi(argv[1]);
	counter = 0;
	while (counter < max)
	{
		printf("[0-100] -> [%lld]\n", ft_randint(0, 100));
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
		printf("[0-100000] -> [%lld]\n", ft_randint(0, 100000));
		counter++;
	}
	return (0);
}
