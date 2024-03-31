/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:54:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/03/31 23:23:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

t_int4	ft_htoi4_getaddrinfo(char *hostname, char *service)
{
	struct addrinfo	config;
	struct addrinfo	*result;
	t_int4			ip;

	ft_bzero(&config, sizeof(config));
	ip = 0;
	config.ai_family = AF_INET;
	if (!getaddrinfo(hostname, service, &config, &result))
	{
		ft_int4_chg(&ip, 0, result->ai_addr->sa_data[5]);
		ft_int4_chg(&ip, 1, result->ai_addr->sa_data[4]);
		ft_int4_chg(&ip, 2, result->ai_addr->sa_data[3]);
		ft_int4_chg(&ip, 3, result->ai_addr->sa_data[2]);
	}
	freeaddrinfo(result);
	return (ip);
}

t_int4	ft_htoi4(char *hostname, char *service)
{
	if (HTOI4_USE_EPOLL == 0)
		ft_htoi4_getaddrinfo(hostname, service);
	// else
	// 	ft_hoti4_epoll(hostname, service);
}
