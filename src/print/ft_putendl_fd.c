/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:42:10 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 02:56:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write the string s and add a new line at the end to the
 *					file descriptor fd
 *
 * @param s			String to print
 * @param fd		File descriptor
 *
 * @return (size_t)	Number of char written to fd.
 */
size_t	ft_putendl_fd(char const *s, int fd)
{
	int	len;

	if (!s || !fd)
		return (0);
	len = 0;
	len += ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
