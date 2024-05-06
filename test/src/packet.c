/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:45:14 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 22:40:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

#include "libft_print.h"

void	test_get_packet()
{
	t_packet		pack;
	t_iphdr			*pack_ip_1;
	t_iphdr			*pack_ip_2;
	t_icmphdr_echo	*pack_icmp_echo_1;
	t_icmphdr_echo	*pack_icmp_echo_2;

	pack = ft_pkt_get();
	pack_ip_1 = ft_pkt_get_ip(&pack);
	pack_ip_2 = (t_iphdr *)pack.data;
	pack_icmp_echo_1 = ft_pkt_get_icmp_echo(&pack);
	pack_icmp_echo_2 = (t_icmphdr_echo *)pack.data + PACK_LEN_IP;

	ft_printf("ip 1:   %p\n", &pack_ip_1);
	ft_printf("ip 2:   %p\n", &pack_ip_2);
	ft_printf("icmp 1: %p\n", &pack_icmp_echo_1);
	ft_printf("icmp 2: %p\n", &pack_icmp_echo_2);
}

void	print_packet(t_packet pack)
{
	t_size	i;

	i = 0;
	while (i < 100)
	{
		ft_printf("%02x", pack.data[i]);
		i++;
		if (!(i % 4))
			ft_printf(" ");
		if (!(i % 16))
			ft_printf("\n");
	}
}

int main(void)
{
	t_packet		pack;
	t_iphdr			*pack_ip;
	t_icmphdr_echo	*pack_icmp_echo;

	pack = ft_pkt_get();
	pack_ip = ft_pkt_get_ip(&pack);
	pack_icmp_echo = ft_pkt_get_icmp_echo(&pack);

	pack_ip->version = 4;
	pack_icmp_echo->type = 8;

	print_packet(pack);
	return (0);
}
