/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:37:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 20:43:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

size_t	ft_vdprintf(int fd, const char *format, va_list args)
{
	size_t	size;

	size = 0;
	size = ft_dprintf_parse(fd, args, format);
	return (size);
}
