/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:02:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 02:02:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_random.h"

t_int64	ft_randint(int start, int end)
{
	int				file;
	t_int64			range;
	t_int64			sum;
	t_int64			counter;
	unsigned char	*buff;

	range = end - start + 1;
	if (range < 0)
		return (end + start + 1);
	range = (range / 0xff) + 1;
	file = open("/dev/urandom", O_RDONLY);
	buff = ft_calloc(sizeof(char), range);
	read(file, buff, range);
	close(file);
	sum = 0;
	counter = 0;
	while (counter++ < range)
		sum += buff[counter - 1];
	free(buff);
	return ((sum % (end - start + 1)) + start);
}
