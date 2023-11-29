/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:36:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_string(t_fmt_conf conf, va_list args)
{
	char	*buff;
	char	*src;
	t_size	src_len;

	buff = ft_printf_buff_get();
	src = va_arg(args, char *);
	src_len = ft_strlen(src);
	ft_strncpy(buff + *conf.i_buff, src, src_len);
	*conf.i_buff += src_len;
}
