/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:29:05 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 23:22:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_padding_char(t_fmt_conf *conf)
{
	char	*buff;
	t_size	counter;

	buff = ft_printf_buff_get();
	counter = 0;
	while (counter++ < conf->width)
		buff[(*conf->i_buff)++] = ' ';
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		buff[*conf->i_buff - conf->width] = conf->cur_type[0];
	else
		buff[*conf->i_buff - 1] = conf->cur_type[0];
}
