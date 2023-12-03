/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:03:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_vprintf(const char *format, va_list args)
{
	char	*ptr_buffer;

	ft_printf_parse(args, format);
	ptr_buffer = ft_printf_buff_get();
	return (ft_putstr_fd(ptr_buffer, 1));
}
