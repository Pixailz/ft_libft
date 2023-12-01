/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:02:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 15:14:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_random.h"

t_int8	ft_randchar(void)
{
	int		file;
	char	buff;

	file = open("/dev/urandom", O_RDONLY);
	read(file, &buff, 1);
	close(file);
	return (buff);
}
