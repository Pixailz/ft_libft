/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:05:41 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:05:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_print.h>

t_size	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptr_buffer;

	ft_printf_buff_reset();
	va_start(args, format);
	ft_printf_parse(args, format);
	va_end(args);
	ptr_buffer = ft_printf_buff_get();
	return (ft_putstr_fd(ptr_buffer, 1));
}
