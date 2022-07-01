/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:49:20 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 08:51:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write the string s to the file descriptor fd
 *
 * @param s			String to write
 * @param fd		File descriptor
 *
 * @return (void)	None.
 */
void	ft_putstr_fd(char const *s, int fd)
{
	char	*tmp;

	if (!s || !fd)
		return ;
	tmp = (char *)s;
	while (*tmp)
		tmp++;
	write(fd, s, tmp - s);
}
