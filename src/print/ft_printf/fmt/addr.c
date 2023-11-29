/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:36:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_addr(t_fmt_conf conf, va_list args)
{
	char		*buff;
	long long	addr;
	char		*addr_str;
	t_size		addr_str_len;

	buff = ft_printf_buff_get();
	addr = va_arg(args, unsigned long long);
	if (!addr)
	{
		ft_strncpy(buff + *conf.i_buff, "(nil)", 5);
		*conf.i_buff += 5;
	}
	else
	{
		ft_strncpy(buff + *conf.i_buff, "0x", 2);
		*conf.i_buff += 2;
		addr_str = ft_itoa_base(addr, "0123456789abcdef");
		addr_str_len = ft_strlen(addr_str);
		ft_strncpy(buff + *conf.i_buff, addr_str, addr_str_len);
		free(addr_str);
		*conf.i_buff += addr_str_len;
	}
}
