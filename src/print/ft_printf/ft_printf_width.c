/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 10:38:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_printf_fmt_get_width(int *i_fmt, const char *format)
{
	char	buff[FT_PRINTF_BUFF_SMALL];
	int		i;

	ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	i = 0;
	while (format[*i_fmt] && ft_isdigit(format[*i_fmt]))
		buff[i++] = format[(*i_fmt)++];
	return (ft_atoi(buff));
}
