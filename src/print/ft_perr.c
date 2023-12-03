/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:34:27 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:04:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_perr(const char *format, ...)
{
	va_list	args;
	t_size	size;

	ft_putstr_fd(P_ERRO, 2);
	va_start(args, format);
	size = ft_vdprintf(2, format, args);
	va_end(args);
	return (size);
}
