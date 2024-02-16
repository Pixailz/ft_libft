/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:54:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/02/16 15:32:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

t_int4	ft_htoi4(char *hostname, char *service)
{
	struct addrinfo	*config;
	struct addrinfo	*result;
	t_int4			ip;

	config = (struct addrinfo *)ft_calloc(1, sizeof(struct addrinfo));
	ip = 0;
	config->ai_family = AF_INET;
	if (!getaddrinfo(hostname, service, config, &result))
	{
		ft_int4_chg(&ip, 0, result->ai_addr->sa_data[5]);
		ft_int4_chg(&ip, 1, result->ai_addr->sa_data[4]);
		ft_int4_chg(&ip, 2, result->ai_addr->sa_data[3]);
		ft_int4_chg(&ip, 3, result->ai_addr->sa_data[2]);
	}
	freeaddrinfo(config);
	return (ip);
}
