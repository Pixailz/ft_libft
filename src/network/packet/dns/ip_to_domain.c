/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_to_domain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:55:14 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/27 12:26:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_network.h"


char	*ft_dns_ip_to_domain(t_int4 ip)
{
	char	*ip_str;
	char	*ret;

	ip_str = ft_getip_str(ft_htonl(ip));
	ret = ft_strjoin(ip_str, ".in-addr.arpa");
	free(ip_str);
	return (ret);
}
