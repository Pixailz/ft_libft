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
	int		file;
	char	buff[4];

	file = open("/dev/urandom", O_RDONLY);
	read(file, buff, 4);
	close(file);
	return ((int)(*((unsigned int*)buff) % (end - start)) + start);
}
