/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 18:45:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_string(t_fmt_conf *conf, va_list args)
{
	char	*src;
	t_size	src_len;

	src = va_arg(args, char *);
	if (src)
	{
		src_len = ft_strlen(src);
		ft_strncpy(conf->cur_type, src, src_len);
	}
	else
		ft_strncpy(conf->cur_type, "(null)", 6);
}
