/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:10 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:35:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_char(t_fmt_conf conf, va_list args)
{
	char	*buff;

	buff = ft_printf_buff_get();
	buff[*conf.i_buff] = va_arg(args, int);
	(*conf.i_buff)++;
}
