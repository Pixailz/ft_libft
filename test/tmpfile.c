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

int	main(void)
{
	t_size	counter;

	counter = 0;
	while (counter < 10)
		printf("[%lu] \t%s\n", counter++, ft_tmpfile(0));
	return (0);
}
