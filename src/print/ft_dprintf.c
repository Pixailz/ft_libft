/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/01/18 15:05:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	char	*ptr_buffer;

	va_start(args, format);
	ft_printf_parse(args, format);
	va_end(args);
	ptr_buffer = ft_printf_buff_get();
	return (ft_putstr_fd(ptr_buffer, fd));
}
