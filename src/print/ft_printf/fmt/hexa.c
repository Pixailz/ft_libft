/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:46:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_hex(t_fmt_conf conf, va_list args)
{
	char	*buff;
	int		i;
	char	*i_str;
	t_size	i_str_len;

	buff = ft_printf_buff_get();
	i = va_arg(args, int);
	i_str = ft_itoa_base(i, "0123456789abcdef");
	i_str_len = ft_strlen(i_str);
	if (conf.flags & FT_PRINTF_FLAG_HASH)
	{
		ft_strncpy(buff + *conf.i_buff, "0x", 2);
		*conf.i_buff += 2;
	}
	ft_strncpy(buff + *conf.i_buff, i_str, i_str_len);
	free(i_str);
	*conf.i_buff += i_str_len;
}

void	ft_printf_fmt_hexa(t_fmt_conf conf, va_list args)
{
	char	*buff;
	int		i;
	char	*i_str;
	t_size	i_str_len;

	buff = ft_printf_buff_get();
	i = va_arg(args, int);
	i_str = ft_itoa_base(i, "0123456789ABCDEF");
	i_str_len = ft_strlen(i_str);
	if (conf.flags & FT_PRINTF_FLAG_HASH)
	{
		ft_strncpy(buff + *conf.i_buff, "0X", 2);
		*conf.i_buff += 2;
	}
	ft_strncpy(buff + *conf.i_buff, i_str, i_str_len);
	free(i_str);
	*conf.i_buff += i_str_len;
}
