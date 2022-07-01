/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:30:45 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 08:50:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write the character c to the file file_descriptor fd
 *
 * @param c			Character to write
 * @param fd		File descriptor
 *
 * @return (void)	None.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
