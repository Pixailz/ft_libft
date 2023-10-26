/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdeb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:24:53 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:45:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

t_size	ft_pdeb(const char *format, ...)
{
	va_list	args;
	t_size	size;

	ft_putstr_fd(P_DEBG, DEBUG_FD);
	va_start(args, format);
	size = ft_vdprintf(DEBUG_FD, format, args);
	va_end(args);
	return (size);
}
