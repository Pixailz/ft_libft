/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_singletone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:35:47 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 20:54:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int	*ft_socket_sing_get()
{
	static	int	*socks = FT_NULL;
	int	index;

	if (socks == FT_NULL)
	{
		socks = (int *)malloc(sizeof(int) * FT_SOCKET_MAX);
		if (socks == FT_NULL)
			return (FT_NULL);
		index = 0;
		while (index < FT_SOCKET_MAX)
		{
			socks[index] = -1;
			index++;
		}
		atexit(ft_socket_sing_free);
	}
	return (socks);
}

void	ft_socket_sing_free()
{
	int			*socks;
	t_socket_id	index;

	socks = ft_socket_sing_get();

	if (socks == FT_NULL)
		return ;
	index = 0;
	while (index < FT_SOCKET_MAX)
	{
		if (socks[index] != -1)
			close(socks[index]);
		index++;
	}
	free(socks);
}
