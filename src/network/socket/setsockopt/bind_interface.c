/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:05 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:22:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_bool ft_setsockopt_bind_interface(int sock, char *interface)
{
	return (
		setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE,
			interface, ft_strlen(interface))
				== -1
	);
}
