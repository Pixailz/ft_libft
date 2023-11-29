/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:18:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:35:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_begin(t_fmt_conf conf, va_list args)
{
	char	*buff;

	(void)args;
	buff = ft_printf_buff_get();
	buff[*conf.i_buff] = '%';
	(*conf.i_buff)++;
}
