/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:29:43 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 22:04:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int	ft_socket(int domain, int type, int protocol)
{
	int			*sock;

	sock = ft_socket_get_new();
	if (sock == (void *)-1)
		return (-1);
	*sock = socket(domain, type, protocol);
	if (*sock == -1)
		return (-1);
	return (*sock);
}
