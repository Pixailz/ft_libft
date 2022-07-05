/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:49:20 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 02:50:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write the string s to the file descriptor fd
 *
 * @param s			String to write
 * @param fd		File descriptor
 *
 * @return (size_t)	Number of char written to fd.
 */
size_t	ft_putstr_fd(char const *s, int fd)
{
	char	*tmp;

	if (!s || !fd)
		return (0);
	tmp = (char *)s;
	while (*tmp)
		tmp++;
	return (write(fd, s, tmp - s));
}
