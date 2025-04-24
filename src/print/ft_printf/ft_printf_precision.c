/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:39:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_printf_fmt_get_precision(int *i_fmt, const char *format)
{
	char	buff[FT_PRINTF_BUFF_SMALL];
	int		i;

	// ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	buff[0] = '0';
	if (format[*i_fmt] && format[*i_fmt] == '.')
	{
		(*i_fmt)++;
		i = 0;
		while (format[*i_fmt] && ft_isdigit(format[*i_fmt]))
			buff[i++] = format[(*i_fmt)++];
	}
	return (ft_atoi(buff));
}
