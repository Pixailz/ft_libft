/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_raw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:26:44 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 23:47:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

void	ft_pkt_print_raw(char *pkt, t_size size)
{
	t_size	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%02x", (unsigned char)pkt[i]);
		i++;
		if (i % 16 == 0)
			ft_printf("\n");
		else if (i % 4 == 0)
			ft_printf("   ");
		else if (i % 2 == 0)
			ft_printf(" ");
	}
	ft_printf("\n");
}
