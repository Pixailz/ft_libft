/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:29:43 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 20:39:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int ft_socket_get(t_socket_id index)
{
	int	*socks;

	socks = ft_socket_sing_get();
	if (socks == FT_NULL)
		return (-1);
	return (socks[index]);
}

int *ft_socket_get_new()
{
	int			index;
	int			*socks;

	socks = ft_socket_sing_get();
	if (socks == FT_NULL)
		return ((void *)-1);
	index = 0;
	while (index < FT_SOCKET_MAX)
	{
		if (socks[index] == -1)
			return (&socks[index]);
		index++;
	}
	return ((void *)-1);
}

t_socket_id	ft_socket_get_index(int sock)
{
	t_socket_id	index;
	int			*socks;

	socks = ft_socket_sing_get();
	if (socks == FT_NULL)
		return (-1);
	index = 0;
	while (index < FT_SOCKET_MAX)
	{
		if (sock == socks[index])
			return (index);
		index++;
	}
	return (-1);
}
