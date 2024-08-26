/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 05:11:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_vsprintf(char *buff, const char *format, va_list args)
{
	char	*ptr_buffer;
	t_size	ret;

	ft_printf_parse(args, format);
	ptr_buffer = ft_printf_buff_get();
	ret = ft_strlen(ptr_buffer);
	ft_memcpy(buff, ptr_buffer, ret);
	ptr_buffer[ret] = 0;
	return (ret);
}