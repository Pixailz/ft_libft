/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:42:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_unsigned(t_fmt_conf conf, va_list args)
{
	char			*buff;
	unsigned int	i;
	char			*i_str;
	t_size			i_str_len;

	buff = ft_printf_buff_get();
	i = va_arg(args, unsigned int);
	i_str = ft_utoa_base(i, "0123456789");
	i_str_len = ft_strlen(i_str);
	if (i > 0)
	{
		if (conf.flags & FT_PRINTF_FLAG_PLUS)
			ft_strncpy(buff + (*conf.i_buff)++, "+", 1);
		else if (conf.flags & FT_PRINTF_FLAG_SPACE)
			ft_strncpy(buff + (*conf.i_buff)++, " ", 1);
	}
	ft_strncpy(buff + *conf.i_buff, i_str, i_str_len);
	free(i_str);
	*conf.i_buff += i_str_len;
}
