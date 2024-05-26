/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:02:43 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

struct sockaddr	ft_ltoaddr(t_int4 ip)
{
	struct sockaddr_in	addr;

	ft_memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_addr.s_addr = ip;
	return (*((struct sockaddr *)&addr));
}
