/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 05:29:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_sprintf(char *buff, const char *format, ...)
{
	va_list	args;
	char	*ptr_buffer;
	t_size	ret;

	va_start(args, format);
	ret = ft_printf_parse(args, format);
	va_end(args);
	ptr_buffer = ft_printf_buff_get();
	ft_memcpy(buff, ptr_buffer, ret);
	ptr_buffer[ret] = 0;
	return (ret);
}