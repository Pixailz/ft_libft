/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:30:45 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 02:53:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write the character c to the file file_descriptor fd
 *
 * @param c			Character to write
 * @param fd		File descriptor
 *
 * @return (size_t)	Number of char written to fd.
 */
size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
