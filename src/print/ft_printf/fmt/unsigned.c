/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 10:20:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_unsigned(t_fmt_conf *conf, va_list args)
{
	unsigned int	i;
	char			*i_str;
	t_size			str_len;

	i = va_arg(args, unsigned int);
	i_str = ft_utoa_base(i, "0123456789");
	str_len = ft_strlen(i_str);
	ft_strncpy(conf->cur_type, i_str, str_len);
	free(i_str);
}
