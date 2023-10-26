/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:37:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 20:40:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

size_t	ft_vprintf(const char *format, va_list args)
{
	size_t	size;

	size = 0;
	size = ft_printf_parse(args, format);
	return (size);
}
