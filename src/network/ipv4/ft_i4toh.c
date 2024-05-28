/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i4toh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:54:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 21:12:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

char	*ft_i4toh_getnameinfo(t_int4 ip)
{
	struct sockaddr_in	sa;
	char				hostname[NI_MAXHOST];

	ft_bzero(&sa, sizeof(struct sockaddr_in));
	ft_bzero(&hostname, NI_MAXHOST);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = ip;
	if (getnameinfo((struct sockaddr *)&sa, sizeof(sa), hostname, NI_MAXHOST, NULL, 0, 0) != 0)
		return (NULL);
	return (ft_strdup(hostname));
}

char	*ft_i4toh(t_int4 ip)
{
	char	*retv;

	if (I4TOH_USE_SOCKET)
		retv = ft_i4toh_socket(ip);
	else
		retv = ft_i4toh_getnameinfo(ip);
	return (retv);
}
