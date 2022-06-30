/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:35:42 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 02:58:00 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Write integer nb to the file descriptor fd
 *
 * @param n			Integer to write
 * @param fd		File descriptor
 *
 * @return (void)	None.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n > 2147483647)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = ~(n - 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
