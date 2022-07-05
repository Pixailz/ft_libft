/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:35:42 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 03:30:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write long long nb to the file descriptor fd
 *
 * @param n			Long Long to write
 * @param fd		File descriptor
 *
 * @return (size_t)	Number of char written to fd.
 */
size_t	ft_putunbr_fd(unsigned long n, int fd)
{
	size_t	len;

	len = 0;
	if (n > 4294967295U)
		return (0);
	if (n >= 10)
		len += ft_putunbr_fd(n / 10, fd);
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
