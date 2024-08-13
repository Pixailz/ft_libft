/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipheader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:05 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:22:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_bool ft_setsockopt_ipheader(int sock)
{
	return (
		setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (int [1]){1}, sizeof(int))
			== -1
	);
}
