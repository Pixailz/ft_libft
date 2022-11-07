/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putip_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:36:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/07 03:39:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_print.h>

t_size	ft_putip_fd(t_int4 n, int fd)
{
	t_size	printed;

	printed = ft_putunbr_fd(ft_int4_dcomp(n, 3), fd);
	printed = ft_putchar_fd('.', fd);
	printed = ft_putunbr_fd(ft_int4_dcomp(n, 2), fd);
	printed = ft_putchar_fd('.', fd);
	printed = ft_putunbr_fd(ft_int4_dcomp(n, 1), fd);
	printed = ft_putchar_fd('.', fd);
	printed = ft_putunbr_fd(ft_int4_dcomp(n, 0), fd);
	return (printed);
}
