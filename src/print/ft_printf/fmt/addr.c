/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 10:15:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_addr(t_fmt_conf *conf, va_list args)
{
	long long	addr;
	char		*addr_str;
	t_size		addr_str_len;

	addr = va_arg(args, unsigned long long);
	if (!addr)
		ft_strncpy(conf->cur_type, "(nil)", 5);
	else
	{
		ft_strncpy(conf->cur_type, "0x", 2);
		addr_str = ft_itoa_base(addr, "0123456789abcdef");
		addr_str_len = ft_strlen(addr_str);
		ft_strncpy(conf->cur_type + 2, addr_str, addr_str_len);
		free(addr_str);
	}
}
