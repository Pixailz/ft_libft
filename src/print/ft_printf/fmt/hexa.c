/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 11:19:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_hex(t_fmt_conf *conf, va_list args)
{
	int		i;
	char	*i_str;
	t_size	str_len;

	i = va_arg(args, int);
	i_str = ft_itoa_base(i, "0123456789abcdef");
	str_len = ft_strlen(i_str);
	ft_strncpy(conf->cur_type + ft_strlen(conf->cur_type), i_str, str_len);
	free(i_str);
}

void	ft_printf_type_hexa(t_fmt_conf *conf, va_list args)
{
	int		i;
	char	*i_str;
	t_size	str_len;

	i = va_arg(args, int);
	i_str = ft_itoa_base(i, "0123456789abcdef");
	str_len = ft_strlen(i_str);
	ft_strncpy(conf->cur_type + ft_strlen(conf->cur_type), i_str, str_len);
	free(i_str);
}
