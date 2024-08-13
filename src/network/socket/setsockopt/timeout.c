/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:05 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:22:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_bool ft_setsockopt_timeout(int sock, int timeout)
{
	struct timeval	tv;

	tv.tv_sec = timeout / A_SEC;
	tv.tv_usec = timeout % A_SEC;
	return (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1);
}
