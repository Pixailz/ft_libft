/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:35:42 by stales            #+#    #+#             */
/*   Updated: 2022/11/07 04:46:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write integer nb, with a given base to the file descriptor
 * 					fd
 *
 * @param n			Integer to write
 * @param base		base to write from
 * @param fd		File descriptor
 *
 * @return (size_t)	Number of char written to fd.
 */
size_t	ft_putnbr_base_fd(t_int64 n, const char *base, int fd)
{
	t_int64	len;
	t_int64	base_len;

	len = 0;
	base_len = ft_strlen((char *)base);
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = ~(n - 1);
	}
	if (n >= base_len)
		len += ft_putnbr_base_fd(n / base_len, base, fd);
	len += ft_putchar_fd(base[n % base_len], fd);
	return (len);
}
